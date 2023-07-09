#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <functional>

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
		unsigned short number_;
		std::string address_;
		Coordinates coordinates_;
		std::string producer_;
		Project project_;
		ChargingStationPlace place_;

	public:
		ChargingStation() = default;
		ChargingStation(unsigned short number, std::string address, Coordinates coordinates, std::string producer, Project project, ChargingStationPlace place) :
			number_(number), address_(address), coordinates_(coordinates), producer_(producer), project_(project), place_(place) {}
		~ChargingStation() = default;

		const unsigned short GetStationNumber() const;
		const std::string GetStationAddress() const;
		const Coordinates GetCoordinates() const;
		const std::string GetProducer() const;
		const std::string GetProject() const;
		const ChargingStationPlace GetLocation() const;

		void SetStationNumber(unsigned short new_number);
		void SetStationAddress(std::string_view new_address);
		void SetCoordinates(double latitude, double longtitude);
		void SetProducer(std::string_view new_producer);
		void SetProject(std::string_view project);
	};

	std::ostream& operator<<(std::ostream& out, const ChargingStation& station);

	bool operator==(const ChargingStation& left, const ChargingStation& right);

	bool operator<(const ChargingStation& left, const ChargingStation& right);

