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
			catch (std::bad_alloc& ex)
			{
				std::cerr << ex.what() << std::endl;
			}
		}
		else if (strcmp(cmd.getBuffer(), "Series") == 0)
		{
			try
			{
				return new Series();
			}
			catch (std::bad_alloc& ex)
			{
				std::cerr << ex.what() << std::endl;
			}
		}
		else
		{
			throw std::exception("Not supported library item!");
		}
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="cmd"></param>
	/// <param name="params"></param>
	/// <returns></returns>
	static LibraryItem* create(const String cmd, String* params)
	{
		if (strcmp(cmd.getBuffer(), "Book") == 0)
		{
			try
			{
				return new Book();
			}
			catch (std::bad_alloc& ex)
			{
				std::cerr << ex.what() << std::endl;
			}
		}
		else if (strcmp(cmd.getBuffer(), "Series") == 0)
		{
			try
			{
				return new Series();
			}
			catch (std::bad_alloc& ex)
			{
				std::cerr << ex.what() << std::endl;
			}
		}
		else
		{
			throw new std::exception("Not supported library item!");
		}
	}
};
#endif