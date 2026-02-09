// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
#include "Course.hpp"
#include "LinkedList.hpp"


struct Student {
        unsigned int id;
        std::string name;
        double gpa;
        LinkedList<Course> courses;

        Student(unsigned int i, std::string n, double g) : id(i), name(n), gpa(g) {}
};


#endif