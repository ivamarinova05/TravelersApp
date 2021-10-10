#include "CommandLineReader.h"
#include "Person.h"
#include <iostream>
#include <fstream>

void CLR::signup()
{
    Person newPerson;
    newPerson.createPerson();
}

void CLR::signin()
{
    std::string username, password, ignore;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    std::ifstream file;
    file.open("users.db", std::ios::in);
    std::string _username, _password;
    while (file)
    {
        file >> _username;
        if (_username.compare(username) == 0)
        {
            file >> _password;
            if (_password.compare(password) == 0)
            {
                std::cout << "You have successfully signed in!\n";
                file.close();
                break;
                //load files?
            }
            else
            {
                std::cout << "Wrong password!\n";
                file.close();
                signin();
            }
            
        }
        else 
        {
            std::cout << "Wrong username!\n";
            file.close();
            signin();
        }
        getline (file, ignore);
        //file >> _username;
        //file >> _username;
    }


}