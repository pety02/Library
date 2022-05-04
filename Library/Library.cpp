#include <iostream>
#include "CustomString.h"

int main()
{
    CustomString str1 = CustomString("Hello, ", 8, 7);
    CustomString str2 = CustomString("World!", 8, 6);
    CustomString concatedStr;
    concatedStr += (str1 + str2);
    std::cout << concatedStr.getValue();
    return 0;
}