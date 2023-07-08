#include "charging_station.h"


	const unsigned int ChargingStation::GetStationNumber() const
	{
		return number_;
	}

	const std::string ChargingStation::GetStationAdress() const
	{
		return adress_;
	}

	const Coordinates ChargingStation::GetCoordinates() const
	{
		return coordinates_;
	}

	const std::string ChargingStation::GetProducer() const
	{
		return producer_;
	}

	const std::string ChargingStation::GetProject() const
	{
		switch (project_) {
		case (Project::EZS_64):
			return "64 charging stations in 2022"s;

		case (Project::M_11):
			return "13 charging stations in 2021"s;

		case (Project::ENSTO):
			return "ENSTO stations"s;

		default:
			return "";
		}
	}

	const CharginStationPlace ChargingStation::GetLocation() const
	{
		return place_;
	}

	void ChargingStation::SetStationNumber(unsigned int new_number)
	{
		
			(new_number > 0) ? number_ = new_number : throw std::logic_error("Station's number can not be negative!");
		
	}

	void ChargingStation::SetStationAdress(std::string_view new_adress)
	{
		adress_ = new_adress;
	}

	void ChargingStation::SetCoordinates(double latitude, double longtitude)
	{
		coordinates_.latitude = latitude;
		coordinates_.longtitude = longtitude;
	}

	void ChargingStation::SetProducer(std::string_view new_producer)
	{
		producer_ = new_producer;
	}

	void ChargingStation::SetProject(std::string_view project)
	{
		if (project == "64") {
			project_ = Project::EZS_64;
		}
		else if (project == "M-11") {
			project_ = Project::M_11;
		}
		else if (project == "Ensto") {
			project_ = Project::ENSTO;
		}
	}

	std::ostream& operator<<(std::ostream& out, const ChargingStation& station) {
		out << "Station number: "s << station.GetStationNumber() << ", adress: "s << station.GetStationAdress() << ", coordinates: latitude - "s << station.GetCoordinates().latitude
			<< ", longtitude - "s << station.GetCoordinates().longtitude << ", producer: "s << station.GetProducer() << ", project:"s << station.GetProject() << ", "s << station.GetLocation() << std::endl;
		return out;
	}

