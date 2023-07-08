#include "cs_data_base.h"

	void CSDataBase::AddStation(ChargingStation&& station) {
		stations_.push_back(std::move(&station));
	}

	const std::vector<ChargingStation*> CSDataBase::GetStations() const
	{
		return stations_;
	}

