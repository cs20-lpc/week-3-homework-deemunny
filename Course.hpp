// TODO:  Course class definitins go here.
#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

struct Course {
    std::string name;
    std::string location;
    
    Course(std::string n = "", std::string l = "") : name(n), location(l) {}
};

#endif