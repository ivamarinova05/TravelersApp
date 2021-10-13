#ifndef __TRIP_H_
#define __TRIP_H_

#include <string>
#include <iostream>

class Trip
{
    private:
    std::string destination;
    std::string timePeriod;
    size_t grade;
    std::string notes;
    std::string images;
    
    

    public:
    void addTrip();
    void printTrip();
    void serTrip(std::string);
    void loadTrip(std::fstream&);
    std::string getDestination() const;
    std::string getNotes() const;
    size_t getGrade() const;

};

#endif