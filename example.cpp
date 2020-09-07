#include <iostream>
#include <Windows.h>
#include <string>
#include "header_ex.h"
/*Submit button: x = 290, y = 300
Image: x = 395, y = 444
Background: x = 1400, y = 700
Textbox: x = 285, y = 225*/

int main() 
{
	Sleep(5000);
	std::string combination;
	combination = "0000";
	std::cout << combination << "\n";
	for (int i = 0; i < 4; i++)
	{
		PressKey(str_to_act(combination, i), 0);
	}
	Click(290, 300);
	if (CheckColor(395, 444) != CheckColor(1400, 700)) return 0;
	for (int i = 0; i < 4; i++)
	{
		PressKey(0x08, 0);
	}
	for (int i = 1; i <= 9; i++)
	{
		combination = "000" + std::to_string(i);
		std::cout << combination << "\n";
		for (int i = 0; i < 4; i++)
		{
			PressKey(str_to_act(combination, i), 0);
		}
		Click(290, 300);
		if (CheckColor(395, 444) != CheckColor(1400, 700)) return 0;
		for (int i = 0; i < 4; i++)
		{
			PressKey(0x08, 0);
		}
	}
	for (int i = 10; i <= 99; i++)
	{
		combination = "00" + std::to_string(i);
		std::cout << combination << "\n";
		for (int i = 0; i < 4; i++)
		{
			PressKey(str_to_act(combination, i), 0);
		}
		Click(290, 300);
		if (CheckColor(395, 444) != CheckColor(1400, 700)) return 0;
		for (int i = 0; i < 4; i++)
		{
			PressKey(0x08, 0);
		}
	}
	for (int i = 100; i <= 999; i++)
	{
		combination = "0" + std::to_string(i);
		std::cout << combination << "\n";
		for (int i = 0; i < 4; i++)
		{
			PressKey(str_to_act(combination, i), 0);
		}
		Click(290, 300);
		if (CheckColor(395, 444) != CheckColor(1400, 700)) return 0;
		for (int i = 0; i < 4; i++)
		{
			PressKey(0x08, 0);
		}
	}
	for (int i = 1000; i <= 9880; i++)
	{
		combination = std::to_string(i);
		std::cout << combination << "\n";
		for (int i = 0; i < 4; i++)
		{
			PressKey(str_to_act(combination, i), 0);
		}
		Click(290, 300);
		if (CheckColor(395, 444) != CheckColor(1400, 700)) return 0;
		Click(285, 225);
		for (int i = 0; i < 4; i++)
		{
			PressKey(0x08, 0);
		}
	}
	
}
