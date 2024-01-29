#pragma once
#include"Mvector.h"
#include"City.h"
#define MAX_GRAPH_SIZE 10001
#define HASH_MODIFIER 97

struct Hash_map_Pair
{
	Mstring first;
	City* second;

};

int hashMethod(Mstring key);

class Hash_map
{
	Mvector<Hash_map_Pair> hash_array[MAX_GRAPH_SIZE];
	public:
		Hash_map();
		~Hash_map();
		void insert(Mstring key, City* value);
		City* find(Mstring key);
};

