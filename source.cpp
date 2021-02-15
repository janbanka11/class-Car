/*
 *	ZAD 1
 *	Klasa Car: model, speed, year, color ( enum )
 *	Pobierz dane z pliku
 *	a. pokaz wszystkie samochody
 *	b. znajdz n samochodow o najwiekszej szybkosc - n podajesz jako argument - uwazaj zeby n nie mialo wartosci wiekszej niz rozmiar vectora
 *	c. do nowego vectora zwroc tylko te samochody, ktore maja kategorie taka jak podana jako argument
 *	d. do nowego vectora zwroc ta kategorie, ktore srednia szybkosc samochodow okazala sie najwieksza
 *	e. umiesc rozwiazane na utworzonym przez ciebi git repo - podpunkty a,b zrob na branchu b1 a pozsotale na branchu b2
 *
 */
#include "car.h"

int main()
{
	auto cars = Car::get_data_from_txt("data.txt");
	auto result = Car::find_n_cars_with_highest_speed(20, cars);
	Car::show_all_cars(result);
	return 0;
}