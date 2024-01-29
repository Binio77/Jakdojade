#include "Hash_map.h"

int hashMethod(Mstring key)
{
	int value = 0;
	for (int i = 0; i < key.Size(); i++)
	{
		value += key[i] * i;
	}
	value *= HASH_MODIFIER;
	return value % MAX_GRAPH_SIZE;
}

Hash_map::Hash_map()
{
}

Hash_map::~Hash_map()
{

}

void Hash_map::insert(Mstring key, City* value)
{
	int index = hashMethod(key);
	for (int i = 0; i < hash_array[index].Size(); i++)
	{
		if (hash_array[index][i].first == key)
		{
			hash_array[index][i].second = value;
			return;
		}
	}
	Hash_map_Pair new_pair;
	new_pair.first = key;
	new_pair.second = value;
	hash_array[index].push_back(new_pair);
}

City* Hash_map::find(Mstring key)
{
	int index = hashMethod(key);
	for (int i = 0; i < hash_array[index].Size(); i++)
	{
		if (hash_array[index][i].first == key)
		{
			return hash_array[index][i].second;
		}
	}
	return nullptr;
}
