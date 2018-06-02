/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 10th, 2018, 10:45 AM
 * Purpose:  Retirement with Arrays and MVC model
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
#include <vector>
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes
void rtrmnt(int,float,float,vector<int> &,vector<float> &,
        vector<float> &,vector<float> &);
void dsply(int,float,vector<int> &,vector<float> &,vector<float> &,vector<float> &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    //Salary in $/year, Return on Investment in %, 
    //Savings required in $, Percentage Deposit in %
    float salary,roi,savReq,percDep;//Initial Conditions
    //Number of Years, Savings at the Beginning of the year
    //Interest Earned at the End of the year,
    //Deposit at the end of the year
    int nyrs=100;//Size of the array
    int nYears;//Number of years the array is utilized for
    vector<float> svBegYr(nyrs),inEndYr(nyrs),dpEndYr(nyrs);
    vector<int> year(nyrs);
    
 
    //Initialize
    salary=1.e5f;     //$100,000
    roi=5e-2;         //5%
    savReq=salary/roi;//Savings required to retire
    percDep=1e-1f;    //10% 
    nYears=50;        //50 years
    svBegYr[0]=0;     //No savings int $'s at start
    inEndYr[0]=0;     //No interest at the beginning
    dpEndYr[0]=percDep*salary;//Deposit at the end of every year
    year[0]=2021;     //Year we get a job
    
    //Map/Process All computations Here
    rtrmnt(nYears,savReq,roi,year,svBegYr,dpEndYr,inEndYr);
    
    //Output the results, hence Display
    dsply(nYears,savReq,year,svBegYr,dpEndYr,inEndYr);
   
    //Exit program!
    return 0;
}

void dsply(int nYears,float savReq,
        vector<int> &year,vector<float> &svBegYr,
        vector<float> &dpEndYr,vector<float> &inEndYr){
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Year  Year     Savings  Interest   Deposit"<<endl;
    int nYear;
    for(nYear=0;nYear<=nYears&&savReq>svBegYr[nYear];nYear++){
            cout<<setw(2)<<nYear
                <<setw(8)<<year[nYear]
                <<setw(12)<<svBegYr[nYear]
                <<setw(10)<<inEndYr[nYear]
                <<setw(10)<<dpEndYr[nYear]<<endl;
    }
    //Output the last year
    cout<<"Savings to Retire = $"<<svBegYr[nYear]
            <<" in year "<<year[nYear]<<endl;
}

void rtrmnt(int nYears,float savReq,float roi,
        vector<int> &year,vector<float> &svBegYr,
        vector<float> &dpEndYr,vector<float> &inEndYr){
    for(int nYear=0;nYear<=nYears&&savReq>svBegYr[nYear];nYear++){
        int isvBgYr=(svBegYr[nYear]+inEndYr[nYear]+dpEndYr[nYear]+0.005)*100;//Calculates in Pennies
        year[nYear+1]=year[nYear]+1;
        svBegYr[nYear+1]=isvBgYr/100;//Shifts back to dollars
        dpEndYr[nYear+1]=dpEndYr[nYear];
        inEndYr[nYear+1]=svBegYr[nYear+1]*roi;
    }
}