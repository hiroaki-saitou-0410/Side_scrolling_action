#include"Window.h"

const char* Window::ClassName = "Side_scrolling_action";

LRESULT CALLBACK Window::WindowProcedure(HWND window_handle, UINT message_id, WPARAM wparam, LPARAM lparam)
{
	switch (message_id)
	{
	case WM_CLOSE: PostQuitMessage(0);
		break;
	default:	return DefWindowProc(window_handle, message_id, wparam, lparam);
		break;
	}
	return 0;
}

bool Window::Create()
{
	if (!WindowClass())return false;

	HWND window_handle = CreateWindow(
		Window::ClassName,
		Title,
		(WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME),
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		Width,
		Height,
		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL);
	if (window_handle == NULL) { return false; }

	Resize(window_handle);

	return true;
}

bool Window::WindowClass()
{
	WNDCLASSEX window_class =
	{
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW,
		WindowProcedure,
		0,
		0,
		GetModuleHandle(NULL),
		LoadIcon(NULL,IDI_APPLICATION),
		LoadCursor(NULL,IDC_ARROW),
		NULL,
		NULL,
		Window::ClassName,
		NULL
	};

	if (RegisterClassEx(&window_class) == 0) { return false; }
	return true;
}

void Window::Resize(HWND window_handle)
{
	RECT window_rect;
	RECT client_rect;

	GetWindowRect(window_handle, &window_rect);
	GetClientRect(window_handle, &client_rect);

	int frame_sizeX = (window_rect.right - window_rect.left) - (client_rect.right - client_rect.left);
	int frame_sizeY = (window_rect.bottom - window_rect.top) - (client_rect.bottom - client_rect.top);

	SetWindowPos(
		window_handle,
		NULL,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		frame_sizeX + Width,
		frame_sizeY + Height,
		SWP_NOMOVE
	);

	ShowWindow(window_handle, SW_SHOW);
	UpdateWindow(window_handle);
}
