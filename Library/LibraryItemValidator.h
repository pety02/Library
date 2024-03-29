#pragma once
#ifndef LIBRARYITEMVALIDATOR_H
#define LYBRARYITEMVALIDATOR_H

#include <cstring>
#include "LibraryItems.h"

/// <summary>
/// 
/// </summary>
class LibraryItemValidator
{
private:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="word"></param>
	/// <returns></returns>
	static bool containsOnlyLetters(const String word)
	{
		bool areOnlyLetters = false;
		const char* tempWord = word.getBuffer();

		while (*word.getBuffer() != '\0')
		{
			if(('a' <= *tempWord && *tempWord <= 'z') || ('A' <= *tempWord && *tempWord <= 'Z'))
			{ 
				areOnlyLetters = true;
			}
			
			tempWord++;
		}

		return areOnlyLetters;
	}

	static size_t sumIssnChars(char ch, int& lastDigit, int& digitPosition)
	{
		if (!isdigit(ch))
		{
			return 0;
		}

		lastDigit = ch - '0';  
		return digitPosition-- * lastDigit;
	}

public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="title"></param>
	/// <returns></returns>
	static bool isValidTilte(const String title)
	{
		bool isValidHeading = true;
		if ((!title.isEmpty() && (0 <= title.getLastIndex() && title.getLastIndex() <= 29)
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
		if ((!publisher.isEmpty() && (0 <= publisher.getLastIndex() && publisher.getLastIndex() <= 29)
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
		return ((!description.isEmpty() && (0 <= description.getLastIndex() && description.getLastIndex() <= 299)) || (description.isEmpty()));
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
		int isbnLenght = strlen(isbn.getBuffer());
		if (isbnLenght != 10)
		{
			return false;
		}
		int sumOfIsbnNumbers = 0;
		for (size_t index = 0; index < 9; ++index)
		{
			int value = isbn[index] - '\0';
			if (0 <= value && value <= 9)
			{
				sumOfIsbnNumbers += (value * (10 - index));
				continue;
			}
			
			return false;
		}
		char lastNumberOfIsbn = isbn[9];
		if (lastNumberOfIsbn == 'X' || ('0' <= lastNumberOfIsbn && lastNumberOfIsbn <= '9'))
		{
			sumOfIsbnNumbers += ((lastNumberOfIsbn == 'X') ? 10 : (lastNumberOfIsbn - '0'));
			return (sumOfIsbnNumbers % 11 == 0);
		}
		
		return false;
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="author"></param>
	/// <returns></returns>
	static bool isValidAuthor(const String author)
	{
		bool isValidAuthorName = true;
		if ((!author.isEmpty() && (1 <= author.getLastIndex() && author.getLastIndex() <= 29)
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
		return (keywordsCount <= 15);
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="keywords"></param>
	/// <param name="keywordsCount"></param>
	/// <returns></returns>
	static bool isValidKeywords(const String* keywords, const size_t keywordsCount)
	{
		bool isValid = false;
		for (size_t index = 0; index < keywordsCount; index++)
		{
			if (containsOnlyLetters(keywords[index]) && !keywords[index].isEmpty())
			{
				isValid = true;
			}
		}

		return isValid;
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="issn"></param>
	/// <returns></returns>
	static bool isValidIssn(const String issn)
	{
		int lastDigit = 0;
		int digitPosition = 8;
		size_t sum = 0;
		for (size_t i = 0; i <= issn.getLastIndex(); i++)
		{
			sum += sumIssnChars(issn.getBuffer()[i], lastDigit, digitPosition);
		}
		
		if (digitPosition != 0)
		{
			throw new std::invalid_argument("Incorrect number of digits in ISSN");
		}
		
		sum -= lastDigit;
		int mod = sum % 11;
		int checkDigit = 0;
		if (mod != 0)
			checkDigit = 11 - mod;

		return (checkDigit == lastDigit);
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
		return (number <= 30);
	}
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="articlesCount"></param>
	/// <returns></returns>
	static bool isValidArticlesCount(const size_t articlesCount)
	{
		return (articlesCount <= 20);
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