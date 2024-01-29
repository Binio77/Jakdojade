#include"Structs.h"

Mstring mstringReverse(Mstring str)
{
	Mstring reversed;
	for (int i = str.Size() - 1; i >= 0; i--)
		reversed += str[i];
	return reversed;
}

