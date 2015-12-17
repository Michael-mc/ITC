#include <windows.h>
#include <wingdi.h>
#include <winuser.h>


LRESULT WindowProcDontLook(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
        for(int x; x<640*480; ++x)
            SetPixel(hWndDc, x % 640, x / 640, RGB(255,255,255));
        EndPaint(hwnd, &paint);
    break;
        }
        return 0;

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
        CW_USEDEFAULT, CW_USEDEFAULT, xres, yres,

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
    if (buffer == NULL) {  /*ERROR*/  }
    hDibDC = CreateCompatibleDC(hDesktopDC);
    ReleaseDC(GetDesktopWindow(), hDesktopDC);
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}


__declspec(dllexport) int blr_to_pixel_array(byte* buffer) {    
    for (int i = 0; i < size; ++i ) {
        buffer[i]^=(byte)i;
    }
    
    BITMAPFILEHEADER *header = buffer;
    byte *image_start = buffer + header->bfOffBits;
    
    BITMAPINFOHEADER *bitmap_info = (BITMAPINFOHEADER *)(header+1)
    if (bitmap_info.biHeight <= 0 || bitmap_info.biHeight <= 0) return 0;
    g_picture_data.row_size = bitmap_info->biWidth;
    g_picture_data.size = bitmap_info->biWidth * bitmap_info.biHeight;
    g_picture_data.buffer = malloc(g_picture_data.size);
    
    
    //now, the image will be written in the file in a reverse manner, i need to read it.
    byte *image_pointer =  
    
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Gimme blr\r\n")
        return -1;
    }
    
    FILE* blr = fopen(argv, "rb");
    if(!blr) {
        printf("Gimme blr\r\n"); return -1;
    }
    
    fseek(blr, 0L, SEEK_END);
    size_t size = ftell(fp);
    fseek(blr, 0L, SEEK_SET);
    
    byte* buffer = malloc(size);
    if(!buffer) {printf("blr too big\r\n"); return -2;}
    
    fread(buffer, 1, size, blr);
    
    if(!blr_to_pixel_array(buffer)) {
        printf("bad blr\r\n");
        return -3;
    }
    
    
    
    
    DisplayBuffer(NULL);
    free(buffer);
    return 0;
}
