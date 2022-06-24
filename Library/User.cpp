#include "Users.h"
#include "UserValidator.h"

User::User()
{
	setUsername(String());
	setPassword(String());
	setRegisterDate(Date());
	setLastLoginDateTime();
	isLoggedIn = false;
}

User::User(const String username, const String password)
{
	setUsername(username);
	setPassword(password);
	setRegisterDate(Date());
	setLastLoginDateTime();
	login();
}

User::User(const String username, const String password, const Date registerDate)
{
	setUsername(username);
	setPassword(password);
	setRegisterDate(registerDate);
	setLastLoginDateTime();
	isLoggedIn = false;
}

void User::setUsername(const String username)
{
	if (this != nullptr)
	{
		if (UserValidator::isValidUsername(username))
		{
			this->username = username;
		}

		throw std::invalid_argument("Invalid username!");
	}

	throw std::runtime_error("User is null pointer!");
}

void User::setPassword(const String password)
{
	if (this != nullptr)
	{
		if (UserValidator::isValidPassword(password))
		{
			this->password = password;
		}

		throw std::invalid_argument("Invalid password!");
	}

	throw std::runtime_error("User is null pointer!");
}

void User::setRegisterDate(const Date registerDate)
{
	if (this != nullptr)
	{
		if (Date(1,1,1970) <= registerDate && registerDate <= Date())
		{
			this->registerDate = registerDate;
		}

		throw std::invalid_argument("Invalid registerDate!");
	}

	throw std::runtime_error("User is null pointer!");
}

void User::setLastLoginDateTime()
{
	if (this != nullptr)
	{
		if (registerDate <= Date() && lastLoginDateTime <= DateTime())
		{
			this->lastLoginDateTime = DateTime();
		}

		throw std::invalid_argument("Invalid last login date time!");
	}

	throw std::runtime_error("User is null pointer!");
}

void User::login()
{
	if (this != nullptr)
	{
		isLoggedIn = true;
	}

	throw std::runtime_error("User is null pointer!");
}

void User::logout()
{
	if (this != nullptr)
	{
		isLoggedIn = false;
	}

	throw std::runtime_error("User is null pointer!");
}

String User::getUsername() const
{
	if (this != nullptr)
	{
		return username;
	}

	throw std::runtime_error("User is null pointer!");
}

String User::getPassword() const
{
	if (this != nullptr)
	{
		return password;
	}

	throw std::runtime_error("User is null pointer!");
}

Date User::getRegisterDate() const
{
	if (this != nullptr)
	{
		return registerDate;
	}

	throw std::runtime_error("User is null pointer!");
}

DateTime User::getLastLoginDateTime() const
{
	if (this != nullptr)
	{
		return lastLoginDateTime;
	}

	throw std::runtime_error("User is null pointer!");
}