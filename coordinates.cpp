#include "coordinates.h"

std::ostream& operator<<(std::ostream& out, const Coordinates coordinates)
{
	
		out << "Latitude: "s << coordinates.latitude << ", longtitude: "s << coordinates.longtitude;
		return out;
	
}

bool operator==(Coordinates left, Coordinates right)
{
	return ((left.latitude == right.latitude) && (left.longtitude == right.longtitude)) ? true : false;
}

bool operator!=(Coordinates left, Coordinates right)
{
	return !(left == right);
}
