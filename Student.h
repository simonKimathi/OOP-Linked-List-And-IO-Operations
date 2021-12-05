#ifndef STUDENT_STUDENT_H
#define STUDENT_STUDENT_H
#include<vector>
#include <string>

using namespace std;
class Student {
    int id;
    char name[10];
    int m_GA=0, m_GB=0, m_GC=0;
    double m_Avg;
    double m_Total;
public:
    Student();

    Student(int id,char name[], int mGa, int mGb, int mGc);

    const char *getName() const;

    int getId() const;

    void setId(int id);

    int getMGa() const;

    void setMGa(int mGa);

    int getMGb() const;

    void setMGb(int mGb);

    int getMGc() const;

    void setMGc(int mGc);

    double getMAvg() const;

    void setMAvg(double mAvg);

    double getMTotal() const;

    void setMTotal(double mTotal);

    virtual ~Student();
    double calculateAVg();
    double calculateTotal();
    string print();
};


#endif //STUDENT_STUDENT_H
