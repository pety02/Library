#include "CustomString.h"
#include "ExceptionHandler.cpp"
#include <cstring>
#include <stdexcept>

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
	try
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
	catch (std::exception_ptr eptr)
	{
		ExceptionHandler::handleExceptionPtr(eptr);
	}
}
CustomString::~CustomString()
{
	destroy();
}

CustomString& CustomString::operator+(const CustomString& other)
{
	return append(other);
}
CustomString& CustomString::operator+=(const CustomString& other)
{
	return append(other);
}
char CustomString::operator[](size_t index)
{
	return value[index];
}
const char CustomString::operator[](size_t index) const
{
	return value[index];
}

char* CustomString::getValue() const
{
	return value;
}
size_t CustomString::getCapacity() const
{
	return capacity;
}
size_t CustomString::getLastIndex() const
{
	return lastIndex;
}

bool CustomString::isEmpty() const
{
	return (lastIndex == 0);
}
bool CustomString::compare(const CustomString& other) const
{
	return (lastIndex == other.lastIndex && capacity == other.capacity && strcmp(value, other.value) == 0);
}
CustomString& CustomString::append(const CustomString& other)
{
	size_t thisCustomStringStartCapacity = capacity;

	size_t thisCustomStringLastIndex = lastIndex;
	size_t otherCustomStringLastIndex = other.lastIndex;

	size_t appendedStringLength = (thisCustomStringLastIndex + 1) + (otherCustomStringLastIndex + 1);

	CustomString tempThisCustomString = CustomString(*this);

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

	for (size_t index = thisCustomStringLastIndex; index <= otherCustomStringLastIndex; ++index)
	{
		value[index] = other.value[index - thisCustomStringLastIndex];
	}

	return *this;
}
void CustomString::pushBack(const char c)
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

		CustomString tempThisCustomString = CustomString(*this);

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
}
void CustomString::popBack()
{
	--lastIndex;
}