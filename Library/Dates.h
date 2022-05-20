#pragma once
#ifndef DATES_H
#define DATES_H

/// <summary>
/// 
/// </summary>
class Date
{
private:
	unsigned int year;
	unsigned int month;
	unsigned int day;

	unsigned int getDaysInMonth();

protected:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="year"></param>
	void setYear(unsigned int year);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="month"></param>
	void setMonth(unsigned int month);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="day"></param>
	void setDay(unsigned int day);

public:
	/// <summary>
	/// 
	/// </summary>
	Date();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="year"></param>
	/// <param name="month"></param>
	/// <param name="day"></param>
	Date(unsigned int year, unsigned int month, unsigned int day);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	virtual bool operator>(const Date& d) const;  
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	virtual bool operator>=(const Date& d) const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	virtual bool operator<(const Date& d) const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	virtual bool operator<=(const Date& d) const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	virtual bool operator==(const Date& d) const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	virtual bool operator!=(const Date& d) const;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	virtual Date& operator++();		
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual Date operator++(int);	
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	virtual Date operator--();		
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual Date operator--(int);	
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="day"></param>
	/// <returns></returns>
	virtual Date operator+(int day) const;   
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="day"></param>
	/// <returns></returns>
	virtual Date operator-(int day) const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="day"></param>
	/// <returns></returns>
	virtual Date& operator+=(int day);      
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="day"></param>
	/// <returns></returns>
	virtual Date& operator-=(int day);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	virtual int operator-(const Date& d);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getYear() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getMonth() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getDay() const;
};

/// <summary>
/// 
/// </summary>
class DateTime final : public Date
{
private:
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="hours"></param>
	void setHours(unsigned int hours);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="minutes"></param>
	void setMinutes(unsigned int minutes);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="seconds"></param>
	void setSeconds(unsigned int seconds);

public:
	/// <summary>
	/// 
	/// </summary>
	DateTime();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="year"></param>
	/// <param name="month"></param>
	/// <param name="day"></param>
	DateTime(unsigned int year, unsigned int month, unsigned int day);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="year"></param>
	/// <param name="month"></param>
	/// <param name="day"></param>
	/// <param name="hours"></param>
	/// <param name="minutes"></param>
	/// <param name="seconds"></param>
	/// <param name="milliSeconds"></param>
	DateTime(unsigned int year, unsigned int month, unsigned int day, 
		unsigned int hours, unsigned int minutes, unsigned int seconds);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	bool operator>(const DateTime& d) const;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	bool operator>=(const DateTime& d) const;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	bool operator<(const DateTime& d) const;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	bool operator<=(const DateTime& d) const;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	bool operator==(const DateTime& d) const;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	bool operator!=(const DateTime& d) const;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="d"></param>
	/// <returns></returns>
	int operator-(const DateTime& d);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getHours() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getMinutes() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getSeconds() const;
};
#endif