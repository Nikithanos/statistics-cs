#include <cassert>

#include "cs_data_base.h"

using namespace std;

void Test_Add_and_Cout() {
	CSDataBase data_base;
	ChargingStation station(1, "Istra", { 55.853895, 36.782164 }, "Parus electro", Project::EZS_64, (Location::Rosneft));
	data_base.AddStation(move(station));
	cout << *data_base.GetStations().back();
}

void Test_Station_Methods() {
	CSDataBase data_base;
	ChargingStation station(1, "Istra", { 55.853895, 36.782164 }, "Parus electro", Project::EZS_64, (Location::Rosneft));
	data_base.AddStation(move(station));

	{
		cout << "Testing Set and Get Station Number:";
		data_base.GetStations().back()->SetStationNumber(2);
		assert(data_base.GetStations().back()->GetStationNumber() == 2);
		cout << " passed." << endl;
	}
	{
		cout << "Testing Set and Get Station Adress:";
		data_base.GetStations().back()->SetStationAdress("Odintsovo, Minskoe shosse");
		assert(data_base.GetStations().back()->GetStationAdress() == "Odintsovo, Minskoe shosse"s);
		cout << " passed." << endl;
	}
	{
		cout << "Testing Set and Get Coordinates:";
		Coordinates coordinates(55.538127, 36.402023);
		data_base.GetStations().back()->SetCoordinates(55.538127, 36.402023);
		assert(data_base.GetStations().back()->GetCoordinates() == coordinates);
		cout << " passed." << endl;
	}
	{
		cout << "Testing Set and Get Producer:";
		data_base.GetStations().back()->SetProducer("E-prom");
		assert(data_base.GetStations().back()->GetProducer() == "E-prom");
		cout << " passed." << endl;
	}
}

int main(){
	Test_Add_and_Cout();
	Test_Station_Methods();
}