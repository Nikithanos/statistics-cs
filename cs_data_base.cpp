#include "cs_data_base.h"

	void CSDataBase::AddStation(ChargingStation&& station) {
		stations_.push_back(std::move(&station));
	}

	const std::vector<ChargingStation*> CSDataBase::GetStations() const {
		return stations_;
	}

	const ChargingStation CSDataBase::FindStationByNumber(int station_number) const {
		for (auto station = stations_.begin(); station != stations_.end(); ++station) {
			if ((*station)->GetStationNumber() == station_number) {
				return *(*station);
			}
		}
	}

	void CSDataBase::SortStationsByNumber() {
		std::sort(stations_.begin(), stations_.end(), [](const ChargingStation& left, const ChargingStation& right) { return left < right;});
	}

