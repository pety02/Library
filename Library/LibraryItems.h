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
protected:
	unsigned int id;
	String title;
	String publisher;
	Genre genre;
	String description;
	unsigned int releaseYear;
	double rating;

	LibraryItem();
	LibraryItem(const String title, const String publisher, Genre genre, const String description,
		unsigned int releaseYear, double rating);

	virtual void setId() = 0;
	void setGenre(Genre genre);
	void setDecription(const String description);
	void setReleaseYear(unsigned int releaseYear);

public:
	void setTitle(const String title);
	void setPublisher(const String publisher);
	void setRating(double rating);

	unsigned int getId() const;
	String getTitle() const;
	String getPublisher() const;
	Genre getGenre() const;
	String getDecription() const;
	unsigned int getReleaseYear() const;
	double getRating() const;
};

class Book final : public LibraryItem
{
private:
	String isbn;
	String author;
	String* keywords;
	size_t keywordsCount;

	Book();
	Book(const Book& other);
	Book(const String title, const String publisher, Genre genre, const String description,
		unsigned int releaseYear, double rating, const String isbn, const String author,
		String* keywords, size_t keywordsCount);
	Book& operator=(const Book& other);

	void copy(const Book& other);
	void destroy();

	void setId();
	void setIsbn(const String isbn);
	void setAuthor(const String author);
	void setKeywords(String* keywords, size_t keywordsCount);
	void setKeywordsCount(size_t keywordsCount);

	friend class ItemFactory;

public:
	~Book();

	unsigned int getId() const;
	String getIsbn() const;
	String getAuthor() const;
	String* getKeywords() const;
	size_t getKeywordsCount() const;
};

class Series final : public LibraryItem
{
private:
	String issn;
	unsigned int releaseMonth;
	unsigned int number;
	Article* content;
	size_t articlesCount;

	Series();
	Series(const Series& other);
	Series(const String title, const String publisher, Genre genre, const String description,
		unsigned int releaseYear, double rating, const String issn, unsigned int releaseMonth,
		unsigned int number, Article* content, size_t articlesCount);
	Series& operator=(const Series& other);

	void copy(const Series& other);
	void destroy();

	void setId();
	void setIssn(const String issn);
	void setReleaseMonth(unsigned int releaseMonth);
	void setNumber(unsigned int number);
	void setContent(Article* content, size_t articlesCount);
	void setArticlesCount(size_t keywordsCount);

	friend class ItemFactory;

public:
	~Series();

	unsigned int getId() const;
	String getIssn() const;
	unsigned int getReleaseMonth() const;
	unsigned int getNumber() const;
	Article* getContent() const;
	size_t getArticlesCount() const;
};

#endif