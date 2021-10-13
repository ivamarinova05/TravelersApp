#include "CLR.h"
#include <iostream>
#include <string>
#include "Person.h"
#include "Session.h"
#include "Validation.h"

void CLR::read()
{
    Person user;
    Session currentSession;
    std::string command, ignore;
    std::cout << "Welcome! Please type sign_in or sign_up to log into the app!\n>_";
    
    do
    {
        //signing in/up in the app before using it
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

        //logging out

        if (command == "add_destination")
        {
            user.addTrip();
        }
        else if (command == "friend_request")
        {
            std::string reciever;
            std::cin >> reciever;
            if (Validation::existingUser(reciever))
            {
                currentSession.addRequest(user.getName(), reciever);
            }
            else 
            {
                std::cout << "There is no user with the name " << reciever << ".\n";
            }   
        }
        else if (command == "view")
        {
            user.viewNotifications();
        }

        //accepting requests
        else if (command == "accept")
        {
            std::string name;
            std::cin >> name;
            if (Validation::validateRequest(name, user.getName()))
            {
                user.acceptFriend(name);
                currentSession.addFriend(name, user.getName());
            }
            else
            {
                std::cout << "You have no friend request from " << name << ". Use friend_request to send one!\n";
            }
            
            
        }

        else if (command == "decline")
        {
            std::string name;
            std::cin >> name;
            if (Validation::validateRequest(name, user.getName()))
            {
                std::cout << "You have declined the friend request from " << name << ".\n";
            }
            else
            {
                std::cout << "You have no friend request from " << name << ".\n";
            }
            
        }
        //reviws of destinations
        else if (command == "review")
        {
            std::string destination;
            getline (std::cin, destination);
            currentSession.review(destination);
            getline(std::cin, ignore);

        }


        else if (command != "exit")
        {
            std::cout << "Invalid command!\n";
        }
        getline(std::cin, ignore);
        //save everything when user exits
    }

}