#include "ItemValidator.h"

Series::Series()
{
	try
	{
		setId();
		setTitle(String());
		setPublisher(String());
		setGenre(Genre::UNKNOWN);
		setDecription(String());
		setReleaseYear(1900);
		setRating(0.0);
		setIssn(String());
		setReleaseMonth(1);
		setNumber(0);
		setArticlesCount(0);
		
		content = new Article[0];
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

Series::Series(const Series& other)
{
	try
	{
		copy(other);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

Series::Series(const String title, const String publisher, const Genre genre, const String description,
	const unsigned int releaseYear, const double rating, const String issn, 
	const unsigned int releaseMonth, const unsigned int number, const Article* content, 
	const size_t articlesCount)
{
	try
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
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

void Series::setId()
{
	if (this != nullptr)
	{
		id = (unsigned int)this + 's';
		return;
	}

	throw std::runtime_error("The Series is null pointer. Id can not be set!");
}

void Series::setIssn(const String issn)
{
	if (this != nullptr)
	{
		this->issn = (ItemValidator::isValidIssn(issn)) ? issn : throw std::invalid_argument("Invalid issn!");
		return;
	}

	throw std::runtime_error("The Series is null pointer. Issn can not be changed!");
}

void Series::setReleaseMonth(const unsigned int releaseMonth)
{
	if (this != nullptr)
	{
		this->releaseMonth = (ItemValidator::isValidReleaseMonth(releaseMonth)) ? releaseMonth : throw std::invalid_argument("Invalid release month!");
		return;
	}

	throw std::runtime_error("The Series is null pointer. ReleaseMonth can not be changed!");
}

void Series::setNumber(const unsigned int number)
{
	if (this != nullptr)
	{
		this->number = (ItemValidator::isValidNumber(number)) ? number : throw std::invalid_argument("Invalid number!");
		return;
	}

	throw std::runtime_error("The Series is null pointer. Number can not be changed!");
}

void Series::setContent(const Article* content, const size_t articlesCount)
{
	if (this != nullptr)
	{
		if (ItemValidator::isValidContent(content, articlesCount))
		{
			for (size_t index = 0; index < articlesCount; index++)
			{
				this->content[index] = content[index];
			}
			return;
		}

		throw std::invalid_argument("Invalid content!");
	}

	throw std::runtime_error("The Series is null pointer. Content can not be changed!");
}

void Series::setArticlesCount(const size_t keywordsCount)
{
	if (this != nullptr)
	{
		articlesCount = (ItemValidator::isValidArticlesCount(articlesCount)) ? articlesCount : throw std::invalid_argument("Invalid articles count!");
		return;
	}

	throw std::runtime_error("The Series is null pointer. ArticlesCount can not be changed!");
}

Series& Series::operator=(const Series& other)
{
	try
	{
		if (this != &other)
		{
			destroy();
			copy(other);
		}

		return *this;
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		throw new std::invalid_argument(invalidArgumentEx.what());
	}
	catch (const std::runtime_error& runtimeErr)
	{
		throw new std::runtime_error(runtimeErr.what());
	}
	catch (const std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
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
	
	throw std::runtime_error("The Series is null pointer. Id can not be readed!");
}

String Series::getIssn() const
{
	if (this != nullptr)
	{
		return issn;
	}
	
	throw std::runtime_error("The Series is null pointer. Issn can not be readed!");
}

unsigned int Series::getReleaseMonth() const
{
	if (this != nullptr)
	{
		return releaseMonth;
	}
	
	throw std::runtime_error("The Series is null pointer. ReleaseMonth can not be readed!");
}

unsigned int Series::getNumber() const
{
	if (this != nullptr)
	{
		return number;
	}
	
	throw std::runtime_error("The Series is null pointer. Number can not be readed!");
}

Article* Series::getContent() const
{
	if (this != nullptr)
	{
		return content;
	}
	
	throw std::runtime_error("The Series is null pointer. Content can not be readed!");
}

size_t Series::getArticlesCount() const
{
	if (this != nullptr)
	{
		return articlesCount;
	}
	
	throw std::runtime_error("The Series is null pointer. ArticlesCount can not be readed!");
}