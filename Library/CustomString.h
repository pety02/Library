#pragma once
#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

class CustomString
{
private:
	char* value;
	size_t capacity;
	size_t lastIndex;

	void copy(const CustomString& other);
	void destroy();
	void resize();

public:
	CustomString();
	CustomString(const CustomString& other);
	CustomString(const char* value, size_t capacity, size_t lastIndex);
	CustomString& operator=(const CustomString& other);
	~CustomString();

	CustomString& operator+(const CustomString& other);
	CustomString& operator+=(const CustomString& other);
	char operator[](size_t index);
	const char operator[](size_t index) const;

	char* getValue() const;
	size_t getCapacity() const;
	size_t getLastIndex() const;

	bool isEmpty() const;
	bool compare(const CustomString& other) const;
	CustomString& append(const CustomString& other);
	void pushBack(const char c);
	void popBack();
};

#endif