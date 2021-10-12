#include "Trip.h"
#include <iostream>
#include <fstream>

void Trip::addTrip()
{
    std::string ignore;
    getline(std::cin, ignore);
    std::cout << "Input destination: ";
    getline(std::cin, destination);
    std::cout << "Input time period: ";
    getline(std::cin, timePeriod);
    std::cout << "How would you grade this destination: ";
    std::cin >> grade;
    getline(std::cin, ignore);
    std::cout << "Input some notes: ";
    getline(std::cin, notes);
    std::cout << "Add some images: ";
    getline(std::cin, images);
    getline(std::cin, ignore);
    //check images
}

void Trip::printTrip()
{
    std::cout << "Destination: " << destination 
              << "\nTime period: " << timePeriod
              << "\nGrade: " << grade
              << "\nNotes: " << notes
              << "\nImages: " << images
              << std::endl;
}

void Trip::serTrip(std::string filename)
{
    std::ofstream file;
    file.open(filename, std::ios::out | std::ios::app);
    file << destination << "\n"
         << timePeriod << "\n"
         << grade << "\n"
         << notes << "\n"
         << images << "\n";
    file.close(); 

}

void Trip::loadTrip(std::fstream& in)
{
    std::string ignore;
    getline(in, destination);
    getline(in, timePeriod);
    in >>grade;
    getline(in,ignore);
    getline(in, notes);
    getline(in, images);

}