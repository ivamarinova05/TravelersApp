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
    file.open("people.txt");
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
    filename.append(".txt");
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