#pragma once
#ifndef LIBRARYITEMS_H
#define LIBRARYITEMS_H

#include "String.h"
#include "Article.h"

size_t LibraryItem::id = 0;

/// <summary>
/// 
/// </summary>
enum class Genre
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
	/// <summary>
	/// 
	/// </summary>
	String title;

	/// <summary>
	/// 
	/// </summary>
	String publisher;

	/// <summary>
	/// 
	/// </summary>
	Genre genre;

	/// <summary>
	/// 
	/// </summary>
	String description;

	/// <summary>
	/// 
	/// </summary>
	unsigned int releaseYear;

	/// <summary>
	/// 
	/// </summary>
	double rating;

protected:
	/// <summary>
	/// 
	/// </summary>
	static unsigned int id;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="genre"></param>
	void setGenre(const Genre& genre);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="description"></param>
	void setDecription(const String& description);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="releaseYear"></param>
	void setReleaseYear(const unsigned int& releaseYear);

	/// <summary>
	/// 
	/// </summary>
	virtual void setId() = 0;

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
	LibraryItem(const String& title, const String& publisher, const Genre& genre, const String& description,
		const unsigned int& releaseYear, const double& rating);

public:
	/// <summary>
	/// 
	/// </summary>
	virtual ~LibraryItem() = 0;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="title"></param>
	void setTitle(const String& title);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="publisher"></param>
	void setPublisher(const String& publisher);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="rating"></param>
	void setRating(const double& rating);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const unsigned int getId() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const String getTitle() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const String getPublisher() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const Genre getGenre() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const String getDecription() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const unsigned int getReleaseYear() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const double getRating() const;
};

/// <summary>
/// 
/// </summary>
class Book final : public LibraryItem
{
private:
	/// <summary>
	/// 
	/// </summary>
	String isbn;

	/// <summary>
	/// 
	/// </summary>
	String author;

	/// <summary>
	/// 
	/// </summary>
	String* keywords;

	/// <summary>
	/// 
	/// </summary>
	size_t keywordsCount;

	/// <summary>
	/// 
	/// </summary>
	void setId()
	{
		id = (unsigned int)this + 'b';
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="isbn"></param>
	void setIsbn(const String& isbn);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="author"></param>
	void setAuthor(const String& author);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="keywords"></param>
	/// <param name="keywordsCount"></param>
	void setKeywordsAndKeywordsCount(const String* keywords, const size_t& keywordsCount);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	void copy(const Book& other);

	/// <summary>
	/// 
	/// </summary>
	void destroy();

public:
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
	/// <param name="other"></param>
	/// <returns></returns>
	Book& operator=(const Book& other);

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
	Book(const String& title, const String& publisher, const Genre& genre, const String& description,
		const unsigned int& releaseYear, const double& rating, const String& isbn, const String& author,
		const String* keywords, const size_t& keywordsCount);

	/// <summary>
	/// 
	/// </summary> 
	~Book();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const unsigned int getId() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const String getIsbn() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const String getAuthor() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const String* getKeywords() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const size_t getKeywordsCount() const;
};

/// <summary>
/// 
/// </summary>
class Series final : public LibraryItem
{
private:
	/// <summary>
	/// 
	/// </summary>
	String issn;

	/// <summary>
	/// 
	/// </summary>
	unsigned int releaseMonth;

	/// <summary>
	/// 
	/// </summary>
	unsigned int number;

	/// <summary>
	/// 
	/// </summary>
	Article* articles;

	/// <summary>
	/// 
	/// </summary>
	size_t articlesCount;
	
	/// <summary>
	/// 
	/// </summary>
	void setId();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="issn"></param>
	void setIssn(const String& issn);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="releaseMonth"></param>
	void setReleaseMonth(const unsigned int& releaseMonth);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="number"></param>
	void setNumber(const unsigned int& number);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="articles"></param>
	/// <param name="articlesCount"></param>
	void setArticlesAndArticlesCount(const Article* articles, const size_t& articlesCount);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	void copy(const Series& other);

	/// <summary>
	/// 
	/// </summary>
	void destroy();

public:
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
	/// <param name="other"></param>
	/// <returns></returns>
	Series& operator=(const Series& other);

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
	/// <param name="articles"></param>
	/// <param name="articlesCount"></param>
	Series(const String& title, const String& publisher, const Genre& genre, const String& description,
		const unsigned int& releaseYear, const double& rating, const String& issn,
		const unsigned int& releaseMonth, const unsigned int& number, const Article* articles,
		const size_t& articlesCount);

	/// <summary>
	/// 
	/// </summary>
	~Series();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const unsigned int getId() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const String getIssn() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const unsigned int getReleaseMonth() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const unsigned int getNumber() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const Article* getArticles() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const size_t getArticlesCount() const;
};

#endif