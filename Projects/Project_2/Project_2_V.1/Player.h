//Header ==> Function Declarations
/* 
 * File:   Player.h
 * Author: Blake Ward
 *
 * Created on May 21, 2018, 10:49 PM
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

