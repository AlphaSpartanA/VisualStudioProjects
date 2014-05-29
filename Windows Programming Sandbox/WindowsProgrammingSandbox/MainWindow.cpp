#include <Windows.h>

LRESULT CALLBACK windowProcedure(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam) //Define the main window procedure
{
	switch (message)
	{
	case WM_LBUTTONDOWN: // handle left mouse button click
		MessageBox(0, L"WM_LBUTTON DOWN message", L"Msg", MB_OK);
		return 0;
	case WM_KEYDOWN: // handle the escape key
		if (wParam == VK_ESCAPE)
			DestroyWindow(windowHandle);
		return 0;
	case WM_DESTROY: // handle exiting the application
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(windowHandle, message, wParam, lParam); // invoke the default window procedure for standard window functionality
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd) // enter the program loop
{
}