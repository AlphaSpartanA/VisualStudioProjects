#include <Windows.h>

//stores handles to the main window and application instance globally
HWND mainWindow = 0;
HINSTANCE appInstance = 0;

//Define the main window procedure
LRESULT CALLBACK windowProcedure(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam) 
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
	//Save handle to application instance
	appInstance = hInstance;

	//fill out a WNDCLASS structure
	WNDCLASS wc;
	wc.style = CS_HREDRAW| CS_VREDRAW;
	wc.lpfnWndProc = windowProcedure;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = appInstance;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"mainWindowClass";

	//Register the class with Windows so it knows that the hell is going on... Because Windows is stupid... :)
	RegisterClass(&wc);

	//Create the Window with this stupid long function, and assign the result to the mainWindow handle.
	mainWindow = CreateWindow(L"mainWindowClass", L"My Window", WS_OVERLAPPEDWINDOW, 240, 240, 720, 720, 0, 0, appInstance, 0);

	//Throw an error and create a messagebox to ask the user if they want to retry
	//TODO:: implement retry functionality
	if (mainWindow == 0)
	{
		MessageBox(0, L"CreateWindow - Failed", 0, MB_RETRYCANCEL);
		return false;
	}

	//Show and update the window
	ShowWindow(mainWindow, showCmd);
	UpdateWindow(mainWindow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


}