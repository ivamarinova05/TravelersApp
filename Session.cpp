#include "Session.h"
#include "Person.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

void Session::addRequest(std::string sender, std::string reciever)
{
    //check if they are friends already
    std::string _sender = sender;
    _sender.append("_friends.txt");
    std::fstream file;
    file.open(_sender, std::ios::in);
    while (file)
    {
        std::string user;
        file >> user;
        if (user == reciever)
        {
            std::cout << "You and " << reciever << " are friends already!\n";
            return;
        }
    }
    file.close();
    std::string _reciever = reciever;
    _reciever.append("_notifications.txt");
    file.open(_reciever, std::ios::out | std::ios::app);
    file << "You have a new friend request from " << sender << ".\n";
    std::cout << "Your request has been sent to " << reciever << ".\n";
}

void Session::addFriend(std::string sender, std::string reciever)
{
    std::fstream file;
    std::string _sender = sender;
    _sender.append("_friends.txt");
    file.open(_sender, std::ios::out | std::ios::app);
    file << reciever << " ";
    file.close();

    _sender = sender;
    _sender.append("_notifications.txt");
    file.open(_sender, std::ios::out | std::ios::app);
    file << "You and " <<reciever << " are friends now!\n";
    file.close();
}

void Session::review(std::string destination, Person& user)
{
    std::vector<std::string> reviews;

    double score = 0;
    double counter = 0;
    destination.append(".db");
    destination.erase(0,1);
    std::fstream file;
    file.open(destination, std::ios::in);
    while(file)
    {
        std::string review;
        getline(file, review);
        if (!review.empty())
        {
           int num;
            std::stringstream currScore;
            currScore << review.back();
            currScore >> num;
            counter++;
            score += num;


            review.pop_back(); 
            reviews.push_back(review);
        }

             
    }
    
    std::vector<std::string> friendsReviews;
    std::vector<std::string> otherReviews;
    for (std::string review : reviews)
    {
        //get the name of the person who wrote the review
        auto index = review.find_first_of(':');
        std::string name = review.substr(0, index); 

        if(user.isFriend(name))
        {
            friendsReviews.push_back(review);
        }
        else
        {
            otherReviews.push_back(review);
        }
        
    }

    if(!friendsReviews.empty())
    {
        std::cout << "What your friends tought of this destination:\n";
        for (std::string review : friendsReviews)
        {
            std::cout << review << "\n";
        }
        std::cout << "Other people tought: \n";
    }

    for (std::string review : otherReviews)
    {
        std::cout << review << "\n";
    }

    std::cout << "Our users graded this place: " << score/counter << "/5.\n";


}

void Session::showProfile(std::string name)
{
    Person user;
    user.loadPersonalData(name, "", "");
    user.loadTrips();
    user.printPerson();
}