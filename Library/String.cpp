#include "String.h"

void String::copy(const String& other)
{
	setCapacity(other.capacity);
	setBuffer(other.buffer);
	setLastIndex(other.lastIndex);
}
void String::destroy() const
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

void String::setBuffer(const char* buffer)
{
	if (this != nullptr)
	{
		if (StringValidator::isValidBuffer(buffer))
		{
			this->buffer = new char[strlen(buffer) + 1];
			strcpy_s(this->buffer, strlen(buffer) + 1, buffer);
		}
		else
		{
			throw std::invalid_argument("Invalid buffer!");
		}
	}
	else
	{
		throw std::runtime_error("String is null pointer. Buffer can not be changed!");
	}
}
void String::setCapacity(const size_t capacity)
{
	if (this != nullptr)
	{
		this->capacity = StringValidator::isValidCapacity(capacity) ? ((lastIndex) % 8 == 0) ? ((lastIndex / 8) * 8) : (((lastIndex / 8) + 1) * 8) : throw std::invalid_argument("Invalid capacity!");
	}
	else
	{
		throw std::runtime_error("String is null pointer. Capacity can not be changed!");
	}
}
void String::setLastIndex(const size_t lastIndex)
{
	if (this != nullptr)
	{
		this->lastIndex = (StringValidator::isValidLastIndex(lastIndex)) ? ((0 == lastIndex) ? lastIndex : (lastIndex - 1)) : throw std::invalid_argument("Invalid lastIndex!");
	}
	else
	{
		throw std::runtime_error("String is null pointer. LastIndex can not be changed!");
	}
}

String::String()
{
	setBuffer('\0');
	setCapacity(8);
	setLastIndex(0);
}
String::String(const String& other)
{
	copy(other);
}
String::String(const char* value)
{
	setLastIndex(strlen(value));
	setCapacity(lastIndex);
	setBuffer(value);
}
// set validation for this != nullptr
String& String::operator=(const String& other)
{
	if (this != nullptr)
	{
		if (this != &other)
		{
			destroy();
			copy(other);
			return *this;
		}
		else
		{
			
		}
	}
	else
	{
		throw std::runtime_error("String is null pointer. Operator = (const String& other) can not be applied!");
	}
}
String::~String()
{
	destroy();
}
// set validation for this != nullptr
String& String::operator=(const char* otherValue)
{
	if (this != nullptr)
	{
		lastIndex = strlen(otherValue) - 1;
		capacity = (lastIndex % 8 == 0) ? ((lastIndex / 8) * 8) : (((lastIndex / 8) + 1) * 8);
		buffer = new char[strlen(otherValue) + 1];
		strcpy_s(buffer, strlen(otherValue) + 1, otherValue);

		return *this;
	}
	else
	{
		throw std::runtime_error("String is null pointer. Operator = (const char* otherValue) can not be applied!");
	}
}
// set validation for this != nullptr
String& String::operator+(const String& other)
{
	if (this != nullptr)
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
	else
	{
		throw std::runtime_error("String is null pointer. Operator + (const String& other) can not be applied!");
	}
}
String& String::operator+=(const String& other)
{
	return operator+(other);
}
// set validation for this != nullptr
char String::operator[](size_t index) const
{
	if (this != nullptr)
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
	else
	{
		throw std::runtime_error("String is null pointer. Operator [] (size_t index) can not be applied!");
	}
}
const char String::operator[](size_t index)
{
	return operator[](index);
}
// set validation for this != nullptr
char* String::getBuffer() const
{
	if (this != nullptr)
	{
		return buffer;
	}
	else
	{
		throw std::runtime_error("String is null pointer. Buffer can not be readed!");
	}
}
// set validation for this != nullptr
size_t String::getCapacity() const
{
	if (this != nullptr)
	{
		return capacity;
	}
	else
	{
		throw std::runtime_error("String is null pointer. Capacity can not be readed!");
	}
}
// set validation for this != nullptr
size_t String::getLastIndex() const
{
	if (this != nullptr)
	{
		return lastIndex;
	}
	else
	{
		throw std::runtime_error("String is null pointer. LastIndex can not be readed!");
	}
}
// set validation for this != nullptr
bool String::isEmpty() const
{
	if (this != nullptr)
	{
		return (lastIndex == 0);
	}
	else
	{

	}
}
// set validation for this != nullptr
bool String::compare(const String& other) const
{
	if (this != nullptr)
	{
		return (lastIndex == other.lastIndex && capacity == other.capacity && strcmp(buffer, other.buffer) == 0);
	}
	else
	{

	}
}
// set validation for this != nullptr
String& String::pushBack(const char c)
{
	if (this != nullptr)
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
	else
	{

	}
}
// set validation for this != nullptr
String& String::popBack()
{
	if (this != nullptr)
	{
		--lastIndex;
		return *this;
	}
	else
	{

	}
}
// set validation for this != nullptr
void String::toString() const
{
	if (this != nullptr)
	{
		for (size_t index = 0; index <= lastIndex; ++index)
		{
			std::cout <<  buffer[index];
		}
	}
	else
	{

	}
}