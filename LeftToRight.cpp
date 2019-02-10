/*
Project Information:
  Project Title: Programming Assignment 1
  Class: CPSC 335 - Section 1 Tu/Th: 4:00 pm - 5:15 pm
  File Name: LeftToRight.cpp
  Due Date: 9/22/2015
  Purpose: Alternating disks problem, left to right algorithm
  Programmers: Alejandro Sanchez, Andrew Huynh, Jim Mao

Problem:
  Description: Given 2n alternating disks, (light and dark) the program reads the number of single color disks,
  arrangesthe disks in the correct order and outputs the number of swaps
  Input: A positive integer n and a list of 2n disks with alternating colors dark-light, starting with dark
  Output: A list of 2n disks, the first n disks being light, the other n disks being dark, and an integer m
  representing the number of moves taken to move the dark ones after the light ones.

README:
  Compiler: g++
  Navigate to project folder containing LeftToRight.cpp
  Open a terminal and run both of these commands

    g++ LeftToRight.cpp -o LeftToRight.out
    ./LeftToRight.out
*/                                                                                                                                                                      

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;
const int SIZE = 50;

/*
Function to print the list of disks
Input: n number of monocolor disks, and the array of 2n disks                                                                                                                                                                                                                                                                                                                                                                                                                             
Output: The list of disks, where L = Light disk, and D = Dark disk 
*/
void print_disks(int n, int disks[])
{
	cout << "Here is the list of Disks:\n";
	for ( int i = 0 ; i < (2*n) ; i++)
	{
		if (disks[i] == 1)                                      // 0 = Light colored disk
  		cout << "L ";
		else                                                    // Otherwise, 1 = Dark colored
	  	cout << "D ";
	}
  cout << endl;
}

int main()
{
  int i, n, m, k, j, swap;
  int disks[SIZE];                                          // Intialized array of empty disks

  // Display the header
  cout << endl << "CPSC 335-01 - Programming Assignment #1" << endl;
  cout << "The alternating disks problem: Left to right algorithm" << endl;
  cout << "Enter the number of single color disks (light or dark)" << endl;
  cin >> n;                                                 // Read the number of disks 

  // Set the initial configurations for the disks to alternate   
  for( i=0; i < n; i++)
  {
    disks[2*i] = 0;                                         
    disks[2*i+1] = 1;
  }

  cout << "\nInitial configuration:" << endl;
  print_disks(n,disks);                                     // Print initial list
  
  // Begin algorithm
  m = 0;                                                    // M represents the number of swaps
  for (i = 0; i < n; i++)                                   // Loop to push light one before darks ones
  { 
	 for (j = i; j< n * 2 - i; j++)                           // Go right                      
	{
		if (disks[j] == 0 && disks[j + 1] == 1)
		{
			swap = disks[j];
			disks[j] = disks[j + 1];
			disks[j + 1] = swap;
			m++;					//increment swap counter
		}
	}
  }                                                         
  // Algorithm finished

  cout << "\nAfter moving darker ones to the right" << endl;  
  print_disks(n, disks);                                    // Print the modified list of disks
  cout << "\nNumber of swaps is " << m << endl;             // Print the total number of moves
 
  return EXIT_SUCCESS;
}