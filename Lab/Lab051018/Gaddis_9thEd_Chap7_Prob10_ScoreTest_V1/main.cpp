/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 10th, 2018, 11:20 AM
 * Purpose:  Score a Test
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
#include <fstream>  //I/O files
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns
#include <cmath>    //Math Library

//Function Prototypes
void rdFile(ifstream &,char [],int);
void wrtFile(ofstream &,char [],char [],int);
int  score(char [],char [],int);


//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int NQSTNS=20;//Number of questions
    char key[NQSTNS],answers[NQSTNS];//Answers and Key
    char keyFlNm[]="key.dat";
    string ansFlNm="answer.dat";
    char scrFlNm[]="score.dat";
    ifstream keyFl,ansFl;
    ofstream scrFl;
 
    //Initial Variables
    keyFl.open(keyFlNm);
    ansFl.open(ansFlNm.c_str());
    scrFl.open(scrFlNm);
 
    //Map/Process Inputs to Outputs
    rdFile(keyFl,key,NQSTNS);
    rdFile(ansFl,answers,NQSTNS);
    wrtFile(scrFl,key,answers,NQSTNS);
    int scrs=score(answers,key,NQSTNS);
    
    //Output the results
    cout<<"The Score Received = "<<100.0f*scrs/NQSTNS<<"%"<<endl;
    
    //Close files
    keyFl.close();
    ansFl.close();
    scrFl.close();
    
    //Exit program!
    return 0;
}

void rdFile(ifstream & in,char keyAns[],int size){
    for(int i=0;i<size;i++){
        in>>keyAns[i];
    }
}
void wrtFile(ofstream & out,char key[],char ans[],int size){
    for(int i=0;i<size;i++){
        if(key[i]==ans[i])out<<i<<". Correct"<<endl;
        else out<<i<<". Incorrect"<<endl;
    }
}
int  score(char ans[],char key[],int size){
    int correct=0;
    for(int i=0;i<size;i++){
        if(key[i]==ans[i])correct++;
    }
    return correct;
}