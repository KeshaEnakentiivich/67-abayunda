// prikolchik.cpp : Определяет точку входа для приложения.
//
#pragma comment(lib, "Winmm.lib")
#include "framework.h"
#include "prikolchik.h"
#include <MMSystem.h>
DWORD WINAPI main(PVOID pv)
{
	HDC hdc = GetDC(NULL);
	LPCWSTR text1 = L"Кофе помогает от Альцгеймера";
	PlaySound(L"POSHALKA.wav", 0, SND_LOOP);
	while (true) {
		SetTextColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
		SetBkColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
		TextOutW(hdc, rand() % GetSystemMetrics(0), rand() % GetSystemMetrics(1), text1, wcslen(text1));
		Sleep(50);
	}
	ReleaseDC(NULL, hdc);
}
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	CreateThread(0, 0, main, 0, 0, 0);
	Sleep(-1);
}

