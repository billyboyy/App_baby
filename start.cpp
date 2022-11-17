#include "Window.h"
#include "Start.h"



void Start::startInit() {

	this->mainWindow = new Window();

	this->mainWindow->WindowInit("oui", 500, 400);
	
}

void Start::Loop(Timer time) {
	SDL_Event e;

	bool quit = false;
	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			//showButton();
			time.TakeHours();
			showTimer(time.getHours(), time.getminutes());
			if (e.type == SDL_QUIT)
				quit = true;
		}

	}
}

void Start::showButton() {

}

void Start::showTimer(int hours, int minutes) {

	SDL_SetRenderDrawColor(this->mainWindow->getRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(this->mainWindow->getRenderer());


	rectangle.x = 50;
	rectangle.y = 150;
	rectangle.h = 300;
	rectangle.w = 300;

	//define color for the renderer
	if (SDL_SetRenderDrawColor(this->mainWindow->getRenderer(), 0, 255, 255, SDL_ALPHA_OPAQUE) != 0) {

	}

	if (SDL_RenderFillRect(this->mainWindow->getRenderer(), &rectangle) != 0) {
		this->mainWindow->SDL_ExitWithError("impossible de dessiner un rectangle");
	}

	//------------------------------------------------------------------------------------------//
	//initialise une font pour mon ecriture 
	 this->test = TTF_OpenFont("font/leadcoat.ttf", 24);

	//crée la couleur bleu en rgb
	SDL_Color bleu = { 0, 255, 255 };

	string timer = to_string(hours) + "h " + to_string(minutes) + "m ";

	//crée un texte sur une surface puis inser la font, texte, couleur
	this->surfacemessage = TTF_RenderText_Solid(this->test, timer.c_str(), bleu);

	//conversion de la surface en texture 
	this->Message = SDL_CreateTextureFromSurface(this->mainWindow->getRenderer(), this->surfacemessage);

	SDL_Rect Message_rect;
	Message_rect.x = 0; // le message afficher sera en haut a gauche
	Message_rect.y = 0;
	Message_rect.h = this->surfacemessage->h;
	Message_rect.w = this->surfacemessage->w;

	SDL_RenderCopy(this->mainWindow->getRenderer(), this->Message, NULL, &Message_rect);

	SDL_FreeSurface(this->surfacemessage);
	SDL_DestroyTexture(this->Message);

	//afficher le texte
	SDL_RenderPresent(this->mainWindow->getRenderer());

}