#include "ItemValidator.h"

LibraryItem::LibraryItem()
{
	try
	{
		setTitle(String());
		setPublisher(String());
		setGenre(UNKNOWN);
		setDecription(String());
		setReleaseYear(1900);
		setRating(0.0);
	}
	catch (std::invalid_argument& invalidArgumentEx)
	{
		String exMsg = invalidArgumentEx.what();
		String msg = " Unable to initialize LibraryItem object!";
		throw new std::invalid_argument((exMsg + msg).getBuffer());
	}
	catch (std::runtime_error& runtimeErr)
	{
		String exMsg = runtimeErr.what();
		String msg = " Create non null pointer LibraryItem object!";
		throw new std::runtime_error((exMsg + msg).getBuffer());
	}
	catch (std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}
LibraryItem::LibraryItem(const String title, const String publisher, const Genre genre,
	const String description, const unsigned int releaseYear, const double rating)
{
	try
	{
		setTitle(title);
		setPublisher(publisher);
		setGenre(genre);
		setDecription(description);
		setReleaseYear(releaseYear);
		setRating(rating);
	}
	catch (std::invalid_argument& invalidArgumentEx)
	{
		String exMsg = invalidArgumentEx.what();
		String msg = " Unable to initialize LibraryItem object!";
		throw new std::invalid_argument((exMsg + msg).getBuffer());
	}
	catch (std::runtime_error& runtimeErr)
	{
		String exMsg = runtimeErr.what();
		String msg = " Create non null pointer LibraryItem object!";
		throw new std::runtime_error((exMsg + msg).getBuffer());
	}
	catch (std::exception& ex)
	{
		throw new std::exception(ex.what());
	}
}

void LibraryItem::setGenre(const Genre genre)
{
	if (this != nullptr)
	{
		this->genre = (ItemValidator::isValidGenre(genre)) ? genre : throw std::invalid_argument("Invalid genre!");
	}
	else
	{
		throw std::runtime_error("The LibraryItem is null pointer. Genre can not be changed!");
	}
}
void LibraryItem::setDecription(const String description)
{
	if (this != nullptr)
	{
		this->description = (ItemValidator::isValidDescription(description)) ? description : throw std::invalid_argument("Invalid description!");
	}
	else
	{
		throw std::runtime_error("The LibraryItem is null pointer. Description can not be changed!");
	}
}
void LibraryItem::setReleaseYear(const unsigned int releaseYear)
{
	if (this != nullptr)
	{
		this->releaseYear = (ItemValidator::isValidReleaseYear(releaseYear)) ? releaseYear : throw std::invalid_argument("Invalid release year!");
	}
	else
	{
		throw std::runtime_error("The LibraryItem is null pointer. ReleaseYear can not be changed!");
	}
}
void LibraryItem::setTitle(const String title)
{
	if (this != nullptr)
	{
		this->title = (ItemValidator::isValidTilte(title)) ? title : throw std::invalid_argument("Invalid title!");
	}
	else
	{
		throw std::runtime_error("The LibraryItem is null pointer. Title can not be changed!");
	}
}
void LibraryItem::setPublisher(const String publisher)
{
	if (this != nullptr)
	{
		this->publisher = publisher;
	}
	else
	{
		throw std::runtime_error("The LibraryItem is null pointer. Publisher can not be changed!");
	}
}
void LibraryItem::setRating(const double rating)
{
	if (this != nullptr)
	{
		this->rating = rating;
	}
	else
	{
		throw std::runtime_error("The LibraryItem is null pointer. Rating can not be changed!");
	}
}

unsigned int LibraryItem::getId() const
{
	if (this != nullptr)
	{
		return id;
	}
	else
	{
		throw new std::runtime_error("The LibraryItem is null pointer. Id can not be readed!");
	}
}
String LibraryItem::getTitle() const
{
	if (this != nullptr)
	{
		return title;
	}
	else
	{
		throw new std::runtime_error("The LibraryItem is null pointer. Title can not be readed!");
	}
}
String LibraryItem::getPublisher() const
{
	if (this != nullptr)
	{
		return publisher;
	}
	else
	{
		throw new std::runtime_error("The LibraryItem is null pointer. Publisher can not be readed!");
	}
}
Genre LibraryItem::getGenre() const
{
	if (this != nullptr)
	{
		return genre;
	}
	else
	{
		throw new std::runtime_error("The LibraryItem is null pointer. Genre can not be readed!");
	}
}
String LibraryItem::getDecription() const
{
	if (this != nullptr)
	{
		return description;
	}
	else
	{
		throw new std::runtime_error("The LibraryItem is null pointer. Description can not be readed!");
	}
}
unsigned int LibraryItem::getReleaseYear() const
{
	if (this != nullptr)
	{
		return releaseYear;
	}
	else
	{
		throw new std::runtime_error("The LibraryItem is null pointer. ReleaseYear can not be readed!");
	}
}
double LibraryItem::getRating() const
{
	if (this != nullptr)
	{
		return rating;
	}
	else
	{
		throw new std::runtime_error("The LibraryItem is null pointer. Rating can not be readed!");
	}
}