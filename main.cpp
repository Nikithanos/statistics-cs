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
		cout << "Testing Set and Get Station Address:";
		data_base.GetStations().back()->SetStationAddress("Odintsovo, Minskoe shosse");
		assert(data_base.GetStations().back()->GetStationAddress() == "Odintsovo, Minskoe shosse"s);
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

void Test_DataBase_Methods() {
	CSDataBase data_base;
	ChargingStation station1(2, "Odintsovo, Minskoe shosse", { 55.538127, 36.402023 }, "E-prom", Project::EZS_64, (Location::Rosneft));
	data_base.AddStation(move(station1));
	ChargingStation station2(1, "Istra", { 55.853895, 36.782164 }, "Parus electro", Project::EZS_64, (Location::Rosneft));
	data_base.AddStation(move(station2));
	ChargingStation station3(3, "Zhukovskiy", { 55.609416, 38.082243 }, "E-prom", Project::EZS_64, (Location::Rosneft));
	data_base.AddStation(move(station3));
	
	{
		cout << "Testing sort by number function: ";
		data_base.SortStationsByNumber();
		/*for (int i = 0; i < data_base.GetStations().size(); ++i) {
			cout << *(data_base.GetStations().at(i)) << endl;
		}*/
		assert(*(data_base.GetStations().at(0)) == station2);
		assert(*(data_base.GetStations().at(1)) == station1);
		assert(*(data_base.GetStations().back()) == station3);
		cout << " passed." << endl;
	}

	{
		cout << "Testing search stations by number: ";
		const ChargingStation foundstation = data_base.FindStationByNumber(3);
		assert(foundstation == station3);
		cout << " passed.";
	}
	/* {
		cout << "Testing search stations by number with wrong number: ";
		const ChargingStation foundstation = data_base.FindStationByNumber(5);
		//assert(foundstation == station3);
		cout << " passed.";
	}*/

}

int main(){
	Test_Add_and_Cout();
	Test_Station_Methods();
	Test_DataBase_Methods();
}