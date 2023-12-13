#define _WIN32_WINNT 0x0A00

#include <Windows.h>
#include<iostream> 

using namespace std;

int main()
{
	HWND hwnd = GetConsoleWindow();
	cout << " ¬ведите х: ";
	LPPOINT pPnt;
	pPnt = static_cast<LPPOINT>(malloc(sizeof(*pPnt)));


	LPRECT rctScr;
	rctScr = static_cast<LPRECT>(malloc(sizeof(*rctScr)));
	GetClientRect(GetDesktopWindow(), rctScr);

	LPRECT rct;
	rct = static_cast<LPRECT>(malloc(sizeof(*rct)));
	GetClientRect(hwnd, rct);

	while (GetKeyState(VK_ESCAPE) >= 0) {
		system("cls");

		cout << " Global size: " << rctScr->right << " x " << rctScr->bottom;
		GetCursorPos(pPnt);
		cout << "\n Global cursor pos: " << pPnt->x << " x " << pPnt->y;


		cout << "\n\n Local size: " << rct->right << " x " << rct->bottom;
		ScreenToClient(hwnd, pPnt);
		cout << "\n Local cursor pos: " << pPnt->x << " x " << pPnt->y;

		Sleep(100);
	}
	return 0;
}