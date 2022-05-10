#include "String.h"
#include "ExceptionHandler.cpp"
#include <cstring>
#include <string>
#include <stdexcept>

void String::copy(const String& other)
{
	lastIndex = other.lastIndex;
	capacity = other.capacity;
	buffer = new char[strlen(other.buffer) + 1];
	strcpy_s(buffer, strlen(other.buffer) + 1, other.buffer);
}
void String::destroy()
{
	delete[] buffer;
}
void String::resize()
{
	destroy();
	capacity *= 2;
	buffer = new char[capacity];
	lastIndex = 0;
}

String::String()
{
	buffer = new char[1];
	buffer[0] = '\0';
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
	this->buffer = new char[strlen(value) + 1];
	strcpy_s(this->buffer, strlen(value) + 1, value);
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
		throw new std::exception_ptr();
	}
}
String::~String()
{
	destroy();
}

String& String::operator=(const char* otherValue)
{
	lastIndex = strlen(otherValue) - 1;
	capacity = (lastIndex % 8 == 0) ? ((lastIndex / 8) * 8) : (((lastIndex / 8) + 1) * 8);
	buffer = new char[strlen(otherValue) + 1];
	strcpy_s(buffer, strlen(otherValue) + 1, otherValue);

	return *this;
}
String& String::operator+(const String& other)
{
	size_t lIndex = lastIndex + other.lastIndex + 1;
	lastIndex = lIndex;

	size_t maxCapacity = capacity + other.capacity;
	capacity = maxCapacity;

	char* s = buffer;
	buffer = new char[strlen(s) + strlen(other.buffer) + 1];
	strcpy_s(buffer, strlen(s) + strlen(other.buffer) + 1, s);
	strcat_s(buffer, strlen(s) + strlen(other.buffer) + 1, other.buffer);
	return *this;
}
String& String::operator+=(const String& other)
{
	return operator+(other);
}
char String::operator[](size_t index)
{
	if (index <= lastIndex)
	{
		return buffer[index];
	}
	else
	{
		throw new std::invalid_argument("Invalid index!");
	}
}
const char String::operator[](size_t index) const
{
	if (index <= lastIndex)
	{
		return buffer[index];
	}
	else
	{
		throw new std::invalid_argument("Invalid index!");
	}
}

char* String::getBuffer() const
{
	return buffer;
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
	return (lastIndex == other.lastIndex && capacity == other.capacity && strcmp(buffer, other.buffer) == 0);
}

String& String::pushBack(const char c)
{
	if (lastIndex < capacity)
	{
		++lastIndex;
		buffer[lastIndex] = c;
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
			buffer[index] = tempThisCustomString.buffer[index];
		}
		++lastIndex;
		buffer[thisCustomStringLastIndex] = c;
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
	for (size_t index = 0; index <= lastIndex; ++index)
	{
		std::cout <<  buffer[index];
	}
}