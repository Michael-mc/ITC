
#include <string.h>
#include <Windows.h>
#include <stdio.h>
#include "sha1.h"
#include "resource.h"

/*
	in this exercise we're basically using the debugger to step over complicated stuff;
	for example - change the result of a big ass authentication function to true.
	another example - set eip to where you want the code to go
	one more - eradicate functions that call exit
*/

__declspec (dllexport) unsigned long long sha_string(unsigned char *a) {
	unsigned char out[20];
	mbedtls_sha1(a, strlen(a), out);
	return *(unsigned long long *)out;
}

__forceinline void fill_path(char *path) {
	*(path++) = '%';
	*(path++) = 'T';
	*(path++) = 'E';
	*(path++) = 'M';
	*(path++) = 'P';
	*(path++) = '%';
	*(path++) = '\\';
	*(path++) = 'g';
	*(path++) = 'a';
	*(path++) = 'm';
	*(path++) = 'e';
	*(path++) = '.';	
	*(path++) = 'e';
	*(path++) = 'x';
	*(path++) = 'e';
	*(path++) = '\0';
}

void create_process_elaborate() {
		char packed[0x10];
		char path[MAX_PATH];
		// First find and load the required resource
		HMODULE hInstance = GetModuleHandle(NULL);
		HRSRC hResource = FindResource(hInstance, MAKEINTRESOURCE(IDR_BINARY1), TEXT("BINARY"));
		HGLOBAL hFileResource = LoadResource(hInstance, hResource);
		
		// Now open and map this to a disk file
		LPVOID lpFile = LockResource(hFileResource);
		DWORD written, dwSize = SizeofResource(hInstance, hResource);
		HANDLE hFile;
		STARTUPINFO a = { 0 };
		
		PROCESS_INFORMATION b;


		fill_path(packed);
		ExpandEnvironmentStringsA(packed,path, 256);
		// Open the file and filemap
		hFile = CreateFile(path, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		
		if (!WriteFile(hFile, lpFile, dwSize, &written, NULL)) MessageBox(0, "You did ok, something else failed", "Oops!", 0);
		CloseHandle(hFile);		
		a.cb = sizeof(a);
		written = CreateProcess(path, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &a, &b);
}

void main() {
	FILE *key = fopen("mykey.h", "r");
	int size;
	char *input;	
	if (!key) return;
	fseek(key, 0, SEEK_END);
	size = ftell(key);
	fseek(key, 0, SEEK_SET);
	input = malloc(size + 1);
	if (!input ) return;
	fread (input, 1, size, key);
	input[size] = 0;	
	if (0xDEADBEEFCAFEBABE != sha_string(input)) return;
	
	create_process_elaborate();	
}
