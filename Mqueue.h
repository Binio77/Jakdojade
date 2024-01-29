#pragma once
#include"Mlist.h"
template<typename T>
class Mqueue
{
	Mlist<T> list;
	public:
		Mqueue();
		~Mqueue();
		void push(T data);
		void pop();
		T front();
		int size();
		bool empty();
};

template<typename T>
Mqueue<T>::Mqueue()
{
}

template<typename T>
Mqueue<T>::~Mqueue()
{
}

template<typename T>
void Mqueue<T>::push(T data)
{
	list.push_back(data);
}

template<typename T>
void Mqueue<T>::pop()
{
	list.pop_front();
}

template<typename T>
T Mqueue<T>::front()
{
	return list.front();
}

template<typename T>
int Mqueue<T>::size()
{
	return list.Size();
}

template<typename T>
bool Mqueue<T>::empty()
{
	if (list.Size() == 0)
		return true;
	else
		return false;
}