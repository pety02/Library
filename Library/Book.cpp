#include "LibraryItemValidator.h"

void Book::setType()
{
	type = Type::BOOK;
}

void Book::setIsbn(const String& isbn)
{
	this->isbn = (LibraryItemValidator::isValidIsbn(isbn)) ? isbn : throw std::invalid_argument("Invalid isbn!");
}

void Book::setAuthor(const String& author)
{
	this->author = (LibraryItemValidator::isValidAuthor(author)) ? author : throw std::invalid_argument("Invalid author!");
}

void Book::setKeywordsAndKeywordsCount(const String* keywords, const size_t& keywordsCount)
{
	if (LibraryItemValidator::isValidKeywordsCount(keywordsCount))
	{
		this->keywordsCount = keywordsCount;
		if (LibraryItemValidator::isValidKeywords(keywords, keywordsCount))
		{
			this->keywords = new String[keywordsCount];
			for (size_t index = 0; index < keywordsCount; ++index)
			{
				this->keywords[index] = keywords[index];
			}
		}
		else
		{
			throw std::invalid_argument("Invalid keywords!");
		}
	}
	else
	{
		throw std::invalid_argument("Invalid keywords count!");
	}
}

void Book::copy(const Book& other)
{
	setId();
	setTitle(other.getTitle());
	setPublisher(other.getPublisher());
	setGenre(other.getGenre());
	setDecription(other.getDecription());
	setReleaseYear(other.getReleaseYear());
	setRating(other.getRating());
	setIsbn(other.getIsbn());
	setAuthor(other.getAuthor());
	setKeywordsAndKeywordsCount(other.getKeywords(), other.getKeywordsCount());
	setType();
}

void Book::destroy()
{
	delete[] keywords;
}

Book::Book() : LibraryItem()
{
	try
	{
		setId();
		setIsbn(String());
		setAuthor(String());
		setKeywordsAndKeywordsCount(new String[keywordsCount], keywordsCount);
		setType();
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
				"Unknwon Exception", ex.what());
		}
	}
}

Book::Book(const Book& other)
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

Book& Book::operator=(const Book& other)
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

Book::Book(const String& title, const String& publisher, const Genre& genre, const String& description,
	const unsigned int& releaseYear, const double& rating, const String& isbn, const String& author,
	const String* keywords, const size_t& keywordsCount) : LibraryItem(title, publisher, genre, description, releaseYear, rating)
{
	try
	{
		setId();
		setIsbn(isbn);
		setAuthor(author);
		setKeywordsAndKeywordsCount(keywords, keywordsCount);
		setType();
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

Book::~Book()
{
	destroy();
}

const unsigned int Book::getId() const
{
	return id;
}

const String Book::getIsbn() const
{
	return isbn;
}

const String Book::getAuthor() const
{
	return author;
}

const String* Book::getKeywords() const
{
	return keywords;
}

const size_t Book::getKeywordsCount() const
{
	return keywordsCount;
}