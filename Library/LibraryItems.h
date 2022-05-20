#pragma once
#ifndef LIBRARYITEMS_H
#define LIBRARYITEMS_H

#include <string>
#include "Article.h"

/// <summary>
/// 
/// </summary>
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

/// <summary>
/// 
/// </summary>
class LibraryItem
{
private:
	String title;
	String publisher;
	Genre genre;
	String description;
	unsigned int releaseYear;
	double rating;

protected:
	unsigned int id;

	/// <summary>
	/// 
	/// </summary>
	LibraryItem();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="title"></param>
	/// <param name="publisher"></param>
	/// <param name="genre"></param>
	/// <param name="description"></param>
	/// <param name="releaseYear"></param>
	/// <param name="rating"></param>
	LibraryItem(const String title, const String publisher, Genre genre, const String description,
		unsigned int releaseYear, double rating);

	/// <summary>
	/// 
	/// </summary>
	virtual void setId() = 0;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="genre"></param>
	void setGenre(Genre genre);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="description"></param>
	void setDecription(const String description);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="releaseYear"></param>
	void setReleaseYear(unsigned int releaseYear);

public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="title"></param>
	void setTitle(const String title);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="publisher"></param>
	void setPublisher(const String publisher);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="rating"></param>
	void setRating(double rating);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getId() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String getTitle() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String getPublisher() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Genre getGenre() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String getDecription() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getReleaseYear() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	double getRating() const;
};

/// <summary>
/// 
/// </summary>
class Book final : public LibraryItem
{
private:
	String isbn;
	String author;
	String* keywords;
	size_t keywordsCount;

	/// <summary>
	/// 
	/// </summary>
	Book();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	Book(const Book& other);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="title"></param>
	/// <param name="publisher"></param>
	/// <param name="genre"></param>
	/// <param name="description"></param>
	/// <param name="releaseYear"></param>
	/// <param name="rating"></param>
	/// <param name="isbn"></param>
	/// <param name="author"></param>
	/// <param name="keywords"></param>
	/// <param name="keywordsCount"></param>
	Book(const String title, const String publisher, Genre genre, const String description,
		unsigned int releaseYear, double rating, const String isbn, const String author,
		String* keywords, size_t keywordsCount);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Book& operator=(const Book& other);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	void copy(const Book& other);
	
	/// <summary>
	/// 
	/// </summary>
	void destroy();

	/// <summary>
	/// 
	/// </summary>
	void setId();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="isbn"></param>
	void setIsbn(const String isbn);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="author"></param>
	void setAuthor(const String author);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="keywords"></param>
	/// <param name="keywordsCount"></param>
	void setKeywords(String* keywords, size_t keywordsCount);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="keywordsCount"></param>
	void setKeywordsCount(size_t keywordsCount);

	/// <summary>
	/// 
	/// </summary>
	friend class ItemFactory;

public:
	/// <summary>
	/// 
	/// </summary> 
	~Book();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getId() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String getIsbn() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String getAuthor() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String* getKeywords() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	size_t getKeywordsCount() const;
};

/// <summary>
/// 
/// </summary>
class Series final : public LibraryItem
{
private:
	String issn;
	unsigned int releaseMonth;
	unsigned int number;
	Article* content;
	size_t articlesCount;

	/// <summary>
	/// 
	/// </summary>
	Series();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	Series(const Series& other);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="title"></param>
	/// <param name="publisher"></param>
	/// <param name="genre"></param>
	/// <param name="description"></param>
	/// <param name="releaseYear"></param>
	/// <param name="rating"></param>
	/// <param name="issn"></param>
	/// <param name="releaseMonth"></param>
	/// <param name="number"></param>
	/// <param name="content"></param>
	/// <param name="articlesCount"></param>
	Series(const String title, const String publisher, Genre genre, const String description,
		unsigned int releaseYear, double rating, const String issn, unsigned int releaseMonth,
		unsigned int number, Article* content, size_t articlesCount);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Series& operator=(const Series& other);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	void copy(const Series& other);
	
	/// <summary>
	/// 
	/// </summary>
	void destroy();

	/// <summary>
	/// 
	/// </summary>
	void setId();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="issn"></param>
	void setIssn(const String issn);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="releaseMonth"></param>
	void setReleaseMonth(unsigned int releaseMonth);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="number"></param>
	void setNumber(unsigned int number);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="content"></param>
	/// <param name="articlesCount"></param>
	void setContent(Article* content, size_t articlesCount);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="keywordsCount"></param>
	void setArticlesCount(size_t keywordsCount);

	/// <summary>
	/// 
	/// </summary>
	friend class ItemFactory;

public:
	/// <summary>
	/// 
	/// </summary>
	~Series();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getId() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String getIssn() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getReleaseMonth() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	unsigned int getNumber() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Article* getContent() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	size_t getArticlesCount() const;
};

#endif