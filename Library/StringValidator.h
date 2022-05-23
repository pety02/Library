#pragma once
#ifndef STRINGVALIDATOR_H
#define STRINGVALIDATOR_H

#include <cstring>

class StringValidator
{
public:
	static bool isValidBuffer(const char* buffer)
	{
		return (0 <= strlen(buffer));
	}
	static bool isValidCapacity(const size_t capacity) 
	{
		return (0 <= capacity);
	}
	static bool isValidLastIndex(const size_t lastIndex)
	{
		return (0 <= lastIndex);
	}
};

#endif