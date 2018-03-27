/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 22nd, 2018, 11:35 AM
 * Purpose:  Calculating Federal Interest Payments
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns
const float TRLLN=1e12f;//Trillion 10^12
const float BILLN=1e9f ;//Billion 10^9
const char  PERCENT=100;//Conversion to Percentage

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float fedDebt, //Federal Debt in $'s
          fedBdgt, //Federal Budget in $'s
          intRate, //Interest rate on the Debt %/year
          dbtPmnt, //Debt Payment in $'s/year 
          pctPymt; //Percentage of Payment/year of the Fed Budget

    //Initial Variables
    fedDebt=20.7*TRLLN;
    fedBdgt=4.1*TRLLN;
    
    //Input the potential interest rate per year
    cout<<"This program calculates the impact of the interest "
            <<"rate on the Federal Budget given the current "
            <<"Federal Debt"<<endl;
    cout<<"Input the potential interest rate 1 to 5 percent/year"<<endl;
    cin>>intRate;
    
    //Map/Process Inputs to Outputs
    intRate=intRate/PERCENT;
    dbtPmnt=fedDebt*intRate;
    pctPymt=dbtPmnt/fedBdgt*PERCENT;

    //Display Outputs
    cout<<"Federal Debt       =  $"<<fedDebt/TRLLN<<" Trillion"<<endl;
    cout<<"Federal Budget     =   $"<<fedBdgt/TRLLN<<" Trillion"<<endl;
    cout<<"Interest Rate/year =    "<<intRate*PERCENT<<"%"<<endl;
    cout<<"Debt Payment       = $"<<dbtPmnt/BILLN<<" Billions/year"<<endl;
    cout<<"Percentage Payment to the Federal Budget = "
            <<pctPymt<<"%"<<endl;
    
    //Exit program!
    return 0;
}