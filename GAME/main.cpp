#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

int CALLBACK WinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR     lpCmdLine,
  int       nCmdShow)
{
	WNDCLASS wc;
	
	RECT wr = {0,0,600,300};
	
	HWND hWnd;
		
	wc.style = CS_HREDRAW|CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW; //CreateSolidBrush(RGB(0,200,200));
	wc.lpszClassName = "asd";
	
	hWnd = CreateWindow(
	"asd",
	"Window Title",
	WS_OVERLAPPEDWINDOW,
	10,
	10,
	wr.right - wr.left,
	wr.bottom - wr.top,
	NULL,
	NULL,
	hInstance,
	NULL
	);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	MSG msg;
	/*while(true)
	{*/
		while (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	//}
	
	return (int) msg.wParam;
};

LRESULT CALLBACK WndProc(
  HWND   hwnd,
  UINT   uMsg,
  WPARAM wParam,
  LPARAM lParam)
{
	switch(uMsg)
	{
		case(WM_QUIT):
			{
				PostQuitMessage(0);
			}break;
	}
	return 0;
};
