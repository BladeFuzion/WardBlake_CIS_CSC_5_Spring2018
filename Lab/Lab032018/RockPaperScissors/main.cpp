/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on March 20th, 2018, 12:15 PM
 * Purpose:  Rock, Paper, Scissors
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char p1,p2;
    
    //Initialize Variables
    p1=rand()%3+'R'; //RST
    p1=p1>'S'?'P':p1;//PRS
    p2=rand()%3+'R'; //RST
    p2=p2>'S'?'P':p2;//PRS
  
    //Players choice
    cout<<"Rock Paper Scissors Game"<<endl;
    cout<<"Player 1 = "<<p1<<endl;
    cout<<"Player 2 = "<<p2<<endl;
    
    //Determine the winner
    if(p1==p2){
        cout<<"The game is a tie"<<endl;
    }else if(p1=='P'){
        if(p2=='S'){
            cout<<"Player 2 wins"<<endl;
        }else{
            cout<<"Player 1 wins"<<endl;
        }
    }else if(p1=='S'){
        if(p2=='R'){
            cout<<"Player 2 wins"<<endl;
        }else{
            cout<<"Player 1 wins"<<endl;
        }
    }else{
        if(p2=='P'){
            cout<<"Player 2 wins"<<endl;
        }else{
            cout<<"Player 1 wins"<<endl;
        }
    }
    
    
    //Output data
    
    //Exit stage right!
    return 0;
}