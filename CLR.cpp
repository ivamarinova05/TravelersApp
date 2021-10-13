#include "CLR.h"
#include <iostream>
#include <string>
#include "Person.h"
#include "Session.h"
#include "Validation.h"

void CLR::read()
{
    
    std::string ignore;
    std::cout << "Welcome! Please type sign_in or sign_up to log into the app!\n>_";
    this->logging();
    
    while (command != "exit")
    {
        std::cout << ">_";
        std::cin >> command;

        if (command == "add_destination")
        {
            user.addTrip();
        }
        else if (command == "friend_request")
        {
            this->friendRequest();  
        }
        else if (command == "view")
        {
            this->view();
            //user.eraseNotifications();
        }

        else if (command == "accept")
        {
            this->accept();
        }

        else if (command == "decline")
        {
            this->decline();
            
        }

        else if (command == "review")
        {
            this->review();

        }

        else if (command == "profile")
        {
            this->profile();  
        }

        else if (command != "exit")
        {
            std::cout << "Invalid command!\n";
        }
        //save everything when user exits
    }

}

void CLR::logging()
{
    do
    {
        //signing in/up in the app before using it
        std::cin >> command;
        if (command == "exit")
        {
            return;
        }
        else if (command == "sign_in")
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
}

void CLR::friendRequest()
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

void CLR::accept()
{
    std::string name;
    std::cin >> name;
    if (Validation::validateRequest(name, user.getName()))
    {
        user.acceptFriend(name);
        currentSession.addFriend(name, user.getName());
        user.eraseNotification(name);
    }
    else
    {
        std::cout << "You have no friend request from " << name << ". Use friend_request to send one!\n";
    }
}

void CLR::decline()
{
    std::string name;
    std::cin >> name;
    if (Validation::validateRequest(name, user.getName()))
    {
        std::cout << "You have declined the friend request from " << name << ".\n";
        std::string toDelete = "You have a new friend request from ";
        toDelete.append(name);
        toDelete.append(".");
        user.eraseNotification(toDelete);
    }
    else
    {
        std::cout << "You have no friend request from " << name << ".\n";
    }
}

void CLR::profile()
{
    std::string username;
    std::cin >> username;
    if (Validation::existingUser(username))
    {
        if(user.isFriend(username))
        {
            currentSession.showProfile(username);
        }
        else
        {
            std::cout << "You are not allowed to see " << username 
                      << "'s profile, because you are not friends.\n";
        }
    }
    else
    {
        std::cout << "There is no user with the name " << username << ".\n";
    }
}

void CLR::view()
{
    user.viewNotifications();
    user.eraseNotification();
    
}

void CLR::review()
{
    std::string destination;
    getline (std::cin, destination);
    currentSession.review(destination, user);
}