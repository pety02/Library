#pragma once
#ifndef ITEMVALIDATOR_H
#define ITEMVALIDATOR_H

#include "LibraryItems.h"

/// <summary>
/// 
/// </summary>
class ItemValidator
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="title"></param>
	/// <returns></returns>
	static bool isValidTilte(const String title)
	{
		bool isValidHeading = true;
		if ((!title.isEmpty() && (1 <= title.getCapacity() && title.getCapacity() <= 30)
			&& ('A' <= title[0] && title[0] <= 'Z')) || (title.isEmpty()))
		{
			for (size_t index = 1; index <= title.getLastIndex(); ++index)
			{
				if (!('a' <= title[index] && title[index] <= 'z'))
				{
					isValidHeading = false;
					break;
				}
			}
		}
		else
		{
			isValidHeading = false;
		}

		return isValidHeading;
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="publisher"></param>
	/// <returns></returns>
	static bool isValidPublisher(const String publisher)
	{
		bool isValidPublisherHouse = true;
		if ((!publisher.isEmpty() && (1 <= publisher.getCapacity() && publisher.getCapacity() <= 30)
			&& ('A' <= publisher[0] && publisher[0] <= 'Z')) || (publisher.isEmpty()))
		{
			for (size_t index = 1; index <= publisher.getLastIndex(); ++index)
			{
				if (!('a' <= publisher[index] && publisher[index] <= 'z'))
				{
					isValidPublisherHouse = false;
					break;
				}
			}
		}
		else
		{
			isValidPublisherHouse = false;
		}

		return isValidPublisherHouse;
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="genre"></param>
	/// <returns></returns>
	static bool isValidGenre(const Genre genre)
	{
		return (Genre::UNKNOWN <= genre&& genre < Genre::GENRE_COUNT);
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="description"></param>
	/// <returns></returns>
	static bool isValidDescription(const String description)
	{
		return ((!description.isEmpty() && (1 <= description.getCapacity() && description.getCapacity() <= 300)) || (description.isEmpty()));
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="releaseYear"></param>
	/// <returns></returns>
	static bool isValidReleaseYear(const unsigned int releaseYear)
	{
		return (1900 <= releaseYear && releaseYear <= 2022);
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="rating"></param>
	/// <returns></returns>
	static bool isValidRating(const double rating)
	{
		return (0.0 <= rating && rating <= 5.0);
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="isbn"></param>
	/// <returns></returns>
	static bool isValidIsbn(const String isbn)
	{
		return true;
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="author"></param>
	/// <returns></returns>
	static bool isValidAuthor(const String author)
	{
		bool isValidAuthorName = true;
		if ((!author.isEmpty() && (1 <= author.getCapacity() && author.getCapacity() <= 30)
			&& ('A' <= author[0] && author[0] <= 'Z')) || (author.isEmpty()))
		{
			for (size_t index = 1; index <= author.getLastIndex(); ++index)
			{
				if (!('a' <= author[index] && author[index] <= 'z'))
				{
					isValidAuthorName = false;
					break;
				}
			}
		}
		else
		{
			isValidAuthorName = false;
		}

		return isValidAuthorName;
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="keywordsCount"></param>
	/// <returns></returns>
	static bool isValidKeywordsCount(const size_t keywordsCount)
	{
		return (0 <= keywordsCount);
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="keywords"></param>
	/// <param name="keywordsCount"></param>
	/// <returns></returns>
	static bool isValidKeywords(const String* keywords, const size_t keywordsCount)
	{
		return true;
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="issn"></param>
	/// <returns></returns>
	static bool isValidIssn(const String issn)
	{
		return true;
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="releaseMonth"></param>
	/// <returns></returns>
	static bool isValidReleaseMonth(const unsigned int releaseMonth)
	{
		return (1 <= releaseMonth && releaseMonth <= 12);
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="number"></param>
	/// <returns></returns>
	static bool isValidNumber(const unsigned int number)
	{
		return (0 <= number);
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="articlesCount"></param>
	/// <returns></returns>
	static bool isValidArticlesCount(const size_t articlesCount)
	{
		return (0 <= articlesCount);
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="content"></param>
	/// <param name="articlesCount"></param>
	/// <returns></returns>
	static bool isValidContent(const Article* content, const size_t articlesCount)
	{
		String authourName = String();
		bool isValidContentArticles = true;

		for (size_t index = 0; index < articlesCount - 1; index++)
		{
			authourName = content[index].getAuthour();
			if (!(authourName.compare(content[index + 1].getAuthour())) || !(isValidAuthor(authourName)))
			{
				isValidContentArticles = false;
				return isValidContentArticles;
			}
		}

		return isValidContentArticles;
	}
};

#endif