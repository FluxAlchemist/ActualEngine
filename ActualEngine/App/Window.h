
#include <Windows.h>
#pragma once
class Window
{
public:
	// Entry
	Window();

	bool running();

    RECT getClientWindowRect();
	RECT getScreenSize();

	// Events
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();
	virtual void onFocus();
	virtual void onKillFocus();
	virtual void onSize();

	// Release
	~Window();

	// Broadcast
	bool broadcast();

protected:
	HWND m_hwnd;
	bool m_running;
};

