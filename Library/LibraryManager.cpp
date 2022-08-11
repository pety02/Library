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
	case TYPES::ACTIONS_LIST::ALL_BOOKS:
	case TYPES::ACTIONS_LIST::ALL_SERIES:
	case TYPES::ACTIONS_LIST::LIST_ALL:
	case TYPES::ACTIONS_LIST::LIST_INFO:
	case TYPES::ACTIONS_LIST::FIND_BOOKS:
	case TYPES::ACTIONS_LIST::FIND_SERIES:
	case TYPES::ACTIONS_LIST::LIST_FIND:

	case TYPES::ACTIONS_LIST::ADD_USER:
	case TYPES::ACTIONS_LIST::FIND_USER:
	case TYPES::ACTIONS_LIST::REMOVE_USER:
	case TYPES::ACTIONS_LIST::CHANGE_USER:

	case TYPES::ACTIONS_LIST::BORROW_BOOK:
	case TYPES::ACTIONS_LIST::RETURN_BOOK:

	default:
		break;
	}
}