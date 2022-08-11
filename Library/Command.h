#pragma once

#include "LibraryItems.h"
#include "IReceiver.h"

class Command
{
protected:
	IReceiver* receiver;

public:
	Command(IReceiver* receiver);

	virtual void execute() = 0;
};