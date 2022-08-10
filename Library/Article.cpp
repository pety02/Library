#include "LibraryItemValidator.h"

void Article::setTitle(const String& title)
{
	this->title = (LibraryItemValidator::isValidTilte(title)) ? title : throw new std::invalid_argument("Invalid title!");
}

void Article::setAuthour(const String& author)
{
	this->authour = (LibraryItemValidator::isValidAuthor(author)) ? author : throw new std::invalid_argument("Invalid author!");
}

void Article::setKeywordsAndKeywordsCount(const String* keywords, const size_t& keywordsCount)
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
			return;
		}
		else
		{
			throw new std::invalid_argument("Invalid keywords!");
		}
	}
	else
	{
		throw new std::invalid_argument("Invalid keywords count!");
	}
}

void Article::copy(const Article& other)
{
	setTitle(other.title);
	setAuthour(other.authour);
	setKeywordsAndKeywordsCount(other.keywords, other.keywordsCount);
}
void Article::destroy()
{
	delete[] keywords;
}

Article::Article()
{
	try
	{
		setTitle(String());
		setAuthour(String());
		setKeywordsAndKeywordsCount(new String[keywordsCount], keywordsCount);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		destroy();
		ExceptionLogger::logException(DateTime(), "exceptions.txt",
			"Invalid Argument Exception", invalidArgumentEx.what());
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
				"Invalid argument Exception", ex.what());
		}
	}
}

Article::Article(const Article& other)
{
	try
	{
		copy(other);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		destroy();
		ExceptionLogger::logException(DateTime(), "exceptions.txt",
			"Invalid Argument Exception", invalidArgumentEx.what());
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
				"Invalid argument Exception", ex.what());
		}
	}
}

Article& Article::operator=(const Article& other)
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
			"Invalid Argument Exception", invalidArgumentEx.what());
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
				"Invalid argument Exception", ex.what());
		}
	}
}

Article::Article(const String& title, const String& authour, const String* keywords, const size_t& keywordsCount)
{
	try
	{
		setTitle(title);
		setAuthour(authour);
		setKeywordsAndKeywordsCount(keywords, keywordsCount);
	}
	catch (const std::invalid_argument& invalidArgumentEx)
	{
		destroy();
		ExceptionLogger::logException(DateTime(), "exceptions.txt",
			"Invalid Argument Exception", invalidArgumentEx.what());
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
				"Invalid argument Exception", ex.what());
		}
	}
}

Article::~Article()
{
	destroy();
}

const String Article::getTitle() const
{
	return title;
}

const String Article::getAuthour() const
{
	return authour;
}

const String* Article::getKeywords() const
{
	return keywords;
}

const size_t Article::getKeywordsCount() const
{
	return keywordsCount;
}