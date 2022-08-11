#pragma once
#ifndef IRECEIVER_H
#define IRECEIVER_H

namespace TYPES
{
	enum class ACTIONS_LIST
	{
		UNKNOWN,

		ALL_BOOKS,
		ALL_SERIES,
		LIST_ALL,
		LIST_INFO,
		FIND_BOOKS,
		FIND_SERIES,
		LIST_FIND,

		ADD_USER,
		FIND_USER,
		REMOVE_USER,
		CHANGE_USER,

		BORROW_BOOK,
		RETURN_BOOK
	};
};

class IReceiver
{
public:
	virtual void setAction(const TYPES::ACTIONS_LIST action) = 0;
	virtual void getResult() = 0;
};

#endif