#pragma once

#include "Command.h"

class Invoker
{
protected:
	Command* command;

public:
	Invoker(Command* command);
	virtual void invoke() = 0;
};