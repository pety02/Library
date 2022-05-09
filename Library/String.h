#pragma once
#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include <iostream>

class String
{
private:
	char* value;
	size_t capacity;
	size_t lastIndex;

	void copy(const String& other);
	void destroy();
	void resize();

public:
	String();
	String(const String& other);
	String(const char* value, size_t capacity, size_t lastIndex);
	String& operator=(const String& other);
	~String();

	String& operator+(const String& other);
	String& operator+=(const String& other);
	char operator[](size_t index);
	const char operator[](size_t index) const;

	char* getValue() const;
	size_t getCapacity() const;
	size_t getLastIndex() const;

	bool isEmpty() const;
	bool compare(const String& other) const;
	String& pushBack(const char c);
	String& popBack();
	void toString();

	friend String append(const String& firstString, const String& secondString)
	{
		size_t lIndex = firstString.getLastIndex() + secondString.getLastIndex();
		size_t maxCapacity = firstString.getCapacity() + secondString.getCapacity();

		char* s = new char[strlen(firstString.getValue()) + strlen(secondString.getValue()) + 1];
		strcpy_s(s, strlen(firstString.getValue()) + strlen(secondString.getValue()) + 1, firstString.getValue());
		strcat_s(s, strlen(firstString.getValue()) + strlen(secondString.getValue()) + 1, secondString.getValue());

		String cs = String(s, maxCapacity, lIndex);

		return cs;
	}
};

#endif