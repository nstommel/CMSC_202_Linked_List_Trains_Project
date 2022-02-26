
/* File:    TrainCar.cpp
 * Project: CMSC 202 Project 3, Spring 2016
 * Author:  Nick Stommel
 * Date:    03/30/16
 * Section: 7
 * Email:   stommel1@gl.umbc.edu 
 * 
 * Description:
 * 
 * Train Car source file containing implementation of TrainCar class functions   
 * 
 */

//
// TrainCar.cpp
// 
// CMSC 202 Project file
//
// COMPLETE THE IMPLEMENTATION AS INSTRUCTED
//

#include <iostream>
using namespace std;

#include "TrainCar.h"

TrainCar::TrainCar() : m_next( NULL ), m_type( NoType )
{ /* empty constructor body */ }

TrainCar::TrainCar( TrainCar::cType car ) : m_next( NULL ),  m_type( car )
{ /* empty constructor body */ }

void TrainCar::setType( TrainCar::cType car ) {
  m_type = car;
}

TrainCar::cType TrainCar::getType() const {
  return m_type;
}

//
// IMPLEMENT THE OVERLOADED INSERTION OPERATOR
//
ostream& operator<<(ostream &outStream, const TrainCar& car) {
    
    //Switch statement used to print individual cars given type returned from 
    //getType() function
    switch(car.getType()) {
        case TrainCar::Locomotive:
            outStream << "[o Locomotive oo]";
            break;
        case TrainCar::CoachClass:
            outStream << "[oo Coach oo]";
            break;
        case TrainCar::BusinessClass:
            outStream << "[oo Business oo]";
            break;
        case TrainCar::DiningCar:
            outStream << "[oo Dining oo]";
            break;
        case TrainCar::SnackCar:
            outStream << "[oo Snack oo]";
            break;
        case TrainCar::SleepingCar:
            outStream << "[oo Sleeping oo]";
            break;
        default:
            outStream << "[oo NoType oo]";
            break;
    }
  
  return outStream;
}
