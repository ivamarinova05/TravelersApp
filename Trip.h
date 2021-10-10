#ifndef __TRIP_H_
#define __TRIP_H_

#include <string>

class Trip
{
    private:
    std::string destination;
    std::string notes;
    std::string images;
    size_t grade;
    std::string timePeriod;

    public:
    void addTrip();
    void printTrip();
    void serTrip(std::string);

};

#endif