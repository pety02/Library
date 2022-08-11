#pragma once

#include "IReceiver.h"
#include "LibraryItems.h"
#include "Users.h"
#include <fstream>
#include <cmath>

enum class KeyOrder
{
	ASC,
	DESC
};

class LibraryManager final : public IReceiver
{
private:
	LibraryItem** items;
	User** users;
	TYPES::ACTIONS_LIST currentAction;

	void copy(const LibraryManager& other);
	void destroy();

	const size_t countLinesInFile(const String& fileName) const;
	const size_t stringToSizeT(const String& str) const;
	const size_t countKeywords(const String& str) const;
	const String* stirngToStringArray(const String& str, size_t& count) const;
	const Book* getAllBooks(const String& fileName, size_t& count) const;
	/*
	const Series* getAllSeries(const String& fileName, size_t& count) const;
	const LibraryItem* getAllItems(const String& fileName, size_t& count) const;
	const String getInfo(const String& fileName, const String& isbnOrIssn) const;
	const Book* findBooks(const String& option, const String& optionValue, const KeyOrder keyOrder, size_t& count) const;
	const Series* findSeriess(const String& option, const String& optionValue, const KeyOrder keyOrder, size_t& count) const;
	const LibraryItem* findList(const String& option, const String& optionValue, const KeyOrder keyOrder, size_t& count) const;
	*/
public:
	LibraryManager();
	LibraryManager(const LibraryManager& other);
	LibraryManager& operator=(const LibraryManager& other);
	LibraryManager(const User& user);
	LibraryManager(const User& user, const LibraryItem& item);
	~LibraryManager();

	void setAction(const TYPES::ACTIONS_LIST action);
	void getResult();
};