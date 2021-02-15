#pragma once
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <algorithm>

namespace Colors
{
	enum class Color
	{
		RED,GREEN,BLUE
	};
	inline std::string to_string(const Color color)
	{
		switch (color)
		{
		case Color::RED:
			return "RED";
		case Color::GREEN:
			return "GREEN";
		default:
			return "BLUE";
		}
	}
	inline Color to_enum(const std::string& enum_expression)
	{
		if(enum_expression == Colors::to_string(Colors::Color::RED))
		{
			return Colors::Color::RED;
		}
		if(enum_expression == Colors::to_string(Colors::Color::GREEN))
		{
			return Colors::Color::GREEN;
		}
		return Colors::Color::BLUE;
	}
	
	
}