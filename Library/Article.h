#pragma once
#ifndef ARTICLE_H
#define ARTICLE_H

#include "String.h"

/// <summary>
/// <c>Article</c> is a class which describes an article as a part of
/// a <c>Series</c> class object ccontent. Every <c>Article</c> object 
/// is composed from title, authour and keywords.
/// </summary>
class Article
{
private:
	
	/// <summary>
	/// <value>
	/// An article field from custom <c>String</c> type 
	/// which stores the article title.
	/// </value>
	/// </summary>
	String title;
	
	/// <summary>
	/// <value>
	/// An article field from custom <c>String</c> type 
	/// which stores the article authour name.
	/// </value>
	/// </summary>
	String authour;
	
	/// <summary>
	/// <value>
	/// An article filed from array of custom <c>String</c> 
	/// type which stores the article keywords.
	/// </value>
	/// </summary>
	String* keywords;
	
	/// <summary>
	/// <value>
	/// An article field from <c>size_t</c> type which stores 
	/// the article keywords count.
	/// </value>
	/// </summary>
	size_t keywordsCount;

	/// <summary>
	/// <c>setTitle(const String title)</c> is a set method in the <c>Article</c> class. 
	/// If title (parameter value of type <c>const String</c>) is valid,
	/// it sets title as a value of an article title field. But if title 
	/// (parameter value of type <c>const String</c>) is not valid, it 
	/// throws a <exception>std::invalid_argument</exception> exception
	/// with a custom message. If article which called this method is null 
	/// pointer, it throws a <exception>std::runtime_error</exception> exception
	/// with a custom message. This method does not return anything.
	/// </summary>
	/// 
	/// <param name="title"> 
	/// takes a <c>const String</c> value, checks wheather it can be
	/// a valid title and if it so, it sets <c>title</c> value as a 
	/// title of the article.
	/// </param>
	void setTitle(const String& title);
	
	/// <summary>
	/// <c>setAuthour(const String authour)</c> is a set method in the <c>Article</c> class.
	/// If authour (parameter value of type <c>const String</c>) is valid,
	/// it sets authour as a value of an article authour field. But if authour 
	/// (parameter value of type <c>const String</c>) is not valid, it 
	/// throws a <exception>std::invalid_argument</exception> exception
	/// with a custom message. If article which called this method is null 
	/// pointer, it throws a <exception>std::runtime_error</exception> exception
	/// with a custom message. This method does not return anything.
	/// </summary>
	/// 
	/// <param name="authour"> 
	/// takes a <c>const String</c> value, checks wheather it can be a valid 
	/// authour name and if it so, it sets <c>authour</c> value as an authour 
	/// name of the article.
	/// </param>
	void setAuthour(const String& authour);
	
	/// <summary>
	/// <c>setKeywordsAndKeywordsCount(const String* keywords, const size_t keywordsCount)</c> is 
	/// a set method in the <c>Article</c> class. If keywords (parameter value 
	/// of type <c>const String*</c>) and keywordsCount (parameter value of type 
	/// <c>const size_t</c>) are valid, it sets keywords as a value of an article 
	/// keywords field. But if keywords (parameter value of type <c>const String*</c>) 
	/// and keywordsCount (parameter value of type <c>const size_t</c>) are not valid, 
	/// it throws a <exception>std::invalid_argument</exception> exception with a custom 
	/// message. If article which called this method is null pointer, it throws a <exception>
	/// std::runtime_error</exception> exception with a custom message. This method does not 
	/// return anything.
	/// </summary>
	/// 
	/// <param name="keywords"> 
	/// takes a const String* value, checks wheather it can be a valid keywords array and 
	/// if it so, it sets <c>keywords</c> value as a keywords array of the article.</param>
	/// <param name="keywordsCount">takes a <c>const size_t</c> value, checks wheather it 
	/// can be a valid article keywords count and if it so, it sets <c>keywordsCount</c> value 
	/// as a keywords count of the article.
	/// </param>
	void setKeywordsAndKeywordsCount(const String* keywords, const size_t& keywordsCount);

	/// <summary>
	/// <c>copy(const Article&amp; other)</c> is a method in the <c>Article</c> class.
	/// It copies every field of other as a value of every field of this article. 
	/// This method does not return anything.
	/// </summary>
	/// 
	/// <param name="other"> 
	/// takes <c>const Article&amp;</c> value and copies fields of other in fields of this article.
	/// </param>
	void copy(const Article& other);
	
	/// <summary>
	/// <c>destroy()</c> is a method in the <c>Article</c> class.
	/// It frees up dynamically allocated memory when we have no 
	/// need from it anymore. This method does not return anything.
	/// </summary>
	void destroy();

public:
	
	/// <summary>
	/// <c>Article()</c> is a default constructor, so it initialize <c>Article</c> object fields 
	/// with default values, using the setter methods and the validation in it. If anything is wrong in 
	/// the runtime of the <c>Article</c> object creation, method catches <c>std::invalid_argument</c>,
	/// <c>std::runtime_error</c> and <c>std::exception</c>, then throws them upper in the method chain. But if 
	/// everything is fine, the constructor successfully initialize every <c>Article</c> object fields with 
	/// valid values.
	/// </summary>
	Article();
	
	/// <summary>
	/// <c>Article(const Article&amp; other)</c> is a copy constructor in <c>Article</c> class, so it initialize <c>Article</c> 
	/// object fields with pre-created <c>Article</c> object fields, using <c>copy(const Article&amp; other)</c> method. If anything 
	/// is wrong in the runtime of the <c>Article</c> object creation, method catches <c>std::invalid_argument</c>, 
	/// <c>std::runtime_error</c> and <c>std::exception</c>, then throws them upper in the method chain. But if everything is fine, 
	/// the constructor successfully initialize every <c>Article</c> object fields with valid values. 
	/// </summary>
	/// 
	/// <param name="other"> 
	/// takes <c>const Article&amp;</c> value and via <c>copy(const Article&amp; other)</c> method initialize
	/// <c>Article</c> object fields.
	/// </param>
	Article(const Article& other);

	/// <summary>
	/// <c>operator=(const Article&amp; other)</c> is a pre-defined operator in <c>Article</c> class.
	/// </summary>
	/// 
	/// <returns>
	/// If this article is not a null pointer, the operator returns this <c>Article</c> object aligned to othe <c>Article</c> object. 
	/// But if this article is null pointer, the methods throws <exception>std::runtime_error</exception> with a custom message.
	/// </returns>
	Article& operator=(const Article& other);
	
	/// <summary>
	/// <c>Article(const String title, const String authour, const String* keywords, const size_t keywordsCount)</c> is a constructor 
	/// with parameters in <c>Article</c> class, so it initialize <c>Article</c> object fields with its parameters values, using the 
	/// setter methods and the validation in it. If anything is wrong in the runtime of the <c>Article</c> object creation, the 
	/// method catches <c>std::invalid_argument</c>, <c>std::runtime_error</c> and <c>std::exception</c>, then throws them upper in the 
	/// method chain. But if everything is fine, the constructor successfully initialize every <c>Article</c> object fields with 
	/// valid values. 
	/// </summary>
	/// 
	/// <param name="title">
	/// takes <c>const String</c> value and treats it as title field value.
	/// </param>
	/// <param name="authour">
	/// takes <c>const String</c> value and treats it as authour field value.
	/// </param>
	/// <param name="keywords">
	/// takes <c>const String*</c> value and treats it as keywords field value.
	/// </param>
	/// <param name="keywordsCount">
	/// takes <c>const size_t</c> value and treats it as keywordsCount value.
	/// </param>
	Article(const String& title, const String& authour, const String* keywords, const size_t& keywordsCount);
	
	/// <summary>
	/// <c>~Article()</c> is a destructor in the <c>Article</c> class. It frees up dynamically allocated 
	/// memory, using <c>destroy()</c> method, when we have no need from it anymore.
	/// </summary>
	~Article();

	/// <summary>
	/// <c>getTitile()</c> is a method in <c>Article</c> class.
	/// </summary>
	/// 
	/// <returns>
	/// If this article is not a null pointer, the method returns the article title. But if this article is null pointer, 
	/// the methods throws a <exception>std::runtime_error</exception> with a custom message.
	/// </returns>
	const String getTitle() const;

	/// <summary>
	/// <c>getAuthour()</c> is a method in <c>Article</c> class.
	/// </summary>
	/// 
	/// <returns>
	/// If this article is not a null pointer, the method returns the article authour name. But if this article is null pointer, 
	/// the methods throws a <exception>std::runtime_error</exception> with a custom message.
	/// </returns>
	const String getAuthour() const;

	/// <summary>
	/// <c>getKeywords()</c> is a method in <c>Article</c> class.
	/// </summary>
	/// 
	/// <returns>
	/// If this article is not a null pointer, the method returns the article keywords array. But if this article is null pointer, 
	/// the methods throws a <exception>std::runtime_error</exception> with a custom message.
	/// </returns>
	const String* getKeywords() const;

	/// <summary>
	/// <c>getKeywordsCount()</c> is a method in <c>Article</c> class.
	/// </summary>
	/// 
	/// <returns>
	/// If this article is not a null pointer, the method returns the article keywords count. But if this article is null pointer, 
	/// the methods throws a <exception>std::runtime_error</exception> with a custom message.
	/// </returns>
	const size_t getKeywordsCount() const;
};

#endif