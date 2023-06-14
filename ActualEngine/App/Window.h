
#include <Windows.h>
#pragma once
class Window
{
public:
	//Entry
	Window();

	//Broadcast
	bool broadcast();

	bool running();

	//Events
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();
	virtual void onFocus();
	virtual void onKillFocus();
	virtual void onSize();

	//Release
	~Window();

protected:
	HWND			m_hwnd;
	bool m_running;
};

