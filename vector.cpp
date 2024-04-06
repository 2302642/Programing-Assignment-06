/*!****************************************************************************************************************************************************************************************************************************************************************************************\file       vector.hpp
\file       vector.cpp
\par        Author:          Najih
\par        Email:           n.hajasheikallaudin
\par        Course:          RSE1202    
\par        Section:         RSE
\par        Tutorial:        Assignment 6
\par        File created on: 29/02/2024 
\brief      user created vector with class
\par        File information:         
            This file is contains 5 constructors and 17 function definition to called by main in vector-driver.\n    
            constructors:
            - vector:: vector()                                                                                                                                                    // default constructor
            - vector:: vector(size_type n)                                                                                                                                         // non-default constructor with size
            - vector:: vector(std::initializer_list<int> rhs)                                                                                                                      // non-default constructor with initializer list
            - vector:: vector(const vector& rhs)                                                                                                                                   // copy constructor
            - vector::~vector()                                                                                                                                                    // destructor
            \n\n function:\n
            - vector& vector::operator=(const vector& rhs)                                                                                                                         // copy assignment operator to assigns the content of another vector to this vector
            - vector& vector::operator=(std::initializer_list<int> rhs)                                                                                                            // assignment operator for initializer list to assigns elements from an initializer list to this vector
            - vector::reference vector::operator[](size_type index)                                                                                                                // Subscript operator for non-const objects to hrow exception if index is out of range
            - vector::const_reference vector::operator[](size_type index) const                                                                                                    // Subscript operator for const objects to Throw exception if index is out of range
            - bool vector::empty() const                                                                                                                                           // checking if the vector is empty
            - vector::size_type vector::size() const                                                                                                                               // getting the size of the vector
            - vector::size_type vector::capacity() const                                                                                                                           // getting the capacity of the vector
            - void vector::reserve(size_type n)                                                                                                                                    // reserve function to update spaces allocated 
            - void vector::resize(size_type n)                                                                                                                                     // resize function to updated the size of the vector
            - void vector::push_back(value_type val)                                                                                                                               // push back function to add a new value to the end of the vector
            - vector::pointer vector::begin()                                                                                                                                      // iterator function to point to the start of the vector
            - vector::pointer vector::end()                                                                                                                                        // iterator function to Point to one past the end of the vector
            - vector::const_pointer vector::begin()   const                                                                                                                        // iterator function to Point to the start of the vector (const version)
            - vector::const_pointer vector::end()     const                                                                                                                        // iterator function to Point to one past the end of the vector (const version)
            - vector::const_pointer vector::cbegin()  const                                                                                                                        // iterator function to Point to the start of the vector (const version)
            - vector::const_pointer vector::cend()    const                                                                                                                        // iterator function to Point to one past the end of the vector (const version)
            - vector::size_type vector::allocations() const                                                                                                                        // getting the number of allocations	
******************************************************************************************************************************************************************************************************************************************************************************************/
#include <algorithm> // for std::copy
#include <stdexcept> // for std::out_of_range
#include "vector.hpp"

namespace hlp2 {
//##########################################################################################################################################################################################################################################################################################
//==========================================================================================================================================================================================================================================================================================
//|                                                                          CONSTRUCTORS SECTION                                                                                                                                                                                          |
//==========================================================================================================================================================================================================================================================================================
    vector:: vector()                               : sz{0},          space{0},          allocs{0}, data{nullptr} {}                                                                 // default constructor
    vector:: vector(size_type n)                    : sz{n},          space{n},          allocs{1}, data{new value_type[n]} {}                                                       // non-default constructor with size
    vector:: vector(std::initializer_list<int> rhs) : sz{rhs.size()}, space{rhs.size()}, allocs{1}, data{new value_type[rhs.size()]} { std::copy(rhs.begin(), rhs.end(), data); }    // non-default constructor with initializer list
    vector:: vector(const vector& rhs)              : sz{rhs.sz},     space{rhs.sz},     allocs{1}, data{new value_type[rhs.sz]}     { std::copy(rhs.data,  rhs.data+sz, data); }    // copy constructor
    vector::~vector() { delete[] data; }                                                                                                                                             // destructor
//==========================================================================================================================================================================================================================================================================================
//|                                                                          FUNCTIONS SECTION                                                                                                                                                                                             |
//==========================================================================================================================================================================================================================================================================================
    vector& vector::operator=(const vector& rhs) {                                                                                                                                   // copy assignment operator to assigns the content of another vector to this vector
        if (this != &rhs) {                                                                                                                                                          // Check for self-assignment
            delete[] data;                                                                                                                                                           // deallocating old storage
            sz = rhs.sz;                                                                                                                                                             // copying size from rhs
            space = rhs.sz;                                                                                                                                                          // copying space from rhs
            ++allocs;                                                                                                                                                                // incrementing allocation count
            data = new value_type[sz];                                                                                                                                               // allocating new storage
            std::copy(rhs.data, rhs.data + sz, data);                                                                                                                                // copying elements from rhs.data to data array
        }
        else if(this == &rhs){ space = rhs.sz; ++allocs; }                                                                                                                           // Handle self-assignment  
        return *this;                                                                                                                                                                // returning reference to the modified vector
    }
//*******************************************************************************************************************************************************************************************************************************************************************************************
    vector& vector::operator=(std::initializer_list<int> rhs) {                                                                                                                      // assignment operator for initializer list to assigns elements from an initializer list to this vector
        delete[] data;                                                                                                                                                               // deallocating old storage
        sz = rhs.size();                                                                                                                                                             // copying size from initializer list
        space = rhs.size();                                                                                                                                                          // copying space from initializer list
        allocs = 1;                                                                                                                                                                  // Set allocation count to 1
        data = new value_type[sz];                                                                                                                                                   // allocating new storage
        std::copy(rhs.begin(), rhs.end(), data);                                                                                                                                     // copying elements from initializer list to data vector
        return *this;                                                                                                                                                                // returning reference to the modified vector
    }
//*******************************************************************************************************************************************************************************************************************************************************************************************
    vector::reference vector::operator[](size_type index) { if (index >= sz) { throw std::out_of_range("Index out of range"); } return data[index]; }                                // Subscript operator for non-const objects to hrow exception if index is out of range
    vector::const_reference vector::operator[](size_type index) const { if (index >= sz) { throw std::out_of_range("Index out of range"); } return data[index]; }                    // Subscript operator for const objects to Throw exception if index is out of range
//*******************************************************************************************************************************************************************************************************************************************************************************************
    bool vector::empty() const {  return sz == 0; }                                                                                                                                  // checking if the vector is empty
    vector::size_type vector::size() const { return sz; }                                                                                                                            // getting the size of the vector
    vector::size_type vector::capacity() const { return space; }                                                                                                                     // getting the capacity of the vector
    vector::size_type vector::allocations() const { return allocs;    }                                                                                                              // getting the number of allocations
//*******************************************************************************************************************************************************************************************************************************************************************************************
    void vector::reserve(size_type n) {                                                                                                                                              // reserve function to update spaces allocated 
        if (n <= space) { return; }                                                                                                                                                  // do nothing if requested capacity is less than or equal to current capacity
        value_type* temp = new value_type[n];                                                                                                                                        // allocate new vector for temp
        std::copy(data, data + sz, temp);                                                                                                                                            // copy old elements to temp vector
        delete[] data;                                                                                                                                                               // deallocate old vector
        data = temp;                                                                                                                                                                 // updating cleared vector with data in temp vector
        space = n;                                                                                                                                                                   // update the capacity in the new vector
        ++allocs;                                                                                                                                                                    // incrementing the allocation count 
    }
//*******************************************************************************************************************************************************************************************************************************************************************************************
    void vector::resize(size_type n) {                                                                                                                                               // resize function to updated the size of the vector
        if (n == sz) { return; }                                                                                                                                                     // do nothing if requested size is equal to current size
        reserve(n);                                                                                                                                                                  // allocating new space
        if (n < sz) { sz = n; }                                                                                                                                                      // shrinking the vector
        else {                                                                                                                                                                       // expanding the vector
            std::fill(data + sz, data + n, value_type{});                                                                                                                            // initializing new elements if the expanding the vector
            sz = n;
        }
    }
//*******************************************************************************************************************************************************************************************************************************************************************************************
    void vector::push_back(value_type val) {                                                                                                                                         // push back function to add a new value to the end of the vector
        if (space == 0) { reserve(1); }                                                                                                                                              // reserving space for 1 element if the vector is empty
        else if (sz == space) { reserve(2 * space); }                                                                                                                                // doubling the space if the vector is full
        data[sz++] = val;                                                                                                                                                            // adding element at the end of the vector and incrementing the size
    }
//==========================================================================================================================================================================================================================================================================================
//|                                                                            ITERATOR FUNCTIONS SECTION                                                                                                                                                                                             |
//==========================================================================================================================================================================================================================================================================================
    vector::pointer       vector::begin()         { return data;      }                                                                                                              // point to the start of the vector
    vector::pointer       vector::end()           { return data + sz; }                                                                                                              // Point to one past the end of the vector
    vector::const_pointer vector::begin()   const { return data;      }                                                                                                              // Point to the start of the vector (const version)
    vector::const_pointer vector::end()     const { return data + sz; }                                                                                                              // Point to one past the end of the vector (const version)
    vector::const_pointer vector::cbegin()  const { return data;      }                                                                                                              // Point to the start of the vector (const version)
    vector::const_pointer vector::cend()    const { return data + sz; }                                                                                                              // Point to one past the end of the vector (const version)
//##########################################################################################################################################################################################################################################################################################
} // namespace hlp2
