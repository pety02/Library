#pragma once

#include "Command.h"
class AllBooksCommand final : public Command
{
private:
public:
    AllBooksCommand(const IReceiver* reciever);
    void execute();
};