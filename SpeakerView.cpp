// Calef Alesse
// Student ID: 2439923
// calesse@chapman.edu
// CPSC 350- 03
// PA03 Do You See What I See?

#include "SpeakerView.h"
#include "MonoStack.h"
#include <string>
#include <fstream>
#include <sstream>

// Constructor: Reads in the file and initializes the seating array
SpeakerView::SpeakerView(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        // Used Stack Overflow resource to throw errors
        throw std::runtime_error("Error: Unable to open file.");
    }

    std::string line;
    std::getline(file, line); // Read and ignore "BEGIN"

    // Read first row to determine number of columns
    if (!std::getline(file, line)) {
        throw std::runtime_error("File does not contain seating data.");
    }

    std::stringstream ss(line);
    float temp;
    columns = 0;
    while (ss >> temp) {
        ++columns;
        std::cout << "Columns: " << columns << std::endl;
    }
    
    // Count remaining rows
    rows = 1;
    while (std::getline(file, line) && line != "END") {
        ++rows;
        std::cout << "Rows: " << rows << std::endl;
    }

    
    // Allocate memory for seating array
    seatingArray = new float*[rows];
    for (int i = 0; i < rows; ++i) {
        seatingArray[i] = new float[columns];
    }

    /*BEGIN CODE FROM CHAT GPT, PROMPT ASKED: how do you reread a file 
    after already reading through it once in C++? */

    // Reset file and read data into seatingArray
    file.clear();
    file.seekg(0);
    std::getline(file, line); // Skip "BEGIN"

    /*END OF CODE FROM CHAT GPT*/

    // to avoid seg fault 
    double test = 0;
    // reads in actual values from file
    for (int i = 0; i < rows; ++i) {
        std::getline(file, line);
        std::stringstream ss(line);
        for (int j = 0; j < columns; ++j) {
            ss >> test; 
            seatingArray[i][j] = test;
        }
    }
}

// Destructor
SpeakerView::~SpeakerView() {
    for (int i = 0; i < rows; ++i) {
        delete[] seatingArray[i];
    }
    delete[] seatingArray;
}

// Visibility in each column
void SpeakerView::colVisibility(int col){

    MonoStack<float> stack(rows, 'd'); // 'd' for decreasing stack

    for (int row = rows-1; row >= 0; row--) { // iterate through each row starting at the bottom 
            stack.push(seatingArray[row][col]); // push the current seat's height onto the stack
    }


    // print the number of seats in the current column that can see
    std::cout << "In column " << col << ", there are " << std::to_string(stack.size()) << " seat(s) that can see. Their heights are: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << ", "; // pop and print each seat's height from the stack
    }
    std::cout << "inches. " << std::endl;
    std::cout << std::endl;

}

// computes visibility for whole auditorium
void SpeakerView::totalVisibility() {
    for (int col = 0; col < columns; col++) { // iterate through each column
        colVisibility(col); // function to compute visibility for the current column
    }
}


