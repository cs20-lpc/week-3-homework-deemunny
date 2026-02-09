#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

using namespace std;

// maybe these could go in a separate file
void insertStudent(LinkedList<Student>&);
void deleteStudent(LinkedList<Student>&);
void displayStudent(LinkedList<Student>&, unsigned int);
void displayAllStudents(LinkedList<Student>&);
void addCourse(LinkedList<Student>&);

int main()
{
  // TO DO: Insert your code to display a menu for user to select to add/delete/view Student and course information.
  cout << "Starting student dostuff program.";

  unsigned int id = 0;
  // string name = "";
  // double gpa = 0.0;
  // TODO: could load an existing list of students here from file. starting empty here tho
  LinkedList<Student> students;

  int userInput;

  do {
    cout 
      << "\nPlease enter a command:\n"
      << "1 Insert Student\n"
      << "2 Delete Student\n"
      << "3 Search Student\n"
      << "4 Display All\n"
      << "5 Count Students\n"
      << "6 Add Course to Student\n"
      << "0 Exit" << endl;
    cin >> userInput;
    cin.ignore();
  
    switch (userInput) {
      case 1:
          insertStudent(students);
          break;
      case 2:
          deleteStudent(students);
          break;
      case 3:
          cout << "Enter ID of student to display. ";
          cin >> id;
          cin.ignore();
          displayStudent(students, id);
          break;
      case 4:
          displayAllStudents(students);
          break;
      case 5:
          cout << students.getLength() << " students currently listed" << endl;
          break;
      case 6:
          addCourse(students);
          break;
      case 0:
          cout << "Kbye";
          break;
      default:
          cout << "bruh can you read?";
    }


  } while (userInput != 0);

return 0;

}

void insertStudent(LinkedList<Student>& students) {
  unsigned int id = 0;
  string name = "";
  double gpa = 0.0;
 
  cout << "Enter student ID: ";
  cin >> id;
  cin.ignore();

  cout << "Enter student name: ";
  getline(cin, name);
  
  cout << "Enter student GPA: ";
  cin >> gpa;
  cin.ignore();

  students.append(Student(id, name, gpa));

}

void deleteStudent(LinkedList<Student>& students) {
  unsigned int id = 0;
  int pos = -1;
  
  cout << "Enter student ID to delete. ";
  cin >> id;
  cin.ignore();

  // TODO: this should be its own helper function, finding via id
  for (int i = 0; i < students.getLength(); ++i) {
    if (students.getElement(i).id == id) {
      pos = i;
      i = students.getLength();
    } 
  }

  if (pos != -1) {
    cout << "Deleteing student " << students.getElement(pos).name << ", ID# " << students.getElement(pos).id << endl;
    students.remove(pos);    
  } else {
    cout << "Student with that ID not found." << endl;
  }
}

void displayStudent(LinkedList<Student>& students, unsigned int id) {
  int pos = -1;

  for (int i = 0; i < students.getLength(); ++i) {
    if (students.getElement(i).id == id) {
      pos = i;
      i = students.getLength();
    } 
  }

  if (pos != -1) {
    cout << "\nName: " << students.getElement(pos).name << "\nID# " << students.getElement(pos).id << "\nGPA: "
          << students.getElement(pos).gpa << "\nCourses: " << endl;
    for (int i = 0; i < students.getElement(pos).courses.getLength(); ++i) {
      cout << "   " << students.getElement(pos).courses.getElement(i).name << endl;
    }
  } else {
    cout << "Student with that ID not found." << endl;
  }
}

void displayAllStudents(LinkedList<Student>& students) {
  for (int i = 0; i < students.getLength(); ++i) {
    displayStudent(students, students.getElement(i).id);
  }
}

void addCourse(LinkedList<Student>& students) {
  int pos = -1; 
  int id = 0;
  string courseName;
  string courseLoc;

  cout << "Enter ID of student to add course. ";
  cin >> id;
  cin.ignore();

  for (int i = 0; i < students.getLength(); ++i) {
    if (students.getElement(i).id == id) {
      pos = i;
      i = students.getLength();
    } 
  }

  if (pos != -1) {
    cout << "Student found. Enter course name: "; 
    getline(cin, courseName); 
    cout << "\nEnter course location: ";
    getline(cin, courseLoc);
    students.getElement(pos).courses.append(Course(courseName,courseLoc));
    cout << "\nCourse added to student." << endl;
  } else {
    cout << "Student with that ID not found." << endl;
  }
}