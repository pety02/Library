#include "LibraryItems.h"
#include "String.h"

class ItemValidatior
{
public:
	static bool isValidTilte(const String title)
	{
		bool isValidHeading = true;
		if (!title.isEmpty() && (1 <= title.getCapacity() && title.getCapacity() <= 30)
			&& ('A' <= title[0] && title[0] <= 'Z'))
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
	static bool isValidPublisher(const String publisher)
	{
		bool isValidPublisherHouse = true;
		if (!publisher.isEmpty() && (1 <= publisher.getCapacity() && publisher.getCapacity() <= 30)
			&& ('A' <= publisher[0] && publisher[0] <= 'Z'))
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
	static bool isValidGenre(Genre genre)
	{
		return (UNKNOWN < genre&& genre < GENRE_COUNT);
	}
	static bool isValidDescription(const String description)
	{
		return (!description.isEmpty() && (1 <= description.getCapacity() && description.getCapacity() <= 300));
	}
	static bool isValidReleaseYear(unsigned int releaseYear)
	{
		return (1900 <= releaseYear && releaseYear <= 2022);
	}
	static bool isValidRating(double rating)
	{
		return (0.0 <= rating && rating <= 5.0);
	}
	static bool isValidIsbn(const String isbn)
	{
		return true;
	}
	static bool isValidAuthor(const String author)
	{
		bool isValidAuthorName = true;
		if (!author.isEmpty() && (1 <= author.getCapacity() && author.getCapacity() <= 30)
			&& ('A' <= author[0] && author[0] <= 'Z'))
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
	static bool isValidKeywordsCount(size_t keywordsCount)
	{
		return (0 <= keywordsCount);
	}
	static bool isValidKeywords(String* keywords, size_t keywordsCount)
	{
		return true;
	}
	static bool isValidIssn(const String issn)
	{
		return true;
	}
	static bool isValidReleaseMonth(unsigned int releaseMonth)
	{
		return (1 <= releaseMonth && releaseMonth <= 12);
	}
	static bool isValidNumber(unsigned int number)
	{
		return (0 < number);
	}
	static bool isValidArticlesCount(size_t articlesCount)
	{
		return (0 <= articlesCount);
	}
	static bool isValidContent(Article* content, size_t articlesCount)
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