#include <cstring>
#include "Student.h"
#include "iostream"
#include "vector"
#include<bits/stdc++.h>

using namespace std;
const char *Student::getName() const {
    return name;
}

int Student::getMGa() const {
    return m_GA;
}

void Student::setMGa(int mGa) {
    m_GA = mGa;
}

int Student::getMGb() const {
    return m_GB;
}

void Student::setMGb(int mGb) {
    m_GB = mGb;
}

int Student::getMGc() const {
    return m_GC;
}

void Student::setMGc(int mGc) {
    m_GC = mGc;
}

Student::Student() {}

Student::Student(int id,char name[], int mGa, int mGb, int mGc) {
    this ->setId(id);
    strcpy(this->name,name);
    this->setMGa(mGa);
    this->setMGb(mGb);
    this->setMGc(mGc);
    this->setMAvg(calculateAVg());
    this->setMTotal(calculateTotal());
}

Student::~Student() {

}

double Student::calculateAVg() {
    return double (getMGa()+getMGb()+getMGc())/3;
}

double Student::calculateTotal() {
    return double (getMGa()+getMGb()+getMGc());
}

string Student::print() {
    string name=getName();
    string output= "Student "
         + name
//         + " has the following grades: \nsubject A:"
//         + to_string(getMGa())
//         + "\nsubject b:"
//         + to_string(getMGb())
//         + "\nsubject c:"
//         + to_string(getMGc())
//         + "\ntotal of:"
         + to_string(calculateTotal()) + "\n";
//         + "and average of:";
//         + to_string(calculateAVg()) + "\n";
    return output;

}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    Student::id = id;
}

double Student::getMAvg() const {
    return m_Avg;
}

void Student::setMAvg(double mAvg) {
    m_Avg = mAvg;
}

double Student::getMTotal() const {
    return m_Total;
}

void Student::setMTotal(double mTotal) {
    m_Total = mTotal;
}




