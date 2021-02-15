#include "car.h"

std::vector<Car> Car::to_vect_of_no_pointers(const std::vector<std::unique_ptr<Car>>& cars)
{
	std::vector<Car> cars_result;
	for (int i = 0; i < cars.size(); ++i)
	{
		cars_result.emplace_back(*cars[i]);
	}
	return cars_result;
}

std::vector<std::unique_ptr<Car>> Car::to_vect_of_uptr(const std::vector<Car>& cars)
{
	std::vector<std::unique_ptr<Car>> cars_result;
	for (int i = 0; i < cars.size(); ++i)
	{
		cars_result.emplace_back(std::make_unique<Car>(cars[i]));
	}
	return cars_result;
}

std::vector<std::unique_ptr<Car>> Car::get_data_from_txt(const std::string& filename)
{
	std::ifstream file;
	file.open(filename);

	std::string model;
	double speed;
	int year;
	std::string color;
	std::string separator;
	std::vector<std::unique_ptr<Car>> data;
	
	if(file.is_open())
	{
		while(!file.eof())
		{
			std::getline(file, model);
			file >> speed; file.get();
			file >> year; file.get();
			std::getline(file, color);
			std::getline(file, separator);
			data.emplace_back(std::make_unique<Car>(model, speed, year, Colors::to_enum(color)));
		}
		file.close();
	}
	else
	{
		std::cout << "Couldn't open file " << filename << std::endl;
	}
	return data;
}

std::vector<std::unique_ptr<Car>> Car::find_n_cars_with_highest_speed(const int n, std::vector<std::unique_ptr<Car>>& cars)
{
	if (n > cars.size()) throw std::exception("n is higher than size of cars vector");
	
	std::vector<Car> no_pointer_cars = to_vect_of_no_pointers(cars);
	std::sort(no_pointer_cars.begin(), no_pointer_cars.end());
	std::vector<Car> car_results;
	for(int i = no_pointer_cars.size() - 1; i >= n; i--)
	{
		car_results.emplace_back(no_pointer_cars[i]);
	}
	
	return to_vect_of_uptr(car_results);
}

bool Car::operator<(const Car& car) const
{
	return this->speed < car.speed;
}

void Car::show_all_cars(const std::vector<std::unique_ptr<Car>>& cars)
{
	for (int i = 0; i < cars.size(); ++i)
	{
		std::cout << *cars[i];
	}
}

std::ostream& operator<<(std::ostream& out, const Car& cars)
{
	return out << cars.model << " " << cars.speed << " " << cars.year << " " << Colors::to_string(cars.color) << " " << std::endl;
}
