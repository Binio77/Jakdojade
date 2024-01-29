#pragma once
#include"Mstring.h"
struct Coords
{
	int x, y;
	Coords() {};
	Coords(int _x, int _y) : x(_x), y(_y) {};
};

struct Neighbour
{
	int distance, city_id;
	Neighbour() {};
	Neighbour(int _distance, int _city_id) : distance(_distance), city_id(_city_id) {};
};

struct Pair
{
	int distance, city_id, last_city_id;
	Pair() {};
	Pair(int _distance, int _city_id, int _last_city_id) : distance(_distance), city_id(_city_id), last_city_id(_last_city_id) {};
	bool operator<(const Pair& rhs) const
	{
		return distance < rhs.distance;
	}
};

Mstring mstringReverse(Mstring str);
