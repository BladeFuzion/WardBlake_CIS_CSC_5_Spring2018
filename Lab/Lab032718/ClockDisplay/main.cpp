/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 27th, 2018   10:20 AM
 * Purpose:  Nested Loops - Clock Time
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

    //Initial Variables
    out.open("Clock.out");
    
    //Map/Process Inputs to Outputs
    for(char ampm='0';ampm<='1';ampm++){
        for(int hours=0;hours<=12;hours++){
            for(char mins10='0';mins10<='5';mins10++){
                for(char mins='0';mins<='9';mins++){
                    for(char sec10='0';sec10<='5';sec10++){
                        for(char sec='0';sec<='9';sec++){
                            if(ampm=='1'&&hours==12){
                                out<<"00:00:00 AM"<<endl;
                                exit(EXIT_SUCCESS);
                            }
                            if(hours<10)out<<'0'<<hours<<':'
                                    <<mins10<<mins<<':'
                                    <<sec10<<sec
                                    <<" "<<(ampm=='0'&&hours<12?"AM":"PM")<<endl;
                            else out<<hours<<':'
                                    <<mins10<<mins<<':'
                                    <<sec10<<sec
                                    <<" "<<(ampm=='0'&&hours<12?"AM":"PM")<<endl;
                        }
                    }
                }
            }
        }
    }

    //Close file
    out.close();
    
    //Exit program!
    return 0;
}