#include <Windows.h>
__declspec(dllexport)
LRESULT __stdcall WindowProcDontLook(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

__declspec(dllexport)
void DisplayBufferDontLook() ;


HWND hwnd;
HDC hDibDC;

struct PictureData {
	char *buffer;
	size_t size;
	size_t width;
	size_t height;
};


struct PictureData g_picture_data = {0};


