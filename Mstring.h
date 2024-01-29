#pragma once
#define BASIC_CAPACITY 20
#define RESIZE_VALUE 2
#include<cstring>
#include<iostream>
class Mstring
{
	char *str;
	int capacity;
	int size;
	friend std::ostream& operator<<(std::ostream& os, const Mstring& obj);
	public:
		Mstring();
		Mstring(int _capacity);
		~Mstring();
		Mstring(const Mstring& orig);
		Mstring& operator=(const Mstring& right);
		Mstring& operator+=(const char& c);
		int to_int();
		int Size();
		bool empty();
		void clear();
		bool operator==(const Mstring& right);
		bool operator!=(const Mstring& right);
		char& operator[](int i);
		void setSize(int _size);
};

