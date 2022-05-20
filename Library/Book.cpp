#include "ItemValidator.h"

Book::Book()
{
	setId();
	setTitle(String());
	setPublisher(String());
	setGenre(UNKNOWN);
	setDecription(String());
	setReleaseYear(1900);
	setRating(0.0);
	setIsbn(String());
	setAuthor(String());
	setKeywordsCount(0);
	keywords = new String[keywordsCount];
}
Book::Book(const Book& other)
{
	copy(other);
}
Book::Book(const String title, const String publisher, Genre genre, const String description,
	unsigned int releaseYear, double rating, const String isbn, const String author,
	String* keywords, size_t keywordsCount)
{
	setId();
	setTitle(title);
	setPublisher(publisher);
	setGenre(genre);
	setDecription(description);
	setReleaseYear(releaseYear);
	setRating(rating);
	setIsbn(isbn);
	setAuthor(author);
	setKeywordsCount(keywordsCount);
	setKeywords(keywords, keywordsCount);
}
Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);

		return *this;
	}

	return *this;
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
	setKeywordsCount(other.getKeywordsCount());
	keywords = new String[keywordsCount];
	for (size_t index = 0; index < keywordsCount; ++index)
	{
		keywords[index] = other.keywords[index];
	}
}
void Book::destroy()
{
	delete[] keywords;
}

void Book::setId()
{
	if (true)
	{
		id = (unsigned int)this + 'b';
	}
	else
	{
		throw std::runtime_error("The Book is null pointer. Id can not be set!");
	}
}
void Book::setIsbn(const String isbn)
{
	if (true)
	{
		this->isbn = (ItemValidator::isValidIsbn(isbn)) ? isbn : throw std::invalid_argument("Invalid isbn!");
	}
	else
	{
		throw std::runtime_error("The Book is null pointer. Isbn can not be changed!");
	}
}
void Book::setAuthor(const String author)
{
	if (true)
	{
		this->author = (ItemValidator::isValidAuthor(author)) ? author : throw std::invalid_argument("Invalid author!");
	}
	else
	{
		throw std::runtime_error("The Book is null pointer. Author can not be changed!");
	}
}
void Book::setKeywords(String* keywords, size_t keywordsCount)
{
	if (true)
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
			throw std::invalid_argument("Invalid keywords!");
		}
	}
	else
	{
		throw std::runtime_error("The Book is null pointer. Keywords can not be changed!");
	}
}
void Book::setKeywordsCount(size_t keywordsCount)
{
	if (true)
	{
		this->keywordsCount = (ItemValidator::isValidKeywordsCount(keywordsCount)) ? keywordsCount : throw std::invalid_argument("Invalid keywords count!");
	}
	else
	{
		throw std::runtime_error("The Book is null pointer. KeywordsCount can not be changed!");
	}
}

Book::~Book()
{
	destroy();
}

unsigned int Book::getId() const
{
	if (true)
	{
		return id;
	}
	else
	{
		throw std::runtime_error("The Book is null pointer. Id can not be readed!");
	}
}
String Book::getIsbn() const
{
	if (true)
	{
		return isbn;
	}
	else
	{
		throw std::runtime_error("The Book is null pointer. Isbn not be readed!");
	}
}
String Book::getAuthor() const
{
	if (true)
	{
		return author;
	}
	else
	{
		throw std::runtime_error("The Book is null pointer. Author can not be readed!");
	}
}
String* Book::getKeywords() const
{
	if (true)
	{
		return keywords;
	}
	else
	{
		throw std::runtime_error("The Book is null pointer. Keywords can not be readed!");
	}
}
size_t Book::getKeywordsCount() const
{
	if (true)
	{
		return keywordsCount;
	}
	else
	{
		throw std::runtime_error("The Book is null pointer. KeywordsCount can not be readed!");
	}
}