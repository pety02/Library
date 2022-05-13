#pragma once
#ifndef ARTICLE_H
#define ARTICLE_H

#include "String.h"

/// <summary>
/// 
/// </summary>
class Article
{
private:
	String title;
	String authour;
	String* keywords;
	size_t keywordsCount;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="title"></param>
	void setTitle(const String title);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="authour"></param>
	void setAuthour(const String authour);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="keywords"></param>
	/// <param name="keywordsCount"></param>
	void setKeywords(String* keywords, size_t keywordsCount);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="keywordsCount"></param>
	void setKeywordsCount(size_t keywordsCount);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	void copy(const Article& other);
	
	/// <summary>
	/// 
	/// </summary>
	void destroy();

public:
	/// <summary>
	/// 
	/// </summary>
	Article();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	Article(const Article& other);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="title"></param>
	/// <param name="authour"></param>
	/// <param name="keywords"></param>
	/// <param name="keywordsCount"></param>
	Article(const String title, const String authour, String* keywords, size_t keywordsCount);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Article& operator=(const Article& other);
	
	/// <summary>
	/// 
	/// </summary>
	~Article();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String getTitle() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String getAuthour() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	String* getKeywords() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	size_t getKeywordsCount() const;
};

#endif