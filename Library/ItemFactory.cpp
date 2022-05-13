#include "LibraryItems.h"

class ItemFactory
{
public:
	static LibraryItem* create(const String cmd)
	{
		if (strcmp(cmd.getBuffer(), "Book") == 0)
		{
			return new Book();
		}
		else if (strcmp(cmd.getBuffer(), "Series") == 0)
		{
			return new Series();
		}
		else
		{
			throw new std::exception("Not supported library item!");
		}
	}
	static LibraryItem* create(const String cmd, String* params)
	{
		if (strcmp(cmd.getBuffer(), "Book") == 0)
		{
			return new Book();
		}
		else if (strcmp(cmd.getBuffer(), "Series") == 0)
		{
			return new Series();
		}
		else
		{
			throw new std::exception("Not supported library item!");
		}
	}
};