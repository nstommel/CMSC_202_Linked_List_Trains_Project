
/* File:    mytest.cpp
 * Project: CMSC 202 Project 3, Spring 2016
 * Author:  Nick Stommel
 * Date:    03/30/16
 * Section: 7
 * Email:   stommel1@gl.umbc.edu 
 * 
 * Description:
 * 
 * Basic test file for debugging Project 2
 * 
 */

#include <iostream>
using namespace std;

#include "Train.h"
//headers "Time.h" and "TrainCar.h" are included in "Train.h"

int main() {
	
    //Test default constructor
	TrainCar car3;
	cout << car3 << endl;
    
    //Test non-default constructor
	TrainCar car4(TrainCar::BusinessClass);
	cout << car4 << endl;
    
    Time t(13, 55);
    //Should print 14:02
    cout << t + 7 << endl;

    Time t0(13, 55);
    Time t1(14, 00);

    bool b = (t0 < t1);       // b gets value true
    bool c = ((t0 + 7) < t1); // c gets value false
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << endl;

	Time invalidTime;
	Time invalidTime2(14,78);


	cout << invalidTime << endl;
	cout << invalidTime2 << endl;

	Time time1(12,04);
	Time time2(11,58);

	cout << "Time 1: " << time1 << endl;
	cout << "Time 2: " << time2 << endl;

	Time time3 = time1 + 34;
	cout << "Time 3: " << time3 << endl;

	cout << (time3 < time1) << endl;
	cout << (time2 < time3) << endl;
    cout << endl;
    
    TrainCar loco1(TrainCar::Locomotive);
    TrainCar coach1(TrainCar::CoachClass);
    
    Train train1(1, time1, "Berlin");
    
    train1.addCar(TrainCar::Locomotive);
    cout << train1 << endl;
    
    train1.addCar(TrainCar::CoachClass);
    cout << train1 << endl;
    
    train1.addCar(TrainCar::SnackCar);
    cout << train1 << endl;
    
    //cout << "REMOVING COACH CAR" << endl;
    train1.removeCar(TrainCar::CoachClass);
    cout << train1 << endl;
    
    train1.removeCar(TrainCar::SnackCar);
    cout << train1 << endl;
        
    train1.addCar(TrainCar::CoachClass);
    cout << train1 << endl;
    
    train1.addCar(TrainCar::CoachClass);
    cout << train1 << endl;
    
    //cout << "REMOVING COACH CAR" << endl;
    train1.removeCar(TrainCar::CoachClass);
    cout << train1 << endl;
    
    train1.addCar(TrainCar::CoachClass);
    cout << train1 << endl;
    
    train1.addCar(TrainCar::CoachClass);
    cout << train1 << endl;
    
    train1.addCar(TrainCar::BusinessClass);
    cout << train1 << endl;
    
    train1.removeCar(TrainCar::BusinessClass);
    cout << train1 << endl;
    
    train1.addCar(TrainCar::SleepingCar);
    cout << train1 << endl;
    
    train1.addCar(TrainCar::BusinessClass);
    cout << train1 << endl;
    
    train1.addCar(TrainCar::SleepingCar);
    cout << train1 << endl;
    
    train1.addCar(TrainCar::DiningCar);
    cout << train1 << endl;
    
    
    //train1.addCar(TrainCar::DiningCar);
    //cout << train1 << endl;
    //train1.addCar(TrainCar::BusinessClass);
    //cout << train1 << endl;
    //train1.addCar(TrainCar::SnackCar);
    //cout << train1 << endl;
    //train1.addCar(TrainCar::Locomotive);
    //cout << train1 << endl;
    //train1.addCar(TrainCar::CoachClass);
    //cout << train1 << endl;
    //train1.addCar(TrainCar::Locomotive);
    //cout << train1 << endl;
    //train1.addCar(TrainCar::BusinessClass);
    //cout << train1 << endl;
    //train1.addCar(TrainCar::CoachClass);
    //cout << train1 << endl;
    //train1.addCar(TrainCar::SleepingCar);
    //cout << train1 << endl;
    //train1.addCar(TrainCar::CoachClass);

    //cout << train1 << endl;
    //cout << train1.removeCar(TrainCar::Locomotive) << endl;
    //cout << train1 << endl;
    
    train1.removeCar(TrainCar::Locomotive);
    cout << train1 << endl;
    train1.removeCar(TrainCar::Locomotive);
    cout << train1 << endl;
    train1.removeCar(TrainCar::Locomotive);
    cout << train1 << endl;
    //cout << "REMOVE BUSINESS CLASS" << endl;
    train1.removeCar(TrainCar::BusinessClass);
    cout << train1 << endl;
    //train1.removeCar(TrainCar::SleepingCar);
    cout << train1 << endl;
    train1.removeCar(TrainCar::SleepingCar);
    cout << train1 << endl;
    train1.removeCar(TrainCar::SleepingCar);
    cout << train1 << endl;
    //train1.removeCar(TrainCar::DiningCar);
    //cout << train1 << endl;
    /*
    train1.removeCar(TrainCar::NoType);
    cout << train1 << endl;
    train1.removeCar(TrainCar::SleepingCar);
    cout << train1 << endl;
    train1.removeCar(TrainCar::CoachClass);
    cout << "2 " << train1 << endl;
    train1.removeCar(TrainCar::CoachClass);
    cout << "1 " << train1 << endl;
    train1.removeCar(TrainCar::CoachClass);
    cout << "0 " << train1 << endl;
    train1.removeCar(TrainCar::CoachClass);
    cout << "0 " << train1 << endl;
    train1.removeCar(TrainCar::SnackCar);
    cout << "None" << train1 << endl;
    */
    
  return 0;
}
