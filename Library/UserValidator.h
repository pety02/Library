#pragma once
#ifndef USERVALIDATOR_H
#define USERVALIDATOR_H

#include "String.h"

/// <summary>
/// 
/// </summary>
class UserValidator
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="stream"></param>
	/// <returns></returns>
	static size_t countCharactersInLine(const std::fstream& stream)
	{
		size_t counter = 0;
		if (stream.is_open())
		{
			while (!stream.eof())
			{
				++counter;
			}
		}

		return counter;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="userName"></param>
	/// <returns></returns>
	static bool isValidUsername(const String userName) 
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

	/// <summary>
	/// 
	/// </summary>
	/// <param name="password"></param>
	/// <returns></returns>
	static bool isValidPassword(const String password) 
	{
		bool isValid = false;
		for (size_t index = 0; index < password.getCapacity() - 8; ++index)
		{
			if (('a' <= password[index] && password[index] <= 'z')
				|| password[index] == '.' || password[index] == '!' 
				|| password[index] == '_'|| password[index] == '-' 
				|| ('0' <= password[index] && password[index] <= '9'))
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

	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	/// <returns></returns>
	static bool hasUserWithCredentials(const String username, const String password)
	{
		std::fstream in("Users.txt", std::ios::in);
		String usernameFromDB;
		String passwordFromDB;
		String fullInputLine;
		String currentCredential;

		bool hasUser = false;

		if (in.is_open())
		{
			size_t counter = countCharactersInLine(in);
			while (!in.eof())
			{
				in.getline(fullInputLine.getBuffer(), counter);
				currentCredential = strtok(fullInputLine.getBuffer(), " |//");
				usernameFromDB = currentCredential;
				while (currentCredential != NULL)
				{
					currentCredential = strtok(NULL, " ,.-");
					passwordFromDB = currentCredential;
					break;
				}

				if (usernameFromDB == username && passwordFromDB == password)
				{
					hasUser = true;
				}
				else
				{
					hasUser = false;
				}
			}

			in.close();
			return hasUser;
		}

		throw new std::runtime_error("Cannot open DataBase!");
	}
};

#endif