/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 6th, 2018, 12:05 PM
 * Purpose:  Paycheck!!!
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Formatting Library
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float payRate=16.78f,  //Pay rate in $'s/Hour
            ssTax=0.06f,   //Social Security tax percentage
            fedTax=0.14f,  //Federal tax percentage
            stTax=0.05f,   //State tax percentage
            hlthIns=35.0f, //Health insurance $'s/week
            unDues=10.0f,  //Union Dues $'s/week
            hrsWrkd,       //Hours worked/week
            grsPay,        //Gross Pay/week
            payChk;        //Net Pay/week
    unsigned char numDep; //Number of Dependents
    
    //Initialize the user values
    cout<<"This program calculates your paycheck"<<endl;
    cout<<"Input the hours worked this week"<<endl;
    cin>>hrsWrkd;
    cout<<"Input the number of dependents, limit 9"<<endl;
    cin>>numDep;
    cout<<endl<<endl;

    //Map/Process Inputs to Outputs
    grsPay=hrsWrkd*payRate;
    grsPay+=hrsWrkd>40?(hrsWrkd-40)*payRate/2:0;
    ssTax*=grsPay;
    fedTax*=grsPay;
    stTax*=grsPay;
    hlthIns=numDep>='3'?hlthIns:0;
    payChk=grsPay-ssTax-fedTax-stTax-hlthIns-unDues;
    
    //Display Outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Hours Worked         =   "<<setw(7)<<hrsWrkd<<endl;
    cout<<"Number of Dependents =   "<<setw(4)<<numDep<<endl;
    cout<<"Gross Pay            = $ "<<setw(7)<<grsPay<<endl;
    cout<<"Social Security      = $ "<<setw(7)<<ssTax<<endl;
    cout<<"Federal Tax          = $ "<<setw(7)<<fedTax<<endl;
    cout<<"State Tax            = $ "<<setw(7)<<stTax<<endl;
    cout<<"Health Insurance     = $ "<<setw(7)<<hlthIns<<endl;
    cout<<"Union Dues           = $ "<<setw(7)<<unDues<<endl;
    cout<<"Net Pay              = $ "<<setw(7)<<payChk<<endl;
    
    //Exit program!
    return 0;
}