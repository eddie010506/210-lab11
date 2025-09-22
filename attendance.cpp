#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// this is a code that checks attendance based on time 
//and how many times they have attended thru out the semester
//time stamp of check in time
struct AttendanceRecord {
    time_t checkintime;
};
//this is for storing students
struct Student {
    string name;
    int StudentID;
    vector<AttendanceRecord> checkin;
    // each student has its own dynamic array, so using vector

};

//function prototypes

