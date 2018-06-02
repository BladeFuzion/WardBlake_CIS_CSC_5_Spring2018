/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on April 24th, 2018, 11:25 AM
 * Purpose:  Initial Savings Function
 */

//System Libraries
#include <iostream>//I/O Library
#include <cmath>   //Math Library
#include <iomanip> //Formatting Library
#include <cstdlib> //exit() function
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const float CNVPERC=1e2f;//100

//Function Prototypes
float fval1(float,float,int);//Future Value with Power Function
float fval2(float,float,int);//Future Value with Log/Exp Function
float fval3(float,float,int);//Future Value with for-loop
float fval4(float,float,int);//Future Value by recursion
float fval5(float,float,int=12);//Future Value by defaulted parameter
float fval4(float,float,float);//Future Value by overloading function
float fval6(float,float,int,int &);//Future Value by static variable and ref parameter
float fval7(float,float,int);//Future Value by exit() function

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float presVal,//Present Value in $'s
          intRate;//Interest rate in %
    int   numCmp; //Number of compounding periods in years
    
    //Initialize Variables
    presVal=1e2f;//$100's
    intRate=6;   //6 per cent
    
    //By the rule of 72
    numCmp=72/intRate;
    
    //Output data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Present Value = $"<<presVal<<endl;
    cout<<"Interest Rate = "<<intRate<<"%"<<endl;
    cout<<"Number of compounding periods  = "<<numCmp<<" years"<<endl;
    cout<<"Savings using FV -> Power              = $"
            <<fval1(presVal,intRate/CNVPERC,numCmp)<<endl;
    cout<<"Savings using FV -> Log/Exp            = $"
            <<fval2(presVal,intRate/CNVPERC,numCmp)<<endl;
    cout<<"Savings using FV -> for-loop           = $"
            <<fval3(presVal,intRate/CNVPERC,numCmp)<<endl;
    cout<<"Savings using FV -> Recursion          = $"
            <<fval4(presVal,intRate/CNVPERC,numCmp)<<endl;
    cout<<"Savings using FV -> Default 12         = $"
            <<fval5(presVal,intRate/CNVPERC)<<endl;
    float fnumCmp=numCmp;
    cout<<"Savings using FV -> Overload           = $"
            <<fval4(presVal,intRate/CNVPERC,fnumCmp)<<endl;
    int count;
    for(int i=1;i<=4;i++){
        fval6(presVal,intRate/CNVPERC,numCmp,count);
    }
    cout<<"Savings using FV -> Static & Reference = $"
            <<fval6(presVal,intRate/CNVPERC,numCmp,count)<<endl;
    cout<<"fval6 was called "<<count<<" times"<<endl;
    cout<<"Savings using FV -> exit()             = $"
            <<fval7(presVal,intRate/CNVPERC,numCmp)<<endl;
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Future Value Functions
//Inputs:
//   pv -> present value in $'s
//   ir -> interest rate in decimal value
//   n  -> number of compounding periods (yrs)
//Outputs:
//   fv -> future value in $'s
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
float fval1(float pv,float ir,int n){
    return pv*pow((1+ir),n);
}

float fval2(float pv,float ir,int n){
    return pv*exp(n*log(1+ir));
}

float fval3(float pv,float ir,int n){
    for(int i=1;i<=n;i++){
        pv*=(1+ir);
    }
    return pv;
}

float fval4(float pv,float ir,int n){
    if(n<=0)return pv;
    return fval4(pv,ir,n-1)*(1+ir);
}

float fval5(float pv,float ir,int n){
    for(int i=1;i<=n;i++){
        pv*=(1+ir);
    }
    return pv;
}

float fval4(float pv,float ir,float n){
    for(int i=1;i<=n;i++){
        pv*=(1+ir);
    }
    return pv;
}

float fval6(float pv,float ir,int n,int &cnt){
    static int count;//Default initialized to 0
    for(int i=1;i<=n;i++){
        pv*=(1+ir);
    }
    //Returns the count through the parameter list
    cnt=++count;//Increment the count each function call
    return pv;
}

float fval7(float pv,float ir,int n){
    for(int i=1;i<=n;i++){
        pv*=(1+ir);
    }
    if(n==12){
        cout<<"Future Value = $"<<pv<<endl;
        exit(0);
    }
    return pv;
}