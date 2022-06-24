#include "Users.h"

void Admin::setEmail(const String email)
{
	this->email = email;
}

void Admin::setDepartment(const Department department)
{
	this->department = department;
}

Admin::Admin()
{
	setEmail(String());
	setDepartment(Department::UNDEFINED);
}
	
Admin::Admin(const String email, const Department department)
{
	setEmail(email);
	setDepartment(department);
}

String Admin::getEmail() const
{
	return email;
}
	
Department Admin::getDepartment() const
{
	return department;
}