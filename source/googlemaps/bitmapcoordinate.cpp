#include <cmath>

#include "coordinate.h"
#include "bitmapcoordinate.h"
#include "tile.h"

namespace googlemaps
{

BitmapCoordinate::BitmapCoordinate(int x, int y, int zoom):
	QPoint(x, y), zoom(zoom)
{

}

BitmapCoordinate::BitmapCoordinate(const googlemaps::Coordinate &coord, int zoom):
	zoom(zoom)
{
	double e = sin(coord.latitude * (M_PI / 180.0));

	rx() = ceil(origin() + coord.longitude * pixelsPerDegree());
	ry() = ceil(origin() + 0.5 * -log((1 + e) / (1 - e)) * pixelsPerRadian());
}

double BitmapCoordinate::pixelsPerDegree() const
{
	return (Tile::SIZE << zoom) / 360.0;
}

double BitmapCoordinate::pixelsPerRadian() const
{
	return (Tile::SIZE << zoom) / (2 * M_PI);
}

int BitmapCoordinate::origin() const
{
	return (Tile::SIZE / 2) << zoom;
}

}
