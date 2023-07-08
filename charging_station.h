#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <iostream>
#include <stdexcept>

#include "coordinates.h"
#include "location.h"

using namespace std::literals::string_literals;


	enum class Project {
		EZS_64,
		M_11,
		ENSTO,
	};

	class ChargingStation {
	private:
		unsigned int number_;
		std::string adress_;
		Coordinates coordinates_;
		std::string producer_;
		Project project_;
		CharginStationPlace place_;

	public:
		ChargingStation(unsigned int number, std::string adress, Coordinates coordinates, std::string producer, Project project, CharginStationPlace place) :
			number_(number), adress_(adress), coordinates_(coordinates), producer_(producer), project_(project), place_(place) {}

		const unsigned int GetStationNumber() const;
		const std::string GetStationAdress() const;
		const Coordinates GetCoordinates() const;
		const std::string GetProducer() const;
		const std::string GetProject() const;
		const CharginStationPlace GetLocation() const;

		void SetStationNumber(unsigned int new_number);
		void SetStationAdress(std::string_view new_adress);
		void SetCoordinates(double latitude, double longtitude);
		void SetProducer(std::string_view new_producer);
		void SetProject(std::string_view project);
	};

	std::ostream& operator<<(std::ostream& out, const ChargingStation& station);

