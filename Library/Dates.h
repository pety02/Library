#pragma once
#ifndef DATES_H
#define DATES_H

#include <iostream>
#include <ctime>

/// <summary>
/// <c>Date</c> is a class which describes a simple date object.
/// Every <c>Date</c> object is composed from year, month and day. 
/// </summary>
class Date
{
private:
	
	/// <summary>
	/// <value>
	/// A date field from <c>unsigned int</c> type which stores 
	/// the date year.
	/// </value>
	/// </summary>
	unsigned int year;
	
	/// <summary>
	/// <value>
	/// A date field from <c>unsigned int</c> type which stores
	/// the date month.
	/// </value>
	/// </summary>
	unsigned int month;
	
	/// <summary>
	/// <value>
	/// A date field from <c>unsigned int</c> type which stores 
	/// the date day.
	/// </value>
	/// </summary>
	unsigned int day;

	/// <summary>
	/// <c>getDaysInMonth()</c> is a method in <c>Date</c> class which 
	/// returns the number of days in a definite month.
	/// </summary>
	/// 
	/// <returns>
	/// <c>getDaysInMonth()</c> returns the number of days per a definite month.
	/// </returns>
	unsigned int getDaysInMonth();

protected:
	
	/// <summary>
	/// <c>setYear(const unsigned int year)</c> is a setter method in <c>Date</c> class.
	/// If year (parameter value of type <c>const unsigned int</c>) is valid,
	/// it sets year as a value of a date year field. But if year 
	/// (parameter value of type <c>const unsigned int</c>) is not valid, it 
	/// throws a <exception>std::invalid_argument</exception> exception
	/// with a custom message. If date which called this method is null 
	/// pointer, it throws a <exception>std::runtime_error</exception> exception
	/// with a custom message. This method does not return anything.
	/// </summary>
	/// 
	/// <param name="year">
	/// takes <c>const unsigned int</c> value and treats it as date year value.
	/// </param>
	void setYear(const unsigned int year);

	/// <summary>
	/// <c>setMonth(const unsigned int month)</c> is a setter method in <c>Date</c> class.
	/// If month (parameter value of type <c>const unsigned int</c>) is valid,
	/// it sets month as a value of a date month field. But if month 
	/// (parameter value of type <c>const unsigned int</c>) is not valid, it 
	/// throws a <exception>std::invalid_argument</exception> exception
	/// with a custom message. If date which called this method is null 
	/// pointer, it throws a <exception>std::runtime_error</exception> exception
	/// with a custom message. This method does not return anything.
	/// </summary>
	/// 
	/// <param name="month">
	/// takes <c>const unsigned int</c> value and treats it as date month value.
	/// </param>
	void setMonth(const unsigned int month);

	/// <summary>
	/// <c>setDay(const unsigned int year)</c> is a setter method in <c>Date</c> class.
	/// If day (parameter value of type <c>const unsigned int</c>) is valid,
	/// it sets day as a value of a date day field. But if day 
	/// (parameter value of type <c>const unsigned int</c>) is not valid, it 
	/// throws a <exception>std::invalid_argument</exception> exception
	/// with a custom message. If date which called this method is null 
	/// pointer, it throws a <exception>std::runtime_error</exception> exception
	/// with a custom message. This method does not return anything.
	/// </summary>
	/// 
	/// <param name="day">
	/// takes <c>const unsigned int</c> value and treats it as date day value.
	/// </param>
	void setDay(const unsigned int day);

public:
	
	/// <summary>
	/// <c>Date()</c> is a default constructor, so it initialize <c>Date</c> object fields 
	/// with default values, using the setter methods and the validation in it. If anything is wrong in 
	/// the runtime of the <c>Date</c> object creation, method catches <c>std::invalid_argument</c>,
	/// <c>std::runtime_error</c> and <c>std::exception</c>, then throws them upper in the method chain. But if 
	/// everything is fine, the constructor successfully initialize every <c>Date</c> object fields with 
	/// valid values.
	/// </summary>
	Date();
	
	/// <summary>
	/// <c>Date(const Date&amp; other)</c> is a copy constructor in <c>Date</c> class, so it initialize <c>Date</c> object 
	/// fields with pre-created <c>Date</c> object fields, using <c>copy(const Date&amp; other)</c> method. If anything is 
	/// wrong in the runtime of the <c>Date</c> object creation, method catches <c>std::invalid_argument</c>, <c>std::runtime_error</c> 
	/// and <c>std::exception</c>, then throws them upper in the method chain. But if everything is fine, the constructor successfully 
	/// initialize every <c>Date</c> object fields with valid values. 
	/// </summary>
	/// 
	/// <param name="year">
	/// takes <c>const unsigned int</c> value and treats it as year field value.
	/// </param>
	/// <param name="month">
	/// takes <c>const unsigned int</c> value and treats it as month field value.
	/// </param>
	/// <param name="day">
	/// takes <c>const unsigned int</c> value and treats it as day field value.
	/// </param>
	Date(const unsigned int year, const unsigned int month, const unsigned int day);

	/// <summary>
	/// <c>getYear()</c> is a method in <c>Date</c> class.
	/// </summary>
	/// 
	/// <returns>
	/// If this date is not a null pointer, the method returns the date year. But if this date is null pointer, 
	/// the methods throws a <exception>std::runtime_error</exception> with a custom message.
	/// </returns>
	unsigned int getYear() const;

	/// <summary>
	/// <c>getMonth()</c> is a method in <c>Date</c> class.
	/// </summary>
	/// 
	/// <returns>
	/// If this date is not a null pointer, the method returns the date month. But if this date is null pointer, 
	/// the methods throws a <exception>std::runtime_error</exception> with a custom message.
	/// </returns>
	unsigned int getMonth() const;

	/// <summary>
	/// <c>getDay()</c> is a method in <c>Date</c> class.
	/// </summary>
	/// 
	/// <returns>
	/// If this date is not a null pointer, the method returns the date year. But if this date is null pointer, 
	/// the methods throws a <exception>std::runtime_error</exception> with a custom message.
	/// </returns>
	unsigned int getDay() const;

	/// <summary>
	/// <c>operator>(const Date&amp; other)</c> is a pre-defined operator which returns wheather this <c>Date</c> object 
	/// is larger from other <c>Date</c> object. For bigger <c>Date</c> object, we accept the date that has bigger year, 
	/// bigger month or bigger day value (in other words the larger date is the date which is closer to today date).
	/// </summary>
	/// 
	/// <param name="other">
	/// takes <c>const Date&amp;</c> value and compares it with this <c>Date</c> object.
	/// </param>
	/// 
	/// <returns>
	/// The method returns  wheather this <c>Date</c> object is larger from other <c>Date</c> object.
	/// </returns>
	virtual bool operator>(const Date& other) const;
	
	/// <summary>
	/// <c>operator>=(const Date&amp; other)</c> is a pre-defined operator which returns wheather this <c>Date</c> object 
	/// is larger from or equal to other <c>Date</c> object. For bigger <c>Date</c> object, we accept the date that has 
	/// bigger year, bigger month or bigger day value (in other words the larger date is the date which is closer to today date).
	/// </summary>
	/// 
	/// <param name="other">
	/// takes <c>const Date&amp;</c> value and compares it with this <c>Date</c> object.
	/// </param>
	/// 
	/// <returns>
	/// The method returns wheather this <c>Date</c> object is larger from or equal to other <c>Date</c> object.
	/// </returns>
	virtual bool operator>=(const Date& other) const;
	
	/// <summary>
	/// <c>operator<(const Date&amp; other)</c> is a pre-defined operator which returns wheather this <c>Date</c> object 
	/// is smaller from other <c>Date</c> object. For smaller <c>Date</c> object, we accept the date that has smaller year, 
	/// smaller month or smaller day value (in other words the smaller date is the date which is further from today date).
	/// </summary>
	/// 
	/// <param name="other">
	/// takes <c>const Date&amp;</c> value and compares it with this <c>Date</c> object.
	/// </param>
	/// 
	/// <returns>
	/// The method returns wheather this <c>Date</c> object is smaller from other <c>Date</c> object.
	/// </returns>
	virtual bool operator<(const Date& other) const;
	
	/// <summary>
	/// <c>operator<=(const Date&amp; other)</c> is a pre-defined operator which returns  wheather this <c>Date</c> object 
	/// is smaller from or equal to other <c>Date</c> object. For smaller <c>Date</c> object, we accept the date that has 
	/// smaller year, smaller month or smaller day value (in other words the smaller date is the date which is further from 
	/// today date).
	/// </summary>
	/// 
	/// <param name="other">
	/// takes <c>const Date&amp;</c> value and compares it with this <c>Date</c> object.
	/// </param>
	/// 
	/// <returns>
	/// The method returns  wheather this <c>Date</c> object is smaller from or equal to other <c>Date</c> object.
	/// </returns>
	virtual bool operator<=(const Date& other) const;
	
	/// <summary>
	/// <c>operator==(const Date&amp; other)</c> is a pre-defined operator which returns wheather this <c>Date</c> object is
	/// equal to other <c>Date</c> object.
	/// </summary>
	/// 
	/// <param name="other">
	/// takes <c>const Date&amp;</c> value and compares it with this <c>Date</c> object.
	/// </param>
	/// 
	/// <returns>
	/// The method returns wheather this <c>Date</c> object is equal to other <c>Date</c> object.
	/// </returns>
	virtual bool operator==(const Date& other) const;
	
	/// <summary>
	/// <c>operator!=(const Date&amp; other)</c> is a pre-defined operator which returns wheather this <c>Date</c> object is
	/// different from other <c>Date</c> object.
	/// </summary>
	/// 
	/// <param name="other">
	/// takes <c>const Date&amp;</c> value and compares it with this <c>Date</c> object.
	/// </param>
	/// 
	/// <returns>
	/// The method returns wheather this <c>Date</c> object is different from other <c>Date</c> object.
	/// </returns>
	virtual bool operator!=(const Date& other) const;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <returns>
	/// 
	/// </returns>
	virtual Date& operator++();		
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	virtual Date operator++(const int);	
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <returns>
	/// 
	/// </returns>
	virtual Date operator--();		
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	virtual Date operator--(const int);
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="days">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	virtual Date operator+(const int days) const;
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="days">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	virtual Date operator-(const int days) const;
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="days">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	virtual Date& operator+=(const int days);
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="days">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	virtual Date& operator-=(const int days);
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="other">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	virtual int operator-(const Date& other);
};

/// <summary>
/// 
/// </summary>
class DateTime final : public Date
{
private:

	/// <summary>
	/// 
	/// </summary>
	unsigned int hours;

	/// <summary>
	/// 
	/// </summary>
	unsigned int minutes;

	/// <summary>
	/// 
	/// </summary>
	unsigned int seconds;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="hours">
	/// 
	/// </param>
	void setHours(const unsigned int hours);
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="minutes">
	/// 
	/// </param>
	void setMinutes(const unsigned int minutes);
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="seconds">
	/// 
	/// </param>
	void setSeconds(const unsigned int seconds);

public:

	/// <summary>
	/// 
	/// </summary>
	DateTime();
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="year">
	/// 
	/// </param>
	/// <param name="month">
	/// 
	/// </param>
	/// <param name="day">
	/// 
	/// </param>
	DateTime(const unsigned int year, const unsigned int month, const unsigned int day);
	
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="year">
	/// 
	/// </param>
	/// <param name="month">
	/// 
	/// </param>
	/// <param name="day">
	/// 
	/// </param>
	/// <param name="hours">
	/// 
	/// </param>
	/// <param name="minutes">
	/// 
	/// </param>
	/// <param name="seconds">
	/// 
	/// </param>
	DateTime(const unsigned int year, const unsigned int month, const unsigned int day, 
		const unsigned int hours, const unsigned int minutes, const unsigned int seconds);

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <returns>
	/// 
	/// </returns>
	unsigned int getHours() const;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <returns>
	/// 
	/// </returns>
	unsigned int getMinutes() const;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <returns>
	/// 
	/// </returns>
	unsigned int getSeconds() const;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="other">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	bool operator>(const DateTime& other) const;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="other">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	bool operator>=(const DateTime& other) const;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="other">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	bool operator<(const DateTime& other) const;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="other">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	bool operator<=(const DateTime& other) const;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="other">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	bool operator==(const DateTime& other) const;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="other">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	bool operator!=(const DateTime& other) const;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="other">
	/// 
	/// </param>
	/// 
	/// <returns>
	/// 
	/// </returns>
	int operator-(const DateTime& other);
};
#endif