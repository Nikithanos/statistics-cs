#pragma once

#include <iostream>

using namespace std::literals::string_literals;

	struct Coordinates {
		Coordinates(double lat, double longt) : latitude(lat), longtitude(longt) {}
		double latitude;
		double longtitude;
	};

	std::ostream& operator<<(std::ostream& out, const Coordinates coordinates);

	bool operator==(Coordinates left, Coordinates right);
	bool operator!=(Coordinates left, Coordinates right);
