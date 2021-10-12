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
    if (!file)
    {
        std::cout << "Please sign up!\n";
        return user;
    }
    std::string _username, _password, _email;
    do
    {
        file >> _username;
        if (_username == username)
        {
            file >> _password;
            if (_password == password )
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
                //file.close();
                //ask if they want to continue
                signin(user);
                return user;
            }
            
        }
        getline (file, ignore);
    } while (file);
        
    std::cout << "Wrong username!\n";
    file.close();
    signin(user);
    return user;   
}