#pragma once
#include"Mlist.h"
template<typename T>
class Mstack
{
	Mlist<T> list;
	public:
		Mstack();
		~Mstack();
		void push(T data);
		void pop();
		T top();
		int size();
		bool empty();
};

template<typename T>
Mstack<T>::Mstack()
{
}

template<typename T>
Mstack<T>::~Mstack()
{
}

template<typename T>
void Mstack<T>::push(T data)
{
	list.push_back(data);
}

template<typename T>
void Mstack<T>::pop()
{
	list.pop_back();
}

template<typename T>
T Mstack<T>::top()
{
	return list.back();
}

template<typename T>
int Mstack<T>::size()
{
	return list.Size();
}

template<typename T>
bool Mstack<T>::empty()
{
	if (list.Size() == 0)
		return true;
	else
		return false;
}
