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