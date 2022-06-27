#ifndef WINDOW_H
#define WINDOW_H

#include<Windows.h>
#include<d3d11.h>

class Window
{
public:

	static const char* ClassName;//LPCWSTR

	Window(const char *title, unsigned int width, unsigned int height):
		Title(title),
		Width(width),
		Height(height)
	{}

	~Window() {}

	static LRESULT CALLBACK WindowProcedure(HWND window_handle, UINT message_id, WPARAM wparam, LPARAM lparam);
	bool Create();

private:

	bool WindowClass();
	void Resize(HWND window_handle);

private:
	const char* Title;
	unsigned int Width;
	unsigned int Height;
};


#endif // !WINDOW_H

