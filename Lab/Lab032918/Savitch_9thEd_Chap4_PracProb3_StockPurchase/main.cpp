/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 29th, 2018, 10:20 AM
 * Purpose:  Stock Purchase
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format
#include <cstdlib>  //Rand function
#include <ctime>    //Time to set the seed
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Initialize the random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int dolStk, numStk, denStk;//Stock price $ num/den
    int numShrs;//Number of Shares
    float valStks;//Value of the stocks in $'s
    char again;//Continue or not

    //Initial Variables
    denStk=8;
    
    //Map/Process Inputs to Outputs
    do{
        //Randomly choose the stock price
        dolStk=rand()%1000;//[0-999]
        numStk=rand()%8;//[0-7]/8
        numShrs=rand()%90+10;//[10-99]
        
        //Calculate the stock value
        valStks=numShrs*(dolStk+static_cast<float>(numStk)/denStk);

        //Display Outputs
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<"The Number of shares of stock = "
                <<numShrs<<endl;
        cout<<"The value of the stock/share = $"
                <<dolStk<<" "<<numStk<<"/"<<denStk
                <<endl;
        cout<<"The total value of the stock = $"
                <<valStks<<endl;
        
        //Prompt user to see if they want to continue
        cout<<endl<<"Would you like to continue Y/N"<<endl;
        cin>>again;
    }while(again=='Y'||again=='y');
    
    //Exit program!
    return 0;
}