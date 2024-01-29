#pragma once

template<typename T>
struct Node
{
	T data;
	Node* next;
	Node* prev;
};

template<typename T>
class Mlist
{
	Node<T>* head;
	Node<T>* tail;
	int size;
	public:
		Mlist();
		~Mlist();
		void push_back(T data);
		void push_front(T data);
		void pop_back();
		void pop_front();
		T& operator[](int index);
		T front();
		T back();
		int Size();
		void swap(int first, int second);
};

template<typename T>
Mlist<T>::Mlist()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
Mlist<T>::~Mlist()
{
	while (head != nullptr)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void Mlist<T>::push_back(T data)
{
	Node<T>* temp = new Node<T>;
	temp->data = data;
	temp->next = nullptr;
	temp->prev = tail;

	if (tail != nullptr)
		tail->next = temp;

	tail = temp;

	if (head == nullptr)
		head = temp;

	size++;
}

template<typename T>
void Mlist<T>::push_front(T data)
{
	Node<T>* temp = new Node<T>;
	temp->data = data;
	temp->next = head;
	temp->prev = nullptr;

	if (head != nullptr)
		head->prev = temp;

	head = temp;

	if (tail == nullptr)
		tail = temp;

	size++;
}

template<typename T>
void Mlist<T>::pop_back()
{
	if (size == 0)
		return;

	Node<T>* temp = tail;
	tail = tail->prev;

	if (tail != nullptr)
		tail->next = nullptr;

	if (temp == head)
		head = nullptr;

	delete temp;
	size--;
}

template<typename T>
void Mlist<T>::pop_front()
{
	if (size == 0)
		return;

	Node<T>* temp = head;
	head = head->next;

	if (head != nullptr)
		head->prev = nullptr;

	if (temp == tail)
		tail = nullptr;

	delete temp;
	size--;
}

template<typename T>
int Mlist<T>::Size()
{
	return size;
}

template<typename T>
T Mlist<T>::front()
{
	return head->data;
}

template<typename T>
T Mlist<T>::back()
{
	return tail->data;
}

template<typename T>
void Mlist<T>::swap(int first, int second)
{
	if (first == second)
		return;

	
	if (first > second)
	{
		int temp = first;
		first = second;
		second = temp;
	}
	

	Node<T>* firstNode = head;
	Node<T>* secondNode = head;

	for (int i = 0; i < first; i++)
		firstNode = firstNode->next;

	for (int i = 0; i < second; i++)
		secondNode = secondNode->next;

	T temp = firstNode->data;
	firstNode->data = secondNode->data;
	secondNode->data = temp;
}

template<typename T>
T& Mlist<T>::operator[](int index)
{
	Node<T>* temp = head;
	for (int i = 0; i < index; i++)
		temp = temp->next;

	return temp->data;
}