#pragma once
#ifndef LIBRARYITEMCONTROLLER_H
#define LIBRARYITEMCONTROLLER_H

#include "LibraryItems.h"

/// <summary>
/// <c>Order</c> is an enum class which describes library items order types.
/// </summary>
enum class Order
{
	ASC,
	DESC
};

/// <summary>
/// <c>LibraryItemController</c> is a class which describes library items
/// bussiness logic.
/// </summary>
class LibraryItemController
{
public:
	/// <summary>
	/// <c>saveLibraryItem(const LibraryItem& item)</c> stores information about a
	/// library item in a txt file.
	/// </summary>
	/// <param name="item">LibraryItem which should be stored</param>
	static void saveLibraryItem(const LibraryItem& item);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="id"></param>
	/// <returns></returns>
	static LibraryItem& getLibraryItem(const size_t id);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="id"></param>
	static void updateLibraryItem(const size_t id);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="id"></param>
	static void deleteLibraryItem(const size_t id);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	static Book* getAllBooks();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	static Series* getAllSeries();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	static LibraryItem** getAll();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="issnOrIsbnNumber"></param>
	static void printLibraryitemInfo(const String issnOrIsbnNumber);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="option"></param>
	/// <param name="optionValue"></param>
	/// <returns></returns>
	static LibraryItem** findLibraryItems(const String option, const String optionValue);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="option"></param>
	/// <param name="optionValue"></param>
	/// <param name="order"></param>
	/// <returns></returns>
	static LibraryItem** findLibraryItems(const String option, const String optionValue, const Order order);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="option"></param>
	/// <param name="optionValue"></param>
	/// <returns></returns>
	static Book* findBooks(const String option, const String optionValue);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="option"></param>
	/// <param name="optionValue"></param>
	/// <param name="order"></param>
	/// <returns></returns>
	static Book* findBooks(const String option, const String optionValue, const Order order);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="option"></param>
	/// <param name="optionValue"></param>
	/// <returns></returns>
	static Series* findSeries(const String option, const String optionValue);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="option"></param>
	/// <param name="optionValue"></param>
	/// <param name="order"></param>
	/// <returns></returns>
	static Series* findSeries(const String option, const String optionValue, const Order order);
};

#endif