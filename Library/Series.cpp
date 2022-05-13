#include "LibraryItems.h"
#include "ItemValidator.cpp"

Series::Series()
{
	setId();
	title = String();
	publisher = String();
	genre = UNKNOWN;
	description = String();
	releaseYear = 1900;
	rating = 0.0;
	issn = String();
	releaseMonth = 1;
	number = 0;
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
	id = other.id;
	title = other.title;
	publisher = other.publisher;
	genre = other.genre;
	description = other.description;
	releaseYear = other.releaseYear;
	rating = other.rating;
	issn = other.issn;
	releaseMonth = other.releaseMonth;
	number = other.number;
	articlesCount = other.articlesCount;
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
	id = (unsigned int)this + 's';
}
void Series::setIssn(const String issn)
{
	this->issn = (ItemValidatior::isValidIssn(issn)) ? issn : throw new std::invalid_argument("Invalid issn!");
}
void Series::setReleaseMonth(unsigned int releaseMonth)
{
	this->releaseMonth = (ItemValidatior::isValidReleaseMonth(releaseMonth)) ? releaseMonth : throw new std::invalid_argument("Invalid release month!");
}
void Series::setNumber(unsigned int number)
{
	this->number = (ItemValidatior::isValidNumber(number)) ? number : throw new std::invalid_argument("Invalid number!");
}
void Series::setContent(Article* content, size_t articlesCount)
{
	if (ItemValidatior::isValidContent(content, articlesCount))
	{
		for (size_t index = 0; index < articlesCount; index++)
		{
			this->content[index] = content[index];
		}
	}
	else
	{
		throw new std::invalid_argument("Invalid content!");
	}
}
void Series::setArticlesCount(size_t keywordsCount)
{
	articlesCount = (ItemValidatior::isValidArticlesCount(articlesCount)) ? articlesCount : throw new std::invalid_argument("Invalid articles count!");
}

Series::~Series()
{
	destroy();
}

unsigned int Series::getId() const
{
	return id;
}
String Series::getIssn() const
{
	return issn;
}
unsigned int Series::getReleaseMonth() const
{
	return releaseMonth;
}
unsigned int Series::getNumber() const
{
	return number;
}
Article* Series::getContent() const
{
	return content;
}
size_t Series::getArticlesCount() const
{
	return articlesCount;
}