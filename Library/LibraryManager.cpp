#pragma warning(disable : 4996)
#include "LibraryManager.h"

void LibraryManager::copy(const LibraryManager& other)
{
	items = other.items;
	users = other.users;
	currentAction = other.currentAction;
}

void LibraryManager::destroy()
{
	delete[] items;
	delete[] users;
}

const size_t LibraryManager::countLinesInFile(const String& fileName) const
{
	size_t count = 0;

	std::ifstream in(fileName.getBuffer(), std::ios::in);
	if (in.is_open())
	{
		String line = "";

		while (in.good())
		{
			in >> line;
			++count;
		}

		in.close();
	}

	return count;
}

const size_t LibraryManager::stringToSizeT(const String& str) const
{
	size_t number = 0;
	size_t digitsCount = str.getLastIndex() + 1;
	size_t power = digitsCount - 1;
	for (size_t i = 0; i < digitsCount; i++)
	{
		number += pow(str[i], power);
		power--;
	}

	return number;
}

const size_t LibraryManager::countKeywords(const String& str) const
{
	size_t cnt = 0;

	char* str2 = new char[str.getCapacity() + 1];
	for (size_t i = 0; i < str.getLastIndex() + 1; i++)
	{
		str2[i] = str[i];
	}

	char* ptr = strtok(str2, ",");
	++cnt;

	while (ptr != NULL)
	{
		ptr = strtok(NULL, ",");
		++cnt;
	}

	return cnt;
}

const String* LibraryManager::stirngToStringArray(const String& str, size_t& count) const
{
	size_t ind = 0;

	char* str2 = new char[str.getCapacity() + 1];
	String* keywords = new String[count];
	for (size_t i = 0; i < str.getLastIndex() + 1; i++)
	{
		str2[i] = str[i];
	}

	char* ptr = strtok(str2, ",");
	keywords[ind] = ptr;
	++ind;

	while (ptr != NULL)
	{
		ptr = strtok(NULL, ",");
		keywords[ind] = ptr;
		++ind;
	}

	return keywords;
}

const Book* LibraryManager::getAllBooks(const String& fileName, size_t& count) const
{
	count = countLinesInFile(fileName);
	size_t tempCount = 0;
	Book* books = new Book[count];

	std::ifstream in(fileName.getBuffer(), std::ios::in);
	if (in.is_open())
	{
		String line = "";
		String* params = new String[1000];
		size_t ind = 0;
		size_t booksIndex = 0;
		while (in.good())
		{
			in >> line;
			char* str = new char[line.getCapacity() + 1];
			for (size_t i = 0; i < line.getLastIndex() + 1; i++)
			{
				str[i] = line[i];
			}
			
			char* ptr = strtok(str, "|");
			params[ind] = ptr; 
			++ind;

			while (ptr != NULL)
			{
				ptr = strtok(NULL, "|");
				params[ind] = ptr;
				++ind;
			}

			
			size_t keywordsCount = countKeywords(params[8]);
			books[booksIndex] = Book(params[0], params[1], (Genre) stringToSizeT(params[2]), params[3], stringToSizeT(params[4]), (double) stringToSizeT(params[5]), params[6], params[7], stirngToStringArray(params[8], keywordsCount), stringToSizeT(params[9]));
			++booksIndex;
		}
		
		in.close();
	}

	return books;
}

/*
const Series* LibraryManager::getAllSeries(const String& fileName, size_t& count) const
{

}

const LibraryItem* LibraryManager::getAllItems(const String& fileName, size_t& count) const
{

}

const String LibraryManager::getInfo(const String& fileName, const String& isbnOrIssn) const
{

}

const Book* LibraryManager::findBooks(const String& option, const String& optionValue, const KeyOrder keyOrder, size_t& count) const
{

}

const Series* LibraryManager::findSeriess(const String& option, const String& optionValue, const KeyOrder keyOrder, size_t& count) const
{

}

const LibraryItem* LibraryManager::findList(const String& option, const String& optionValue, const KeyOrder keyOrder, size_t& count) const
{

}
*/

LibraryManager::LibraryManager()
{
	items = new LibraryItem* [0];
	users = new User* [0];
	currentAction = TYPES::ACTIONS_LIST::UNKNOWN;
}

LibraryManager::LibraryManager(const LibraryManager& other)
{
	copy(other);
}

LibraryManager& LibraryManager::operator=(const LibraryManager& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

LibraryManager::LibraryManager(const User& user)
{
	items = new LibraryItem* [0];
	users = new User* [1];
	users[0][0] = user;
	currentAction = TYPES::ACTIONS_LIST::UNKNOWN;
}

LibraryManager::LibraryManager(const User& user, const LibraryItem& item)
{
	items = new LibraryItem* [1];
	items[0][0] = item;
	users = new User* [1];
	users[0][0] = user;
	currentAction = TYPES::ACTIONS_LIST::UNKNOWN;
}

LibraryManager::~LibraryManager()
{
	destroy();
}

void LibraryManager::setAction(const TYPES::ACTIONS_LIST action)
{
	currentAction = action;
}

void LibraryManager::getResult()
{
	switch (currentAction)
	{
	case TYPES::ACTIONS_LIST::ALL_BOOKS: {size_t count = 0; const Book* books = getAllBooks("books.txt", count); for (size_t index = 0; index < count; ++index) { items[0][index] = books[index]; } break;}
	case TYPES::ACTIONS_LIST::ALL_SERIES: {/*size_t count = 0; const Series* series = getAllSeries("series.txt", count); for (size_t index = 0; index < count; ++index) { items[0][index] = series[index]; }*/ break;}
	case TYPES::ACTIONS_LIST::LIST_ALL: break;
	case TYPES::ACTIONS_LIST::LIST_INFO: break;
	case TYPES::ACTIONS_LIST::FIND_BOOKS: break;
	case TYPES::ACTIONS_LIST::FIND_SERIES: break;
	case TYPES::ACTIONS_LIST::LIST_FIND: break;

	case TYPES::ACTIONS_LIST::ADD_USER: break;
	case TYPES::ACTIONS_LIST::FIND_USER: break;
	case TYPES::ACTIONS_LIST::REMOVE_USER: break;
	case TYPES::ACTIONS_LIST::CHANGE_USER: break;

	case TYPES::ACTIONS_LIST::BORROW_BOOK: break;
	case TYPES::ACTIONS_LIST::RETURN_BOOK: break;

	default:
		break;
	}
}