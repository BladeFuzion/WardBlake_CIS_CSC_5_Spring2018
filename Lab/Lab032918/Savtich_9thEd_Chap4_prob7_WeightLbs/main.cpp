/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 29th, 2018, 11:20 AM
 * Purpose:  My attraction to the earth
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns
const float GRAVITY=6.673e-8f;//cm^3/g/sec^2
const float CMMTRS=0.01f;//Centimeters to Meters
const float MTRSFT=3.281f;//Meters to feet
const float LBSLUG=32.174f;//Pounds per Slug

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float myMass, msEarth,rEarth,myWt,myWtCnv;

    //Initial Variables
    myMass=6;//6 slugs
    myWtCnv=myMass*LBSLUG;
    msEarth=5.972e27f;//grams
    rEarth=6.371e6f;//meters
    
    //Map/Process Inputs to Outputs
    myWt=GRAVITY*CMMTRS*CMMTRS*CMMTRS
            *myMass*msEarth*MTRSFT
            /(rEarth*rEarth);
    
    //Output my Weight
    cout<<fixed<<setprecision(0);
    cout<<myMass<<" slugs = "<<myWt<<" lbs"<<endl;
    cout<<myMass<<" slugs = "<<myWtCnv<<" lbs"<<endl;
    
    //Exit program!
    return 0;
}