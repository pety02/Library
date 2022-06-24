#include "UserController.h"

void UserController::saveUser(const User user)
{
	std::ofstream out("Users.txt", std::ios::out, std::ios::app);
	if (out.is_open())
	{
		out << user.getUsername().getBuffer() << " | " << user.getPassword().getBuffer() << " | " 
			<< user.getRegisterDate().getDay() << "/" << user.getRegisterDate().getMonth() << "/" 
			<< user.getRegisterDate().getYear() << std::endl;
		out.close();
	}
}

User& UserController::getUser(const String username, const String password)
{
	std::ifstream in("Users.txt", std::ios::in, std::ios::app);
	if (in.is_open())
	{
		while (!in.eof())
		{
			// check wheather in Users.txt there are username 
			// and password and return the user with these credentials.
		}
		in.close();
	}
}

void UserController::updateUser(const String username, const String password)
{
	std::ifstream in("Users.txt", std::ios::in, std::ios::app);
	if (in.is_open())
	{
		while (!in.eof())
		{
			// check wheather in Users.txt there are username 
			// and password and update the user with these credentials.
		}
		in.close();
	}
}

void UserController::deleteUser(const String username, const String password)
{
	std::ifstream in("Users.txt", std::ios::in, std::ios::app);
	if (in.is_open())
	{
		while (!in.eof())
		{
			// check wheather in Users.txt there are username 
			// and password and delete the user with these credentials.
		}
		in.close();
	}
}

void UserController::registerUser(const String username, const String password, const String reEnteredPassword)
{
	if (UserValidator::hasUserWithCredentials(username, password))
	{
		throw std::invalid_argument("Invalid user credentials!");
	}

	UserController::saveUser(Reader(username, password));
}

bool UserController::login(const String username, const String password)
{
	if (UserValidator::hasUserWithCredentials(username, password))
	{
		User* currentUser = new Reader(username, password);
		std::cout << "Welcome, " << currentUser->getUsername()  << "!";
		return true;
	}

	throw std::invalid_argument("Invalid user credentials!");
}

bool UserController::logout()
{

}

User* UserController::findUser(const String option, const String optionValue)
{

}

void UserController::addUser(const String username, const String password, const UserRole role)
{

}

void UserController::changePassword(const User& user, const String newPassword)
{

}

void UserController::borrowLibraryItem(const LibraryItem& item, const User& user)
{

}

void UserController::returnLibraryItem(const LibraryItem& item, const User& user)
{

}