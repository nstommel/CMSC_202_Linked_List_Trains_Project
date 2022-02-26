#ifndef TRAINCAR_H
#define TRAINCAR_H

//
// TrainCar.h
// 
// CMSC 202 Project File
//
// ** DO NOT MODFIY ** 
//

class TrainCar {
 public:

  // Define types of train cars
  typedef enum { Locomotive, CoachClass, BusinessClass, 
		 DiningCar, SnackCar, SleepingCar, NoType } cType;

  // Default constructor.  
  // Initialize m_type to NoType and m_next to NULL
  TrainCar();

  // Non-default constructor.
  // Initialize m_type to car and m_next to NULL
  TrainCar( cType car );

  // Change the type of a TrainCar
  void setType( cType car );

  // Get the type of a TrainCar
  cType getType() const;
  
  // Points to the next node in the linked list
  TrainCar *m_next;  

 private:

  // Stores the type of car
  cType m_type;

};

// Overloaded insertion operator to print a character graphic
// representation of a train car
ostream& operator<<(ostream &outStream, const TrainCar& car);

#endif
