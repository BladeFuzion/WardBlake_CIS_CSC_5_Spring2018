/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 27th, 2018, 12:05 PM
 * Purpose:  Our nearest neighbors
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns
const float VLIGHT=3e5f;//Velocity of Light = 300,000km/sec
const float VESCAPE=16.6f;//Solar System Escape velocity from earth 16.6km/sec
const float SECMIN=60;//60 seconds per minute
const float MINHR=60;//60 minutes per hour
const float HRDAY=24;//24 hours per day
const float DAYYR=365;//365 days per year
const float TRLLION=1e12f;//Trillion = 10^12
const float THSNDS=1e3f;//Thousand = 10^3
const float MILESKM=0.62137f;//Miles per kilometer


//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float dstLYr,dstKm,dstMls,time,timeChk;

    //Input the distance
    cout<<"Have we been visited by Aliens?"<<endl;
    cout<<"Input distance to star in light years"<<endl;
    cin>>dstLYr;
    
    //How far and How long?????
    dstKm=VLIGHT*SECMIN*MINHR*HRDAY*DAYYR*dstLYr;
    dstMls=dstKm*MILESKM;
    time=dstKm/VESCAPE/SECMIN/MINHR/HRDAY/DAYYR;
    timeChk=dstLYr*VLIGHT/VESCAPE;
    
    //Display Outputs
    cout<<"The distance   to the star = "
            <<dstKm/TRLLION<<" Trillions of Kilometers"<<endl;
    cout<<"The distance   to the star = "
            <<dstMls/TRLLION<<" Trillions of Miles"<<endl;
    cout<<"Time to travel to the star = "
            <<time/THSNDS<<" Thousands of Years"<<endl;
    cout<<"Time to travel to the star = "
            <<timeChk/THSNDS<<" Thousands of Years"<<endl;
    
    //Exit program!
    return 0;
}