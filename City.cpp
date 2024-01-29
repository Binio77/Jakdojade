#include "City.h"

City::City()
{
}

City::City(int _x, int _y, int _id)
{
	coords.x = _x;
	coords.y = _y;
	id = _id;
}

City::City(Mstring _name, Coords _coords)
{
	name = _name;
	coords = _coords;
}

void City::addNeighbour(int distance, int city_id)
{
	for (int i = 0; i < neighbours.Size(); i++)
	{
		if (city_id == neighbours[i].city_id && neighbours[i].distance > distance)
		{
			neighbours[i].distance = distance;
			return;
		}
	}

	Neighbour neighbour(distance, city_id);
	neighbours.push_back(neighbour);
}

void City::addPlaneAsNeighbour(int distance, int city_id)
{
	Neighbour neighbour(distance, city_id);
	neighbours.push_back(neighbour);
}

Mstring City::getName()
{
	return name;
}

void City::setName(Mstring _name)
{
	name = _name;
}

Mvector<Neighbour> City::getNeighbours()
{
	return neighbours;
}

int City::getNeighbourId(int index)
{
	return neighbours[index].city_id;
}

Coords City::getCoords()
{
	return coords;
}

void City::setCoords(int x, int y)
{
	coords.x = x;
	coords.y = y;
}

int City::getId()
{
	return id;
}

int City::getNeighboursSize()
{
	return neighbours.Size();
}

Neighbour City::getNeighbour(int index)
{
	return neighbours[index];
}