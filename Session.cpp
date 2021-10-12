#include "Session.h"
#include "Person.h"
#include <iostream>
#include <fstream>

Person Session::signup()
{
    Person user;
    user.createPerson();
    return user;
}

Person& Session::signin(Person& user)
{
    std::string username, password, ignore;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    std::ifstream file;
    file.open("users.db", std::ios::in);
    std::string _username, _password, _email;
    while (file)
    {
        file >> _username;
        if (_username.compare(username) == 0)
        {
            file >> _password;
            if (_password.compare(password) == 0)
            {
                std::cout << "You have successfully signed in!\n";
                file >> _email;
                user.loadPerson(_username, _password, _email);
                file.close();
                return user;
            }
            else
            {
                std::cout << "Wrong password!\n";
                file.close();
                signin(user);
                return user;
            }
            
        }
        else 
        {
            std::cout << "Wrong username!\n";
            file.close();
            signin(user);
            return user;
        }
        getline (file, ignore);
    }
    return user;
}