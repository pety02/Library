#pragma once
#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include <iostream>
#include <cstring>
#include <stdexcept>

/// <summary>
/// String class written by me in order to be able
/// to use string as data type in my project.
/// </summary>
class String
{
private:
	char* buffer;
	size_t capacity;
	size_t lastIndex;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="capacity"></param>
	void setCapacity(const size_t& capacity);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="buffer"></param>
	/// <param name="lastIndex"></param>
	void setBufferAndLastIndex(const char* buffer, const size_t& lastIndex);

	/// <summary>
	/// <c>copy</c> is a method for copying all fields of one 
	/// string to another string when it is needed.
	/// </summary>
	/// <param name="other">
	/// "other" - string which fields need to be copied. Pre-created string object.
	/// </param>
	void copy(const String& other);
	
	/// <summary>
	/// <c>destroy</c> is a method for releaseing buffer's memory when it is needed.
	/// </summary>
	void destroy() const;
	
	/// <summary>
	/// <c>resize</c> is a method for resizing string's buffer when it is needed.
	/// </summary>
	void resize();

public:
	/// <summary>
	/// Default constructor for string. Constructs default object 
	/// of class String, settings default values for its fields.
	/// </summary>
	String(); 
	
	/// /// <summary>
	/// Copy constructor for string. Constructs a string as copying
	/// of pre-created String object. Uses <c>copy</c> private method.
	/// </summary>
	/// <param name="other">
	/// "other" - string which fields need to be copied. Pre-created string object.
	/// </param>
	String(const String& other); 

	/// <summary>
	/// Operator = for string. Assigns <paramref name = "other" /> string 
	/// to "this" string.
	/// </summary>
	/// <param name="other">
	/// "other" -  string which fields need to be assigned to other string's 
	/// fields. Pre-created string object.
	/// </param>
	/// <exception cref="exception_ptr">
	/// Thrown when "this" string object is equal to "other" string object.
	/// </exception>
	/// <returns>
	/// Returns reference to the modified string.
	/// </returns>
	String& operator=(const String& other);

	/// <summary>
	/// Operator = for string. Assigns an existing string to another string.
	/// </summary>
	/// <param name="otherValue">
	/// "otherValue" - const char array from which the operator creates brand
	/// new string object.
	/// </param>
	/// <returns>
	/// Returns reference to the modified string.
	/// </returns>
	String& operator=(const char* other);
	
	/// <summary>
	/// Constructor with a parameter. Constructs a string as setting a parameter's 
	/// value as buffer's value and setting other fields' values based on the value of 
	/// the parameter.
	/// </summary>
	/// <param name="value">
	/// "value" - const char array (string buffer's value).
	/// </param>
	String(const char* value); 
	
	/// <summary>
	/// Destructor for string. Destroys the string object when it already 
	/// is not in use.
	/// </summary>
	~String();

	/// <summary>
	/// <c>getBuffer</c> - is a getter for buffer string's field.
	/// </summary>
	/// <returns>
	/// Returns the value of string's buffer.
	/// </returns>
	const char* getBuffer() const;

	/// <summary>
	/// <c>getCapacity</c> - is a getter for capacity string's field.
	/// </summary>
	/// <returns>
	/// Returns the capacity of the string.
	/// </returns>
	const size_t getCapacity() const;

	/// <summary>
	/// <c>getLastIndex</c> - is a getter for the lastIndex string's field. 
	/// </summary>
	/// <returns>
	/// Returns the last index in string's buffer value.
	/// </returns>
	const size_t getLastIndex() const;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	bool operator==(const char* other);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	bool operator==(const String& other);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	bool operator!=(const char* other);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	bool operator!=(const String& other);

	/// <summary>
	/// <c>operator+(const String& other)</c> is predefined operator in class <c>String</c> which
	/// concatenates two <c>String</c> objects.
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	String& operator+(const String& other); 
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	String& operator+(const char* other);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other">
	/// 
	/// </param>
	/// <returns>
	/// Returns reference to the modified string.
	/// </returns>
	String& operator+=(const String& other); 

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	String& operator+=(const char* other);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="index">
	/// 
	/// </param>
	/// <exception cref = "">
	///
	/// </exception>
	/// <returns>
	/// 
	/// </returns>
	char& operator[](const size_t& index) const; 
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="index">
	/// 
	/// </param>
	/// <exception cref = "">
	///
	/// </exception>
	/// <returns>
	/// 
	/// </returns>
	const char operator[](const size_t& index); 

	/// <summary>
	/// 
	/// </summary>
	/// <returns>
	/// 
	/// </returns>
	const bool isEmpty() const; 
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="other">
	/// 
	/// </param>
	/// <returns>
	/// 
	/// </returns>
	const bool compare(const String& other) const; 

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	const bool compare(const char* other) const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="c">
	/// 
	/// </param>
	/// <returns>
	/// Returns reference to the modified string.
	/// </returns>
	String& pushBack(const char& symbol); 
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns>
	/// Returns reference to the modified string.
	/// </returns>
	String& popBack(); 

	/// <summary>
	/// 
	/// </summary>
	void toString() const; 

	/// <summary>
	/// 
	/// </summary>
	/// <param name="firstString">
	/// 
	/// </param>
	/// <param name="secondString">
	/// 
	/// </param>
	/// <returns></returns>
	friend String& append(const String& firstString, const String& secondString);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="out"></param>
	/// <returns></returns>
	friend std::ostream& operator<<(std::ostream& out, const String& str);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="in"></param>
	/// <returns></returns>
	friend std::istream& operator>>(std::istream& in, String str);
};

#endif