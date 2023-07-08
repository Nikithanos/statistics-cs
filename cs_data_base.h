#pragma once

#include "charging_station.h"

using namespace std::literals::string_literals;


	class CSDataBase {
	private:
		std::vector<ChargingStation*> stations_;
		//std::unordered_map<Day, Statistics> statistics_;
	public:
		void AddStation(ChargingStation&& station);

		const std::vector<ChargingStation*> GetStations() const;
	};
