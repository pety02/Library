#include "String.h"

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

	throw std::runtime_error("String is null pointer. Buffer can not be changed!");
}

void String::setCapacity(const size_t capacity)
{
	if (this != nullptr)
	{
		this->capacity = StringValidator::isValidCapacity(capacity) ? (lastIndex % 8 == 0) ? ((lastIndex / 8) * 8) : (((lastIndex / 8) + 1) * 8) : throw std::invalid_argument("Invalid capacity!");
	}

	throw std::runtime_error("String is null pointer. Capacity can not be changed!");
}

void String::setLastIndex(const size_t lastIndex)
{
	if (this != nullptr)
	{
		this->lastIndex = (StringValidator::isValidLastIndex(lastIndex)) ? ((0 == lastIndex) ? lastIndex : (lastIndex - 1)) : throw std::invalid_argument("Invalid lastIndex!");
	}

	throw std::runtime_error("String is null pointer. LastIndex can not be changed!");
}

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
	try
	{
		destroy();
		setCapacity(capacity * 2);
		buffer = new char[capacity];
		setLastIndex(0);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw std::exception(ex.what());
	}
}

String::String()
{
	try
	{
		setBuffer("\0");
		setCapacity(8);
		setLastIndex(0);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

String::String(const String& other)
{
	try
	{
		copy(other);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

String::String(const char* value)
{
	try
	{
		setLastIndex(strlen(value));
		setCapacity(lastIndex);
		setBuffer(value);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

String::~String()
{
	destroy();
}

char* String::getBuffer() const
{
	if (this != nullptr)
	{
		return buffer;
	}

	throw new std::runtime_error("String is null pointer. Buffer can not be readed!");
}

size_t String::getCapacity() const
{
	if (this != nullptr)
	{
		return capacity;
	}

	throw new std::runtime_error("String is null pointer. Capacity can not be readed!");
}

size_t String::getLastIndex() const
{
	if (this != nullptr)
	{
		return lastIndex;
	}

	throw new std::runtime_error("String is null pointer. LastIndex can not be readed!");
}

String& String::operator=(const String& other)
{
	try
	{
		if (this != nullptr)
		{
			if (this != &other)
			{
				destroy();
				copy(other);
			}

			return *this;
		}
		
		throw new std::runtime_error("String is null pointer. Operator = (const String& other) can not be applied!");
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

String& String::operator=(const char* other)
{
	try
	{
		if (this != nullptr)
		{
			setLastIndex(strlen(other) - 1);
			(lastIndex % 8 == 0) ? setCapacity(lastIndex) : setCapacity(lastIndex - lastIndex % 8);
			setBuffer(other);

			return *this;
		}
		
		throw new std::runtime_error("String is null pointer. Operator = (const char* otherValue) can not be applied!");
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

bool String::operator==(const char* other)
{
	String temp = other;
	return (getBuffer() == temp.getBuffer() && getLastIndex() == temp.getLastIndex() && getCapacity() == temp.getCapacity());
}

bool String::operator==(const String& other)
{
	return (getBuffer() == other.getBuffer() && getLastIndex() == other.getLastIndex() && getCapacity() == other.getCapacity());
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
	if (this != nullptr)
	{
		lastIndex += (strlen(other.buffer) + 1);
		capacity += other.capacity;

		char* tempBuffer = buffer;
		size_t tempBufferLenght = strlen(tempBuffer) + strlen(other.buffer);

		destroy();
		buffer = new char[tempBufferLenght + 1];
		strcpy_s(buffer, (tempBufferLenght + 1), tempBuffer);
		strcat_s(buffer, (tempBufferLenght + 1), other.buffer);

		return *this;
	}
	
	throw new std::runtime_error("String is null pointer. Operator + (const String& other) can not be applied!");
}

String& String::operator+(const char* other)
{
	try
	{
		String otherWord = String(other);
		return operator+(otherWord);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error&)
	{
		throw std::runtime_error("String is null pointer. Operator + (const char* other) can not be applied!");
	}
	catch (const std::exception& ex)
	{
		throw std::exception(ex.what());
	}
}

String& String::operator+=(const String& other)
{
	try
	{
		return operator+(other);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error&)
	{
		throw std::runtime_error("String is null pointer. Operator += (const String& other) can not be applied!");
	}
	catch (const std::exception& ex)
	{
		throw std::exception(ex.what());
	}
}

String& String::operator+=(const char* other)
{
	try
	{
		return operator+(other);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error&)
	{
		throw std::runtime_error("String is null pointer. Operator += (const char* other) can not be applied!");
	}
	catch (const std::exception& ex)
	{
		throw std::exception(ex.what());
	}
}

char String::operator[](const size_t index) const
{
	if (this != nullptr)
	{
		if (0 <= index && index <= lastIndex)
		{
			return buffer[index];
		}
		else
		{
			throw new std::invalid_argument("Invalid index!");
		}
	}
	
	throw new std::runtime_error("String is null pointer. Operator [] (size_t index) can not be applied!");
}

const char String::operator[](const size_t index)
{
	try
	{
		return operator[](index);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error&)
	{
		throw std::runtime_error("String is null pointer. Operator [] (const size_t index) can not be applied!");
	}
	catch (const std::exception& ex)
	{
		throw std::exception(ex.what());
	}
}

bool String::isEmpty() const
{
	if (this != nullptr)
	{
		return (lastIndex == 0);
	}
	
	throw new std::runtime_error("String is null pointer. isEmpty () method can not be proceeded!");
}

bool String::compare(const String& other) const
{
	if (this != nullptr)
	{
		return (lastIndex == other.lastIndex && capacity == other.capacity && strcmp(buffer, other.buffer) == 0);
	}
	
	throw new std::runtime_error("String is null pointer. compare (const String& other) method can not be proceeded!");
}

bool String::compare(const char* other) const
{
	try
	{
		String otherWord = String(other);
		return compare(otherWord);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error&)
	{
		throw std::runtime_error("String is null pointer. Method compare (const char* other) can not be proceeded!");
	}
	catch (const std::exception& ex)
	{
		throw std::exception(ex.what());
	}
}

String& String::pushBack(const char symbol)
{
	if (this != nullptr)
	{
		if (lastIndex < capacity)
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

	throw new std::runtime_error("String is null pointer. pushBack (const char symbol) method can not be proceeded!");
}

String& String::popBack()
{
	if (this != nullptr)
	{
		--lastIndex;
		return *this;
	}
	
	throw new std::runtime_error("String is null pointer. popBack () method can not be proceeded!");
	
}

void String::toString() const
{
	if (this != nullptr)
	{
		for (size_t index = 0; index <= lastIndex; ++index)
		{
			std::cout <<  buffer[index];
		}

		return;
	}
	
	throw std::runtime_error("String is null pointer. toString () method can not be proceeded!");
}

std::ostream& operator<<(std::ostream& out, String str)
{
	out << str.getBuffer();
	return out;
}

std::istream& operator>>(std::istream& in, String str)
{
	in >> str.getBuffer();
	return in;
}