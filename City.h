#pragma once
#include"Structs.h"
#include"Mvector.h"

class City
{
	int id;
	Mstring name;
	Mvector<Neighbour> neighbours;
	Coords coords;
public:
	City();
	City(int _x, int _y, int _id);
	City(Mstring _name, Coords _coords);
	void addNeighbour(int distance, int city_id);
	void addPlaneAsNeighbour(int distance, int city_id);
	Mstring getName();
	void setName(Mstring _name);
	Mvector<Neighbour> getNeighbours();
	int getNeighbourId(int index);
	Coords getCoords();
	void setCoords(int x, int y);
	int getId();
	int getNeighboursSize();
	Neighbour getNeighbour(int index);
};

