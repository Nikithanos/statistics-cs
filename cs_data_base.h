#pragma once

#include "charging_station.h"

#include <unordered_map>
#include <algorithm>


using namespace std::literals::string_literals;


	class CSDataBase {
	private:
		std::vector<ChargingStation*> stations_;
		std::unordered_map<size_t, ChargingStation> stations_for_search_;
	public:
		void AddStation(ChargingStation&& station);

		const std::vector<ChargingStation*> GetStations() const;

		const ChargingStation FindStationByNumber(int station_number) const;

		void SortStationsByNumber();
	};
