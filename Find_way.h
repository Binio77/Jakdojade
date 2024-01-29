#pragma once
#include"Mqueue.h"
#include"Mpriority_queue.h"
#include"Hash_map.h"
#include"Mstack.h"
class Find_way
{
	Mvector<City> cities;
	Hash_map cities_map;
	int** cities_id_array;
	int** was_there;
	int width, height;
	char** map;
	Mqueue<Coords>was_there_queue;
public:
	Find_way();
	~Find_way();
	void input();
	void findCitiesNames();
	Mstring findCityName(Coords coords);
	bool firstOrLast(Coords coords);
	Mstring findRestOfCityName(Coords coords);
	void addPlanes(int plane_count);
	void createWasThere();
	void wasThereToDefault();
	void createCitiesIdArray();
	void citiesArrayIdDestructor();
	void wasThereDestructor();
	void seekNeighbours();
	void BFS(int seeker_id);
	void checkField(int checked, Coords coords, Mqueue<Coords>* intersections, int seeker_id);
	void mapDestructor();
	void checkPath(int path_count);
	void Dijkstra(Mstring start, Mstring destination, int type);
	void printPath(int start_city_id, Pair destination_pair, Mvector<Pair>distances);
	void CitiesIdArrayDestructor();
};

