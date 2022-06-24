#pragma once
#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <fstream>
#include "Users.h"
#include "UserValidator.h"

/// <summary>
/// 
/// </summary>
enum class UserRole
{
	ADMIN,
	READER
};

/// <summary>
/// 
/// </summary>
class UserController
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="user"></param>
	static void saveUser(const User user);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	/// <returns></returns>
	static User& getUser(const String username, const String password);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	static void updateUser(const String username, const String password);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	static void deleteUser(const String username, const String password);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	/// <param name="reEnteredPassword"></param>
	static void registerUser(const String username, const String password, const String reEnteredPassword);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	/// <returns></returns>
	static bool login(const String username, const String password);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	static bool logout();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="option"></param>
	/// <param name="optionValue"></param>
	/// <returns></returns>
	static User* findUser(const String option, const String optionValue);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	/// <param name="role"></param>
	static void addUser(const String username, const String password, const UserRole role);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="user"></param>
	/// <param name="newPassword"></param>
	static void changePassword(const User& user, const String newPassword);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="item"></param>
	/// <param name="user"></param>
	static void borrowLibraryItem(const LibraryItem& item, const User& user);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="item"></param>
	/// <param name="user"></param>
	static void returnLibraryItem(const LibraryItem& item, const User& user);
};

#endif