#include "Window.h"
#include "Timer.h"
#include "start.h"

#include <stdio.h>
#include <iostream>


int main(int argc, char* args[])
{
	Timer time;
	
	Start start;

	start.startInit();
	start.Loop(time);

	return 0;
}
