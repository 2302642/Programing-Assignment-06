/*!****************************************************************************************************************************************************************************************************************************************************************************************\file       vector.hpp
\file       vector.hpp
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
#ifndef VECTOR_HPP
#define VECTOR_HPP
////////////////////////////////////////////////////////////////////////////////
#include <cstddef>          // need this for size_t
#include <initializer_list> // need this for std::initializer_list<int>
namespace hlp2 {
  class vector {
    public:
        // Type aliases
        using size_type = std::size_t;
        using value_type = int;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;

        vector();                                                   // default constructor
        explicit vector(size_type n);                               // non-default constructor with size
        vector(std::initializer_list<int> rhs);                     // non-default constructor with initializer list
        vector(const vector& rhs);                                  // copy constructor
        ~vector();                                                  // destructor

        vector& operator=(const vector& rhs);                       // copy assignment operator to assigns the content of another vector to this vector
        vector& operator=(std::initializer_list<value_type> rhs);   // assignment operator for initializer list to assigns elements from an initializer list to this vector

        reference operator[](size_type index);                      // Subscript operator for non-const objects to hrow exception if index is out of range
        const_reference operator[](size_type index) const;          // Subscript operator for const objects to Throw exception if index is out of range

        bool empty() const;                                         // checking if the vector is empty
        size_type size() const;                                     // getting the size of the vector
        size_type capacity() const;                                 // getting the capacity of the vector
        size_type allocations() const;                              // getting the number of allocations

        void reserve(size_type n);                                  // reserve function to update spaces allocated
        void resize(size_type n);                                   // resize function to updated the size of the vector
        void push_back(value_type val);                             // push back function to add a new value to the end of the vector

            // iterators ...
        pointer begin();                                            // point to the start of the vector
        pointer end();                                              // Point to one past the end of the vector
        const_pointer begin()  const;                               // Point to the start of the vector (const version)
        const_pointer end()    const;                               // Point to one past the end of the vector (const version)
        const_pointer cbegin() const;                               // Point to the start of the vector (const version)
        const_pointer cend()   const;                               // Point to one past the end of the vector (const version)
      
    private:
        size_type sz;                                               // the number of elements in the array
        size_type space;                                            // the allocated size (in terms of elements) of the array
        size_type allocs;                                           // number of times space has been updated
        pointer data;                                               // the dynamically allocated array
  };
} // namespace hlp2
#endif // VECTOR_HPP
