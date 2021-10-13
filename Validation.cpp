#include "Validation.h"

#include <fstream>
#include <iostream>


bool Validation::validateRequest(std::string sender, std::string reciever)
{
    std::fstream file;
    reciever.append("_notifications.txt");
    file.open(reciever, std::ios::in);
    while(file)
    {
        std::string request;
        getline(file, request);
        auto index = request.find_last_of(' ');
        std::string _sender = request.substr(++index);
        _sender.pop_back();
        if ( sender == _sender)
        {
            return true;
        }
    }
    return false;
}

bool Validation::existingUser(std::string name)
{
    std::fstream file;
    file.open("users.db", std::ios::in);
    while (file)
    {
        std::string user, ignore;
        file >> user;
        if (user == name)
        {
            return true;
        }
        getline (file, ignore);
    }
    return false;
}

bool Validation::newDestination(std::string destination)
{
    //destination is not already in the database
    std::fstream file;
    file.open("destinations.db", std::ios::in);
    while(file)
    {
        std::string currDestination;
        getline(file, currDestination);
        if (destination == currDestination)
        {
            file.close();
            return false;
        }
    }
    file.close();
    return true;
}