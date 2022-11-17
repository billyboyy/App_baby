/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/


/*
	SDL_RENDERER_SOFTWARE
	SDL_RENDERER_ACCELERATED
	SDL_RENDERER_PRESENTVSYNC
	SDL_RENDERER_TARGETTEXTURE
*/

//Using SDL and standard IO
#include "Window.h"
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>


//Screen dimension constants

Window::Window()
{
	this->window = NULL;
	this->screenSurface = NULL;
	this->renderer = NULL;
}

Window::~Window() {
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	//Quit SDL subsystems
	SDL_Quit();
}

int Window::WindowInit(const char* name, int heigh, int width) {



	//Initialize SDL

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_ExitWithError("La fenetre n a pas pu s initialiser  !");
	}
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	else
	{
		//create window and renderer
		if (SDL_CreateWindowAndRenderer(width, heigh, 0, &this->window, &this->renderer) != 0) {
			SDL_ExitWithError("Creation de la fenetre et du rendu echouee");
		}
		//else
		//{
		//	//Get window surface
		//	this->screenSurface = SDL_GetWindowSurface(this->window);

		//	//Fill the surface white
		//	SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB(this->screenSurface->format, 0, 0xFF, 0xFF));

		//	//Update the surface
		//	SDL_UpdateWindowSurface(this->window);

		//}

		//define color for the renderer



		//refresh the renderer.
		SDL_RenderPresent(this->renderer);


		//Hack to get window to stay up

		/*this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
		if (this->renderer == NULL)
		{
			SDL_ExitWithError("Creation du rendu echouee");
		}*/
		
	}
	return EXIT_SUCCESS;
}


void Window::SDL_CleanRenderer() {
	if (SDL_RenderClear(this->renderer) != 0) {
		SDL_ExitWithError("clear du renderer");
	};

}

void Window::SDL_ExitWithError(const char* message) {
	SDL_Log("Erreur : %s > %s\n", message, SDL_GetError());
	TTF_Quit();
	SDL_Quit();
	exit(EXIT_FAILURE);
}

SDL_Renderer* Window::getRenderer() {
	return this->renderer;
}