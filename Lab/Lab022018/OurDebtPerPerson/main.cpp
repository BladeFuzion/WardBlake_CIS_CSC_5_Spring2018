/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 20th, 2018, 11:50 AM
 * Purpose:  US Debt Per Person
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns
const float MLLN=1e6f;  //1 Million
const float TRLLN=1e12f;//1 Trillion
const char  PERCENT=100;//Conversion to percent

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float   fed2008,//Federal Debt 2008
            fed2018,//Federal Debt 2018
            pop2008,//US Population 2008
            pop2018,//US Population 2018
            dbtPP08,//Debt per person 2008
            dbtPP18,//Debt per person 2018
            pctChgD,//Percentage change in debt
            pctChgP;//Percentage change in debt per person
    
    //Initialize values
    fed2008=9.9*TRLLN;
    fed2018=20.7*TRLLN;
    pop2008=304*MLLN;
    pop2018=326*MLLN;

    //Calculate the debt/person and percentage change
    dbtPP08=fed2008/pop2008;
    dbtPP18=fed2018/pop2018;
    pctChgD=(fed2018-fed2008)/fed2008*PERCENT;
    pctChgP=(dbtPP18-dbtPP08)/dbtPP08*PERCENT;
 
    //Display Outputs
    cout<<"2008 Federal Debt    = $"<<fed2008<<endl;
    cout<<"2018 Federal Debt    = $"<<fed2018<<endl;
    cout<<"2008 US Population   =  "<<pop2008<<endl;
    cout<<"2018 US Population   =  "<<pop2018<<endl;
    cout<<"2008 Debt per Person = $"<<dbtPP08<<endl;
    cout<<"2018 Debt per Person = $"<<dbtPP18<<endl;
    cout<<"Percentage Increase in Debt Total  "<<pctChgD<<"%"<<endl;
    cout<<"Percentage Increase in Person Debt "<<pctChgP<<"%"<<endl;
    
    //Exit program!
    return 0;
}