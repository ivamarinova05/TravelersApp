#include "CLR.h"
#include <iostream>
#include <string>
#include "Person.h"
#include "Session.h"

void CLR::read()
{
    Person user;
    Session currentSession;
    std::string command, ignore;
    std::cout << "Welcome! Please type sign_in or sign_up to log into the app!\n>_";
    std::cin >> command;
    while (command != "exit")
    {
        if (command == "sign_in")
        {
            user = currentSession.signin(user);
        }
        else if (command == "sign_up")
        {
            user = currentSession.signup();
        }
        else
        {
            std::cout << "Invalid command!\n";
        }
        getline(std::cin, ignore);
        std::cout << ">_";
        std::cin >> command;
    }

}