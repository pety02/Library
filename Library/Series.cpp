#include "LibraryItemValidator.h"

void Series::setId()
{
	id = (unsigned int)this + 's';
}

void Series::setIssn(const String& issn)
{
	this->issn = (LibraryItemValidator::isValidIssn(issn)) ? issn : throw std::invalid_argument("Invalid issn!");
}

void Series::setReleaseMonth(const unsigned int& releaseMonth)
{
	this->releaseMonth = (LibraryItemValidator::isValidReleaseMonth(releaseMonth)) ? releaseMonth : throw std::invalid_argument("Invalid release month!");
}

void Series::setNumber(const unsigned int& number)
{
	this->number = (LibraryItemValidator::isValidNumber(number)) ? number : throw std::invalid_argument("Invalid number!");
}

void Series::setArticlesAndArticlesCount(const Article* articles, const size_t& articlesCount)
{
	if (LibraryItemValidator::isValidArticlesCount(articlesCount))
	{
		this->articlesCount = articlesCount;
		if (LibraryItemValidator::isValidContent(articles, articlesCount))
		{
			this->articles = new Article[articlesCount];
			for (size_t index = 0; index < articlesCount; index++)
			{
				this->articles[index] = articles[index];
			}
		}
		else
		{
			throw std::invalid_argument("Invalid articles!");
		}
	}
	else
	{
		throw std::invalid_argument("Invalid articles count!");
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
	setArticlesAndArticlesCount(other.getArticles(), other.getArticlesCount());
}

void Series::destroy()
{
	delete[] articles;
}


Series::Series() : LibraryItem()
{
	try
	{
		setId();
		setIssn(String());
		setReleaseMonth(1);
		setNumber(0);
		setArticlesAndArticlesCount(new Article[0], getArticlesCount());
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		destroy();
		ExceptionLogger::logException(DateTime(), "exceptions.txt", 
			"Invalid argument Exception", invalidArgumentEx.what());
	}
	catch (const std::exception& ex)
	{
		destroy();
		ExceptionLogger::logException(DateTime(), "exceptions.txt", 
			"Exception", ex.what());
	}
	catch (...)
	{
		try
		{
			std::exception_ptr eptr = std::current_exception();
			std::rethrow_exception(eptr);
		}
		catch (const std::exception& ex)
		{
			ExceptionLogger::logException(DateTime(), "exceptions.txt",
				"Unknown Exception", ex.what());
		}
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
		destroy();
		ExceptionLogger::logException(DateTime(), "exceptions.txt",
			"Invalid argument Exception", invalidArgumentEx.what());
	}
	catch (const std::exception& ex)
	{
		destroy();
		ExceptionLogger::logException(DateTime(), "exceptions.txt", 
			"Exception", ex.what());
	}
	catch (...)
	{
		try
		{
			std::exception_ptr eptr = std::current_exception();
			std::rethrow_exception(eptr);
		}
		catch (const std::exception& ex)
		{
			ExceptionLogger::logException(DateTime(), "exceptions.txt",
				"Unknown Exception", ex.what());
		}
	}
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
		destroy();
		ExceptionLogger::logException(DateTime(), "exceptions.txt", 
			"Invalid argument Exception", invalidArgumentEx.what());
	}
	catch (const std::exception& ex)
	{
		destroy();
		ExceptionLogger::logException(DateTime(), "exceptions.txt", 
			"Exception", ex.what());
	}
	catch (...)
	{
		try
		{
			std::exception_ptr eptr = std::current_exception();
			std::rethrow_exception(eptr);
		}
		catch (const std::exception& ex)
		{
			ExceptionLogger::logException(DateTime(), "exceptions.txt",
				"Unknown Exception", ex.what());
		}
	}
}

Series::Series(const String& title, const String& publisher, const Genre& genre, const String& description,
	const unsigned int& releaseYear, const double& rating, const String& issn,
	const unsigned int& releaseMonth, const unsigned int& number, const Article* content,
	const size_t& articlesCount) : LibraryItem(title, publisher, genre, description, releaseYear, rating)
{
	try
	{
		setId();
		setIssn(issn);
		setReleaseMonth(releaseMonth);
		setNumber(number);
		setArticlesAndArticlesCount(content, articlesCount);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		destroy();
		ExceptionLogger::logException(DateTime(), "exceptions.txt", 
			"Invalid argument Exception", invalidArgumentEx.what());
	}
	catch (const std::exception& ex)
	{
		destroy();
		ExceptionLogger::logException(DateTime(), "exceptions.txt", 
			"Exception", ex.what());
	}
	catch (...)
	{
		destroy();
		try
		{
			std::exception_ptr eptr = std::current_exception();
			std::rethrow_exception(eptr);
		}
		catch (const std::exception& ex)
		{
			ExceptionLogger::logException(DateTime(), "exceptions.txt",
				"Unknown Exception", ex.what());
		}
	}
}

Series::~Series()
{
	destroy();
}

const unsigned int Series::getId() const
{
	return id;
}

const String Series::getIssn() const
{
	return issn;
}

const unsigned int Series::getReleaseMonth() const
{
	return releaseMonth;
}

const unsigned int Series::getNumber() const
{
	return number;
}

const Article* Series::getArticles() const
{
	return articles;
}

const size_t Series::getArticlesCount() const
{
	return articlesCount;
}