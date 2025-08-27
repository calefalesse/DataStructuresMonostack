// Calef Alesse
// Student ID: 2439923
// calesse@chapman.edu
// CPSC 350- 03
// PA03 Do You See What I See?

#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include "MonoStack.h"
#include <string>

class SpeakerView{
    private:
        int rows; // number of rows
        int columns; // number of columns
        float** seatingArray; // 2D array to store the seating heights

    public:
        SpeakerView(const std::string& filename); // constructor reads in file
        ~SpeakerView(); // destructor

        void colVisibility(int col); // calculate who can see in a row
        void totalVisibility(); // calculate who can see in auditorium 



};

#endif