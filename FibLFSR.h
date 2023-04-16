/*
Name: Matthew Svenson
Course Name: Computing IV
Assignment Name: PS1a
Instructors Name: James Daly
Due Date: 1/31/2022

Program Description:
Creating a Linear Feedback Register Shift (Left)
*/

#ifndef FIBLFSR_H
#define FIBLFSR_H

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class FibLFSR { 
public: 
	FibLFSR(string seed); // constructor to create LFSR with      
						// the given initial seed
	int step();             	// simulate one step and return the    
						// new bit as 0 or 1 
	int generate(int k);    	// simulate k steps and return  
						// k-bit integer 
	friend ostream& operator<<(ostream& os, FibLFSR& output);

	string print();
private:

	int FibSeed[16];
};

#endif
