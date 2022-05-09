#include "String.h"
#include "ExceptionHandler.cpp"
#include <cstring>
#include <string>
#include <stdexcept>

void String::copy(const String& other)
{
	lastIndex = other.lastIndex;
	capacity = other.capacity;
	value = new char[strlen(other.value) + 1];
	strcpy_s(value, strlen(other.value) + 1, other.value);
}
void String::destroy()
{
	delete[] value;
}
void String::resize()
{
	destroy();
	capacity *= 2;
	value = new char[capacity];
	lastIndex = 0;
}

String::String()
{
	value = new char[1];
	value[0] = '\0';
	capacity = 8;
	lastIndex = 0;
}
String::String(const String& other)
{
	copy(other);
}
String::String(const char* value)
{
	this->lastIndex = strlen(value) - 1;
	this->capacity = ((this->lastIndex) % 8 == 0) ? ((this->lastIndex / 8) * 8) : (((this->lastIndex / 8) + 1) * 8);
	this->value = new char[strlen(value) + 1];
	strcpy_s(this->value, strlen(value) + 1, value);
}
String::String(const char* value, size_t capacity, size_t lastIndex)
{
	this->lastIndex = strlen(value) - 1;
	this->capacity = (0 <= capacity && this->lastIndex < capacity) ? capacity : 8;
	this->value = new char[strlen(value) + 1];
	strcpy_s(this->value, strlen(value) + 1, value);
}
String& String::operator=(const String& other)
{
	
	if (this != &other)
	{
		destroy();
		copy(other);
		return *this;
	}
	else
	{
		throw std::exception_ptr();
	}
}
String::~String()
{
	destroy();
}

String& String::operator+(const String& other)
{
	size_t lIndex = lastIndex + other.lastIndex;
	lastIndex = lIndex;

	size_t maxCapacity = capacity + other.capacity;
	capacity = maxCapacity;

	char* s = value;
	value = new char[strlen(s) + strlen(other.value) + 1];
	strcpy_s(value, strlen(s) + strlen(other.value) + 1, s);
	strcat_s(value, strlen(value) + strlen(other.value) + 1, other.value);

	return *this;
}
String& String::operator+=(const String& other)
{
	return operator+(other);
}
char String::operator[](size_t index)
{
	return value[index];
}
const char String::operator[](size_t index) const
{
	return value[index];
}

char* String::getValue() const
{
	return value;
}
size_t String::getCapacity() const
{
	return capacity;
}
size_t String::getLastIndex() const
{
	return lastIndex;
}

bool String::isEmpty() const
{
	return (lastIndex == 0);
}
bool String::compare(const String& other) const
{
	return (lastIndex == other.lastIndex && capacity == other.capacity && strcmp(value, other.value) == 0);
}

String& String::pushBack(const char c)
{
	if (lastIndex < capacity)
	{
		value[lastIndex] = c;
		++lastIndex;
	}
	else
	{
		size_t thisCustomStringStartCapacity = capacity;

		size_t thisCustomStringLastIndex = lastIndex;
		size_t appendedStringLength = (thisCustomStringLastIndex + 1);

		String tempThisCustomString = String(*this);

		do {
			resize();
			if (thisCustomStringStartCapacity < capacity)
			{
				break;
			}
		} while (capacity < (appendedStringLength + 1));


		for (size_t index = 0; index < thisCustomStringLastIndex; ++index)
		{
			value[index] = tempThisCustomString.value[index];
		}
		value[thisCustomStringLastIndex] = c;
		++lastIndex;
	}

	return *this;
}
String& String::popBack()
{
	--lastIndex;
	return *this;
}
void String::toString()
{
	for (size_t index = 0; index < lastIndex; ++index)
	{
		std::cout <<  value[index];
	}
}