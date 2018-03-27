/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 15th, 2018, 11:55 AM
 * Purpose:  Gas Tax at the Pump
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns
const float PERCENT=100;//Calculate percentages

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float   pmPrice,//Pump Price in $'s
            basePrc,//Base Price in $'s
            fedTax, //Federal tax in $'s/gallon
            stateTx,//State tax in $'s/gallon
            salesTx,//Sales tax in % of Base Price
            totTax, //Tot axes paid/gallon
            prctTax;//Percentage taxes paid

    //Initial Variables
    pmPrice=3.30f;//$3.30/gallon
    fedTax=0.184f;//18.4 cents/gallon .184 $'s/gallon
    stateTx=0.417f;//41.7 cents/gallon .417 $'s/gallon
    salesTx=0.0225f;//2.25% sales tax from base pump price
    
    //Map/Process Inputs to Outputs
    basePrc=(pmPrice-fedTax-stateTx)/(1+salesTx);
    totTax=pmPrice-basePrc;
    prctTax=totTax/basePrc*PERCENT;

    //Display Outputs
    cout<<"Pump Price = $"<<pmPrice<<"/gallon"<<endl;
    cout<<"Federal Excise Tax = $"<<fedTax<<"/gallon"<<endl;
    cout<<"State Excise Tax = $"<<stateTx<<"/gallon"<<endl;
    cout<<"State Sales Tax = "<<salesTx*PERCENT<<"%"<<endl;
    cout<<"Base Price = $"<<basePrc<<"/gallon"<<endl;
    cout<<"Total Taxes = $"<<totTax<<"/gallon"<<endl;
    cout<<"Percentage Tax = "<<prctTax<<"%"<<endl;
    
    //Exit program!
    return 0;
}