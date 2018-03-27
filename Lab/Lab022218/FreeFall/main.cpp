/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 22nd, 2018, 12:35 PM
 * Purpose:  Free Fall Calculation
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns
const float GRAVITY=32.174f;//Gravity in units of ft/sec^2

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float time,    //time in seconds
          distnce; //distance dropped in ft
    
    //Input the potential interest rate per year
    cout<<"This program calculates how far an object falls "<<endl;
    cout<<"under Gravity, input the time of fall in seconds"<<endl;
    cin>>time;
    
    //Map/Process Inputs to Outputs
    distnce=GRAVITY*time*time/2;
    
    //Display Outputs
    cout<<"Time to fall in Gravity = "<<time<<" seconds"<<endl;
    cout<<"Distance in free fall   = "<<distnce<<" feet"<<endl;

    
    //Exit program!
    return 0;
}