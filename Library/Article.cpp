#include "ItemValidator.h"

void Article::setTitle(const String title)
{
	this->title = (ItemValidator::isValidTilte(title)) ? title : throw new std::invalid_argument("Invalid title!");
}
void Article::setAuthour(const String author)
{
	this->authour = (ItemValidator::isValidAuthor(author)) ? author : throw new std::invalid_argument("Invalid author!");
}
void Article::setKeywords(String* keywords, size_t keywordsCount)
{
	if (ItemValidator::isValidKeywords(keywords, keywordsCount))
	{
		this->keywords = new String[keywordsCount];
		for (size_t index = 0; index < keywordsCount; ++index)
		{
			this->keywords[index] = keywords[index];
		}
	}
	else
	{
		throw new std::invalid_argument("Invalid keywords!");
	}
}
void Article::setKeywordsCount(size_t keywordsCount)
{
	this->keywordsCount = (ItemValidator::isValidKeywordsCount(keywordsCount)) ? keywordsCount : throw new std::invalid_argument("Invalid keywords count!");
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
	title = String();
	authour = String();
	keywordsCount = 0;
	keywords = new String[keywordsCount];
}
Article::Article(const Article& other)
{
	copy(other);
}
Article::Article(const String title, const String authour, String* keywords, size_t keywordsCount)
{
	setTitle(title);
	setAuthour(authour);
	setKeywordsCount(keywordsCount);
	setKeywords(keywords, keywordsCount);
}
Article& Article::operator=(const Article& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}
Article::~Article()
{
	destroy();
}

String Article::getTitle() const
{
	return title;
}
String Article::getAuthour() const
{
	return authour;
}
String* Article::getKeywords() const
{
	return keywords;
}
size_t Article::getKeywordsCount() const
{
	return keywordsCount;
}
