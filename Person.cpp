/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Person.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */

#include "Person.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

Person::Person(string inputString) : Person() {
    turn = stoi(inputString.substr(0,1));
    currentFloor = stoi(inputString.substr(2, 3));
    targetFloor = stoi(inputString.substr(4, 5));
    angerLevel = stoi(inputString.substr(6, 7));
    
}

bool Person::tick(int currentTime) {
    if (currentTime % TICKS_PER_ANGER_INCREASE == 0) {
        angerLevel++;
    }
    if (angerLevel >= MAX_ANGER) {
        return true;
    }
    else {
        return false;
    }
}

void Person::print(ostream &outs) {
    string floor;
    string target;
    string anger;
    stringstream ss;
    ss << currentFloor;
    ss >> floor;
    ss.clear();
    ss << targetFloor;
    ss >> target;
    ss.clear();
    ss << angerLevel;
    ss >> anger;
    ss.clear();
    string x = "f" + floor + "t" + target + "a" + anger;
    outs << x;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Person::Person() {
    turn = 0;
    currentFloor = 0;
    targetFloor = 0;
    angerLevel = 0;
}

int Person::getTurn() const {
    return turn;
}

int Person::getCurrentFloor() const {    
    return currentFloor;
}

int Person::getTargetFloor() const {    
    return targetFloor;
}

int Person::getAngerLevel() const {    
    return angerLevel;
}

ostream& operator<< (ostream& outs, Person p)
{
    p.print(outs);
    return outs;
}
