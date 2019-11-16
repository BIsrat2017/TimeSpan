// Bisrat Asefaw
// assignemetn HW2
// 10/11/19.
//
// file of the class TimeSpan that contains only the method prints
//Design and implement TimeSpan class which represents a duration in hours, minutes and seconds

#include <iomanip>
#include "timespan.h"

timespan::timespan() {
    this->hr = 0;
    this->min = 0;
    this->sec = 0;
    this->totalsec = 0;

}

//constructor that accepts one parameter
// @param hour the hour
//in timeSpan
timespan::timespan(double hr) {
    this->hr = hr;
    this->min = 0;
    this->sec = 0;
    this->totalsec = hr * 3600;
}

//constructor that accepts two parameter
//  hour represented double hr and minute represented double min
timespan::timespan(double hr, double min) {
    this->hr = hr;
    this->min = min;
    this->sec = 0;
    this->totalsec = hr * 3600 + min * 60;
}

//constructor that accepts three parameter
//hour represented double hr , minute represented double min and second represented double sec
timespan::timespan(double hr, double min, double sec) {
    this->hr = hr;
    this->min = min;
    this->sec = sec;
    this->totalsec = sec + min * 60 + hr * 3600;
}

//copy constructor that accepts TimeSpan and makes a copy of it
// parameter t the TimeSpan that is to be duplicated
timespan::timespan(const timespan &t) {
    this->totalsec = t.totalsec;
}

//helper method that used to format the TimeSpan
//into respective hour , minute and second
void timespan::simplify() {
    hr = totalsec / 3600;
    min = totalsec % 3600 / 60;
    sec = totalsec % 3600 % 60;
}

//overloading the << operator
//parameters ostream output and Timespan t
ostream &operator<<(ostream &output, timespan &t) {
    t.simplify();

    if (t.sec < 0||t.min<0) {

        if (t.sec<0) {
        t.sec *= -1;
        }
        if(t.min<0){
            t.min *= -1;
            if(t.hr<0){
                t.hr*=-1;
            }
        }
        output << "-";
    }
    output << t.hr << ":"<< setfill('0') << std::setw(2) << t.min << ":";

    output << setfill('0') << std::setw(2) << t.sec;
    stringstream ss;

    return output;
}

//overloading the == operator
//parameter TimeSpan t
///returns true if this timespan is equal to
//        the input parameter timespan t and
//      false otherwise.
bool timespan::operator==(timespan const &t) const {

    if (this == &t) {
        return true;
    }
    if (this->totalsec == t.totalsec) {
        return true;
    } else {
        return false;
    }

}

//overloading the != operator
//parameter Timespan t
//returns true if this timespan is different from
//        the input parameter timespan t
//        and false otherwise.
bool timespan::operator!=(timespan const &t) const {
    //t.simplify();
    if (this->totalsec != t.totalsec) {
        return true;
    }
    return false;
}


//overloading the > operator
//parameter Timespan t
//returns true if this timespan is greater than
//        the input parameter timespan t and
//        false otherwise.
bool timespan::operator>(timespan const &t) const {
    if (this->totalsec > t.totalsec) {
        return true;
    }
    return false;
}

//overloading the < operator
//parameter Timespan t
//returns true if this timespan is less than
//        the input parameter timespan t and
//        false otherwise.
bool timespan::operator<(timespan const &t) const {
    if (this->totalsec < t.totalsec) {
        return true;
    }
    return false;
}

//overloading the >= operator
//parameter Timespan t
//returns true if this timespan is greater than
//        or equals the input parameter timespan t and
//        false otherwise.
bool timespan::operator>=(timespan const &t) const {
    if (this->totalsec >= t.totalsec) {
        return true;
    }
    return false;
}

//overloading the <= operator
//parameter Timespan t
//returns true if this timespan is less than
//        or equals the input parameter timespan t and
//        false otherwise.
bool timespan::operator<=(timespan const &t) const {
    if (this->totalsec <= t.totalsec) {
        return true;
    }
    return false;
}

// overloading + operator
// gets a parameter TimeSpan t
// and returns the sum of this plus t
timespan timespan::operator+(timespan const &t) const {
    timespan temp;
    temp.totalsec = this->totalsec + t.totalsec;
    return temp;
}

// overloading - operator
// gets a parameter TimeSpan t
// and returns the difference of this plus t
timespan timespan::operator-(timespan const &t) const {
    timespan temp;
    temp.totalsec = this->totalsec - t.totalsec;
    return temp;
}

//overloading the multiplication * by integer operator
//parameter num input integer
//returns the current timespan multiplied by integer
timespan timespan::operator*(double num) {
    timespan temp;
    temp.totalsec = this->totalsec * num;
    return temp;
}

// overloading += binary operator
// gets a parameter TimeSpan t
// and returns the current time span
//  with added t
timespan &timespan::operator+=(timespan const &t) {
    this->totalsec = this->totalsec + t.totalsec;
    return *this;
}

// overloading -= binary operator
// gets a parameter TimeSpan t
// and returns the current time span
//  by subtracting t
timespan &timespan::operator-=(timespan const &t) {
    this->totalsec = this->totalsec - t.totalsec;
    return *this;
}

//overloading the assignment = operator
//parameter t the other timespan
//retruns the current timespan that assigned to t other
timespan &timespan::operator=(const timespan &t) {
    this->totalsec = t.totalsec;
    return *this;
}










