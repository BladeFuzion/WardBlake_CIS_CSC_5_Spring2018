/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 1st, 2018, 11:20 AM
 * Purpose:  What day of the week is it?
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes
unsigned char cnvDay(string);
unsigned char cnvMnth(string);
bool isLpYr(unsigned short);
char  gtCntVl(unsigned int);
char  gtYrVal(unsigned int);
char  gtMnVal(char,unsigned int);
string dyOfWk(char, char, unsigned int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    string sMonth,sDay;
    unsigned short year;//2 Byte Integer Value
    unsigned char day, month;//1 Byte Integer Value
 
    //Initial Variables
    cout<<"This program outputs the day of the week "<<endl;
    cout<<"given the date"<<endl;
    cout<<"Input the date i.e. July 4, 2008"<<endl;
    cin>>sMonth>>sDay>>year;
 
    //Map/Process Inputs to Outputs
    day=cnvDay(sDay);
    month=cnvMnth(sMonth);
    cout<<year<<" Is Leap Year? -> "<<(isLpYr(year)?"True":"False")<<endl;
    cout<<"Century Value = "<<static_cast<int>(gtCntVl(year))<<endl;
    cout<<"Year Value = "<<static_cast<int>(gtYrVal(year))<<endl;
    cout<<"Month Value = "<<static_cast<int>(gtMnVal(month,year))<<endl;

    
    //Output the results
    cout<<"The date is "
            <<static_cast<int>(month)<<"/"
            <<static_cast<int>(day)<<"/"<<year<<endl;
    cout<<"The day of the week = "
            <<dyOfWk(month,day,year)<<endl;

    
    //Exit program!
    return 0;
}

string dyOfWk(char month, char day, unsigned int year){
    int weekDay=(day+gtMnVal(month,year)+gtYrVal(year)+gtCntVl(year));
    weekDay%=7;
    switch(weekDay){
        case 0:return "Sunday";
        case 1:return "Monday";
        case 2:return "Tuesday";
        case 3:return "Wednesday";
        case 4:return "Thursday";
        case 5:return "Friday";
    }
    return "Saturday";
}

char  gtMnVal(char month,unsigned int year){
    switch(month){
        case 1:{
            if(isLpYr(year))return 6;
            return 0;
        }
        case 2:{
            if(isLpYr(year))return 2;
            return 3;
        }
        case 3:case 11:{return 3;}
        case 4:case 7:{return 6;}
        case 5:{return 1;}
        case 6:{return 4;}
        case 8:{return 2;}
        case 9:case 12:{return 5;}
        case 10:{return 0;}
    }
}

char  gtYrVal(unsigned int year){
    return year%100+(year%100)/4;
}

char  gtCntVl(unsigned int year){
    int century=year/100;
    return 2*(3-century%4);
}

bool isLpYr(unsigned short year){
    return ((year%400==0)||((year%4==0)&&(!(year%100==0))));
}

unsigned char cnvMnth(string sMonth){
    if(sMonth=="January")  return 1;
    if(sMonth=="February") return 2;
    if(sMonth=="March")    return 3;
    if(sMonth=="April")    return 4;
    if(sMonth=="May")      return 5;
    if(sMonth=="June")     return 6;
    if(sMonth=="July")     return 7;
    if(sMonth=="August")   return 8;
    if(sMonth=="September")return 9;
    if(sMonth=="October")  return 10;
    if(sMonth=="November") return 11;
    return 12;
}

unsigned char cnvDay(string sDay){
    char day=sDay[0]-48;
    if(sDay[1]==',')return day;
    day*=10;
    day+=sDay[1]-48;
    return day;
}