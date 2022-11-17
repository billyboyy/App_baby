#pragma once
#include "Window.h"
#include "Timer.h"
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>
#include <cstring>
#include <Windows.h>

class Start {

public:

	void startInit();
	void showButton();
	void Loop(Timer);
	void showTimer(int, int);

protected:
	bool quit;
	Window* mainWindow;
	SDL_Renderer* renderer;
	SDL_Rect rectangle;
	//insersion de texte 
	SDL_Surface* surfacemessage;
	SDL_Texture* Message;
	TTF_Font* test;

};