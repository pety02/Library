#pragma once
#ifndef EXCEPTIONLOGGER_H
#define EXCEPTIONLOGGER_H

#include "String.h"
#include "Dates.h"
#include <fstream>

class ExceptionLogger
{
private:
public:
	static void logException(const Date& date, const String& fileName,
		const String& exceptionTitle, const String& exceptionMessage)
	{
		std::ofstream out(fileName.getBuffer(), std::ios::out | std::ios::app);
		if (out.is_open())
		{
			out << date.getDay() << " \\ " << date.getMonth() << " \\ " << date.getYear()
				<< std::endl << exceptionTitle << " occures:" << std::endl << exceptionMessage << std::endl
				<< std::endl;

			out.close();
		}
	}

	static void logException(const DateTime& dateTime, const String& fileName,
		const String& exceptionTitle, const String& exceptionMessage)
	{
		std::ofstream out(fileName.getBuffer(), std::ios::out | std::ios::app);
		if (out.is_open())
		{
			out << dateTime.getDay() << " \\ " << dateTime.getMonth() << " \\ " << dateTime.getYear() << " - "
				<< dateTime.getHours() << " : " << dateTime.getMinutes() << " : " << dateTime.getSeconds()
				<< std::endl << exceptionTitle << " occures:" << std::endl << exceptionMessage << std::endl 
				<< std::endl;

			out.close();
		}
	}

	static void logException(const String& fileName,
		const String& exceptionTitle, const String& exceptionMessage)
	{
		std::ofstream out(fileName.getBuffer(), std::ios::out | std::ios::app);
		if (out.is_open())
		{
			out << exceptionTitle << " occures:" << std::endl << exceptionMessage << std::endl
				<< std::endl;

			out.close();
		}
	}
};

#endif