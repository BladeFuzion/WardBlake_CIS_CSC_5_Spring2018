/* 
 * File:   main.cpp
 * Author: Blake Ward
 * Created on April 17, 2018, 7:30 PM
 * Purpose:  A game of Hang Man.
 */

//System Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

//Texts, top borders, and bottom borders of the game
void PrntMsg(string message,bool printTp=true,bool printBm=true)
    
    //If top is true
{
      if(printTp)//Top borders
    {          
        cout<<"☠▣^^^^^▣^^^^▣^^^☠^^^▣^^^^▣^^^^^▣☠"<<endl;//Top borders
        cout<<"Ⅲ";//Side Borders
    }
    else
    {
        cout<<"Ⅲ";//Side Borders
    }
    bool front=true;
    for(int i=message.length();i<33;i++)//Length of borders
    {
        if(front)//Front message
        {
            message=" "+message;//Spacing
        }
        else
        {
            message=message+" ";//Spacing
        }
        front=!front;
    }
    cout<<message.c_str();
    
    //If bottom is true
    if(printBm)//Bottom borders
    {
        cout<<"Ⅲ"<<endl;//Side Borders
        cout<<"☉∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎▣▣▣∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎☉"<<endl;//Bottom borders
    }
    else
    {
        cout<<"Ⅲ"<<endl;//Side Borders
    }
}

//Making the Hang Man
void Hangman(int guesCnt=0)
{
    if (guesCnt>=1)//First Fail
        PrntMsg("|", false,false);//First part of the rope
    else
        PrntMsg("",false,false);//Spacing
 
    if (guesCnt>=2)//Second Fail
        PrntMsg("|",false,false);//Second part of the rope
    else
        PrntMsg("",false,false);//Spacing
 
    if (guesCnt>=3)//Third Fail
        PrntMsg("Q",false,false);//Head of Hang Man
    else
        PrntMsg("",false,false);//Spacing
 
    if (guesCnt==4)//Fourth Fail
        PrntMsg("/  ",false,false);//Left arm of Hang Man
   
    if (guesCnt==5)//Fifth Fail
        PrntMsg("/| ",false,false);//Left arm and body of Hang Man
 
    if (guesCnt>=6)//Sixth Fail
        PrntMsg("/|\\",false,false);//Left arm, right arm, and body of Hang Man
    else
        PrntMsg("",false,false);//Spacing
 
    if (guesCnt>=7)//Ninth Fail
        PrntMsg("|",false,false);//Second part of the body
    else
        PrntMsg("",false,false);//Spacing
 
    if (guesCnt==8)//Eighth Fail
        PrntMsg("/",false,false);//Left leg of Hang Man
 
    if (guesCnt>=9)//Ninth Fail
        PrntMsg("/ \\",false,false);//Left and right leg of Hang Man
    else
        PrntMsg("",false,false);//Spacing
}

//Printed Letters
void PrntLtr(string input,char from,char to)
{
    string s;
    for(char i=from;i<=to;i++)//Letter inputs
    {
        if(input.find(i)==string::npos)//Found "npos" in chapter 19
        {
            s+=i;
            s+=" ";
        }
        else
            s+="  ";
    }
    PrntMsg(s,false,false);
}

//Available Letters to choose from
void AvbLtrs(string taken)
{
    PrntMsg("Available letters");
    PrntLtr(taken,'A','G');
    PrntLtr(taken,'H','M');
    PrntLtr(taken,'N','T');
    PrntLtr(taken,'U','Z');
}

bool WinChck(string word, string guessed)
{
    bool won=true;
    string s;
    for (int i=0;i<word.length();i++)
    {
        if (guessed.find(word[i])==string::npos)
        {
            won=false;
            s+="_ ";
        }
        else
        {
            s+=word[i];
            s+=" ";
        }
    }
    PrntMsg(s,false);
    return won;
}

string LoadWrd(string path)
{
    int lineCount=0;
    string word;
    vector<string> v;
    ifstream reader(path);
    if(reader.is_open())
    {
        while(std::getline(reader,word))
            v.push_back(word);
 
        int rndmLne=rand()%v.size();
 
        word = v.at(randomLine);
        reader.close();
    }
    return word;
}

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string guesses="ABHJIKKLL";
    
    //Random Number Generator
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
    string wrdGess;
    PrntMsg("Welcome to Hang Man");
    Hangman(9);
    AvbLtrs(guesses);
    PrntMsg("Guess the Word");
    WinChck("YO",guesses);
    
    //Output data
    
    //Exit stage right!
    return 0;
}