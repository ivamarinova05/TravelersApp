#ifndef __PERSON_H_
#define __PERSON_H_

#include "Trip.h"

#include <vector>

class Person
{
    private:
    std::string username;
    std::string password;
    std::string email;
    std::vector<Trip> trips;
    std::vector<std::string> notifications;
    std::vector<std::string> friends;

    public:
    void createPerson();
    void printPerson();
    void addTrip();
    void savePerson();
    void loadPerson(std::string, std::string, std::string);
    void viewNotifications();
    void acceptFriend(std::string);
    void eraseNotifications();
    bool isFriend(std::string);

    std::string getName() const;
};

#endif