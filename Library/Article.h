#pragma once
#ifndef ARTICLE_H
#define ARTICLE_H

#include "String.h"

class Article
{
private:
	String title;
	String authour;
	String* keywords;
	size_t keywordsCount;

	void setTitle(const String title);
	void setAuthour(const String authour);
	void setKeywords(String* keywords, size_t keywordsCount);
	void setKeywordsCount(size_t keywordsCount);

	void copy(const Article& other);
	void destroy();

public:
	Article();
	Article(const Article& other);
	Article(const String title, const String authour, String* keywords, size_t keywordsCount);
	Article& operator=(const Article& other);
	~Article();

	String getTitle() const;
	String getAuthour() const;
	String* getKeywords() const;
	size_t getKeywordsCount() const;
};

#endif