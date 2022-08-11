#pragma warning(disable : 4996)

#include <iostream>
#include<cstring>
#include <stdexcept>
#include <fstream>
#include "Dates.h"
#include "Users.h"
#include "UserValidator.h"

/// <summary>
/// 
/// </summary>
/// <param name="username"></param>
/// <param name="password"></param>
void enterCredentials(String &username, String &password, String& reEnteredPassword)
{
    do
    {
        std::cout << "in";
        std::cout << "Enter username: ";
        std::cin >> username.getBuffer();
    } 
    while (!UserValidator::isValidUsername(username));

    do
    {
        std::cout << "Enter password: ";
        std::cin >> password.getBuffer();
    } 
    while (!UserValidator::isValidPassword(password));

    do
    {
        std::cout << "Re-enter password: ";
        std::cin >> reEnteredPassword.getBuffer();
    } 
    while (!UserValidator::isValidPassword(reEnteredPassword) || reEnteredPassword != password);
}

int main()
{
    String unm;
    String pass;
    String reEnteredPass;

    //enterCredentials(unm, pass, reEnteredPass);
    //UserController::registerUser(unm, pass, reEnteredPass);
   
    return 0;
}