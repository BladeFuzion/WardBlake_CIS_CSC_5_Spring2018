/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 8th, 2018, 9:52 PM
 * Purpose:  Loan Calculator
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <cmath>    //Power function
#include <iomanip>  //Format Library
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns
unsigned char MNYR=12;    //Months per year
unsigned char PERCENT=100;//Percentage conversion

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables and initialize variables
    float loanAmt=1e4f,  //Loan Amount $10,000
          intRate=1.2e1f,//12%/year
          monPymt,       //Monthly Payment $'s/month
          totAmt,        //Total paid for the Loan $'s
          totInt;        //Total interest paid for the loan $'s
    unsigned char nMnths=36;//Months used in loan

    //Map/Process Inputs to Outputs
    intRate/=(MNYR*PERCENT);
    float temp=pow(1+intRate,nMnths);
    monPymt=intRate*temp*loanAmt/(temp-1);
    int pennies=static_cast<int>((monPymt+0.005)*100);
    monPymt=pennies/100.0f;//Convert back to dollars
    totAmt=monPymt*nMnths;
    totInt=totAmt-loanAmt;

    //Display Outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Loan Amount         = $"<<setw(8)<<loanAmt<<endl;
    cout<<"Interest Rate       = "<<setw(6)<<static_cast<int>(intRate*MNYR*PERCENT)
            <<"%/year"<<endl;
    cout<<"Number of Payments  = "<<setw(6)<<static_cast<int>(nMnths)<<endl;
    cout<<"Monthly Payment     = $"<<setw(8)<<monPymt<<endl;
    cout<<"Total Paid for Loan = $"<<setw(8)<<totAmt<<endl;
    cout<<"Total Interest      = $"<<setw(8)<<totInt;
    
    //Exit program!
    return 0;
}