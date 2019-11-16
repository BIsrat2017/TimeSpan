// Bisrat Asefaw
// assignemetn HW2
// 10/11/19.
//
// test classes TimeSpan that contains the testing cases for different cases
//implements TimeSpan class which represents a duration in hours, minutes and seconds
//all possible cases are tested to the best knowledge

#include <sstream>
#include <cassert>
#include <iostream>
#include "timespan.h"

using namespace std;

//test cases for constructor
void test1() {
    timespan ts(1, 20, 30);
    stringstream ss;
    ss << ts;
    assert(ss.str() == "1:20:30");

    timespan ts2(4, -20, -90);

    ss.str("");
    ss << ts2;
    assert(ss.str() == "3:38:30");

    timespan ts3(1.5, 30.5, -90);
    ss.str("");
    ss << ts3;
    assert(ss.str() == "1:59:00");

    timespan ts4(0, 0.07, 0);
    ss.str("");
    ss << ts4;
    assert(ss.str() == "0:00:04");
}

//test for the methods ==, != , + , * by integer.
// makes sure all the tests passes when called the time span class
void test2() {
    timespan ts(1, 20, 30);
    timespan ts2(1, 20, 30);
    timespan ts3(0, 0, 0);
    timespan ts4(2, 41, 00);
    assert(ts == ts2);
    assert(ts3 != ts2);
    assert(!(ts != ts2));
    assert((ts + ts + ts) == (ts2 * 3));
    assert((ts * 5) == (ts2 * 4) + ts2);
    assert((ts * 5) == (ts2 * 6) - ts2);
    assert((ts + ts - ts) == ((ts2 * 2) - ts));
    assert((ts - ts2) == ts3);
    assert((ts3 * 5) == ts3);

}

//tets for +=, -=,>,<,<=,>= and the deep copy constructor
// makes sure all the tests passes when called the time span class
void test3() {
    timespan test(1, 30);
    timespan test2(1, 30);
    timespan test3(1, 29);
    timespan test4(3);
    timespan test5(test);
    timespan test6(1,30,10);
    timespan test7(4,22,3);
    timespan test8(6,33,8);
    timespan test9(4,37);

    assert(test==test2);
    assert(test>=test2);
    assert(test2>test3);
    assert(test2>=test3);
    assert(test5==test2);
    assert(!(test4<=test));
    assert(test<test4);
    assert((test += test2) == test4);
    assert((test2-=test2)==(test2-test2));
    assert(!(test6>test8));
    assert(test9<=test8);
    assert(test2<=test);
    assert(test>=test2);

}

//calling all the test methods
void testAll() {
    test1();
    test2();
    test3();
}

//main method
int main() {
    testAll();
    
    
    cout << "Done." << std::endl;
    return 0;
}
