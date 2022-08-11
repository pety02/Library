#pragma once
#ifndef INVOKER_H
#define INVOKER_H

#include "Command.h"

class Invoker
{
protected:
	Command* command;

public:
	Invoker(Command* command);
	virtual void invoke() = 0;
};

#endif