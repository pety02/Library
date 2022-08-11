#include "String.h"

void String::setBufferAndLastIndex(const char* buffer, const size_t& lastIndex)
{
	this->buffer = new char[capacity + 1];
	if (0 <= strlen(buffer) && strlen(buffer) <= capacity)
	{
		strcpy_s(this->buffer, strlen(buffer) + 1, buffer);
		this->lastIndex = strlen(this->buffer) - 1;
	}
	else
	{
		throw std::invalid_argument("Invalid string!");
	}
}

void String::setCapacity(const size_t& capacity)
{
	this->capacity = capacity;
}

void String::copy(const String& other)
{
	setCapacity(other.capacity);
	setBufferAndLastIndex(other.buffer, other.lastIndex);
}

void String::destroy() const
{
	delete[] buffer;
}

void String::resize()
{
	destroy();
	setCapacity(capacity * 2);
	buffer = new char[capacity + 1];
	lastIndex = 0;
}

String::String()
{
	try
	{ 
		setCapacity(8);
		setBufferAndLastIndex("\0", 0);
	}
	catch (const std::invalid_argument& invalidArgEx)
	{
		destroy();
	}
	catch (const std::exception& ex)
	{
		destroy();
	}
	catch (...)
	{
		destroy();
	}
}

String::String(const String& other)
{
	copy(other);
}

String::String(const char* value)
{
	try
	{
		setCapacity(lastIndex);
		setBufferAndLastIndex(value, strlen(value) - 1);
	}
	catch (const std::invalid_argument& invalidArgEx)
	{
		destroy();
	}
	catch (const std::exception& ex)
	{
		destroy();
	}
}

String::~String()
{
	destroy();
}

const char* String::getBuffer() const
{
	return buffer;
}

const size_t String::getCapacity() const
{
	return capacity;
}

const size_t String::getLastIndex() const
{
	return lastIndex;
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

String& String::operator=(const char* other)
{
	try
	{
		setCapacity(lastIndex * 2);
		setBufferAndLastIndex(other, strlen(other) - 1);
	}
	catch (const std::invalid_argument& invalidArgEx)
	{
		destroy();
	}
	catch (const std::exception& ex)
	{
		destroy();
	}

	return *this;
}

bool String::operator==(const char* other)
{
	String temp = other;
	return compare(other);
}

bool String::operator==(const String& other)
{
	return compare(other);
}

bool String::operator!=(const char* other)
{
	return !operator==(other);
}

bool String::operator!=(const String& other)
{
	return !operator==(other);
}

String& String::operator+(const String& other)
{
	String word = String(buffer);
	word += String(other);

	return word;
}

String& String::operator+(const char* other)
{
	String word = String(buffer);
	word += String(other);

	return word;
}

String& String::operator+=(const String& other)
{
	char* tempBuffer = buffer;
	size_t tempBufferLenght = strlen(tempBuffer) + strlen(other.buffer);

	destroy();
	buffer = new char[tempBufferLenght + 1];
	strcpy_s(buffer, (tempBufferLenght + 1), tempBuffer);
	strcat_s(buffer, (tempBufferLenght + 1), other.buffer);

	return *this;
}

String& String::operator+=(const char* other)
{
	char* tempBuffer = buffer;
	size_t tempBufferLenght = strlen(tempBuffer) + strlen(other);

	destroy();
	buffer = new char[tempBufferLenght + 1];
	strcpy_s(buffer, (tempBufferLenght + 1), tempBuffer);
	strcat_s(buffer, (tempBufferLenght + 1), other);

	return *this;
}

char& String::operator[](const size_t& index) const
{
	if (index <= lastIndex && lastIndex <= capacity)
	{
		return buffer[index];
	}
	else
	{
		throw new std::invalid_argument("Invalid index!");
	}
}

const char String::operator[](const size_t& index)
{
	if (index <= lastIndex && lastIndex <= capacity)
	{
		return buffer[index];
	}
	else
	{
		throw new std::invalid_argument("Invalid index!");
	}
}

const bool String::isEmpty() const
{
	return (lastIndex == 0);
}

const bool String::compare(const String& other) const
{
	return (strcmp(buffer, other.buffer) == 0);
}

const bool String::compare(const char* other) const
{
	String otherWord = String(other);
	return compare(otherWord);
}

String& String::pushBack(const char& symbol)
{
	if (lastIndex <= capacity)
	{
		++lastIndex;
		buffer[lastIndex] = symbol;
	}
	else
	{
		size_t thisCustomStringStartCapacity = capacity;

		size_t thisCustomStringLastIndex = lastIndex;
		size_t appendedStringLength = (thisCustomStringLastIndex + 1);

		String tempThisCustomString = String(*this);

		do
		{
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
		buffer[thisCustomStringLastIndex] = symbol;
	}

	return *this;
}

String& String::popBack()
{
	if (0 <= lastIndex)
	{
		--lastIndex;
		return *this;
	}
	
	throw new std::exception("Invalid index!");
}

void String::toString() const
{
	std::cout << buffer;
}

String& append(const String& firstString, const String& secondString)
{
	char* s = new char[strlen(firstString.getBuffer()) + strlen(secondString.getBuffer()) + 1];
	strcpy_s(s, strlen(firstString.getBuffer()) + strlen(secondString.getBuffer()) + 1, firstString.getBuffer());
	strcat_s(s, strlen(firstString.getBuffer()) + strlen(secondString.getBuffer()) + 1, secondString.getBuffer());

	String cs = String(s);

	return cs;
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	out << str.getBuffer();
	return out;
}

std::istream& operator>>(std::istream& in, String str)
{
	in >> str.getBuffer();
	return in;
}