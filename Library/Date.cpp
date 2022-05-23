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

void Date::setYear(unsigned int year)
{
	if (this != nullptr)
	{
		this->year = (1900 <= year && year <= 2022) ? year : throw std::invalid_argument("Invalid year!");
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Year can not be changed!");
	}
}
void Date::setMonth(unsigned int month)
{
	if (this != nullptr)
	{
		this->month = (1 <= month && month <= 12) ? month : throw std::invalid_argument("Invalid month!");
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Month can not be changed!");
	}
}
void Date::setDay(unsigned int day)
{
	if (this != nullptr)
	{
		switch (month)
		{
		case 2:
			if((year % 4 == 0 && year % 100 == 0) || (year % 4 == 0 && year % 100 != 0))
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
	else
	{
		throw std::runtime_error("The Date is null pointer. Day can not be changed!");
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

bool Date::operator>(const Date& other) const
{
	if (this != nullptr)
	{
		if ((year > other.year) || (year == other.year && month > other.month) || (month == other.month && day > other.day)) 
		{
			return true;
		}

		return false;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator > (const Date& other) can not be applied!");
	}
}

bool Date::operator>=(const Date& other) const
{
	if (this != nullptr)
	{
		if (*this == other || *this > other) 
		{
			return true;
		}

		return false;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator >= (const Date& other) can not be applied!");
	}
}

bool Date::operator<(const Date& other) const
{
	if (this != nullptr)
	{
		if (*this <= other && *this != other) 
		{
			return true;
		}

		return false;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator < (const Date& other) can not be applied!");
	}
}

bool Date::operator<=(const Date& other) const
{
	if (this != nullptr)
	{
		if (*this == other || *this < other) 
		{
			return true;
		}

		return false;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator <= (const Date& other) can not be applied!");
	}
}

bool Date::operator==(const Date& other) const
{
	if (this != nullptr)
	{
		if (year == other.year && month == other.month && day == other.day) 
		{
			return true;
		}

		return false;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator == (const Date& other) can not be applied!");
	}
}

bool Date::operator!=(const Date& other) const
{
	if (this != nullptr)
	{
		if (*this != other) 
		{
			return true;
		}

		return false;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator != (const Date& other) can not be applied!");
	}
}

Date& Date::operator++()
{
	if (this != nullptr)
	{
		*this += 1;
		return *this;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator ++ () can not be applied!");
	}
}

Date Date::operator++(int)
{
	if (this != nullptr)
	{
		*this += 1;
		Date nextDate(*this);
		return nextDate;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator ++ (int) can not be applied!");
	}
}

Date Date::operator--()
{
	if (this != nullptr)
	{
		*this -= 1;
		return *this;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator -- () can not be applied!");
	}
}

Date Date::operator--(int)
{
	if (this != nullptr)
	{
		*this -= 1;
		Date previousDate(*this);
		return previousDate;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator -- (int) can not be applied!");
	}
}

Date Date::operator+(int days) const
{
	if (this != nullptr)
	{
		Date increasedDate(*this);
		increasedDate += days;
		return increasedDate;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator + (int days) can not be applied!");
	}
}

Date Date::operator-(int days) const
{
	if (this != nullptr)
	{
		Date decreasedDate(*this);
		decreasedDate -= days;
		return decreasedDate;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator - (int days) can not be applied!");
	}
}

Date& Date::operator+=(int days)
{
	if (this != nullptr)
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
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator += (int days) can not be applied!");
	}
}

Date& Date::operator-=(int days)
{
	if (this != nullptr)
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
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator -= (int days) can not be applied!");
	}
}

int Date::operator-(const Date& other)
{
	if (this != nullptr)
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
	else
	{
		throw std::runtime_error("The Date is null pointer. Operator - (const Date& other) can not be applied!");
	}
}

unsigned int Date::getYear() const
{
	if (this != nullptr)
	{
		return year;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Year can not be readed!");
	}
}
unsigned int Date::getMonth() const
{
	if (this != nullptr)
	{
		return month;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Month can not be readed!");
	}
}
unsigned int Date::getDay() const
{
	if (this != nullptr)
	{
		return day;
	}
	else
	{
		throw std::runtime_error("The Date is null pointer. Day can not be readed!");
	}
}