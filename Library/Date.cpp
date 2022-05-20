#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include "Dates.h"

unsigned int Date::getDaysInMonth()
{
	switch (month)
	{
	case 2:
		if ((year % 4 == 0 && year % 100 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			return 29;
		}
		else
		{
			return 28;
		}
	case 4:
	case 6:
	case 9:
	case 11: return 30;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: return 31;

	default: throw std::invalid_argument("Invalid days in month count!"); break;
	}
}

void Date::setYear(unsigned int year)
{
	this->year = (1900 <= year && year <= 2022) ? year : throw std::invalid_argument("Invalid year!");
}
void Date::setMonth(unsigned int month)
{
	this->month = (1 <= month && month <= 12) ? month : throw std::invalid_argument("Invalid month!");
}
void Date::setDay(unsigned int day)
{
	switch (month)
	{
	case 2: 
		if ((year % 4 == 0 && year % 100 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			this->day = (1 <= day && day <= 29) ? day : throw std::invalid_argument("Invalid day!"); break;
		}
		else
		{
			this->day = (1 <= day && day <= 28) ? day : throw std::invalid_argument("Invalid day!"); break;
		}
	case 4:
	case 6:
	case 9:
	case 11: this->day = (1 <= day && day <= 30) ? day : throw std::invalid_argument("Invalid day!"); break;
	case 1:
	case 3:
	case 5: 
	case 7:
	case 8:
	case 10:
	case 12: this->day = (1 <= day && day <= 31) ? day : throw std::invalid_argument("Invalid day!"); break;

	default: throw std::invalid_argument("Invalid day!"); break;
	}
}

Date::Date()
{
	std::time_t t = std::time(0);   
	std::tm* now = std::localtime(&t);
	setYear(1900 + now->tm_year);
	setMonth(1 + now->tm_mon);
	setDay(now->tm_mday);
}
Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

bool Date::operator>(const Date& d) const
{
	if (year > d.year) {
		return true;
	}
	else if (year == d.year) {
		if (month > d.month) {
			return true;
		}
		else if (month == d.month) {
			if (day > d.day) {
				return true;
			}
		}
	}
	return false;
}

bool Date::operator>=(const Date& d) const
{
	if ((*this == d) || (*this > d)) {
		return true;
	}
	return false;
}

bool Date::operator<(const Date& d) const
{
	if ((!(*this > d) && !(*this == d))) {
		return true;
	}
	return false;
}

bool Date::operator<=(const Date& d) const
{
	if ((*this == d) || (*this < d)) {
		return true;
	}
	return false;
}

bool Date::operator==(const Date& d) const
{
	if (year == d.year
		&& month == d.month && day == d.day) {
		return true;
	}
	return false;
}

bool Date::operator!=(const Date& d) const
{
	if (!(*this == d)) {
		return true;
	}
	return false;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date res(*this);
	*this += 1;
	return res;
}

Date Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date res(*this);
	*this -= 1;
	return res;
}

Date Date::operator+(int day) const
{
	Date res(*this);
	res += day;
	return res;
}

Date Date::operator-(int day) const
{
	Date res(*this);
	res -= day;
	return res;
}

Date& Date::operator+=(int day)
{
	this->day += day;
	while (this->day > getDaysInMonth()) {
		this->day -= getDaysInMonth();
		month++;
		if (month == 13) {
			year++;
			month = 1;
		}
	}
	return *this;
}

Date& Date::operator-=(int day)
{
	this->day -= day;
	while (this->day <= 0) {
		month--;
		if (month == 0) {
			year--;
			month = 12;
		}
		this->day += getDaysInMonth();
	}
	return *this;
}

int Date::operator-(const Date& d)
{
	if (*this < d) {
		int cnt = 0;
		Date res(*this);
		while (1) {
			res += 1;
			cnt++;
			if (res == d) {
				return cnt;
			}
		}
	}
	else if (*this > d) {
		int cnt = 0;
		Date ret(d);
		while (1) {
			ret += 1;
			cnt++;
			if (ret == *this) {
				return cnt;
			}
		}
	}
	return 0;
}

unsigned int Date::getYear() const
{
	return year;
}
unsigned int Date::getMonth() const
{
	return month;
}
unsigned int Date::getDay() const
{
	return day;
}