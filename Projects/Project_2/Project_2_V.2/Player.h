//Header ==> Function Declarations
/* 
 * File:   main.cpp
 * Author: Blake Ward
 * Created on April 17, 2018, 7:30 PM
 * Purpose:  A game of Hang Man.
 */

#include <iostream>
#include <string>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    //Default Constructor
    Player();
    
    //Overload Constructor
    Player(string, int);
    
    //Destructor
    ~Player();
    
    //Accessor Functions
    string getName() const;
           //getName - returns name of player
    
    int getAge() const;
        //getAge - returns age of player
    
    //Mutator Functions
    void setName(string);
         //setName - sets name of player
         //@param string - name of patient
    
    void setAge(int);
        // setAge - sets age of player
        // @param int - age of player
    
private:
    //Member Variables
    string newName;
    int    newAge;
};

#endif /* PLAYER_H */
