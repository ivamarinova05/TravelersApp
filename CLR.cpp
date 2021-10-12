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
    
    do
    {
        std::cin >> command;
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
            std::cout << "Please sign in or sign up first!\n>_";
        }
    } while ( command != "sign_in" && command != "sign_up");
    
    while (command != "exit")
    {
        std::cout << ">_";
        std::cin >> command;
        //once they sign in or sign up they shouldn't be able to do it again unless they log out.
        //logging out
        if (command == "add_destination")
        {
            user.addTrip();
        }
        else if (command != "exit")
        {
            std::cout << "Invalid command!\n";
        }
        getline(std::cin, ignore);
        
    }

}