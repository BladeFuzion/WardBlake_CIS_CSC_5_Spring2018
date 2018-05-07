/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 27th, 2018   10:20 AM
 * Purpose:  Nested Loops - Date Time
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <fstream>  //File Library
#include <cstdlib>  //exit()
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    ofstream out;
    string year;

    //Initial Variables
    out.open("Date.out");
    year="2018";
    
    //Map/Process Inputs to Outputs
    for(int months=1;months<=12;months++){
        for(int days=1;days<=31;days++){
            if(months<10&&days>=10)
                cout<<'0'<<months<<"\\"<<days<<"\\"<<year<<endl;
            else if(days<10&&months>=10)
                cout<<months<<"\\"<<'0'<<days<<"\\"<<year<<endl;
            else if(days<10&&months<10)
                cout<<'0'<<months<<"\\"<<'0'<<days<<"\\"<<year<<endl;
            else cout<<months<<"\\"<<days<<"\\"<<year<<endl;
            if(months==2&&days==28)break;
            if((months==4||months==6||months==9||months==11)&&days==30)break;
        }
    }

    //Close file
    out.close();
    
    //Exit program!
    return 0;
}