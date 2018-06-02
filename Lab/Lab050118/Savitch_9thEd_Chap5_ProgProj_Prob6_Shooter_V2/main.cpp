/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 26th, 2018, 12:10 PM
 * Purpose:  Shooter Program
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
#include <cstdlib>  //Srand function
#include <ctime>    //Time function
#include <cmath>    //Power function
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes
float frand();//Probability from 0 to 1
bool shoot(float);
void shoot(bool, float, bool &,bool &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    bool aLive,bLive,cLive;
    char remain;
    float aPk,bPk,cPk;
    int aCnt,bCnt,cCnt,nGames;

    //Initial Variables
    aCnt=bCnt=cCnt=0;
    aPk=1.0f/3.0f;
    bPk=1.0f/2.0f;
    cPk=1.0f;
    nGames=1000;
    
    for(int game=1;game<=nGames;game++){
        //Initialize Life
        aLive=bLive=cLive=true;
        
        //Map/Process Inputs to Outputs
        do{
            shoot(aLive,aPk,cLive,bLive);
            shoot(bLive,bPk,cLive,aLive);
            shoot(cLive,cPk,bLive,aLive);
            remain=aLive+bLive+cLive;
        }while(remain>1);
        
        aCnt+=aLive;
        bCnt+=bLive;
        cCnt+=cLive;
    }
    
    //Output the results
    cout<<"Aaron   Pk = "<<aPk<<endl;
    cout<<"Bob     Pk = "<<bPk<<endl;
    cout<<"Charlie Pk = "<<cPk<<endl;
    cout<<"Out of "<<nGames<<" games"<<endl;
    cout<<"Aaron   Lives "<<aCnt<<" times"<<endl;
    cout<<"Bob     Lives "<<bCnt<<" times"<<endl;
    cout<<"Charlie Lives "<<cCnt<<" times"<<endl;
    cout<<"Game Check = "<<aCnt+bCnt+cCnt<<" games"<<endl;
    
    //Exit program!
    return 0;
}

void shoot(bool aLive, float aPk, bool &cLive,bool &bLive){
    if(aLive){
          if(cLive)      cLive=shoot(aPk);
          else if(bLive) bLive=shoot(aPk);
    }
}

bool shoot(float pk){
    if(frand()>pk)return true;
    return false;
}

float frand(){
    static float MAXRAND=pow(2,31)-1;
    return rand()/MAXRAND;
}