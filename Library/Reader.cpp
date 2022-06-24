#include "Users.h"

void Reader::setItems(LibraryItem** items)
{
	for (size_t firstIndex = 0; firstIndex < getBorrowingsCapacity(); ++firstIndex)
	{
		for (size_t secondIndex = 0; secondIndex < getBorrowingsCapacity(); ++secondIndex)
		{
			this->items[firstIndex][secondIndex] = items[firstIndex][secondIndex];
		}
	}
}

void Reader::setBorrowingsDates(const Date* borrowingsDates)
{
	for (size_t index = 0; index < getBorrowingsCapacity(); ++index)
	{
		this->borrowingsDates[index] = borrowingsDates[index];
	}
}

void Reader::setReturningsDates(const Date* returningsDates)
{
	for (size_t index = 0; index < getBorrowingsCapacity(); ++index)
	{
		this->returningsDates[index] = returningsDates[index];
	}
}

void Reader::setBorrowingCapacity(const size_t borrowingsCapacity)
{
	this->borrowingCapacity = borrowingCapacity;
}

void Reader::setBorrowingLastIndex(const size_t borrowingsLastIndex)
{
	this->borrowingLastIndex = borrowingLastIndex;
}

void Reader::copy(const Reader& other)
{
	setItems(other.getItems());
	setBorrowingsDates(other.getBorrowingsDates());
	setReturningsDates(other.getReturningsDates());
	setBorrowingCapacity(other.getBorrowingsCapacity());
	setBorrowingLastIndex(other.getBorrowingLastIndex());
}

void Reader::destroy()
{
	for (size_t index = 0; index < getBorrowingsCapacity(); ++index)
	{
		delete[] items[index];
	}
	delete[] borrowingsDates;
	delete[] returningsDates;
}

Reader::Reader() : User()
{
	LibraryItem **items = new LibraryItem*[0];
	setItems(items);
	
	Date* borrowingsDates = new Date[0];
	setBorrowingsDates(borrowingsDates);
	
	Date* returningsDates = new Date[0];
	setReturningsDates(returningsDates);
	
	setBorrowingCapacity(8);
	setBorrowingLastIndex(0);
}

Reader::Reader(const String username, const String password) : User(username, password)
{
	LibraryItem** items = new LibraryItem * [0];
	setItems(items);

	Date* borrowingsDates = new Date[0];
	setBorrowingsDates(borrowingsDates);

	Date* returningsDates = new Date[0];
	setReturningsDates(returningsDates);

	setBorrowingCapacity(8);
	setBorrowingLastIndex(0);
}
	
Reader::Reader(const String username, const String password, LibraryItem** items, 
	const Date* borrowingsDates, const Date* returningsDates, const size_t borrowingsCapacity, 
	const size_t borrowingsLastIndex) : User(username, password)
{
	setBorrowingCapacity(borrowingCapacity);
	setBorrowingLastIndex(borrowingLastIndex);
	setItems(items);
	setBorrowingsDates(borrowingsDates);
	setReturningsDates(returningsDates);
}
	
Reader::Reader(const Reader& other)
{
	copy(other);
}

Reader::~Reader()
{
	destroy();
}

Reader Reader::operator=(const Reader& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

LibraryItem** Reader::getItems() const
{
	return items;
}

Date* Reader::getBorrowingsDates() const
{
	return borrowingsDates;
}

Date* Reader::getReturningsDates() const
{
	return returningsDates;
}

size_t Reader::getBorrowingsCapacity() const
{
	return borrowingCapacity;
}

size_t Reader::getBorrowingLastIndex() const
{
	return borrowingLastIndex;
}