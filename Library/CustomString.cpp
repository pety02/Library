#include "CustomString.h"
#include <cstring>

void CustomString::copy(const CustomString& other)
{
	capacity = other.capacity;
	lastIndex = other.lastIndex;
	value = new char[capacity + 1];
	strcpy_s(value, capacity, other.value);
}
void CustomString::destroy()
{
	delete[] value;
}
void CustomString::resize()
{
	destroy();
	capacity *= 2;
	value = new char[capacity + 1];
	lastIndex = 0;
}

CustomString::CustomString()
{
	value = new char[1];
	value[0] = '\0';
	capacity = 8;
	lastIndex = 0;
}
CustomString::CustomString(const CustomString& other)
{
	copy(other);
}
CustomString::CustomString(const char* value, size_t capacity, size_t lastIndex)
{
	this->capacity = (0 < capacity) ? capacity : 8;
	this->lastIndex = (0 < lastIndex && lastIndex < this->capacity) ? lastIndex : 0;
	strcpy_s(this->value, this->capacity, value);
}
CustomString& CustomString::operator=(const CustomString& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}
CustomString::~CustomString()
{
	destroy();
}

CustomString& CustomString::operator+(const CustomString& other)
{

}
CustomString& CustomString::operator+=(const CustomString& other)
{

}
char CustomString::operator[](size_t index)
{

}
const char CustomString::operator[](size_t index) const
{

}

char* CustomString::getValue() const
{

}
size_t CustomString::getCapacity() const
{

}
size_t CustomString::getLastIndex() const
{

}

bool CustomString::isEmpty() const
{

}
bool CustomString::compare(const CustomString& other) const
{

}
CustomString& CustomString::append(const CustomString& other)
{

}
void CustomString::pushBack(const char c)
{

}
void CustomString::popBack()
{

}