#pragma once

#include "Invoker.h"

class LibraryInvoker final : Invoker
{
private:
public:
	LibraryInvoker(Command* command);
	void invoke();
};