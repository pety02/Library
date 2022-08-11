#pragma once
#ifndef ALLBOOKSCOMMAND_H
#define ALLBOOKSCOMMAND_H

#include "Command.h"
class AllBooksCommand final : public Command
{
private:
public:
    AllBooksCommand(const IReceiver* reciever);
    void execute();
};

#endif