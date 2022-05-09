#pragma once
#ifndef LIBRARYITEMS_H
#define LIBRARYITEMS_H

#include <string>
#include "String.h"
#include "Article.h"

enum Genre
{
	UNKNOWN,

	ACTION,
	ADVENTURE,
	CLASSICS,
	COMIC,
	DETECTIVE,
	SCIENCE_FICTION,
	HORROR,
	TABLOID,
	NEWSLETTER,
	MAGAZINE,

	GENRE_COUNT
};

class LibraryItem
{
private:
	static const unsigned int ID = 0;

	String id;
	String title;
	String publisher;
	Genre genre;
	String description;
	unsigned int releaseYear;
	double rating;

	virtual void setId() = 0;

public:
	LibraryItem();
	LibraryItem(const String title, const String publisher, Genre genre, const String description, unsigned int releaseYear, double rating);

	String getId() const;
	String getTitle() const;
	String getPublisher() const;
	Genre getGenre() const;
	String getDecription() const;
	unsigned int getReleaseYear() const;
	double getRating() const;

	void setPublisher(const String publisher);
	void setRating(double rating);
};

class Book : public LibraryItem
{
private:
	String isbn;
	String author;
	String* keywords;

public:
};

class Series : public LibraryItem
{
private:
	String issn;
	unsigned int releaseMonth;
	unsigned int number;
	Article* content;

public:
};

#endif