/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 1st, 2018, 11:20 AM
 * Purpose:  x \ /
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char shape;
    int size;
    
    //Initial Variables
    shape='b';
    size=5;
 
    
    //Output the results
    if(shape=='x'&&size%2==1){
        for(int row=1;row<=size;row++){
            for(int col=1;col<=size;col++){
                if(row==col){
                    cout<<size+1-row;;
                }else if(row+col==size+1){
                    cout<<row;
                }else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }else if(shape=='x'&&size%2==0){
        for(int row=1;row<=size;row++){
            for(int col=1;col<=size;col++){
                if(row==col){
                    cout<<row;
                }else if(row+col==size+1){
                    cout<<size+1-row;;
                }else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }
    
    if(shape=='b'&&size%2==1){
        for(int row=1;row<=size;row++){
            for(int col=1;col<=size;col++){
                if(row==col){
                    cout<<size+1-row;;
                }else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }else if(shape=='b'&&size%2==0){
        for(int row=1;row<=size;row++){
            for(int col=1;col<=size;col++){
                if(row==col){
                    cout<<row;
                }else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }

    
    //Exit program!
    return 0;
}