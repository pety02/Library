#include "ItemValidator.h"

void LibraryItem::setGenre(const Genre genre)
{
	if (this != nullptr)
	{
		this->genre = (ItemValidator::isValidGenre(genre)) ? genre : throw std::invalid_argument("Invalid genre!");
		return;
	}

	throw std::runtime_error("The LibraryItem is null pointer. Genre can not be changed!");
}

void LibraryItem::setDecription(const String description)
{
	if (this != nullptr)
	{
		this->description = (ItemValidator::isValidDescription(description)) ? description : throw std::invalid_argument("Invalid description!");
		return;
	}

	throw std::runtime_error("The LibraryItem is null pointer. Description can not be changed!");
}

void LibraryItem::setReleaseYear(const unsigned int releaseYear)
{
	if (this != nullptr)
	{
		this->releaseYear = (ItemValidator::isValidReleaseYear(releaseYear)) ? releaseYear : throw std::invalid_argument("Invalid release year!");
		return;
	}

	throw std::runtime_error("The LibraryItem is null pointer. ReleaseYear can not be changed!");
}

LibraryItem::LibraryItem()
{
	try
	{
		setTitle(String());
		setPublisher(String());
		setGenre(Genre::UNKNOWN);
		setDecription(String());
		setReleaseYear(1900);
		setRating(0.0);
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

void LibraryItem::setTitle(const String title)
{
	if (this != nullptr)
	{
		this->title = (ItemValidator::isValidTilte(title)) ? title : throw std::invalid_argument("Invalid title!");
		return;
	}
	
	throw std::runtime_error("The LibraryItem is null pointer. Title can not be changed!");
}

void LibraryItem::setPublisher(const String publisher)
{
	if (this != nullptr)
	{
		this->publisher = (ItemValidator::isValidPublisher(publisher)) ? publisher : throw std::invalid_argument("Invalid publisher!");
		return;
	}
	
	throw std::runtime_error("The LibraryItem is null pointer. Publisher can not be changed!");
}

void LibraryItem::setRating(const double rating)
{
	if (this != nullptr)
	{
		this->rating = (ItemValidator::isValidRating(rating)) ? rating : throw std::invalid_argument("Invalid rating!");
		return;
	}
	
	throw std::runtime_error("The LibraryItem is null pointer. Rating can not be changed!");
}

unsigned int LibraryItem::getId() const
{
	if (this != nullptr)
	{
		return id;
	}
	
	throw new std::runtime_error("The LibraryItem is null pointer. Id can not be readed!");
}

String LibraryItem::getTitle() const
{
	if (this != nullptr)
	{
		return title;
	}
	
	throw new std::runtime_error("The LibraryItem is null pointer. Title can not be readed!");
}

String LibraryItem::getPublisher() const
{
	if (this != nullptr)
	{
		return publisher;
	}
	
	throw new std::runtime_error("The LibraryItem is null pointer. Publisher can not be readed!");
}
Genre LibraryItem::getGenre() const
{
	if (this != nullptr)
	{
		return genre;
	}
	
	throw new std::runtime_error("The LibraryItem is null pointer. Genre can not be readed!");
}

String LibraryItem::getDecription() const
{
	if (this != nullptr)
	{
		return description;
	}
	
	throw new std::runtime_error("The LibraryItem is null pointer. Description can not be readed!");
}

unsigned int LibraryItem::getReleaseYear() const
{
	if (this != nullptr)
	{
		return releaseYear;
	}
	
	throw new std::runtime_error("The LibraryItem is null pointer. ReleaseYear can not be readed!");
}

double LibraryItem::getRating() const
{
	if (this != nullptr)
	{
		return rating;
	}
	
	throw new std::runtime_error("The LibraryItem is null pointer. Rating can not be readed!");
}