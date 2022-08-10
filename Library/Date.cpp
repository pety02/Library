#pragma warning(disable : 4996)
#include "Dates.h"

unsigned int Date::getDaysInMonth()
{
	switch (month)
	{
	case 2: return ((year % 4 == 0 && year % 100 == 0) || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
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

	default: throw std::exception("Invalid days in month count!");
	}
}

void Date::setYear(const unsigned int& year)
{
	this->year = (1900 <= year && year <= 2022) ? year : throw std::invalid_argument("Invalid year!");
}

void Date::setMonth(const unsigned int& month)
{
	this->month = (1 <= month && month <= 12) ? month : throw std::invalid_argument("Invalid month!");
}

void Date::setDay(const unsigned int& day)
{
	this->day = (1 <= day && day <= getDaysInMonth()) ? day : throw std::invalid_argument("Invalid day!");
}

Date::Date()
{
	try
	{
		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);

		setYear(1900 + now->tm_year);
		setMonth(1 + now->tm_mon);
		setDay(now->tm_mday);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		ExceptionLogger::logException("exceptions.txt", 
			"Invalid Argument Exception", invalidArgumentEx.what());
	}
	catch (const std::exception& ex)
	{
		ExceptionLogger::logException(DateTime(), "exceptions.txt",
			"Exception", ex.what());
	}
	catch (...)
	{
		try
		{
			std::exception_ptr eptr = std::current_exception();
			std::rethrow_exception(eptr);
		}
		catch (const std::exception& ex)
		{
			ExceptionLogger::logException(DateTime(), "exceptions.txt",
				"Unknown Exception", ex.what());
		}
	}
}

Date::Date(const unsigned int& year, const unsigned int& month, const unsigned int& day)
{
	try
	{
		setYear(year);
		setMonth(month);
		setDay(day);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		ExceptionLogger::logException("exceptions.txt",
			"Invalid Argument Exception", invalidArgumentEx.what());
	}
	catch (const std::exception& ex)
	{
		ExceptionLogger::logException(DateTime(), "exceptions.txt",
			"Exception", ex.what());
	}
	catch (...)
	{
		try
		{
			std::exception_ptr eptr = std::current_exception();
			std::rethrow_exception(eptr);
		}
		catch (const std::exception& ex)
		{
			ExceptionLogger::logException(DateTime(), "exceptions.txt",
				"Unknown Exception", ex.what());
		}
	}
}

const unsigned int Date::getYear() const
{
	return year;
}

const unsigned int Date::getMonth() const
{
	return month;
}

const unsigned int Date::getDay() const
{
	return day;
}

const bool Date::operator>(const Date& other) const
{
	if ((year > other.year) || (year == other.year && month > other.month) || (month == other.month && day > other.day))
	{
		return true;
	}

	return false;
}

const bool Date::operator>=(const Date& other) const
{
	if (*this == other || *this > other)
	{
		return true;
	}

	return false;
}

const bool Date::operator<(const Date& other) const
{
	if (*this <= other && *this != other)
	{
		return true;
	}

	return false;
}

const bool Date::operator<=(const Date& other) const
{
	if (*this == other || *this < other)
	{
		return true;
	}

	return false;
}

const bool Date::operator==(const Date& other) const
{
	if (year == other.year && month == other.month && day == other.day)
	{
		return true;
	}

	return false;
}

const bool Date::operator!=(const Date& other) const
{
	if (*this != other)
	{
		return true;
	}

	return false;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date& Date::operator++(const int)
{
	*this += 1;
	Date nextDate(*this);
	return nextDate;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date& Date::operator--(const int)
{
	*this -= 1;
	Date previousDate(*this);
	return previousDate;
}

const Date& Date::operator+(const int& days) const
{
	Date increasedDate(*this);
	increasedDate += days;
	return increasedDate;
}

const Date& Date::operator-(const int& days) const
{
	Date decreasedDate(*this);
	decreasedDate -= days;
	return decreasedDate;
}

Date& Date::operator+=(const int& days)
{
	this->day += days;

	while (this->day > getDaysInMonth())
	{
		this->day -= getDaysInMonth();
		month++;
		if (month == 13)
		{
			year++;
			month = 1;
		}
	}
	return *this;
}

Date& Date::operator-=(const int& days)
{
	this->day -= days;
	while (this->day <= 0)
	{
		month--;
		if (month == 0)
		{
			year--;
			month = 12;
		}
		this->day += getDaysInMonth();
	}
	return *this;
}

int Date::operator-(const Date& other)
{
	if (*this < other)
	{
		int daysBetweenTwoDates = 0;
		Date dateBefore(*this);
		while (dateBefore != other)
		{
			dateBefore += 1;
			daysBetweenTwoDates++;
		}

		return daysBetweenTwoDates;
	}
	else if (*this > other)
	{
		int daysBetweenTwoDates = 0;
		Date dateBefore(other);
		while (dateBefore != *this)
		{
			dateBefore += 1;
			daysBetweenTwoDates++;
		}

		return daysBetweenTwoDates;
	}

	return 0;
}