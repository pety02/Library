#include "ItemValidator.h"

Series::Series()
{
	setId();
	setTitle(String());
	setPublisher(String());
	setGenre(UNKNOWN);
	setDecription(String());
	setReleaseYear(1900);
	setRating(0.0);
	setIssn(String());
	setReleaseMonth(1);
	setNumber(0);
	setArticlesCount(0);
	content = new Article[0];
}
Series::Series(const Series& other)
{
	copy(other);
}
Series::Series(const String title, const String publisher, Genre genre, const String description,
	unsigned int releaseYear, double rating, const String issn, unsigned int releaseMonth,
	unsigned int number, Article* content, size_t articlesCount)
{
	setId();
	setTitle(title);
	setPublisher(publisher);
	setGenre(genre);
	setDecription(description);
	setReleaseYear(releaseYear);
	setRating(rating);
	setIssn(issn);
	setReleaseMonth(releaseMonth);
	setNumber(number);
	setContent(content, articlesCount);
}
Series& Series::operator=(const Series& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	
	return *this;
}

void Series::copy(const Series& other)
{
	setId();
	setTitle(other.getTitle());
	setPublisher(other.getPublisher());
	setGenre(other.getGenre());
	setDecription(other.getDecription());
	setReleaseYear(other.getReleaseYear());
	setRating(other.getRating());
	setIssn(other.getIssn());
	setReleaseMonth(other.getReleaseMonth());
	setNumber(other.getNumber());
	setArticlesCount(other.getArticlesCount());
	content = new Article[articlesCount];
	for (size_t index = 0; index < articlesCount; ++index)
	{
		content[index] = other.content[index];
	}
}
void Series::destroy()
{
	delete[] content;
}

void Series::setId()
{
	if (this != nullptr)
	{
		id = (unsigned int)this + 's';
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. Id can not be set!");
	}
}
void Series::setIssn(const String issn)
{
	if (this != nullptr)
	{
		this->issn = (ItemValidator::isValidIssn(issn)) ? issn : throw std::invalid_argument("Invalid issn!");
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. Issn can not be changed!");
	}
}
void Series::setReleaseMonth(unsigned int releaseMonth)
{
	if (this != nullptr)
	{
		this->releaseMonth = (ItemValidator::isValidReleaseMonth(releaseMonth)) ? releaseMonth : throw std::invalid_argument("Invalid release month!");
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. ReleaseMonth can not be changed!");
	}	
}
void Series::setNumber(unsigned int number)
{
	if (this != nullptr)
	{
		this->number = (ItemValidator::isValidNumber(number)) ? number : throw std::invalid_argument("Invalid number!");
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. Number can not be changed!");
	}
}
void Series::setContent(Article* content, size_t articlesCount)
{
	if (this != nullptr)
	{
		if (ItemValidator::isValidContent(content, articlesCount))
		{
			for (size_t index = 0; index < articlesCount; index++)
			{
				this->content[index] = content[index];
			}
		}
		else
		{
			throw std::invalid_argument("Invalid content!");
		}
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. Content can not be changed!");
	}
}
void Series::setArticlesCount(size_t keywordsCount)
{
	if (this != nullptr)
	{
		articlesCount = (ItemValidator::isValidArticlesCount(articlesCount)) ? articlesCount : throw std::invalid_argument("Invalid articles count!");
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. ArticlesCount can not be changed!");
	}
}

Series::~Series()
{
	destroy();
}

unsigned int Series::getId() const
{
	if (this != nullptr)
	{
		return id;
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. Id can not be readed!");
	}
}
String Series::getIssn() const
{
	if (this != nullptr)
	{
		return issn;
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. Issn can not be readed!");
	}
}
unsigned int Series::getReleaseMonth() const
{
	if (this != nullptr)
	{
		return releaseMonth;
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. ReleaseMonth can not be readed!");
	}
}
unsigned int Series::getNumber() const
{
	if (this != nullptr)
	{
		return number;
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. Number can not be readed!");
	}
}
Article* Series::getContent() const
{
	if (this != nullptr)
	{
		return content;
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. Content can not be readed!");
	}
}
size_t Series::getArticlesCount() const
{
	if (this != nullptr)
	{
		return articlesCount;
	}
	else
	{
		throw std::runtime_error("The Series is null pointer. ArticlesCount can not be readed!");
	}
}