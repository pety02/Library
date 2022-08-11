#pragma once

#include "Command.h"

class Invoker
{
private:
	Command* command;

public:
	Invoker(Command* command);
	virtual void invoke() = 0;
};