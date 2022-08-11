#include "AllBooksCommand.h"

AllBooksCommand::AllBooksCommand(const IReceiver* reciever) : Command(receiver)
{

}

void AllBooksCommand::execute()
{
	receiver->setAction(TYPES::ACTIONS_LIST::ALL_BOOKS);
	receiver->getResult();
}