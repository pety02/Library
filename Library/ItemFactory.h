#pragma once
#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "LibraryItems.h"

/// <summary>
/// 
/// </summary>
class ItemFactory
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="cmd"></param>
	/// <returns></returns>
	static LibraryItem* create(const String cmd)
	{
		
		if (strcmp(cmd.getBuffer(), "Book") == 0)
		{
			try
			{
				return new Book();
			}
			catch (std::bad_alloc& badAllocEx)
			{
				throw new std::bad_alloc();
			}
		}
		else if (strcmp(cmd.getBuffer(), "Series") == 0)
		{
			try
			{
				return new Series();
			}
			catch (std::bad_alloc& badAllocEx)
			{
				throw new std::bad_alloc();
			}
		}
		else
		{
			throw new std::exception("Not supported library item!");
		}
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="cmd"></param>
	/// <param name="params"></param>
	/// <returns></returns>
	static LibraryItem* create(const String cmd, const String* params)
	{
		if (strcmp(cmd.getBuffer(), "Book") == 0)
		{
			try
			{
				return new Book();
			}
			catch (std::bad_alloc& badAllocEx)
			{
				throw new std::bad_alloc();
			}
		}
		else if (strcmp(cmd.getBuffer(), "Series") == 0)
		{
			try
			{
				return new Series();
			}
			catch (std::bad_alloc& badAllocEx)
			{
				throw new std::bad_alloc();
			}
		}
		else
		{
			throw new std::exception("Not supported library item!");
		}
	}
};
#endif