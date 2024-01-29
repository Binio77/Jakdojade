#include "Mstring.h"

Mstring::Mstring()
{
	str = new char[BASIC_CAPACITY];
	capacity = BASIC_CAPACITY;
	size = 0;
	str[size] = '\0';
}

Mstring::Mstring(int _capacity)
{
	str = new char[_capacity];
	capacity = _capacity;
	size = 0;
	str[size] = '\0';
}

Mstring::~Mstring()
{
	delete[] str;
}

Mstring::Mstring(const Mstring& orig)
{
	size = orig.size;
	capacity = orig.capacity;
	str = new char[capacity];
	strcpy_s(str, capacity, orig.str);
	str[size] = '\0';
}

Mstring& Mstring::operator=(const Mstring& right)
{
	if (this == &right)
		return *this;

	if (str != nullptr)
		delete[] str;

	size = right.size;
	capacity = right.capacity;
	str = new char[capacity];

	strcpy_s(str, capacity, right.str);

	str[size] = '\0';
	return *this;
}

Mstring& Mstring::operator+=(const char& c)
{
	if (size + 1 == capacity)
	{
		capacity *= RESIZE_VALUE;
		char* temp = new char[capacity];
		strcpy_s(temp, capacity, str);
		delete[] str;
		str = temp;
	}
	str[size] = c;
	size++;
	str[size] = '\0';
	return *this;
}

int Mstring::to_int()
{
	return atoi(str);
}

int Mstring::Size()
{
	return size;
}

void Mstring::clear()
{
	delete[] str;
	str = new char[BASIC_CAPACITY];
	capacity = BASIC_CAPACITY;
	size = 0;
	str[size] = '\0';
}

bool Mstring::empty()
{
	return size == 0;
}

bool Mstring::operator==(const Mstring& right)
{
	if (size != right.size)
		return false;

	for (int i = 0; i < size; i++)
	{
		if (str[i] != right.str[i])
			return false;
	}

	return true;
}

bool Mstring::operator!=(const Mstring& right)
{
	return !(*this == right);
}

char& Mstring::operator[](int i)
{
	return str[i];
}

std::ostream& operator<<(std::ostream& os, const Mstring& obj)
{
	os << obj.str;
	return os;
}

void Mstring::setSize(int _size)
{
	size = _size;
}