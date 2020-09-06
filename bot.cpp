#include <iostream>
#include <Windows.h>

/*This program provides a list of handy functions to perform certain actions 
involving pressing keys, mouse buttons, etc.
Full documentation of functions from Windows.h library can be found here:
https://docs.microsoft.com/en-us/windows/win32/api/winuser/ */

void CurrentCursorPos() //Chcecks current coordinates of the cursor
{
	POINT p;
	if (GetCursorPos(&p)) 
	{
		std::cout << "x = " << p.x << ", y = " << p.y << "\n";
	}
}

void Click(int x, int y) //clicks mouse left button at given coordinates
{
	SetCursorPos(x, y); //set cursor on these coordinates

	INPUT ipmouse; //create an object of class INPUT (whole documentation available at)
	ipmouse.type = INPUT_MOUSE;
	ipmouse.mi.dx = 0;
	ipmouse.mi.dy = 0;
	ipmouse.mi.time = 0;
	ipmouse.mi.dwExtraInfo = 0;
	ipmouse.mi.mouseData = 0; //specified only if dwFlags contains MOUSEEVENTF_WHEEL
	ipmouse.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &ipmouse, sizeof(INPUT));
	//still pressed
	ipmouse.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &ipmouse, sizeof(INPUT));
}
void PressKey(char name, int duration)
{
	INPUT ipkb;
	//specify Virtual Key code for given character (only two shown as for an example)
	if (name == 'a') ipkb.ki.wVk = 0x41;
	else if (name == ' ') ipkb.ki.wVk = VK_SPACE;
	else ipkb.ki.wVk = VK_ESCAPE;
	
	ipkb.type = INPUT_KEYBOARD;
	ipkb.ki.wScan = 0; //hardware scan code for the key
	ipkb.ki.time = 0; //time stamp
	ipkb.ki.dwExtraInfo = 0;
	//ipkb.ki.wVk = 0x41;
	ipkb.ki.dwFlags = 0; //key pressed
	SendInput(1, &ipkb, sizeof(INPUT));
	//still pressed!
	Sleep(duration);
	ipkb.ki.dwFlags = KEYEVENTF_KEYUP; //key released
	SendInput(1, &ipkb, sizeof(INPUT));
}

void ChceckColor(int x, int y)
{
	HDC dc = GetDC(NULL);
	COLORREF color = GetPixel(dc, x, y);
	std::cout << "color at x = " << x << " and y = " << y << " is:\n";
	int red = GetRValue(color);
	std::cout << "R " << red << "\n";
	int green = GetGValue(color);
	std::cout << "G " << green << "\n";
	int blue = GetBValue(color);
	std::cout << "B " << blue << "\n";
	std::cout << color << "\n";
	ReleaseDC(NULL, dc);
}

int main() //example of usage: bot clicking ten times at a given point on the screen
{
	Sleep(5000);
	CurrentCursorPos();
	for (int i = 0; i < 10; i++)
	{
		Click(1683, 1011); //position relative to the screen, may be different in your case
		Sleep(1000);
	}

}
