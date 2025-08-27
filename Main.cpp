// Calef Alesse
// Student ID: 2439923
// calesse@chapman.edu
// CPSC 350- 03
// PA03 Do You See What I See?

#include <iostream>
#include "SpeakerView.h"

int main(int argc, char* argv[]) {

    std::string input = argv[1];
    SpeakerView auditorium(input);
    auditorium.totalVisibility();

    return 0;
}
