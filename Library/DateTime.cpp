#include "Dates.h"

void DateTime::setHours(unsigned int hours)
{
	this->hours = (0 <= hours && hours <= 23) ? hours : throw std::invalid_argument("Invalid hours!");
}

void DateTime::setMinutes(unsigned int minutes)
{
	this->minutes = (0 <= minutes && minutes <= 59) ? minutes : throw std::invalid_argument("Invalid minutes!");
}

void DateTime::setSeconds(unsigned int seconds)
{
	this->seconds = (0 <= seconds && seconds <= 59) ? seconds : throw std::invalid_argument("Invalid seconds!");
}

DateTime::DateTime() : Date()
{
	try
	{
		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);

		if (0 <= now->tm_min && now->tm_min <= 59)
		{
			setHours(now->tm_hour);
			if (0 <= now->tm_sec && now->tm_sec <= 59)
			{
				setMinutes(now->tm_min);
				setSeconds(now->tm_sec);
			}
			else
			{
				setMinutes(now->tm_min + 1);
				setSeconds(0);
			}
		}
		else
		{
			setHours(now->tm_hour + 1);
			if (0 <= now->tm_sec && now->tm_sec <= 59)
			{
				setMinutes(now->tm_min);
				setSeconds(now->tm_sec);
			}
			else
			{
				setMinutes(now->tm_min + 1);
				setSeconds(0);
			}
		}
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		ExceptionLogger::logException("exceptions.txt", "Invalid Argument Exception", invalidArgumentEx.what());
	}
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day) : Date(year, month, day)
{
	try
	{
		setHours(0);
		setMinutes(0);
		setSeconds(0);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		ExceptionLogger::logException("exceptions.txt", "Invalid Argument Exception", invalidArgumentEx.what());
	}
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day,
	unsigned int hours, unsigned int minutes, unsigned int seconds) : Date(year, month, day)
{
	try
	{
		setHours(hours);
		setMinutes(minutes);
		setSeconds(seconds);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		ExceptionLogger::logException("exceptions.txt", "Invalid Argument Exception", invalidArgumentEx.what());
	}
}

DateTime::~DateTime()
{

}

const unsigned int DateTime::getHours() const
{
	return hours;
}

const unsigned int DateTime::getMinutes() const
{
	return minutes;
}

const unsigned int DateTime::getSeconds() const
{
	return seconds;
}

bool DateTime::operator>(const DateTime& other) const
{
	try
	{
		if ((getYear() > other.getYear())
			|| (getYear() == other.getYear() && getMonth() > other.getMonth())
			|| (getMonth() == other.getMonth() && getDay() > other.getDay())
			|| (getDay() == other.getDay() && getHours() > other.getHours())
			|| (getHours() == other.getHours() && getMinutes() > other.getMinutes())
			|| (getMinutes() == other.getMinutes() && getSeconds() > other.getSeconds()))
		{
			return true;
		}

		return false;
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		ExceptionLogger::logException("exceptions.txt", "Invalid Argument Exception", invalidArgumentEx.what());
	}
}

bool DateTime::operator>=(const DateTime& other) const
{
	if (*this == other || *this > other)
	{
		return true;
	}

	return false;
}

bool DateTime::operator<(const DateTime& other) const
{
	return !operator>=(other);
}

bool DateTime::operator<=(const DateTime& other) const
{
	return !operator>(other);
}

bool DateTime::operator==(const DateTime& other) const
{
	if (getYear() == other.getYear()
		&& getMonth() == other.getMonth()
		&& getDay() == other.getDay()
		&& getHours() == other.getHours()
		&& getMinutes() == other.getMinutes()
		&& getSeconds() == other.getSeconds())
	{
		return true;
	}

	return false;
}

bool DateTime::operator!=(const DateTime& other) const
{
	return !operator==(other);
}

int DateTime::operator-(const DateTime& other)
{
	if (*this < other)
	{
		int daysBetweenTwoDates = 0;
		DateTime dateBefore(*this);
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
		DateTime dateBefore(other);
		while (dateBefore != *this)
		{
			dateBefore += 1;
			daysBetweenTwoDates++;
		}
		return daysBetweenTwoDates;
	}
	return 0;
}