
// File: casting
// Created by Jaxon Greenwood on 10/10/2017 for CS1410.
// Copyright (c) 2017 WSU
//
#include <iostream>
using namespace std;

// Constants
class Distance{
private:
    float MTF;        //Meters to feet
    int feet;
    float inches;
public:
    Distance():feet(0), inches(0.0), MTF(3.280833F){}

    Distance(int meters): MTF(3.280833F){
        float fltFeet = MTF * meters;

        feet = int(fltFeet);
        inches = 12 * (fltFeet - feet);
    }

    Distance(int f, float i): MTF(3.280833F){
        feet = f;
        inches = i;
    }

    void getDist(){
        cout << "Enter feet: ";
        cin >> feet;

        cout << "Enter inches: ";
        cin >> inches;
    }

    void showDist(){
        cout << feet << "\' - " << inches << "\"";
    }

    Distance operator + (Distance) const;
    void operator += (Distance);
    operator float() const{
        float ffeet = inches/12;
        ffeet += static_cast<float>(feet);
        return ffeet/MTF;
    }                      // converts to inches
};

// Return the sum
Distance Distance::operator + (Distance d2) const {
    int f = feet + d2.feet;
    int i = inches + d2.inches;

    while (i >= 12.0){
        i -= 12.0;
        f++;
    }
    return Distance(f, i);
}

void Distance::operator += (Distance d2) {      // adding 1 distance to existing one

    feet += d2.feet;
    inches = inches + d2.inches;

    if (inches >= 12.0){
        inches -= 12.0;
        feet++;
    }

}

// Prototypes

// Main Program Program

int main(void) {

    Distance d1;
    Distance d2(11, 6.25);
    Distance d3(5);
    float mtrs;
    d1.getDist();

    cout << "\nDistance d1 = ";
    d1.showDist();
    cout << endl;

    cout << "Distance d2 = ";
    d2.showDist();
    cout << endl;
    // Add binary operator support;

    d3 = d1 + d2;
    cout << "Distance d3 =";
    d3.showDist();
    cout << endl;

    mtrs = static_cast<float>(d2);
    cout << "Dist d2 = " << mtrs << " meters" << endl;

    d2 += d3;
    cout << "Distance d2 =";
    d2.showDist();
    cout << endl;


    return 0;
}

// Function Definitions
