//
//  main.cpp
//  LectureTitle
//
//  Created by Boris Tarovik on 25.06.2021.
//

#include <iostream>
#include <string>

using namespace std;

struct Specialization {
    string value;
    explicit Specialization(const string& newValue) {
        value = newValue;
    }
};

struct Course {
    string value;
    explicit Course(const string& newValue) {
        value = newValue;
    }
};

struct Week {
    string value;
    explicit Week(const string& newValue) {
        value = newValue;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    
    LectureTitle(const Specialization& s, const Course& c, const Week& w) {
        specialization = s.value;
        course = c.value;
        week = w.value;
    }

};


