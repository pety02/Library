#pragma warning(disable : 4996)
#include "Dates.h"

void DateTime::setHours(unsigned int hours)
{
	if (this != nullptr)
	{
		this->hours = (0 <= hours && hours <= 23) ? hours : throw std::invalid_argument("Invalid hours!");
		return;
	}
	
	throw std::runtime_error("The DateTime is null pointer. Hours can not be changed!");
}

void DateTime::setMinutes(unsigned int minutes)
{
	if (this != nullptr)
	{
		this->minutes = (0 <= minutes && minutes <= 59) ? minutes : throw std::invalid_argument("Invalid minutes!");
		return;
	}
	
	throw std::runtime_error("The DateTime is null pointer. Minutes can not be changed!");
}

void DateTime::setSeconds(unsigned int seconds)
{
	if (this != nullptr)
	{
		this->seconds = (0 <= seconds && seconds <= 59) ? seconds : throw std::invalid_argument("Invalid seconds!");
		return;
	}
	
	throw std::runtime_error("The DateTime is null pointer. Seconds can not be changed!");
}

DateTime::DateTime()
{
	try
	{
		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);
		setYear(1900 + now->tm_year);
		setMonth(1 + now->tm_mon);
		setDay(now->tm_mday);
		setHours(now->tm_hour);

		if (0 <= now->tm_sec && now->tm_sec <= 59)
		{
			setMinutes(now->tm_min);
			setSeconds(now->tm_sec);
		}
		else if (now->tm_sec == 60)
		{
			setMinutes(now->tm_min + 1);
			setSeconds(0);
		}
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day)
{
	try
	{
		setYear(year);
		setMonth(month);
		setDay(day);
		setHours(0);
		setMinutes(0);
		setSeconds(0);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day,
	unsigned int hours, unsigned int minutes, unsigned int seconds)
{
	try
	{
		setYear(year);
		setMonth(month);
		setDay(day);
		setHours(hours);
		setMinutes(minutes);
		setSeconds(seconds);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

unsigned int DateTime::getHours() const
{
	if (this != nullptr)
	{
		return hours;
	}

	throw std::runtime_error("The DateTime is null pointer. Hours cannot be readed!");
}

unsigned int DateTime::getMinutes() const
{
	if (this != nullptr)
	{
		return minutes;
	}

	throw std::runtime_error("The DateTime is null pointer. Minutes cannot be readed!");
}

unsigned int DateTime::getSeconds() const
{
	if (this != nullptr)
	{
		return seconds;
	}

	throw std::runtime_error("The DateTime is null pointer. Seconds cannot be readed!");
}

bool DateTime::operator>(const DateTime& other) const
{
	try
	{
		if (this != nullptr)
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
		else
		{
			throw std::runtime_error("The DateTime is null pointer. Operator > (const DateTime& other) cannot be applied!");
		}
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

bool DateTime::operator>=(const DateTime& other) const
{
	if (this != nullptr)
	{
		if (*this == other || *this > other)
		{
			return true;
		}

		return false;
	}
	
	throw new std::runtime_error("The DateTime is null pointer. Operator >= (const DateTime& other) cannot be applied!");
}

bool DateTime::operator<(const DateTime& other) const
{
	try
	{
		return !operator>=(other);
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error("The DateTime is null pointer. Operator < (const DateTime& other) cannot be applied!");
	}
}

bool DateTime::operator<=(const DateTime& other) const
{
	try
	{
		return !operator>(other);
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error("The DateTime is null pointer. Operator <= (const DateTime& other) cannot be applied!");
	}
}

bool DateTime::operator==(const DateTime& other) const
{
	if (this != nullptr)
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
	
	throw std::runtime_error("The DateTime is null pointer. Operator == (const DateTime& other) cannot be applied!");
}

bool DateTime::operator!=(const DateTime& other) const
{
	try
	{
		return !operator==(other);
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error("The DateTime is null pointer. Operator != (const DateTime& other) cannot be applied!");
	}
}

int DateTime::operator-(const DateTime& other)
{
	if (this != nullptr)
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
	
	throw std::runtime_error("The DateTime is null pointer. Operator - (const DateTime& other) cannot be applied!");
}