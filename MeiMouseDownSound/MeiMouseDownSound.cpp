// MeiMouseDownSound.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

bool running = true;
bool mouseDown = false;
int doOnceCount = 1;

void CheckQuit()
{
	if ((GetKeyState(VK_ESCAPE) & 0x1B) != 0)
	{
		//running = false;
	}
}

void CheckMouseDown()
{
	if ((GetKeyState(VK_LBUTTON) < 0))
	{
		cout << "Mouse is down\n";
		mouseDown = true;
		//Sleep(500);
	}
	else
	{
		Sleep(1);
		//cout << "Mouse is up";
		mouseDown = false;
		//Sleep(500);
	}
}

void PlayASound()
{
	PlaySound(TEXT("Mei.wav"), NULL, SND_LOOP | SND_ASYNC);
	return;
}


void CheckShouldPlay()
{
	if (mouseDown && doOnceCount < 1)
	{
		Sleep(200);
		doOnceCount = 1;
		cout << "PLAYING SOUND\n";
		PlayASound();
		//cin.get();
	}
	else if (!mouseDown)
	{
		//Sleep(5000);
		cout << "STOPPING SOUND\n";
		doOnceCount = 0;
		PlaySound(NULL, NULL, 0);
		//cin.get();
	}
}

int main()
{
	while (running)
	{
		CheckQuit();
		CheckMouseDown();
		CheckShouldPlay();
	}
	return 0;
}

