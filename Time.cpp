
/* File:    Time.cpp
 * Project: CMSC 202 Project 3, Spring 2016
 * Author:  Nick Stommel
 * Date:    03/30/16
 * Section: 7
 * Email:   stommel1@gl.umbc.edu 
 * 
 * Description:
 * 
 * Time source file containing implementation of Time class functions.
 * 
 */

#include <iostream>
using namespace std;

#include "Time.h"

Time::Time() : m_hours(0), m_minutes(0)
{/*Empty constructor body*/}

Time::Time(int hours, int minutes) {
    
    //Set m_hours and m_minutes to zero if an invalid time is provided
    if(hours > 23 || hours < 0 || minutes > 59 || minutes < 0) {
        m_hours = 0;
        m_minutes = 0;
    
    //Otherwise, if input hours and minutes are valid, assign accordingly
    } else {
        m_hours = hours;
        m_minutes = minutes;
    }
}

const Time Time::operator+(const int minutes) const {
    
    //Convert original time to minuteTime
    int minuteTime = m_hours * 60 + m_minutes;
    
    //Add minutes to original minuteTime
    int newTime = minuteTime + minutes;
    
    //Find newHours using integer division
    int newHours = newTime / 60;
    
    //Account for overflow of hours
    if(newHours > 23) {
        newHours -= 24;
    }
    
    //Find newMinutes using modulus operator
    int newMinutes = newTime % 60;
    
    //Return new, updated time
    return Time(newHours, newMinutes);
    
}

const bool Time::operator<(const Time& t) const {
    
    //Convert both Times to minuteTime
    int minuteTimeLeft = m_hours * 60 + m_minutes;
    int minuteTimeRight = t.m_hours * 60 + t.m_minutes;
    
    if(minuteTimeLeft < minuteTimeRight) {
        return true;
        
    } else {
        return false;
    }
    
}

ostream& operator<<(ostream& outStream, const Time& t) {
    
    //Print hours
    if(t.m_hours < 10) {
        outStream << 0 << t.m_hours << ":";
    } else {
        outStream << t.m_hours << ":";
    }
    
    //Print minutes
    if(t.m_minutes < 10) {
        outStream << 0 << t.m_minutes;
    } else {
        outStream << t.m_minutes;
    }
    
    return outStream;
    
}