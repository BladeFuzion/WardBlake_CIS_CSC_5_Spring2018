/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on March 20th, 2018, 11:50 AM
 * Purpose:  Fibonacci
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int fn,fnm1,fnm2;
    
    //Initialize Variables
    fnm2=1;
    fnm1=1;
    
    //Printout the first 2 in the sequence
    cout<<"Fibonacci Sequence"<<endl;
    cout<<"{"<<fnm2<<","<<fnm1;
    
    //Calculate 3rd element in sequence
    fn=fnm1+fnm2;
    fnm2=fnm1;
    fnm1=fn;
    cout<<","<<fn;
    
    //Calculate 4th element in sequence
    fn=fnm1+fnm2;
    fnm2=fnm1;
    fnm1=fn;
    cout<<","<<fn;
    
    //Calculate 5th element in sequence
    fn=fnm1+fnm2;
    fnm2=fnm1;
    fnm1=fn;
    cout<<","<<fn;
 
    //Calculate 6th element in sequence
    fn=fnm1+fnm2;
    fnm2=fnm1;
    fnm1=fn;
    cout<<","<<fn;
    
    //Calculate 7th element in sequence
    fn=fnm1+fnm2;
    fnm2=fnm1;
    fnm1=fn;
    cout<<","<<fn;
    
    //Calculate 8th element in sequence
    fn=fnm1+fnm2;
    fnm2=fnm1;
    fnm1=fn;
    cout<<","<<fn;
    
    //Calculate 9th element in sequence
    fn=fnm1+fnm2;
    fnm2=fnm1;
    fnm1=fn;
    cout<<","<<fn<<"}"<<endl;
    
    //Exit stage right!
    return 0;
}