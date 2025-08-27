// Calef Alesse
// Student ID: 2439923
// calesse@chapman.edu
// CPSC 350- 03
// PA03 Do You See What I See?

#ifndef MONOSTACK_H
#define MONOSTACK_H
#include <iostream>
#include <stdexcept>

// Templated Class 
template<typename T>
class MonoStack{
    private:
        T* stackArr; // dynamic array
        int top; // top element in stack
        int maxSize; // max size of stack
        char direction; // order of the stack ('i' for increasing, 'd' for decreasing)
        int count;

    public:
        MonoStack(int size, char o); // constructor
        ~MonoStack(); // destructor

        // methods
        void push(T value);
        T pop();
        T peek();
        bool isEmpty() const;
        bool isFull() const;
        void clear();
        int size();
};


// constructor
template <typename T>
MonoStack<T>::MonoStack(int size, char o) {
    maxSize = size;
    direction = o;
    stackArr = new T[maxSize]; 
    count = 0;
    top = -1;
}

// destructor
template <typename T>
MonoStack<T>::~MonoStack() {
    delete[] stackArr;
}

// return size of array
template <typename T>
int MonoStack<T>::size(){
    return count;
}

// push function 
template <typename T>
void MonoStack<T>::push(T value) {
    // monotonic stack
    // check if stack is in descending order
    if (isEmpty()){
        stackArr[++top] = value;
        ++count;
        return; // done adding, return so it doesn't add again later
    } else if(direction == 'd') {
        // remove elements that are smaller
        while (!isEmpty() && peek() < value) {
            pop();
        }
    } else if (direction == 'i') {  // check if stack is in ascending order
        // remove elements that are larger
        while (!isEmpty() && peek() > value) {
            pop();
        }
    }
    stackArr[++top] = value; // assign value
    ++count;
}

//pop function 
template <typename T>
T MonoStack<T>::pop(){
    // remove from the top
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty. Cannot pop.");
    } 
    // decrease count and return top of stack      
    --count;
    return stackArr[top--];
}


// peek function
template <typename T>
T MonoStack<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
        return -1;
    }
    return stackArr[top];
}

// isEmpty
template <typename T>
bool MonoStack<T>::isEmpty() const{
    // check if stack is empty
    return count == 0; // return true if stack is empty
}

// isFull
template <typename T>
bool MonoStack<T>::isFull() const {
    // check if stack is full
    return top == maxSize - 1; // return true if stack is full
}


// clear the stack
template <typename T>
void MonoStack<T>::clear() {
    top = -1; // reset top to -1 to clear the stack
}
 
#endif