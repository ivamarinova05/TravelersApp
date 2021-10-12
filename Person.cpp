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
}


void Person::printPerson()
{
    std::cout << "\nUsername: " << username
              << "\nPassword: " << password
              << "\nEmail: " << email
              << "\nTrips:\n";
    for (Trip t : trips)
    {
        t.printTrip();
    }
    std::cout << std::endl;
}

void Person::loadPerson(std::string _username, std::string _password, std::string _email)
{
    username = _username;
    password = _password;
    email = _email;
    std::fstream file;
    _username.append(".db");
    file.open(_username, std::ios::in);
    while (file)
    {
        Trip newTrip;
        newTrip.loadTrip(file);
        trips.push_back(newTrip);
    }
    trips.pop_back(); //sort that out like wtf
    file.close();
}