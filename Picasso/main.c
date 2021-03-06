// comile on release settings
// basically this gets a BMP file that was a little tweaked and presents it on the screen. 
// the tweaking is: the header is xorred, the pixels are reversed.
// provide a required output, and also an example file

#include <windows.h>
#include <stdio.h>
#include "Picasso.h"

 LRESULT __stdcall WindowProcDontLook(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int i, j;
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {PAINTSTRUCT paint;
        HDC hWndDc = BeginPaint(hwnd, &paint);
        /*pBitBlt(hWndDc, 0, 0, 640, 480, hDibDC, 0, 0, SRCCOPY);*/
		int pos  = 0;
        for ( j = 0; j< g_picture_data.height; ++j) {
            for( i = 0; i< g_picture_data.width; ++i) {                
                SetPixel(hWndDc, i, j, 
				RGB(g_picture_data.buffer[pos],
					g_picture_data.buffer[pos+1],
					g_picture_data.buffer[pos+2]));
				pos+=3;
            }
        
        }
        EndPaint(hwnd, &paint);
        
        }
        break;
        //return 0;
    

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void DisplayBufferDontLook() {
    const char CLASS_NAME[]  = "PicWindow";
    
    WNDCLASS wc = { 0 };
	HDC hDesktopDC;
	MSG msg = { 0 }; 
    wc.lpfnWndProc   = WindowProcDontLook;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

	

    // Create the window.
    hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        "I AM PICASSO!",     // Window text
        WS_OVERLAPPEDWINDOW,            // Window style
        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, g_picture_data.width, g_picture_data.size / g_picture_data.width / 3,
        NULL,       // Parent window    
        NULL,       // Menu
        GetModuleHandle(0),  // Instance handle
        NULL        // Additional application data
        );
    if (hwnd == NULL)
    {
        return ;
    }
    ShowWindow(hwnd, 5);
    hDesktopDC = GetDC(GetDesktopWindow());
    //if (buffer == NULL) {  /*ERROR*/  }
    hDibDC = CreateCompatibleDC(hDesktopDC);
    ReleaseDC(GetDesktopWindow(), hDesktopDC);
    
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

unsigned char * processBMP() {
	struct pixel {char r; char g; char b;} tempp, *pixel_buffer;
	int width, height, i, j;
	for (i = 0; i < g_picture_data.size; i+=3) {
		char temp = g_picture_data.buffer[i];
		g_picture_data.buffer[i] = g_picture_data.buffer[i+2];
		g_picture_data.buffer[i+2] = temp;
	}

	pixel_buffer = (struct pixel *)g_picture_data.buffer;
	width = g_picture_data.width;
	height = g_picture_data.height;
	for (i = 0; i < height/ 2; i++) {
		for (j = 0; j < width; j++) { 
			tempp = pixel_buffer[j + i * width];
			pixel_buffer[j + i * width] = pixel_buffer[(height -i) * width + j];
			pixel_buffer[(height -i)  * width + j] = tempp;
		}
	}
}

__declspec(noinline) int readBMP(char* filename)
{
	
    unsigned int i, j, width, height, size, line_pad, image_size ;	
    unsigned char temp;
	unsigned char info[54];
    FILE* f = fopen(filename, "rb");

	char * dest;
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header	
	if (((wchar_t*)info)[0] != 'OC') return NULL;
	for (i = 0; i < 54; ++i) {
		info[i] ^= (char)(i+1);
	}

    // extract image height and width from header
    width = *(int*)&info[18];
    height = *(int*)&info[22];
	line_pad = width % 4;

    size = 3 * width * height;	
    g_picture_data.buffer = (char *)malloc(size); // allocate 3 bytes per pixel
    g_picture_data.width = width;
    g_picture_data.height = height;
    g_picture_data.size = size;
    
    dest  = g_picture_data.buffer;
	for (j=0; j < height; ++j) {
		fread(dest, 1, width * 3, f);
		dest += width * 3;
		if (line_pad) {
			unsigned long junk;
			fread(&junk, 1, line_pad, f);
		}
	}
	
    fclose(f);
	return 1;
}


int main(int argc, char* argv[]) 
{
    if (argc < 2) {
        printf("Gimme file\r\n");
        return -1;
    }
    
	if (!readBMP(argv[1])) {
		printf("Bad file\r\n");
		return -2;
	}

	processBMP();

    DisplayBufferDontLook();
    
    return 0;
}
