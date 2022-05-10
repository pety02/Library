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
	
	/**
	 * \brief Creates a new instace of String class as a copy of other one. Does not return a value.
	 * \param other - other is a pre-created instance of String, parameter of the method.
	 */
	void copy(const String& other);
	/**
	 * \brief Releases memory via deleting value of the String object (char array). Does not return a value.
	 */
	void destroy();
	/**
	 * \brief Resizes the value's char array of the instance from String class. Does not return a value.
	 */
	void resize();

public:

	String(); 
	String(const String& other); 
	String(const char* value); 
	String& operator=(const String& other); 
	~String(); 

	String& operator=(const char* otherValue); 
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
		char* s = new char[strlen(firstString.getValue()) + strlen(secondString.getValue()) + 1];
		strcpy_s(s, strlen(firstString.getValue()) + strlen(secondString.getValue()) + 1, firstString.getValue());
		strcat_s(s, strlen(firstString.getValue()) + strlen(secondString.getValue()) + 1, secondString.getValue());

		String cs = String(s);

		return cs;
	}
};

#endif