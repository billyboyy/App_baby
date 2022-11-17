#pragma once
#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

class Timer
{
protected:
	int hours,
		minutes;
	int end = 0;
public:
	Timer();
	void Clock();
	int getHours();
	int getminutes();
	void TakeHours();

private:

};