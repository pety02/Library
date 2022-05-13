#include "LibraryItems.h"
#include <cmath>
#include "ItemValidator.cpp"

LibraryItem::LibraryItem()
{
	title = String();
	publisher = String();
	genre = UNKNOWN;
	description = String();
	releaseYear = 1900;
	rating = 0.0;
}
LibraryItem::LibraryItem(const String title, const String publisher, Genre genre,
	const String description, unsigned int releaseYear, double rating)
{
	setTitle(title);
	setPublisher(publisher);
	setGenre(genre);
	setDecription(description);
	setReleaseYear(releaseYear);
	setRating(rating);
}

void LibraryItem::setGenre(Genre genre)
{
	this->genre = (ItemValidatior::isValidGenre(genre)) ? genre : throw new std::invalid_argument("Invalid genre!");
}
void LibraryItem::setDecription(const String description)
{
	this->description = (ItemValidatior::isValidDescription(description)) ? description : throw new std::invalid_argument("Invalid description!");
}
void LibraryItem::setReleaseYear(unsigned int releaseYear)
{
	this->releaseYear = (ItemValidatior::isValidReleaseYear(releaseYear)) ? releaseYear : throw new std::invalid_argument("Invalid release year!");
}
void LibraryItem::setTitle(const String title)
{
	this->title = (ItemValidatior::isValidTilte(title)) ? title : throw new std::invalid_argument("Invalid title!");
}
void LibraryItem::setPublisher(const String publisher)
{
	this->publisher = publisher;
}
void LibraryItem::setRating(double rating)
{
	this->rating = rating;
}

unsigned int LibraryItem::getId() const
{
	return id;
}
String LibraryItem::getTitle() const
{
	return title;
}
String LibraryItem::getPublisher() const
{
	return publisher;
}
Genre LibraryItem::getGenre() const
{
	return genre;
}
String LibraryItem::getDecription() const
{
	return description;
}
unsigned int LibraryItem::getReleaseYear() const
{
	return releaseYear;
}
double LibraryItem::getRating() const
{
	return rating;
}