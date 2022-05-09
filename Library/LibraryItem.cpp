#include "LibraryItems.h"

/*

	String id;
	String title;
	String publisher;
	Genre genre;
	String description;
	unsigned int releaseYear;
	double rating;

*/

LibraryItem::LibraryItem()
{
	id = String();
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

}

String LibraryItem::getId() const
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

void LibraryItem::setPublisher(const String publisher)
{
	this->publisher = publisher;
}
void LibraryItem::setRating(double rating)
{
	this->rating = rating;
}