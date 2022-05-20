#pragma once
#ifndef USERS_H
#define USERS_H

#include "String.h"
#include "Dates.h"

class User
{
protected:
	String username;
	String password;
	Date registerDate;
	DateTime lastLoginDateTime;

	User();
	User(const String username, const String password);

	void setUsername(const String username);
	void setPassword(const String password);
	void setRegisterDate(Date registerDate);
	void setLastLoginDateTime(DateTime lastLoginDateTime);

	friend class UserFactory;

public:
	String getUsername() const;
	String getPassword() const;
	Date getRegisterDate() const;
	DateTime getLastLoginDateTime() const;
};


#endif