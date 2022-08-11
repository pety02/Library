#include "Command.h"

Command::Command(IReceiver* receiver)
{
	this->receiver = receiver;
}