#pragma once
#ifndef STRINGVALIDATOR_H
#define STRINGVALIDATOR_H

#include <cstring>

/// <summary>
/// 
/// </summary>
class StringValidator
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="buffer"></param>
	/// <returns></returns>
	static bool isValidBuffer(const char* buffer)
	{
		return (0 <= strlen(buffer));
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="capacity"></param>
	/// <returns></returns>
	static bool isValidCapacity(const size_t capacity) 
	{
		return (0 <= capacity);
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="lastIndex"></param>
	/// <returns></returns>
	static bool isValidLastIndex(const size_t lastIndex)
	{
		return (0 <= lastIndex);
	}
};

#endif