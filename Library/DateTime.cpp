#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
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

DateTime::DateTime()
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
	else
	{
		throw std::invalid_argument("Invalid seconds!");
	}
}
DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day)
{
	setYear(year);
	setMonth(month);
	setDay(day);
	setHours(0);
	setMinutes(0);
	setSeconds(0);
}
DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day,
	unsigned int hours, unsigned int minutes, unsigned int seconds)
{
	setYear(year);
	setMonth(month);
	setDay(day);
	setHours(hours);
	setMinutes(minutes);
	setSeconds(seconds);
}

bool DateTime::operator>(const DateTime& d) const
{
	if (getYear() > d.getYear()) {
		return true;
	}
	else if (getYear() == d.getYear()) {
		if (getMonth() > d.getMonth()) {
			return true;
		}
		else if (getMonth() == d.getMonth()) {
			if (getDay() > d.getDay()) {
				return true;
			}
			else if (getDay() == d.getDay())
			{
				if (getHours() > d.getHours()) {
					return true;
				}
				else if (getHours() == d.getHours()) {
					if (getMinutes() > d.getMinutes())
					{
						return true;
					}
					else if (getMinutes() == d.getMinutes()) {
						if (getSeconds() > d.getSeconds())
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool DateTime::operator>=(const DateTime& d) const
{
	if ((*this == d) || (*this > d)) {
		return true;
	}
	return false;
}

bool DateTime::operator<(const DateTime& d) const
{
	if ((!(*this > d) && !(*this == d))) {
		return true;
	}
	return false;
}

bool DateTime::operator<=(const DateTime& d) const
{
	if ((*this == d) || (*this < d)) {
		return true;
	}
	return false;
}

bool DateTime::operator==(const DateTime& d) const
{
	if (getYear() == d.getYear()
		&& getMonth() == d.getMonth()
		&& getDay() == d.getDay()
		&& getHours() == d.getHours()
		&& getMinutes() == d.getMinutes()
		&& getSeconds() == d.getSeconds()) {
		return true;
	}
	return false;
}

bool DateTime::operator!=(const DateTime& d) const
{
	if (!(*this == d)) {
		return true;
	}
	return false;
}

int DateTime::operator-(const DateTime& d)
{
	if (*this < d) {
		int cnt = 0;
		DateTime res(*this);
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
		DateTime ret(d);
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

unsigned int DateTime::getHours() const
{
	return hours;
}
unsigned int DateTime::getMinutes() const
{
	return minutes;
}
unsigned int DateTime::getSeconds() const
{
	return seconds;
}