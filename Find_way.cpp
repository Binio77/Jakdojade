#include "Find_way.h"
#define INF 0x3f3f3f3f
#define LONGEST_CITY_NAME 100

Find_way::Find_way()
{
}

Find_way::~Find_way()
{
}


void Find_way::input()
{
    scanf_s("%d %d", &width, &height);
    map = new char* [height];
    for (int i = 0; i < height; i++)
        map[i] = new char[width + 1];

    createCitiesIdArray();
    fgetc(stdin);
    int city_count = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            char c;
            c = fgetc(stdin);
            if (isalnum(c) || c == '#' || c == '*' || c == '.')
            {
                map[i][j] = c;

                if (c == '*')
                {
                    City city(j, i, city_count);
                    cities.push_back(city);
                    cities_id_array[i][j] = city_count;
                    city_count++;
                }

            }
        }
        fgetc(stdin);
        map[i][width] = '\0';
    }

    findCitiesNames();

    Mstring plane_count;
    char c = fgetc(stdin);
    do
    {
        if (isalnum(c))
            plane_count += c;
        c = fgetc(stdin);
    } while (c != '\n');

    addPlanes(plane_count.to_int());
    seekNeighbours();
    mapDestructor();

    int path_count;
    scanf_s("%d", &path_count);
    checkPath(path_count);
}

void Find_way::findCitiesNames()
{
    for (int i = 0; i < cities.Size(); i++)
    {
        cities[i].setName(findCityName(cities[i].getCoords()));
        cities_map.insert(cities[i].getName(), &cities[i]);
    }
}

Mstring Find_way::findCityName(Coords coords)
{
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (coords.x + j >= 0 && coords.x + j < width && coords.y + i >= 0 && coords.y + i < height)
            {
                if (isalnum(map[coords.y + i][coords.x + j]))
                {
                    Coords new_coords(coords.x + j, coords.y + i);
                    if (firstOrLast(new_coords))
                    {
                        return findRestOfCityName(new_coords);
                    }
                }
            }
        }
    }

    return Mstring();
}

bool Find_way::firstOrLast(Coords coords)
{
    if (coords.x > 0 && coords.x < width - 1 && isalnum(map[coords.y][coords.x - 1]) && isalnum(map[coords.y][coords.x + 1]))
        return false;
    else
        return true;
}

Mstring Find_way::findRestOfCityName(Coords coords)
{
    Mstring city_name;
    int i = 0;

    if (coords.x > 0 && isalnum(map[coords.y][coords.x - 1]))
    {
        while (coords.x - i >= 0 && isalnum(map[coords.y][coords.x - i]))
        {
            city_name += map[coords.y][coords.x - i];
            map[coords.y][coords.x - i] = '.';
            i++;
        }

        city_name = mstringReverse(city_name);
    }
    else if (coords.x < width && isalnum(map[coords.y][coords.x + i]))
    {
        while (coords.x + i < width && isalnum(map[coords.y][coords.x + i]))
        {
            city_name += map[coords.y][coords.x + i];
            map[coords.y][coords.x + i] = '.';
            i++;
        }
    }
    return city_name;
}

void Find_way::mapDestructor()
{
    for (int i = 0; i < height; i++)
        delete[] map[i];

    delete[] map;
}

void Find_way::addPlanes(int plane_count)
{
    char c;
    Mstring start(LONGEST_CITY_NAME), destination(LONGEST_CITY_NAME), distance(LONGEST_CITY_NAME);
    int size = 0;
    for (int i = 0; i < plane_count; i++)
    {
        c = fgetc(stdin);
        
        do
        {
            if (isalnum(c))
            {
                start[size] = c;
                size++;
            }

            c = fgetc(stdin);
        } while (c != ' ');

        start.setSize(size);
        start[size] = '\0';
        c = fgetc(stdin);

        size = 0;
        do
        {
            if (isalnum(c))
            {
				destination[size] = c;
				size++;
			}
			c = fgetc(stdin);
		} while (c != ' ');

        destination.setSize(size);
        destination[size] = '\0';

        c = fgetc(stdin);

        size = 0;

        do
        {
            if (isalnum(c))
            {
                distance[size] = c;
                size++;
            }

            c = fgetc(stdin);
        } while (c != '\n');

        distance.setSize(size);
        distance[size] = '\0';
        size = 0;

        cities_map.find(start)->addPlaneAsNeighbour(distance.to_int(), cities_map.find(destination)->getId());
    }
}

void Find_way::checkPath(int path_count)
{
    int type;
    char c;
    Mstring start(LONGEST_CITY_NAME), destination(LONGEST_CITY_NAME);
    int size = 0;
    for (int i = 0; i < path_count; i++)
    {
        fgetc(stdin);
        c = fgetc(stdin);
        do
        {
            if (isalnum(c))
            {
                start[size] = c;
                size++;
            }

            c = fgetc(stdin);
        } while (c != ' ');

        start.setSize(size);
        start[size] = '\0';
        size = 0;

        c = fgetc(stdin);

        do
        {
            if (isalnum(c))
            {
                destination[size] = c;
                size++;
            }    

            c = fgetc(stdin);
        } while (c != ' ');

        destination.setSize(size);
        destination[size] = '\0';
        size = 0;

        scanf_s("%d", &type);

        Dijkstra(start, destination, type);
    }
}

void Find_way::createWasThere()
{
    was_there = new int* [height];
    for (int i = 0; i < height; i++)
    {
        was_there[i] = new int[width];
        for (int j = 0; j < width; j++)
        {
            was_there[i][j] = -1;
        }
    }
}

void Find_way::wasThereToDefault()
{
    while (was_there_queue.size() > 0)
    {
        was_there[was_there_queue.front().y][was_there_queue.front().x] = -1;
        was_there_queue.pop();
    }
}

void Find_way::wasThereDestructor()
{
    for (int i = 0; i < height; i++)
    {
        delete[] was_there[i];
    }

    delete[] was_there;
}

void Find_way::createCitiesIdArray()
{
    cities_id_array = new int* [height];
    for (int i = 0; i < height; i++)
    {
        cities_id_array[i] = new int[width];

        for (int j = 0; j < width; j++)
        {
            cities_id_array[i][j] = -1;
        }
    }
}

void Find_way::CitiesIdArrayDestructor()
{
    for (int i = 0; i < height; i++)
        delete[] cities_id_array[i];

    delete[] cities_id_array;
}

void Find_way::citiesArrayIdDestructor()
{
    for (int i = 0; i < height; i++)
    {
        delete[] cities_id_array[i];
    }
    delete[] cities_id_array;
}

void Find_way::seekNeighbours()
{
    createWasThere();

    for (int i = 0; i < cities.Size(); i++)
    {
        BFS(cities[i].getId());
    }

    wasThereDestructor();
    citiesArrayIdDestructor();
}

void Find_way::BFS(int seeker_id)
{
    wasThereToDefault();
    Mqueue<Coords> intersections;
    int checked_fields = 0;
    was_there[cities[seeker_id].getCoords().y][cities[seeker_id].getCoords().x] = checked_fields++;
    was_there_queue.push(cities[seeker_id].getCoords());
    intersections.push(cities[seeker_id].getCoords());

    Coords current_coords;
    Coords new_coords;

    while (!intersections.empty())
    {
        checked_fields = was_there[intersections.front().y][intersections.front().x];
        current_coords.x = intersections.front().x;
        current_coords.y = intersections.front().y;
        intersections.pop();

        if (current_coords.x > 0 && was_there[current_coords.y][current_coords.x - 1] == -1)
        {
            new_coords.x = current_coords.x - 1;
            new_coords.y = current_coords.y;
            checkField(checked_fields, new_coords, &intersections, seeker_id);
        }

        if (current_coords.x < width - 1 && was_there[current_coords.y][current_coords.x + 1] == -1)
        {
            new_coords.x = current_coords.x + 1;
            new_coords.y = current_coords.y;
            checkField(checked_fields, new_coords, &intersections, seeker_id);
        }

        if (current_coords.y > 0 && was_there[current_coords.y - 1][current_coords.x] == -1)
        {
            new_coords.x = current_coords.x;
            new_coords.y = current_coords.y - 1;
            checkField(checked_fields, new_coords, &intersections, seeker_id);
        }

        if (current_coords.y < height - 1 && was_there[current_coords.y + 1][current_coords.x] == -1)
        {
            new_coords.x = current_coords.x;
            new_coords.y = current_coords.y + 1;
            checkField(checked_fields, new_coords, &intersections, seeker_id);
        }

        checked_fields++;
    }

}

void Find_way::checkField(int checked_fields, Coords coords, Mqueue<Coords>* intersections, int seeker_id)
{
    if (map[coords.y][coords.x] == '#')
    {
        intersections->push(coords);
        was_there[coords.y][coords.x] = checked_fields + 1;
        was_there_queue.push(coords);
    }
    else if (map[coords.y][coords.x] == '*')
    {
        int neighbour_id = cities_id_array[coords.y][coords.x];
        cities[seeker_id].addNeighbour(checked_fields + 1, neighbour_id);
        was_there[coords.y][coords.x] = checked_fields + 1;
        was_there_queue.push(coords);
    }
}

void Find_way::Dijkstra(Mstring start, Mstring destination, int type)
{
    Mpriority_queue<Pair> pq;
    City start_city = *cities_map.find(start);
    int destination_city_id = cities_map.find(destination)->getId();
    Mvector<Pair> distances(cities.Size(), Pair{ INF, -1, -1 });
    distances[start_city.getId()].distance = 0;
    pq.push(Pair{ 0, start_city.getId(), -1 });

    while (!pq.empty())
    {
        Pair current_pair = pq.top();
        pq.pop();

        if (current_pair.city_id == destination_city_id)
        {
            std::cout << distances[current_pair.city_id].distance << " ";
            if (type == 1)
            {
                printPath(start_city.getId(), current_pair, distances);
            }

            std::cout << std::endl;
            return;
        }

        for (int i = 0; i < cities[current_pair.city_id].getNeighboursSize(); i++)
        {
            int neighbour_id = cities[current_pair.city_id].getNeighbour(i).city_id;
            int neighbour_distance = cities[current_pair.city_id].getNeighbour(i).distance;
            if (distances[neighbour_id].distance > distances[current_pair.city_id].distance + neighbour_distance)
            {
                distances[neighbour_id].distance = distances[current_pair.city_id].distance + neighbour_distance;
                distances[neighbour_id].last_city_id = current_pair.city_id;
                pq.push(Pair{ distances[neighbour_id].distance, neighbour_id, current_pair.city_id });
            }
        }
    }
}

void Find_way::printPath(int start_city_id, Pair destination_pair, Mvector<Pair>distances)
{
    if (start_city_id == destination_pair.city_id)
    {
        return;
    }

    Mstack<int> path;
    int current_city_id = destination_pair.last_city_id;
    while (current_city_id != start_city_id)
    {
        path.push(current_city_id);
        current_city_id = distances[current_city_id].last_city_id;
    }

    while (!path.empty())
    {
        std::cout << cities[path.top()].getName() << " ";
        path.pop();
    }
}