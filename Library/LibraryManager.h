#pragma once

#include "IReceiver.h"
#include "LibraryItems.h"
#include "Users.h"
#include <fstream>

class LibraryManager final : public IReceiver
{
private:
	LibraryItem** items;
	User** users;
	TYPES::ACTIONS_LIST currentAction;

	void copy(const LibraryManager& other);
	void destroy();
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