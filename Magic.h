#pragma once

#include "TreeType.h"
#include "teebuff.h" //combines file output and console output into a single line of code
#include <algorithm> //allows for the usage of different algorithm functions
#include <cctype> //given to characters and digits in the ASCII librarian to classify them
#include <fstream> //allows for file IO manipulation
#include <iostream> //allows for console IO manipulation
#include <limits> //clears the input buffer for words and strings
#include <sstream> //seperates each word found in a string
#include <vector> //arrays with dynamic allocation functions
using std::ofstream;
using std::ifstream;
using std::vector;
using std::string;
using std::getline;

class Magic
{
private:

	string names; //names of participants
	vector<string> magicWords; //magic words
	vector<string> missedMagicWords; //words that the contestants missed

	TreeType phrase; //Needed for book's code
	OrderType orderOfInput; //is the order of the string words
	bool present; //bool that stores wether a magic word is present or not in a text

	
	ofstream outFile; //out put file
	ComposeStream out; //echos output to both console and file

public:
  Magic(); //Constructor
  ~Magic(); //Destructor
  
  /**
  Gets the magic words from the input file
  **/
  void getMagic();
  
  /*
  converts a string into a string that has no formatting
  */
  string convert(string text);

  /*
  Processes the player's input.
  */
  void processPlayer();

  /*
  Finds if any of the player's answers match with the magic words.  If user's answer matched with all
  magic words, print wining results, otherwise print losing results
  */
  void MatchNPrint();
};