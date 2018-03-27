/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 8th, 2018, 11:25 AM
 * Purpose:  Math Tutor
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <cstdlib>  //Random number library
#include <ctime>    //Time to set random number seed
#include <iomanip>  //Format Library
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned short op1,op2,stuAns,correct;

    //Initial Variables
    op1=rand()%900+100;//[100,999]
    op2=rand()%999+1;  //[1,999]
    cout<<"This is a simple Math Tutor Program"<<endl;
    cout<<"Input the Answer to the following addition problem"<<endl;
    cout<<setw(5)<<op1<<endl;
    cout<<"+ "<<setw(3)<<op2<<endl;
    cout<<"-----"<<endl;

    //Calculate the answer
    correct=op1+op2;
    cout<<((correct>1000)?" ":"  ");
    cin>>stuAns;
  
    //Display Outputs
    cout<<endl<<(stuAns==correct?"Correct Answer":"Wrong Answer")<<endl;
    
    //Exit program!
    return 0;
}