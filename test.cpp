/*
 * Copyright 2022 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Final Project - Elevators
 */
 
////////////////////////////////////////////////
// You will submit test.cpp to the autograder //
// FOR LAB 8, but NOT the final project Core  //
////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "AI.h"
#include "Building.h"
#include "BuildingState.h"
#include "Elevator.h"
#include "Floor.h"
#include "Game.h"
#include "Move.h"
#include "Person.h"
#include "SatisfactionIndex.h"
#include "Utility.h"

using namespace std;

// declare your test functions here
void person_tests();
void elevator_tests();

void start_tests() {
    person_tests();
    elevator_tests();
}


// write test functions here
void person_tests() {
    // initialize a person with targetFloor 5, anger 5
    Person p("0f0t5a5");
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 5" << endl;

    // simulate time being a multiple of TICKS_PER_ANGER_INCREASE
    bool exploded = p.tick(TICKS_PER_ANGER_INCREASE);
    cout << exploded << " Expected 0" << endl;
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;

    // simulate time not being a multiple
    p.tick(TICKS_PER_ANGER_INCREASE - 1);
    
    // no change
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;

    p.tick(TICKS_PER_ANGER_INCREASE); //7 after
    p.tick(TICKS_PER_ANGER_INCREASE); //8 after
    p.tick(TICKS_PER_ANGER_INCREASE); //9 after
    exploded = p.tick(TICKS_PER_ANGER_INCREASE);
    cout << exploded << " Expected 1" << endl;

    // initialize a person using nondefault constructor
    Person p1("1f2t3a4");

    // test person's attributes
    cout << "Expected: 1, actual: " << p1.getTurn() << endl;
    cout << "Expected: 2, actual: " << p1.getCurrentFloor() << endl;
    cout << "Expected: 3, actual: " << p1.getTargetFloor() << endl;
    cout << "Expected: 4, actual: " << p1.getAngerLevel() << endl;

    // initialize a person and set currentTime to 2
    Person p2("1f2t3a4");
    int currentTime = 2;

    // test tick() when currentTime is 2
    cout << "Expected: 0, actual: " << p2.tick(currentTime) << endl;
    cout << "Expected: 2, actual: " << p2.getAngerLevel() << endl;

    // initialize a person and reset currentTime to 10
    Person p3("1f2t3a4");
    currentTime = 10;
    
    // test tick() when currentTime is 10
    cout << "Expected: 0, actual: " << p3.tick(currentTime) << endl;
    cout << "Expected: 3, actual: " << p3.getAngerLevel() << endl;

    // initialize a person and reset currentTime to 10
    Person p4("1f2t3a11");
    currentTime = 10;
    
    // test tick() when person has reached MAX_ANGER
    cout << "Expected: 1, actual: " << p4.tick(currentTime) << endl;
}

void elevator_tests() {
    // initialize an elevator
    Elevator e1;

    // testing tick() when not servicing and not on target floor
    e1.tick(3);
    cout << "Expected: w, actual: ";
    e1.print(cout);
    cout << endl;

    // call service request
    e1.serviceRequest(10);

    // testing tick() when servicing and not on target floor
    e1.tick(4);
    cout << "Expected: s10, actual: ";
    e1.print(cout);
    cout << endl;

    // initialize an elevator
    Elevator e2;

    // testing serviceRequest()
    e2.serviceRequest(10);
    cout << "Expected: 10, actual: " << e2.getTargetFloor() << endl;
    cout << "Expected: 1, actual: " << e2.isServicing() << endl;
    
}
