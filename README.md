# CMSC_202_Linked_List_Trains_Project
This project implements a train station system comprised of linked-list trains that contain train cars adhering to certain rules.

# Background

Linked lists are a fundamental and widely-used data structure. In this project, you will implement a linked list to store the cars of a train in their proper order. As cars are added to the train, your implementation must ensure that they are inserted at the correct position within the list; similarly, when a car is removed from a train, you must check that the remaining cars are still in their proper position, and re-position them if necessary.

For our purposes, a train consists of six different types of cars: locomotives, coach cars, business class cars, sleeping cars, snack cars, and dining cars; a train must have at least one locomotive and one coach car, but the other car types are optional. The car types, along with a value NoType, are defined as an enumeration in the file TrainCar.h:

typedef enum { Locomotive, CoachClass, BusinessClass, DiningCar, SnackCar, SleepingCar, NoType } cType; 

There are a number of rules regarding the location of each type of car within the train. The locomotives and passenger cars must be in this order:

    Locomotive(s)

    There may be one or more locomotives. They must be the first non-dummy nodes of the linked list.
    BusinessClass

    BusinessClass cars are optional, but if they are present, must be the first cars after the locomotives.
    CoachClass

    Every train must have at least one CoachClass car. If there are no business class cars, then they are immediately after the locomotives; otherwise, they follow the business class cars, possibly separated by a SnackCar (see below).
    SleepingCar

    SleepingCars, like business class cars, are optional. They are always the last cars in the train, following the coach cars and dining car.

The Snack and Dining cars have their own special placement rules:

    SnackCar

    A SnackCar is optional; there can be at most one.

    If the train has both business class and coach class, the SnackCar must be placed between coach and business.

    If the train has no business class, then the SnackCar must be placed in the middle of the coach class cars; if there is an odd number of coach class cars, it should be placed closer to the locomotives.
    DiningCar

    A train has a DiningCar if and only if it has one or more sleeping cars. The DiningCar should be placed between the coach cars and the sleeping cars.

The TrainCar class is defined in TrainCar.h and implemented in TrainCar.cpp. It is equivalent to the Node class in other linked-list examples you have seen: it has one data field (the car type) and a pointer to the next TrainCar object. The TrainCar class is nearly complete, but you do need to implement the overloaded operator<< to complete it.

The "meat" of the linked list is in the Train class defined in Train.h and implemented in Train.cpp. The Train class stores basic information a bout a train, including it's number, destination, and departure time and also has a pointer to the first (dummy) node of the linked list. It implements all the functions necessary to insert and remove cars in a Train and has an overloaded operator<< that prints a character graphic representation of the train. You are given implementations of two Train constructors, but you must implement the remainder of the class.

Finally, there is a small Time class that you must implement from scratch (no files are provided). The Time class is used to represent train departure times, to do simple arithmetic with times, and to output times in a nice format.

# Assignment

Your assignment is to complete the implementations of the TrainCar and Train classes and to write a Time class from scratch.

The TrainCar class is defined in TrainCar.h and implemented in TrainCar.cpp. You only need to implement the overloaded insertion operator to complete the class.

The Train class is defined in Train.h and implemented in Train.cpp. Only the constructors are provided; you must implement the remaining functions. Do not forget to implement the destructor ~Train() ~TrainCar().

The Time class must be written "from scratch." The class is used to store, compare, and output times on a 24-hour clock. The interface must be in Time.h, the implementation must be in Time.cpp, and the class must have the following features:

    Two integer variables: one to store hours, the other to store minutes.
    Default constructor sets hours and minutes to 0.
    Non-default constructor sets hours and minutes to specified values; must check that specified values are valid.
    Overloaded operator<< must print times with a colon between hours and minutes and with zero-padding of single-digit hours or minutes.
    Overloaded operator+ to add minutes to a time object. For example,


          Time t(13, 55);
          cout << t + 7 << endl;

    should print "14:02".
    Overloaded operator< to compare two Time objects. For example,


          Time t0(13, 55);
          Time t1(14, 00);

          bool b = (t0 < t1);       // b gets value true
          bool c = ((t0 + 7) < t1); // c gets value false

Your classes must work with the provided TrainStation class:

    TrainStation.h
    TrainStation.cpp 

This class creates several "tracks," assigns trains to the tracks, prints scheduled departures, etc. In addition, one test file is provided, station_test.cpp, which exercises all the class in the projects (TrainStation, Train, TrainCar, and Time). As with previous projects, you should do lots of additional testing — station_test.cpp is just one example of a test program.

