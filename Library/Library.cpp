#include <iostream>
#include<cstring>
#include <stdexcept>
#include "ItemFactory.h"
#include "Dates.h"

int main()
{
    /*String s = "hey, ";
    String s1 = "misho";//operator =
    s += s1;
    std::cout << s.getBuffer();
    
    //String* s = new String();
    //String str = "hey";
    String* str2 = nullptr;
    delete[] str2;*/
    //str2->operator+("haya");
    //str2 = new String(str);
    //str2->toString();
    //LibraryItem *item = nullptr;
    String* s = nullptr;
    try
    {
        s->popBack();
    }
    catch (std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return -1;
    }
    //DateTime* d = new DateTime();
    //std::cout << d->getDay() << "/" << d->getMonth() << "/" << d->getYear() << "-" << d->getHours() << ":" << d->getMinutes() << ":" << d->getSeconds();
    /*try
    {
        LibraryItem* book1 = ItemFactory::create("Book");
        //LibraryItem* book2 = ItemFactory::create("Book");
        //std::cout << book1->getId() << std::endl;
        //std::cout << book2->getId();
        return 0;
    }
    catch (std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        std::cout << "Type cmd: ";
        char* cmd = new char[256];
        std::cin >> cmd;
        String cmdStr = cmd;
        LibraryItem* item = ItemFactory::create(cmdStr);
        if (item != nullptr)
        {
            std::cout << item->getId() << std::endl;
        }
        else
        {
            std::cerr << ex.what();
        }
        return -1;
    }*/
}