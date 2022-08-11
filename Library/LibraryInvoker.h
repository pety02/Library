#pragma once
#ifndef LIBRARYINVOKER_H
#define LIBRARYINVOKER_H

#include "Invoker.h"

class LibraryInvoker final : Invoker
{
private:
public:
	LibraryInvoker(Command* command);
	void invoke();
};

#endif