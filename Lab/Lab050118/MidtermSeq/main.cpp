/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 1st, 2018, 11:20 AM
 * Purpose:  Sequence
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns
#include <cmath>    //Math Library

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int nTerms;
    float x,seqVal,delta;

    //Initial Variables
    nTerms=10;
    x=1;
    delta=seqVal=x;
    
    //Map/Process Inputs to Outputs
    for(int cnt=3,term=2;term<=nTerms;cnt+=2,term++){
        delta*=(-x*x/cnt/(cnt-1));
        seqVal+=delta;
    }
    
    //Output the results
    cout<<"The sin("<<x<<") = "<<sin(x)<<endl;
    cout<<"The Sequence Value = "<<seqVal<<" for "<<nTerms<<" n Terms"<<endl;
    
    //Exit program!
    return 0;
}