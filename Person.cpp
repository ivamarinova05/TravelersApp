#include "Person.h"
#include <iostream>
#include <fstream>

void Person::createPerson()
{
    std::string ignore;
    std::cout << "Input username: ";
    std::cin >> username;
    getline (std::cin, ignore);
    std::cout << "Input password: ";
    std::cin >> password;
    getline (std::cin, ignore);
    std::cout << "Input email: ";
    std::cin >> email;
    std::cout << "You have successfully registered in the system!\n";
    savePerson();
}

void Person::savePerson()
{
    std::ofstream file;
    file.open("users.db", std::ios::out | std::ios::app);
    file << username << " "
         << password << " "
         << email << "\n";
    file.close();

}

void Person::addTrip()
{
    Trip t;
    t.addTrip();
    trips.push_back(t);

    std::string filename;
    filename = username;
    filename.append(".db");
    t.serTrip(filename);

    std::fstream file;
    std::string destination = t.getDestination();
    destination.append(".db");
    file.open(destination, std::ios::out | std::ios::app);
    file << username << ": " << t.getNotes() << " " << t.getGrade() <<"\n";
}


void Person::printPerson()
{
    std::cout << "\nUsername: " << username
              << "\nTrips:\n";
    for (Trip t : trips)
    {
        t.printTrip();
    }
    std::cout << std::endl;
}

void Person::loadTrips()
{
    std::string _username = username;
    std::fstream file;
    _username.append(".db");
    file.open(_username, std::ios::in);

    if (file)
    {
        while (file)
        {
            Trip newTrip;
            newTrip.loadTrip(file);
            trips.push_back(newTrip);
        }
        trips.pop_back(); //sort that out like wtf
        file.close();
    }

}

void Person::loadFriends()
{
    std::fstream file;
    std::string _username = username;
    _username.append("_friends.txt");
    file.open(_username, std::ios::in);
    if (file)
    {
        while(file)
        {
            std::string user;
            file >> user;
            friends.push_back(user);
        }
    }
    file.close();

}

void Person::loadNotifications()
{
    std::fstream file;
    std::string _username = username;
    _username.append("_notifications.txt");
    file.open(_username, std::ios::in);
    if(file)
    {
       while(file)
        {
            std::string message;
            getline(file, message);
            notifications.push_back(message);
        } 
    }
}

void Person::loadPersonalData(std::string _username, std::string _password, std::string _email)
{
    username = _username;
    password = _password;
    email = _email;
}

void Person::loadPerson(std::string _username, std::string _password, std::string _email)
{
    this->loadPersonalData(_username, _password, _email);

    this->loadTrips();
    this->loadFriends();
    this->loadNotifications();
    
    size_t count = 0;
    if (notifications.size() != 0)
    {
        count = notifications.size() - 1;
    }
    //maybe check here if notifications.size() == 0
    std::cout << "Hello, " << username 
              << "! You have " << count  
              << " new notifications.\n Type view to see them.\n";
}

void Person::viewNotifications()
{
    if (notifications.size() == 0)
    {
        std::cout << "No new notifications.\n";
    }
    for (std::string s : notifications)
    {
        std::cout << s << "\n" ;
    }
    notifications.clear();


}

void Person::eraseNotifications()
{
    //empty the file with notifications
    std::fstream file;
    std::string _username = username;
    _username.append("_notifications.txt");
    file.open(_username, std::ios::out | std::ios::trunc);
    file.close();

}

void Person::acceptFriend(std::string user)
{
    std::string _username = username;
    friends.push_back(user);
    _username.append("_friends.txt");
    std::fstream file;
    file.open(_username, std::ios::out | std::ios::app);
    file << user << " ";
    file.close();
    std::cout << "You and " << user << " are friends now!\n";
}

bool Person::isFriend(std::string name)
{
    for (std::string user : friends)
    {
        if(user == name)
        {
            return true;
        }
    }
    return false;
}

std::string Person::getName() const
{
    return this->username;
}

    