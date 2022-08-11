#pragma once
#ifndef USERS_H
#define USERS_H

#include "String.h"
#include "Dates.h"
#include "LibraryItems.h"

/// <summary>
/// 
/// </summary>
class User
{
protected:
	/// <summary>
	/// 
	/// </summary>
	String username;

	/// <summary>
	/// 
	/// </summary>
	String password;

	/// <summary>
	/// 
	/// </summary>
	Date registerDate;

	/// <summary>
	/// 
	/// </summary>
	DateTime lastLoginDateTime;

	/// <summary>
	/// 
	/// </summary>
	bool isLoggedIn;

	/// <summary>
	/// 
	/// </summary>
	User();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	User(const String username, const String password);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	/// <param name="registerDate"></param>
	User(const String username, const String password, const Date registerDate);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	void setUsername(const String username);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="password"></param>
	void setPassword(const String password);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="registerDate"></param>
	void setRegisterDate(const Date registerDate);

	/// <summary>
	/// 
	/// </summary>
	void setLastLoginDateTime();

public:
	/// <summary>
	/// 
	/// </summary>
	void login();

	/// <summary>
	/// 
	/// </summary>
	void logout();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String getUsername() const;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String getPassword() const;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Date getRegisterDate() const;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	DateTime getLastLoginDateTime() const;
};

class Reader final : public User
{
private:
	/// <summary>
	/// 
	/// </summary>
	LibraryItem** items;
	
	/// <summary>
	/// 
	/// </summary>
	Date* borrowingsDates;
	
	/// <summary>
	/// 
	/// </summary>
	Date* returningsDates;
	
	/// <summary>
	/// 
	/// </summary>
	size_t borrowingCapacity;
	
	/// <summary>
	/// 
	/// </summary>
	size_t borrowingLastIndex;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="items"></param>
	void setItems(LibraryItem** items);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="borrowingsDates"></param>
	void setBorrowingsDates(const Date* borrowingsDates);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="returningsDates"></param>
	void setReturningsDates(const Date* returningsDates);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="borrowingsCapacity"></param>
	void setBorrowingCapacity(const size_t borrowingsCapacity);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="borrowingsLastIndex"></param>
	void setBorrowingLastIndex(const size_t borrowingsLastIndex);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	void copy(const Reader& other);
	
	/// <summary>
	/// 
	/// </summary>
	void destroy();
public:
	/// <summary>
	/// 
	/// </summary>
	Reader();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	Reader(const String username, const String password);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="username"></param>
	/// <param name="password"></param>
	/// <param name="items"></param>
	/// <param name="borrowingsDates"></param>
	/// <param name="returningsDates"></param>
	/// <param name="borrowingsCapacity"></param>
	/// <param name="borrowingsLastIndex"></param>
	Reader(const String username, const String password, LibraryItem** items, const Date* borrowingsDates,
		const Date* returningsDates, const size_t borrowingsCapacity, const size_t borrowingsLastIndex);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	Reader(const Reader& other);
	
	/// <summary>
	/// 
	/// </summary>
	~Reader();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Reader operator=(const Reader& other);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LibraryItem** getItems() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Date* getBorrowingsDates() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Date* getReturningsDates() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	size_t getBorrowingsCapacity() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	size_t getBorrowingLastIndex() const;
};

/// <summary>
/// 
/// </summary>
enum class Department
{
	UNDEFINED,

	BOSS,
	LIBRARIAN,
	BORROW_MANAGER,
	SECURITY,

	DEPARTMENTS_COUNT
};

/// <summary>
/// 
/// </summary>
class Admin final : public User
{
private:
	/// <summary>
	/// 
	/// </summary>
	String email;
	
	/// <summary>
	/// 
	/// </summary>
	Department department;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="email"></param>
	void setEmail(const String email);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="department"></param>
	void setDepartment(const Department department);

public:
	/// <summary>
	/// 
	/// </summary>
	Admin();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="email"></param>
	/// <param name="department"></param>
	Admin(const String email, const Department department);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String getEmail() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Department getDepartment() const;
};

#endif