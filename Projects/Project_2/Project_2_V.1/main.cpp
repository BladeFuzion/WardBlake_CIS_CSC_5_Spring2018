/* 
 * File:   main.cpp
 * Author: Blake Ward
 * Created on April 17, 2018, 7:30 PM
 * Purpose:  A game of Hang Man.
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <vector>   //Initializing its Contents
#include <fstream>  //File i/o
#include <string>   //String
#include <ctime>    //Time
#include <cstdlib>  //Rand/Srand
#include <iomanip>  //Format Library
#include <cmath>    //Mathematical Operations

#include "Player.h"

using namespace std;//namespace I/O stream library created

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
void Hangman(float guesCnt=0)
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
        PrntMsg("/ ",false,false);//Left leg of Hang Man
 
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
void AvbLtrs(string taken)//Available Letters to type
{
    PrntMsg("Available letters");//Shows Letters to choose from
    PrntLtr(taken,'A','G');//Letters A - G
    PrntLtr(taken,'H','M');//Letters H - M
    PrntLtr(taken,'N','T');//Letters N - T
    PrntLtr(taken,'U','Z');//Letters U - Z
}

//Checking if the user won
bool WinChck(string word, string guessed)//Checks if user won
{
    bool won=true;//Set won to true
    string s;
    for (int i=0;i<word.length();i++)//Word length
    {
        if (guessed.find(word[i])==string::npos)//finds word
        {
            won=false;//won set to false
            s+="_ ";
        }
        else
        {
            s+=word[i];//If += to word
            s+=" ";
        }
    }
    PrntMsg(s,false);//Prints message if false
    return won;//Returns win
}

//Loading the random word
string LoadWrd(string path)
{
    int lineCount=0;//Set line count to 0
    string word;//String for word
    vector<string> v;//found the use of vectors in Chapter 8,
                     //v is used for word line
    ifstream reader(path);
    if(reader.is_open())
    {
        while(std::getline(reader,word))
            v.push_back(word);
        int rndmLne=rand()%v.size();
        word=v.at(rndmLne);
        reader.close();
    }
    return word;//Returns word
}

//Tries left in game
int TrysLft(string word,string guessed)
{
    int error=0;//setting error to 0
    for (int i=0;i<guessed.length();i++)//Having 'i' equal to zero while having it 
                                        //less than the 'guessed.length'
    {
        if (word.find(guessed[i])==string::npos)
            error++;
    }
    return error;//Returns the error
}

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) { 
    
    //Players info
    string name; //Players name
    int age;     //Players age
    
    cout<<"Enter your name: ";//Outputs players name
    cin>>name;                //For player to type in name
    cout<<"Enter your Age: "; //Outputs players age
    cin>>age;                 //For player to type in age
    
    Player user(name, age);   //users name
    
    cout<<endl<<"Players Name: "<<user.getName()<<endl<<
               "Age: "<<user.getAge()<<endl;
    
    cout<<endl;
    
    cout<<"Enter Player 2's name (If no player 2, type 'n/a'): ";//Outputs player 2's name
    cin>>name;                                                  //For player 2 to type in name
    cout<<"Enter player 2's Age (Type 0 if none): ";            //Outputs player 2's age
    cin>>age;                                                   //For player to type in age
    
    Player user2;       //New player code
    
    user2.setName(name);//Player 2's name
    user2.setAge(age);  //Player 2's age
    
    cout<<endl<<"Player 2's Name: "<<user2.getName()<<endl<<
               "Age: "<<user2.getAge()<<endl;
    
    cout<<endl;
    
    cout<<"Hello "<<user.getName()<<" (Age: "<< user.getAge()
                  <<") and "<<user2.getName()<<" (age: "
                  << user2.getAge()<<")!"<<endl;
            
    //Random number generator
    srand(time(0));
    
    //Declare Variables
    string guesses;//Guesses
    string wrdGues;//Word Guesses
    
    //Process/Map inputs to outputs
        wrdGues=LoadWrd("Words.txt");//Word file
        int tries=0;                 //Tries
        bool win=false;              //Win equal to false
        do                           //do loop
    {
            system("clear"); //Fresh system
            PrntMsg("Welcome to Hang Man");//Intro to Hangman
            Hangman(tries);                //Amount of tries player has attempted
            AvbLtrs(guesses);              //Available guesses left
            PrntMsg("Guess the Word (Caps only)");     //Tells player to guess to word
            WinChck(wrdGues,guesses);      //Checks whether you won or not
            if(win)
                win=1;
            char x;
            cout<<">";cin>>x;              //User input
            if(guesses.find(x)==string::npos)
               guesses+=x;
            tries=TrysLft(wrdGues,guesses);//?gives you the amount of tries left
        }while(tries<10);
        if(win)
            PrntMsg("You Win");//Text if you won
        else
            PrntMsg("You Lost. Correct Word Was:");//Text if you lost
            cout<<setw(22)<<wrdGues<<endl;
            float border=1,border2=2;//Border 1 and border 
            switch(1){
                case 1:cout<<"☉∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎▣"; //Extra borders
                case 2:cout<<"▣▣∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎☉";//Extra borders
            }cout<<border<<border2;

    //Exit stage right!
    return 0;
}