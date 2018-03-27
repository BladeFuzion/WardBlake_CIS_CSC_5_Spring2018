/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 20th, 2018, 11:30 AM
 * Purpose:  Creating a multi-line C Character
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char x;

    //Prompt for the varialbe value
    cout<<"Type in a character utilized to output the Big C"<<endl;
    cin>>x;

    //Display Outputs
    cout<<"  "<<x<<x<<x<<endl;
    cout<<" "<<x<<"   "<<x<<endl;
    cout<<x<<endl;
    cout<<x<<endl;
    cout<<x<<endl;
    cout<<x<<endl;
    cout<<x<<endl;
    cout<<" "<<x<<"   "<<x<<endl;
    cout<<"  "<<x<<x<<x<<endl;
    
    //Exit program!
    return 0;
}