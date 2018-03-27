/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 6th, 2018, 12:05 PM
 * Purpose:  CPP Template
 *           To be copied for each project
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns
const float LBTOGRM=454.0f;//Pounds to Grams conversion
const float DAYSYR =365.0f;//Days per year

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float mMouse=35.0f,  //Mass of the mouse in grams
          mKllM=5.0f,    //Mass in sweetener to kill the mouse
          mSoda=350.f,   //Mass of Soda
          sodaCnc=.001f, //Soda concentration of sweetener
          wtDtr;         //Weight of the dieter in lbs,
    unsigned int numCans,//Number of cans to drink before death
            cCnsmd,      //Number of cans consumed
            cnsDay,      //Cans per day
            numYrs;      //Number of years consuming soda
      
    //Initial Variables
    cout<<"This program calculates soda can consumption permitted"<<endl;
    cout<<"Input your final desired  weight in lbs after diet soda consumption"<<endl;
    cin>>wtDtr;
    cout<<"Input how many cans you drink per day"<<endl;
    cin>>cnsDay;
    cout<<"Input how many years you have consumed this soda"<<endl;
    cin>>numYrs;
    
    //Map/Process Inputs to Outputs
    numCans=mKllM*wtDtr*LBTOGRM/(mMouse*mSoda*sodaCnc)-1;
    cCnsmd=cnsDay*DAYSYR*numYrs;

    //Display Outputs
    cout<<"The weight of the dieter after soda consumption = "<<wtDtr<<endl;
    cout<<"Maximum cans of soda allowed to consume = "<<numCans<<endl;
    cout<<"Total cans of soda so far consumed = "<<cCnsmd<<endl;
    cout<<(cCnsmd<numCans?"You Live":"You have expired")<<endl;
    
    //Exit program!
    return 0;
}