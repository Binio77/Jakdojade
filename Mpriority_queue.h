#pragma once
#include"Mvector.h"
template<typename T>
class Mpriority_queue
{
	Mvector<T> heap;
	void heapify_up(int index);
	void heapify_down(int index);
	public:
		Mpriority_queue();
		~Mpriority_queue();
		void push(T data);
		void pop();
		T top();
		int size();
		bool empty();
};

template<typename T>
Mpriority_queue<T>::Mpriority_queue()
{
}

template<typename T>
Mpriority_queue<T>::~Mpriority_queue()
{
}

template<typename T>
void Mpriority_queue<T>::push(T data)
{
	heap.push_back(data);
	heapify_up(heap.Size() - 1);
}

template<typename T>
void Mpriority_queue<T>::pop()
{
	heap.swap(0, heap.Size() - 1);
	heap.pop_back();
	heapify_down(0);
}


template<typename T>
T Mpriority_queue<T>::top()
{
	return heap[0];
}

template<typename T>
int Mpriority_queue<T>::size()
{
	return heap.Size();
}

template<typename T>
bool Mpriority_queue<T>::empty()
{
	if (heap.Size() == 0)
		return true;
	else
		return false;
}


template<typename T>
void Mpriority_queue<T>::heapify_up(int index)
{
	if (index == 0)
		return;

	int parent = (index - 1) / 2;
	if (heap[index] < heap[parent])
	{
		heap.swap(index, parent);
		heapify_up(parent);
	}
}

template<typename T>
void Mpriority_queue<T>::heapify_down(int index)
{
	int left_child = 2 * index + 1;
	int right_child = 2 * index + 2;
	int max = index;

	if (left_child < heap.Size() && heap[left_child] < heap[max])
		max = left_child;

	if (right_child < heap.Size() && heap[right_child] < heap[max])
		max = right_child;

	if (max != index)
	{
		heap.swap(index, max);
		heapify_down(max);
	}
}

