#pragma once
#include "headers.h"

class Car
{
private:
	std::string model;
	double speed;
	int year;
	Colors::Color color;
	static std::vector<Car> to_vect_of_no_pointers(const std::vector<std::unique_ptr<Car>>& cars);
	static std::vector<std::unique_ptr<Car>> to_vect_of_uptr(const std::vector<Car>& cars);
public:
	Car(const std::string& model = "", const double speed = 0, const int year = 1900
		, Colors::Color color = Colors::Color::RED) : model(model), speed(speed), year(year), color(color){}
	
	static std::vector<std::unique_ptr<Car>> get_data_from_txt(const std::string& filename);

	static std::vector<std::unique_ptr<Car>> find_n_cars_with_highest_speed(const int n, std::vector<std::unique_ptr<Car>>& cars);
	bool operator<(const Car& car) const;
	friend std::ostream& operator<<(std::ostream& out, const Car& cars);
	static void show_all_cars(const std::vector<std::unique_ptr<Car>>& cars);
};

