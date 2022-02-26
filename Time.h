
/* File:    Time.h
 * Project: CMSC 202 Project 3, Spring 2016
 * Author:  Nick Stommel
 * Date:    03/30/16
 * Section: 7
 * Email:   stommel1@gl.umbc.edu 
 * 
 * Description:
 * 
 * Time header file containing declaration of Time class functions   
 * 
 */

#ifndef TIME_H
#define TIME_H

class Time {
    
public:
    
    //Default constructor
    Time();
    //Non-default constructor
    Time(int hours, int minutes);
    
    //Overloaded addition operator (method) for adding minutes to a time object
    const Time operator+(const int minutes) const;

    //Overloaded less than operator (method) for comparing Time objects
    const bool operator<(const Time& t) const;
    
    //Overloaded (friend function) insertion operator for printing time 
    //in a nice format
    friend ostream& operator<<(ostream& outStream, const Time& t);
    
    
private:
    
    int m_hours;
    int m_minutes;
};


#endif /* TIME_H */

