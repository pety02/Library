#include "ItemValidator.h"

void Article::setTitle(const String title)
{
	if (this != nullptr)
	{
		this->title = (ItemValidator::isValidTilte(title)) ? title : throw new std::invalid_argument("Invalid title!");
		return;
	}
	
	throw std::runtime_error("Article is null pointer object! Title can not be set.");
}

void Article::setAuthour(const String author)
{
	if(this != nullptr)
	{ 
		this->authour = (ItemValidator::isValidAuthor(author)) ? author : throw new std::invalid_argument("Invalid author!");
		return;
	}
	
	throw std::runtime_error("Article is null pointer object! Authour can not be set.");
}

void Article::setKeywords(const String* keywords, const size_t keywordsCount)
{
	if (this != nullptr)
	{
		if (ItemValidator::isValidKeywords(keywords, keywordsCount))
		{
			this->keywords = new String[keywordsCount];
			for (size_t index = 0; index < keywordsCount; ++index)
			{
				this->keywords[index] = keywords[index];
			}
			return;
		}
		
		throw new std::invalid_argument("Invalid keywords!");
	}
	
	throw std::runtime_error("Article is null pointer object! Keywords can not be set.");
}

void Article::setKeywordsCount(const size_t keywordsCount)
{
	if (this != nullptr)
	{
		this->keywordsCount = (ItemValidator::isValidKeywordsCount(keywordsCount)) ? keywordsCount : throw new std::invalid_argument("Invalid keywords count!");
		return;
	}

	throw std::runtime_error("Article is null pointer object! Keywords count can not be set.");
}

void Article::copy(const Article& other)
{
	title = other.title;
	authour = other.authour;
	keywordsCount = other.keywordsCount;
	keywords = new String[keywordsCount];
	for (size_t index = 0; index < keywordsCount; ++index)
	{
		keywords[index] = other.keywords[index];
	}
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
		setKeywordsCount(0);
		setKeywords(new String[keywordsCount], keywordsCount);
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

Article::Article(const Article& other)
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

Article::Article(const String title, const String authour, const String* keywords, const size_t keywordsCount)
{
	try
	{
		setTitle(title);
		setAuthour(authour);
		setKeywordsCount(keywordsCount);
		setKeywords(keywords, keywordsCount);
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

Article::~Article()
{
	destroy();
}

String Article::getTitle() const
{
	if (this != nullptr)
	{
		return title;
	}

	throw std::runtime_error("Article is null pointer object! Title can not be gotten.");
}

String Article::getAuthour() const
{
	if (this != nullptr)
	{
		return authour;
	}

	throw std::runtime_error("Article is null pointer object! Authour can not be gotten.");
}

String* Article::getKeywords() const
{
	if (this != nullptr)
	{
		return keywords;
	}

	throw std::runtime_error("Article is null pointer object! Keywords can not be gotten.");
}

size_t Article::getKeywordsCount() const
{
	if (this != nullptr)
	{
		return keywordsCount;
	}

	throw std::runtime_error("Article is null pointer object! Keywords count can not be gotten.");
}

Article& Article::operator=(const Article& other)
{
	if (this != nullptr)
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
	
	throw std::runtime_error("Article is null pointer object! operator = (const Article& other) can not be proceeded.");
	
}