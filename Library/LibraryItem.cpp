#include "LibraryItemValidator.h"

void LibraryItem::setGenre(const Genre& genre)
{
	this->genre = (LibraryItemValidator::isValidGenre(genre)) ? genre : throw std::invalid_argument("Invalid genre!");
}

void LibraryItem::setDecription(const String& description)
{
	this->description = (LibraryItemValidator::isValidDescription(description)) ? description : throw std::invalid_argument("Invalid description!");
}

void LibraryItem::setReleaseYear(const unsigned int& releaseYear)
{
	this->releaseYear = (LibraryItemValidator::isValidReleaseYear(releaseYear)) ? releaseYear : throw std::invalid_argument("Invalid release year!");
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
		ExceptionLogger::logException(DateTime(), "exceptions.txt", 
			"Invalid argument Exception", invalidArgumentEx.what());
	}
	catch (const std::exception& ex)
	{
		ExceptionLogger::logException(DateTime(), "exceptions.txt", 
			"Exception", ex.what());
	}
	catch (...)
	{
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

LibraryItem::LibraryItem(const String& title, const String& publisher, const Genre& genre,
	const String& description, const unsigned int& releaseYear, const double& rating)
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
		ExceptionLogger::logException(DateTime(), "exceptions.txt", 
			"Invalid argument Exception", invalidArgumentEx.what());
	}
	catch (const std::exception& ex)
	{
		ExceptionLogger::logException(DateTime(), "exceptions.txt", 
			"Exception", ex.what());
	}
	catch (...)
	{
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

void LibraryItem::setTitle(const String& title)
{
	this->title = (LibraryItemValidator::isValidTilte(title)) ? title : throw std::invalid_argument("Invalid title!");
}

void LibraryItem::setPublisher(const String& publisher)
{
	this->publisher = (LibraryItemValidator::isValidPublisher(publisher)) ? publisher : throw std::invalid_argument("Invalid publisher!");
}

void LibraryItem::setRating(const double& rating)
{
	this->rating = (LibraryItemValidator::isValidRating(rating)) ? rating : throw std::invalid_argument("Invalid rating!");
}

const unsigned int LibraryItem::getId() const
{
	return id;
}

const String LibraryItem::getTitle() const
{
	return title;
}

const String LibraryItem::getPublisher() const
{
	return publisher;
}

const Genre LibraryItem::getGenre() const
{
	return genre;
}

const String LibraryItem::getDecription() const
{
	return description;
}

const unsigned int LibraryItem::getReleaseYear() const
{
	return releaseYear;
}

const double LibraryItem::getRating() const
{
	return rating;
}