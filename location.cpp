#include "location.h"


const std::string ChargingStationPlace::GetLocation() const {
	switch (location_) {
	case (Location::Lukoil):
		return "Lukoil"s;

	case (Location::Rosneft):
		return "Rosneft"s;

	case (Location::Tatneft):
		return "Tatneft"s;

	case (Location::Dubna):
		return "Dubna"s;

	case (Location::Sibur_lukoil):
		return "Sibur"s;
	
	case (Location::Municipal):
		return "Municipal land"s;
	}
}

void ChargingStationPlace::SetLocation(std::string location) {
	if ((location == "Lukoil"s) || (location == "lukoil"s)) {
		location_ = Location::Lukoil;
	}
	else if ((location == "Rosneft"s) || (location == "rosneft"s)) {
		location_ = Location::Rosneft;
	}
	else if ((location == "Tatneft"s) || (location == "tatneft"s)) {
		location_ = Location::Tatneft;
	}
	else if ((location == "Sibur"s) || (location == "sibur"s)) {
		location_ = Location::Sibur_lukoil;
	}
	else if ((location == "Dubna"s) || (location == "dubna"s)) {
		location_ = Location::Dubna;
	}
	else {
		location_ = Location::Municipal;
	}
}

void ChargingStationPlace::SetLocationNumber(std::string location_number) {
	location_number_ = location_number;
}

void ChargingStationPlace::SetContacts(std::string name, std::string number) {
	contacts_ = std::make_pair( name, number );
}


const std::string ChargingStationPlace::GetLocationNumber() const {
	return location_number_;
}

const std::pair<std::string, std::string> ChargingStationPlace::GetContacts() const {
	return contacts_;
}

std::ostream& operator<<(std::ostream& out, const ChargingStationPlace& place) {
	out << "Where: "s << place.GetLocation(); // ", station number:" << place.GetLocationNumber() << ", contacts: " << place.GetContacts();
	return out;
}

bool operator==(const ChargingStationPlace& left, const ChargingStationPlace& right) {
	return (left.GetLocationNumber() == right.GetLocationNumber() && left.GetLocation() == right.GetLocation()) ? true : false;
}