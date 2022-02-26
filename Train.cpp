
/* File:    Train.cpp
 * Project: CMSC 202 Project 3, Spring 2016
 * Author:  Nick Stommel
 * Date:    03/30/16
 * Section: 7
 * Email:   stommel1@gl.umbc.edu 
 * 
 * Description:
 * 
 * Train source file containing implementation of Train Class functions   
 * 
 */

//
// Train.cpp
// 
// CMSC 202 Project File
//
// TWO CONSTRUCTORS ARE GIVEN.  IMPLEMENT THE REMAINDER OF
// THE CLASS AND THE OVERLOADED INSERTION OPERATOR
//

#include <iostream>
using namespace std;

#include "Train.h"
#include "TrainCar.h"

// Default constructor.  Initialize variables and create dummy node.
Train::Train() : m_number(0), m_departs( Time() ), m_destination ( "" ),
		 m_numCoachClass(0), m_numBusinessClass(0),
		 m_numSleepingCar(0), m_hasSnackCar(false) {
  m_head = new TrainCar(); // dummy node
}

// Non-default constructor.  Initialize variables and create dummy node.
Train::Train( int num, Time dep, string dest) 
  : m_number(num), m_departs(dep), m_destination(dest),
     m_numCoachClass(0), m_numBusinessClass(0),
     m_numSleepingCar(0), m_hasSnackCar(false) {
  m_head = new TrainCar(); // dummy node
}

//
// IMPLEMENT THE REMAINDER OF THE CLASS AND THE OVERLOADED
// INSERTION OPERATOR
//
Train::~Train() {
    
    //Deconstructor used from linked list lab
    
    TrainCar *current, *next;

    current = m_head;
    while(current != NULL) {
        next = current->m_next;
        delete current;
        current = next;
    }
    
}

void Train::addCar(TrainCar::cType car) {
    
    //Create boolean for repositioning snack car, set to true if car must be
    //repositioned (i.e. when )
    bool repositionSnackCar = false;
    
    //Create a pointer to the element BEFORE the one being inserted
    TrainCar *beforeInsert = m_head;
   
    //For adding locomotive
    if(car == TrainCar::Locomotive) {
        beforeInsert = m_head;
    
    } else if(car == TrainCar::BusinessClass) {
        
        if(m_numBusinessClass > 0) {
            
            ++m_numBusinessClass;
            
            //Business Class Car found, adding before...
            beforeInsert = findCarBefore(TrainCar::BusinessClass);
        
        } else {
            
             ++m_numBusinessClass;
            
            /* Possibilities are as follows
             * Invalid cases are accounted for so that cars can be added out of order!
             * (Thereby possibly making train valid once other cars are added)
             * Cars marked with an [x] represent missing cars for a valid train 
             * (they aren't actually present)
             * 
             * [newBusinessCar]-[SnackCar]...
             * -INVALID ...[newBusinessCar]-[x]-[Coach Car]...
             * -INVALID ...[newBusinessCar]-[x]-[x]-[Dining Car]...
             * -INVALID ...[newBusinessCar]-[x]-[x]-[x]-[Sleeping Car]...
             * -INVALID ...[newBusinessCar]-[x]-[x]
             */
            
            //Business Class Car not found, adding to train...
            
            if(m_numCoachClass > 0) {
                //Found Coach Car!
                beforeInsert = findCarBefore(TrainCar::CoachClass);
                
                //If the train has a snack car, reset placement
                if(m_hasSnackCar) {
                    //Reset SnackCar placement by removing it and marking it for
                    //repositioning.
                    removeCar(TrainCar::SnackCar);
                    repositionSnackCar = true;
                
                //If the train does not already have a snack car, add one:
                } else {
                    addCar(TrainCar::SnackCar);
                    //Set beforeInsert so that BusinessClass car is placed 
                    //before snack car
                    beforeInsert = findCarBefore(TrainCar::SnackCar);
                }
                
            } else if(m_hasSnackCar) {
                //Found Snack Car!
                beforeInsert = findCarBefore(TrainCar::SnackCar);
                
            //Check if dining car exists
            } else if(findCarBefore(TrainCar::DiningCar)->m_next != NULL) {
                //Found Dining Car!
                beforeInsert = findCarBefore(TrainCar::DiningCar);
                
            } else if(m_numSleepingCar > 0) {
                //Found Sleeping Car!
                beforeInsert = findCarBefore(TrainCar::SleepingCar);
                                
            //Otherwise, if no snack, coach, dining, or sleeping cars are found, 
            //add onto the end of invalid train
            } else {
                beforeInsert = findCarBefore(TrainCar::BusinessClass);
            }
        }
        
    } else if(car == TrainCar::SnackCar) {
        
        //Case with more than one snack car invalid, Check if snack car exists
        //and return if it does
        if(m_hasSnackCar) {
            
            //Snack Car found, not adding
            return;
            
        } else {
            
            m_hasSnackCar = true;
            
            /* There are several possibilities for snack car insertion:
             * 
             * (ONE) There are no business cars and the snack car must be inserted in the
             * middle of the coach cars, but closest to the locomotive if m_numCoachClass is odd
             * 
             * (TWO) There are business cars and coach cars, but no snack car
             * 
             * (THREE) There are business cars but no coach cars (could be added later) -INVALID
             *      -INVALID  ...[businessClass]-[newSnackCar]-[x]
             *      -INVALID  ...[businessClass]-[newSnackCar]-[x]-[Dining Car]...
             *      -INVALID  ...[businessClass]-[newSnackCar]-[x]-[x]-[Sleeping Car]...
             * 
             * (FOUR) There are no business cars or coach cars (could be added later) -INVALID
             */
            
            if(m_numBusinessClass == 0 && m_numCoachClass > 0) {
                beforeInsert = findCarBefore(TrainCar::CoachClass);
                int carsToMiddle = m_numCoachClass / 2;
                while(beforeInsert->m_next != NULL && carsToMiddle != 0) {
                    beforeInsert = beforeInsert->m_next;
                    --carsToMiddle;
                }
                
            } else if(m_numBusinessClass > 0 && m_numCoachClass > 0) {
                
                beforeInsert = findCarBefore(TrainCar::CoachClass);
                
            } else if(m_numBusinessClass > 0 && m_numCoachClass == 0) {
                if(findCarBefore(TrainCar::DiningCar)->m_next != NULL) {
                    //Found Dining Car!
                    beforeInsert = findCarBefore(TrainCar::DiningCar);
                } else if (m_numSleepingCar > 0) {
                    //Found Sleeping Car!
                    beforeInsert = findCarBefore(TrainCar::SleepingCar);
                } else {
                    //Set beforeInsert to point to the end of the train
                    beforeInsert = findCarBefore(TrainCar::CoachClass);
                }
                
            } else {
                //Set beforeInsert to point to the end of the train
                beforeInsert = findCarBefore(TrainCar::CoachClass);
            }
            
        }
    
    } else if(car == TrainCar::CoachClass) {
        
        if(m_numCoachClass > 0) {
      
            //Coach Car found, adding before...
            beforeInsert = findCarBefore(TrainCar::CoachClass);
            
            
            if(m_hasSnackCar) {
                //Necessary to prevent memory error, because when m_numCoachClass
                //equals 1, the snack car IS the car before the CoachClass car
                //In this case, beforeInsert must be pushed back one.
                if(m_numCoachClass == 1) {
                    beforeInsert = findCarBefore(TrainCar::SnackCar);
                }
                removeCar(TrainCar::SnackCar);
                repositionSnackCar = true;
                
            }
            
            ++m_numCoachClass;
            
        } else {
            
            ++m_numCoachClass;
            
            /* Possibilities are as follows
             * Invalid cases are accounted for so that cars can be added out of order!
             * (Thereby possibly making train valid once other cars are added)
             * Cars marked with an [x] represent missing cars for a valid train 
             * (they aren't actually present)
             * 
             * ...[newCoachClassCar]-[Dining Car]...
             * -INVALID ...[newCoachClassCar]-[x]-[Sleeping Car]...
             *  ...[newCoachClassCar]
             */

            //Coach Car not found, adding to train
            //If dining car exists, set beforeInsert to that location
            if(findCarBefore(TrainCar::DiningCar)->m_next != NULL) {
                //Found Dining Car!
                beforeInsert = findCarBefore(TrainCar::DiningCar);
            } else if (m_numSleepingCar > 0) {
                //Found Sleeping Car!
                beforeInsert = findCarBefore(TrainCar::SleepingCar);
            } else {
                //Set beforeInsert to point to the end of the train
                beforeInsert = findCarBefore(TrainCar::CoachClass);
            }
            
        }
    
    } else if(car == TrainCar::DiningCar) {
        
        //Case with more than one dining car invalid. Check if dining car exists and return
        //if it does.
        if(findCarBefore(TrainCar::DiningCar)->m_next != NULL) {
            
            //Dining Car found, not adding...
            return;
        
        } else {
            
            /* Possibilities are as follows
             * Invalid cases are accounted for so that cars can be added out of order!
             * (Thereby possibly making train valid once other cars are added)
             * Cars marked with an [x] represent missing cars for a valid train 
             * (they aren't actually present)
             * 
             * ...[newDiningCar]-[SleepingCar]...
             * -INVALID ...[newDiningCar]-[x]
             */
            
            if(m_numSleepingCar > 0) {
                //Found Sleeping Car!
                beforeInsert = findCarBefore(TrainCar::SleepingCar);
            } else {
                //Set beforeInsert to point to the end of the train
                beforeInsert = findCarBefore(TrainCar::DiningCar);
            }
            
        }

    } else if(car == TrainCar::SleepingCar) {
       
        ++m_numSleepingCar;
        
        if(m_numSleepingCar == 1) {
            //If the first sleeping car is added, add dining car before.
            addCar(TrainCar::DiningCar);
            beforeInsert = findCarBefore(TrainCar::SleepingCar);
            
        //Otherwise, if other sleeping car exists, don't add dining car:
        } else {
            beforeInsert = findCarBefore(TrainCar::SleepingCar);
        }
        
    }
    
    // ACTUAL INSERTION TAKES PLACE BELOW:
    
    //Allocate memory for new TrainCar
    TrainCar *insert = new TrainCar(car);
    
    //If car is added in middle (or beginning) of train
    //(There is a car that exists to the right):
    if(beforeInsert->m_next != NULL) {
        TrainCar *afterInsert = beforeInsert->m_next;
        beforeInsert->m_next = insert;
        insert->m_next = afterInsert;
        
    //If car is added on end (where afterInsert cannot possibly exist):
    } else {
        beforeInsert->m_next = insert;
    }
    
    if(repositionSnackCar) {
        //REPOSITIONING SNACK CAR
        //Re-add snack car with insertion taken into account
        addCar(TrainCar::SnackCar);
    }
    
}
    

bool Train::removeCar( TrainCar::cType car ) {
    
    //Error check 
    if(m_head == NULL || m_head->m_next == NULL) {
        cout << "ERROR - Train is empty!" << endl;
        return false;
    
    } else {
        
        //Create pointer to the car before the one being discarded
        TrainCar *beforeDiscard = findCarBefore(car);
        
        //Check for existence of searched car
        if(beforeDiscard->m_next == NULL || (beforeDiscard->m_next)->getType() != car) {
            cout << "ERROR - CAR NOT FOUND!" << endl;
            return false;
        
        //Otherwise, if car is found:
        } else {
            
            //Decrement counts of data attributes accordingly
            if(car == TrainCar::BusinessClass){
                --m_numBusinessClass;
            } else if(car == TrainCar::CoachClass) {
                --m_numCoachClass;
            } else if(car == TrainCar::SleepingCar) {
                --m_numSleepingCar;
            } else if(car == TrainCar::SnackCar) {
                m_hasSnackCar = false;
            }
            
            //Save location of discard
            TrainCar *discard = beforeDiscard->m_next;
            
            //If a car after the discard car exists (is in the middle), execute block
            if(discard->m_next != NULL) {
                
                //Save location of car after discard if it exists
                TrainCar *afterDiscard = discard->m_next;
                
                //Link the car before the discard car to the car after
                //the discard car
                beforeDiscard->m_next = afterDiscard;
                
                //Delete discard 
                delete discard;
                
                //Avoid dangling pointer
                discard = NULL;
                
            //If car to be removed is on end of train, execute block
            } else {
                
                //Set the beforeDiscard car's link to null to avoid
                //invalid pointer error
                beforeDiscard->m_next = NULL;
                
                //Delete discard car
                delete discard;
                
                //Avoid dangling pointer
                discard = NULL;
                
            }
            
            //Reposition snack car if last business car is removed or if a coach class
            //car is removed (provided that the train has a snack car)
            if((car == TrainCar::CoachClass || 
               (car == TrainCar::BusinessClass && m_numBusinessClass == 0)) &&
                m_hasSnackCar) {
                
                removeCar(TrainCar::SnackCar);
            
                //Add car back in with removal of all business class or 
                //any single coach class car taken into account
                addCar(TrainCar::SnackCar);
            }

            //Remove Dining Car if it exists and all sleeping cars are removed
            if(m_numSleepingCar == 0 && findCarBefore(TrainCar::DiningCar)->m_next != NULL) {
                removeCar(TrainCar::DiningCar);
            }
            
            return true;
        }
    }
}

TrainCar* Train::findCarBefore(TrainCar::cType car) const {
    
    //Initialize pointer to start at head of train linked list
    TrainCar *beforeFirst = m_head;
    
    //Move pointer down the train until next car of correct type is found
    //OR the end of the linked list is reached
    while(beforeFirst->m_next != NULL && (beforeFirst->m_next)->getType() != car) {
        beforeFirst = beforeFirst->m_next;
    } 
    
    //Return pointer to the car before the one being searched for
    //OR if the car is not found, return pointer to the end of the linked list
    return beforeFirst;
    
}

int Train::getNumber() const {
    return m_number;
}

void Train::setNumber( int num ) {
    m_number = num;
}

Time Train::getDepartureTime() const {
    return m_departs;
}

void Train::setDepartureTime( const Time& t ) {
    m_departs = t;
}

string Train::getDestination() const {
    return m_destination;
}

void Train::setDestination( string dest ) {
    m_destination = dest;
}

bool Train::isValid() {
    
    //If train has more than one coach class car and the first car is a locomotive,
    //return true
    if((m_numCoachClass > 0) && (m_head->m_next != NULL) && 
        ((m_head->m_next)->getType() == TrainCar::Locomotive)) {
        return true;
        
    } else {
        
        cout << "ERROR in Train::isValid(): ";
        
        //Check if train doesn't have any coaches
        if(m_numCoachClass == 0) {
            cout << "- Train #" << m_number << " Does not have any coaches!"<< endl;
        }
        
        //Check if train doesn't have a locomotive
        if(m_head->m_next != NULL &&
          (m_head->m_next)->getType() != TrainCar::Locomotive) {
            
            cout << "- Train #" << m_number << " Does not have a locomotive!" << endl;
        }
        
        //Make sure to return false, as the train is invalid
        return false;
    }
}

ostream& operator<<(ostream &outStream, const Train& train) {
    
    //Create TrainCar pointer, skipping the dummy node
    TrainCar *current = train.m_head->m_next;
    
    //Output bracket to mark front of train:
    outStream << "{";
    
    while(current != NULL) {
        
        //Dereference current car pointer so that TrainCar's overloaded insertion
        //operator is also used.
        outStream << *current;
        
        //Check if another car exists, and if so, print dash to connect cars.
        if(current->m_next != NULL) {
            outStream << "-";
        }
        current = current->m_next;
    }
    
    //Output pipe to mark end of train:
    outStream << "|";
    
    return outStream;
}