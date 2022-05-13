#include <iostream>
#include<cstring>
#include "String.h"
#include "LibraryItems.h"
#include "ItemFactory.cpp"

int main()
{
    LibraryItem* item = ItemFactory::create("Book");
    return 0;
}