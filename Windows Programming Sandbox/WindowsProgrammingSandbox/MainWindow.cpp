#include <Windows.h>

//stores handles to the three windows and application instance globally
HWND window1 = 0;
HWND window2 = 0;
HWND window3 = 0;
HINSTANCE appInstance = 0;

int quit;

//Window procedure for the first window
LRESULT CALLBACK window1Procedure(HWND window1, UINT message, WPARAM wParam, LPARAM lParam) 
{
	switch (message)
	{
	case WM_LBUTTONDOWN: // handle left mouse button click
		MessageBox(0, L"You clicked Window #1", L"Window 1", MB_OK);
		return 0;
	case WM_KEYDOWN: // handle the escape key
		if (wParam == VK_ESCAPE)
			quit = MessageBox(window1, L"Are you sure you want to Exit window #1 ?", L"Exit Window #1?", MB_YESNO);
		if (quit == 6)//If the user pressed yes, exit the program.
			DestroyWindow(window1);
		else//Otherwise, continue the loop.
			return 0;
	case WM_DESTROY: // handle exiting the application
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(window1, message, wParam, lParam); // invoke the default window procedure for standard window functionality
}

//Window procedure for the second window
LRESULT CALLBACK window2Procedure(HWND window2, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN: // handle left mouse button click
		MessageBox(0, L"You clicked Window #2", L"Window 2", MB_OK);
		return 0;
	case WM_KEYDOWN: // handle the escape key
		if (wParam == VK_ESCAPE)
			quit = MessageBox(window2, L"Are you sure you want to Exit window #2 ?", L"Exit Window #2?", MB_YESNO);
		if (quit == 6)//If the user pressed yes, exit the program.
			DestroyWindow(window2);
		else//Otherwise, continue the loop.
			return 0;
	case WM_DESTROY: // handle exiting the application
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(window1, message, wParam, lParam); // invoke the default window procedure for standard window functionality
}

//Window procedure for the third window
LRESULT CALLBACK window3Procedure(HWND window3, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN: // handle left mouse button click
		MessageBox(0, L"You clicked Window #3", L"Window 3", MB_OK);
		return 0;
	case WM_KEYDOWN: // handle the escape key
		if (wParam == VK_ESCAPE)
			quit = MessageBox(window3, L"Are you sure you want to Exit window #3 ?", L"Exit Window #3?", MB_YESNO);
		if (quit == 6)//If the user pressed yes, exit the program.
			DestroyWindow(window3);
		else//Otherwise, continue the loop.
			return 0;
	case WM_DESTROY: // handle exiting the application
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(window1, message, wParam, lParam); // invoke the default window procedure for standard window functionality
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd) // enter the program loop
{
	//Save handle to application instance
	appInstance = hInstance;

	//fill out a WNDCLASS structure for the first window
	WNDCLASS wc1;
	wc1.style = CS_HREDRAW| CS_VREDRAW;
	wc1.lpfnWndProc = window1Procedure;
	wc1.cbClsExtra = 0;
	wc1.cbWndExtra = 0;
	wc1.hInstance = appInstance;
	wc1.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc1.hCursor = LoadCursor(0, IDC_ARROW);
	wc1.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc1.lpszMenuName = 0;
	wc1.lpszClassName = L"window1Class";

	//for the second window
	WNDCLASS wc2;
	wc2.style = CS_HREDRAW | CS_VREDRAW;
	wc2.lpfnWndProc = window2Procedure;
	wc2.cbClsExtra = 0;
	wc2.cbWndExtra = 0;
	wc2.hInstance = appInstance;
	wc2.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc2.hCursor = LoadCursor(0, IDC_ARROW);
	wc2.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc2.lpszMenuName = 0;
	wc2.lpszClassName = L"window2Class";

	//Register the class with Windows so it knows that the hell is going on... Because Windows is stupid... :)
	RegisterClass(&wc1);

	//Create the Window with this stupid long function, and assign the result to the mainWindow handle.
	window1 = CreateWindow(L"mainWindowClass", L"My Window", WS_OVERLAPPEDWINDOW|WS_HSCROLL|WS_VSCROLL, 240, 240, 720, 720, 0, 0, appInstance, 0);

	//Throw an error and create a messagebox to ask the user if they want to retry
	//TODO:: implement retry functionality
	if (window1 == 0)
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