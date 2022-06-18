#pragma once
#ifndef USERVALIDATOR_H
#define USERVALIDATOR_H

#include "String.h"

class UserValidator
{
public:
	bool isValidUsername(const String userName) const
	{
		bool isValid = false;
		for (size_t index = 0; index < userName.getCapacity() - 4; ++index)
		{
			if ('a' <= userName[index] && userName[index] <= 'z')
			{
				isValid = true;
			}
			else
			{
				isValid = false;
			}
		}
		for (size_t index = userName.getCapacity() - 4; 
			index < userName.getCapacity(); ++index)
		{
			if ((0 <= userName[index] && userName[index] <= 9) || (userName[index] == '.'
				|| userName[index] == '-' || userName[index] == '_'))
			{
				isValid = true;
			}
			else
			{
				isValid = false;
			}
		}

		return isValid;
	}

	bool isValidEmail(const String email) const
	{
		bool isValid = false;
		for (size_t index = 0; index < email.getCapacity() - 7; ++index)
		{
			if ('a' <= email[index] && email[index] <= 'z')
			{
				isValid = true;
			}
			else
			{
				isValid = false;
			}
		}
		

		return isValid;
	}

	bool isValidPassword(const String password) const
	{

	}
};

#endif