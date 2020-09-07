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
void PressKey(int name, int duration)
{
	INPUT ipkb;
	ipkb.ki.wVk = name;
	ipkb.type = INPUT_KEYBOARD;
	ipkb.ki.wScan = 0; //hardware scan code for the key
	ipkb.ki.time = 0; //time stamp
	ipkb.ki.dwExtraInfo = 0;
	ipkb.ki.dwFlags = 0; //key pressed
	SendInput(1, &ipkb, sizeof(INPUT));
	Sleep(duration);
	ipkb.ki.dwFlags = KEYEVENTF_KEYUP; //key released
	SendInput(1, &ipkb, sizeof(INPUT));
}

int CheckColor(int x, int y)
{
	HDC dc = GetDC(NULL);
	COLORREF color = GetPixel(dc, x, y);
	int red = GetRValue(color);
	int green = GetGValue(color);
	int blue = GetBValue(color);
	return red * green * blue;
	ReleaseDC(NULL, dc);
}

int str_to_act(std::string str, int i)
{
	char elem = str[i];
	if (elem == '0') return 0x30;
	if (elem == '1') return 0x31;
	if (elem == '2') return 0x32;
	if (elem == '3') return 0x33;
	if (elem == '4') return 0x34;
	if (elem == '5') return 0x35;
	if (elem == '6') return 0x36;
	if (elem == '7') return 0x37;
	if (elem == '8') return 0x38;
	if (elem == '9') return 0x39;

}
