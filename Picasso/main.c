#include <windows.h>
#include <stdio.h>
#include "Picasso.h"

__stdcall LRESULT WindowProcDontLook(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {PAINTSTRUCT paint;
        HDC hWndDc = BeginPaint(hwnd, &paint);
        /*pBitBlt(hWndDc, 0, 0, 640, 480, hDibDC, 0, 0, SRCCOPY);*/
        for (int j = 0; j< g_picture_data.height; j++) {
            for(int i = 0; i< g_picture_data.row_size; ++i) {
                int pos = j * g_picture_data.row_size + i * 3;
                SetPixel(hWndDc, i, j, 
                RGB(g_picture_data.buffer[pos],
                    g_picture_data.buffer[pos+1],
                    g_picture_data.buffer[pos+2]));
            }
        
        }
        EndPaint(hwnd, &paint);
        
        }
        break;
        //return 0;
    

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void DisplayBuffer(byte* buffer) {
    const wchar_t CLASS_NAME[]  = L"PicWindow";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProcDontLook;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style
        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, g_picture_data.row_size, g_picture_data.size / g_picture_data.row_size / 3,
        NULL,       // Parent window    
        NULL,       // Menu
        GetModuleHandle(0),  // Instance handle
        NULL        // Additional application data
        );
    if (hwnd == NULL)
    {
        return 0;
    }
    ShowWindow(hwnd, 5);
    HDC hDesktopDC = GetDC(GetDesktopWindow());
    //if (buffer == NULL) {  /*ERROR*/  }
    hDibDC = CreateCompatibleDC(hDesktopDC);
    ReleaseDC(GetDesktopWindow(), hDesktopDC);
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

unsigned char* readBMP(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    int size = 3 * width * height;
    g_picture_data.buffer = malloc(size); // allocate 3 bytes per pixel
    g_picture_data.row_size = width;
    g_picture_data.height = height;
    g_picture_data.size = size;
    
    printf("width: %d, height: %d", width, height);
    int line_pad = g_picture_data.row_size % 4;
    printf("line pad: %d", line_pad);
    char * dest = g_picture_data.buffer;
    for (int j = 0 ; j< height; j++) {
        fread(dest , 3, width, f); // read the rest of the data at once
        dest += 3 * width;
        if (line_pad) {
            DWORD junk;
            fread(&junk, 1, line_pad, f);
        }        
    }/*
    for (int x= 0 ; x < size; x+=3) {
        char temp = g_picture_data.buffer[x];
        g_picture_data.buffer[x] = g_picture_data.buffer[x+2];
        g_picture_data.buffer[x+2] = temp;
    }*/
    printf("\r\n");
    //  printf("%x %x %x %x %x %x", g_picture_data.buffer[0], g_picture_data.buffer[1], g_picture_data.buffer[2], g_picture_data.buffer[3] ,g_picture_data.buffer[4], g_picture_data.buffer[5], g_picture_data.buffer[6]);
    
    fclose(f);
}


int main(int argc, char* argv[]) 
{
    if (argc < 2) {
        printf("Gimme blr\r\n");
        return -1;
    }
    
    readBMP(argv[1]);
    
    DisplayBuffer(NULL);
    
    return 0;
}
