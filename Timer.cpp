#pragma warning(disable : 4996)
#include "Timer.h"


Timer::Timer() {
	/*while (end != 1) {
		system("CLS");
		TakeHours();
		Clock();
		Sleep(1000);
	}*/
}

void Timer::Clock() {
	/*cout << setfill(' ') << setw(55) << "           TIMER          \n";
	cout << setfill(' ') << setw(55) << "--------------------------\n";
	cout << setfill(' ') << setw(29);
	cout << "| " << setfill('0') << setw(2) << hours << " hrs | ";
	cout << setfill('0') << setw(2) << minutes << " min | ";
	cout << setfill('0') << setw(2) << seconds << " sec |\n";
	cout << setfill(' ') << setw(55) << "--------------------------\n";
	*/
}

void Timer::TakeHours() {
	// date / heure actuelle basée sur le système actuel
	time_t actuel = time(0);
	tm* ltm = localtime(&actuel);
	// prend l'heure en temps réel
	hours = ltm->tm_hour;
	minutes = ltm->tm_min;
}

int Timer::getHours() {
	return this->hours;

}

int Timer::getminutes() {
	return this->minutes;
}
