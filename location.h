#pragma once

#include <string>
#include <iostream>

using namespace std::literals::string_literals;

enum class Location {
	Lukoil,
	Sibur_lukoil,
	Rosneft,
	Tatneft,
	Dubna,
	Municipal,
};

class CharginStationPlace {
private:
	Location location_;
	std::string location_number_;
	std::pair<std::string, std::string> contacts_;

public:
	CharginStationPlace(Location location, std::string location_number, std::pair<std::string, std::string> contacts) : location_(location), location_number_(location_number), contacts_(contacts) {}
	CharginStationPlace(Location location, std::string location_number) : location_(location), location_number_(location_number) {}
	CharginStationPlace(Location location) : location_(location) {}

	void SetLocation(std::string location);
	void SetLocationNumber(std::string location_number);
	void SetContacts(std::string name, std::string number);

	const std::string GetLocation() const;
	const std::string GetLocationNumber() const;
	const std::pair<std::string, std::string> GetContacts() const;
};

std::ostream& operator<<(std::ostream& out, const CharginStationPlace& place);