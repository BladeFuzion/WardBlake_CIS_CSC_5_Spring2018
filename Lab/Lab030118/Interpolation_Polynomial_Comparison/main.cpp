/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 1st, 2018, 12:00 PM
 * Purpose:  Random Number Test, with
 *           a comparison of interpolation
 *           to a first order polynomial
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <cstdlib>  //Random number generator 
#include <ctime>    //Time to seed random number generator
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Seed random number generator once, here only
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned char f1=32,f2=212,c1=0,c2=100;//Table values for temperature
    float m=5.0f/9.0f, b=-32.0f;//Polynomial coefficients
    float ceq,cint,f;//Temperature values and conversions

    //Initial Variables
    f=rand()%181+32;//[32,212]
    
    //Map/Process Inputs to Outputs
    ceq=m*(f+b);
    cint=c1+static_cast<float>(c2-c1)/(f2-f1)*(f-f1);

    //Display Outputs
    cout<<f<<" Fahrenheit = "
            <<ceq<<" Centigrade equation "
            <<cint<<" Celsius interpolation"<<endl;
    
    //Exit program!
    return 0;
}