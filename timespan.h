
// Bisrat Asefaw
// assignemetn HW2
// 10/11/19.
//
//header file of the class TimeSpan that contains only the method prints
//Design and implement TimeSpan class which represents a duration in hours, minutes and seconds

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H


#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class timespan {
public:

    //default constructor for
    timespan();

    //constructor that accepts one parameter
    // @param hour the hour
    //in timeSpan
    timespan(double hr);

    //constructor that accepts two parameter
    //  hour represented double hr and minute represented double min
    timespan(double hr, double min);

    //constructor that accepts three parameter
    //hour represented double hr , minute represented double min and second represented double sec
    timespan(double hr, double min, double sec);

    //copy constructor that accepts TimeSpan and makes a copy of it
    // parameter t the TimeSpan that is to be duplicated
    timespan(const timespan &t);

    //helper method that used to format the TimeSpan
    //into respective hour , minute and second
    void simplify();

    //overloading the << operator
    //parameters ostream output and Timespan t
    friend ostream &operator<<(ostream &output, timespan &t);

    //overloading the == operator
    //parameter TimeSpan t
    ///returns true if this timespan is equal to
    //        the input parameter timespan t and
    //      false otherwise.
    bool operator==(timespan const &t) const;

    //overloading the != operator
    //parameter Timespan t
    //returns true if this timespan is different from
    //        the input parameter timespan t
    //        and false otherwise.
    bool operator!=(timespan const &t) const;

    //overloading the > operator
    //parameter Timespan t
    //returns true if this timespan is greater than
    //        the input parameter timespan t and
    //        false otherwise.
    bool operator>(timespan const &t) const;

    //overloading the < operator
    //parameter Timespan t
    //returns true if this timespan is less than
    //        the input parameter timespan t and
    //        false otherwise.
    bool operator<(timespan const &t) const;

    //overloading the >= operator
    //parameter Timespan t
    //returns true if this timespan is greater than
    //        or equals the input parameter timespan t and
    //        false otherwise.
    bool operator>=(timespan const &t) const;

    //overloading the <= operator
    //parameter Timespan t
    //returns true if this timespan is less than
    //        or equals the input parameter timespan t and
    //        false otherwise.
    bool operator<=(timespan const &t) const;

    // overloading + operator
    // gets a parameter TimeSpan t
    // and returns the sum of this plus t
    timespan operator+(timespan const &t) const;

    // overloading - operator
    // gets a parameter TimeSpan t
    // and returns the difference of this plus t
    timespan operator-(timespan const &t) const;

    // overloading += binary operator
    // gets a parameter TimeSpan t
    // and returns the current time span
    //  with added t
    timespan &operator+=(const timespan &t);

    // overloading -= binary operator
    // gets a parameter TimeSpan t
    // and returns the current time span
    //  by subtracting t
    timespan &operator-=(const timespan &t);

    //overloading the multiplication * by integer operator
    //parameter num input integer
    //returns the current timespan multiplied by integer
    timespan operator*(double num);

    //overloading the assignment = operator
    //parameter t the other timespan
    //retruns the current timespan that assigned to t other
    timespan &operator=(const timespan &t);

//private member variable
// hr hour , min minut , sec second and totalsec total second stores the timespan in second
private:
    double sec;
    double min;
    double hr;
    int totalsec;

};


#endif //ASS2_TIMESPAN_H
