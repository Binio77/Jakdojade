#pragma once
#define RESIZE_VALUE 2

template <typename T>
class Mvector
{
	private:
	T* data;
	int size;
	int capacity;
	void resize();
	public:
		Mvector();
		Mvector(int _size);
		Mvector(int _size, T value);
		Mvector(const Mvector& orig);
		Mvector& operator=(const Mvector& right);
		T& operator[](int i);
		void push_back(T& element);
		void pop_back();
		int Size();
		~Mvector();
		void swap(int first, int second);
};

template<typename T>
inline Mvector<T>::Mvector()
{
	size = 0;
	capacity = 0;
	data = nullptr;
}

template<typename T>
inline Mvector<T>::Mvector(int _size)
{
	size = _size;
	capacity = _size;
	data = new T[size];
}

template<typename T>
inline Mvector<T>::Mvector(int _size, T value)
{
	size = _size;
	capacity = _size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = value;
}


template<typename T>
inline Mvector<T>::Mvector(const Mvector& orig)
{
	size = orig.size;
	capacity = orig.capacity;

	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = orig.data[i];
}

template<typename T>
inline Mvector<T>& Mvector<T>::operator=(const Mvector& right)
{
	if (this == &right)
		return *this;

	if (data != nullptr)
		delete[] data;

	size = right.size;
	capacity = right.capacity;
	data = new T[size];

	for (int i = 0; i < size; i++)
		data[i] = right.data[i];

	return *this;
}


template<typename T>
inline T& Mvector<T>::operator[](int i)
{
	return data[i];
}

template<typename T>
inline void Mvector<T>::push_back(T& element)
{
	if (size == capacity)
		resize();

	data[size] = element;
	size++;
}

template<typename T>
inline int Mvector<T>::Size()
{
	return size;
}

template<typename T>
inline void Mvector<T>::resize()
{
	if (capacity == 0)
	{
		capacity = 1;
		data = new T[capacity];
	}
	else
	{
		capacity *= RESIZE_VALUE;
		T* temp = new T[capacity];

		for (int i = 0; i < size; i++)
			temp[i] = data[i];

		delete[] data;
		data = temp;
	}
}

template<typename T>
inline Mvector<T>::~Mvector()
{
	if (data != nullptr)
		delete[] data;
}

template<typename T>
inline void Mvector<T>::pop_back()
{
	if (size > 0)
		size--;
}

template<typename T>
inline void Mvector<T>::swap(int first, int second)
{
	T temp = data[first];
	data[first] = data[second];
	data[second] = temp;
}