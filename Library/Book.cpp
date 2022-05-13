#include "LibraryItems.h"
#include "ItemValidator.cpp"

Book::Book()
{
	setId();
	title = String();
	publisher = String();
	genre = UNKNOWN;
	description = String();
	releaseYear = 1900;
	rating = 0.0;
	isbn = String();
	author = String();
	keywordsCount = 0;
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
	}

	return *this;
}

void Book::copy(const Book& other)
{
	id = other.id;
	title = other.title;
	publisher = other.publisher;
	genre = other.genre;
	description = other.description;
	releaseYear = other.releaseYear;
	rating = other.rating;
	isbn = other.isbn;
	author = other.author;
	keywordsCount = other.keywordsCount;
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
	id = (unsigned int)this + 'b';
}
void Book::setIsbn(const String isbn)
{
	this->isbn = (ItemValidatior::isValidIsbn(isbn)) ? isbn : throw new std::invalid_argument("Invalid isbn!");
}
void Book::setAuthor(const String author)
{
	this->author = (ItemValidatior::isValidAuthor(author)) ? author : throw new std::invalid_argument("Invalid author!");
}
void Book::setKeywords(String* keywords, size_t keywordsCount)
{
	if (ItemValidatior::isValidKeywords(keywords, keywordsCount))
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
void Book::setKeywordsCount(size_t keywordsCount)
{
	this->keywordsCount = (ItemValidatior::isValidKeywordsCount(keywordsCount)) ? keywordsCount : throw new std::invalid_argument("Invalid keywords count!");
}

Book::~Book()
{
	destroy();
}

unsigned int Book::getId() const
{
	return id;
}
String Book::getIsbn() const
{
	return isbn;
}
String Book::getAuthor() const
{
	return author;
}
String* Book::getKeywords() const
{
	return keywords;
}
size_t Book::getKeywordsCount() const
{
	return keywordsCount;
}