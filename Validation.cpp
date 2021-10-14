#include "Validation.h"

#include <fstream>
#include <iostream>
#include <sstream>

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

bool Validation::uniqueUser(std::string name)
{
    std::fstream file;
    file.open("users.db", std::ios::in);
    while(file)
    {
        std::string user, ignore;
        file >> user;
        if (user == name)
        {
            file.close();
            return false;
        }
        getline(file, ignore);
    }
    file.close();
    return true;
}

bool Validation::validTimePeriod(std::string timePeriod)
{
    std::string arr, dep;
    auto index = timePeriod.find_first_of(' ');
    
    arr = timePeriod.substr(0, index);
    dep = timePeriod.substr(++index);

    std::vector<int> arrival = convertDates(arr);
    std::vector<int> departure = convertDates(dep);

    if (arrival[1]<= 0 || arrival[1]>=13 || 
        departure[1] <= 0 || departure[1] >= 13 || 
        arrival[0] <=0 || departure[0] <=0 ||
        arrival[0] > 31 || departure[0] >31)
    {
        return false;
    }
    if ((arrival[2] % 4 == 0 && arrival[1] == 2 && arrival[0] > 29) ||
        (departure[2] % 4 == 0 && departure[1] == 2 && departure[0] > 29))
    {
        return false;
    }
    if ((arrival[2] % 4 != 0 && arrival[1] == 2 && arrival[0] > 28) ||
        (departure[2] % 4 == 0 && departure[1] == 2 && departure[0] > 28))
    {
        return false;
    }
    if((arrival[1] < 7 && arrival[1] % 2 ==0 && arrival[0] > 30) ||
       (arrival[1] > 8 && arrival[1] % 2 !=0 && arrival[0] > 30) ||
       (departure[1] < 7 && departure[1] % 2 ==0 && departure[0] > 30) ||
       (departure[1] > 8 && departure[1] % 2 !=0 && departure[0] > 30))
    {
        return false;
    }
    if(arrival[2] > departure[2])
    {
        return false;
    }
    if(arrival[2] < departure[2])
    {
        return true;
    }
    if (arrival[1] > departure[1])
    {
        return false;
    }
    if(arrival[1] < departure[1])
    {
        return true;
    }
    if(arrival[0] > departure[0])
    {
        return false;
    }

    return true;
    
}


std::vector<int> Validation::convertDates(std::string date)
{
    std::vector<int> result;
    int rDay, rMonth, rYear;
    std::stringstream day, month, year;
    
    day << date.substr(0,2);
    day >> rDay;

    month << date.substr(3,2);
    month >> rMonth;

    year << date.substr(6,2);
    year >> rYear;

    result.push_back(rDay);
    result.push_back(rMonth);
    result.push_back(rYear);
    return result;
}

bool Validation::validGrade(int grade)
{
    return (grade >= 1 && grade <=5);
}

bool Validation::validImages(std::string images)
{
    while (!images.empty())
    {
        std::string currImage;
        auto index = images.find_first_of(' ');
        if (index == images.npos)
        {
            currImage = images;
            images.clear();
        }
        else
        {
            currImage = images.substr(0,index);
            images.erase(0, ++index);
            std::cout << "\n" << currImage << "\n" << images << "\n";
        }
        
        std::string shortFormat = currImage.substr(currImage.length() - 4);
        std::string longFormat = currImage.substr(currImage.length() - 5);
        if (shortFormat != ".jpg" && shortFormat != ".png" && longFormat != ".jpeg")
        {
            return false;
        }
    }
    return true;
}