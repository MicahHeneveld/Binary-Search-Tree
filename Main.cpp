/**
Binary Search Tree
4/18/2022
Micah Heneveld
Acknowledgments to https://stackoverflow.com/a/1761027 for the teebuff code
**/



#include "Magic.h" 
using std::cerr;  //used for error message in the try and catch

int main()
{
	Magic magicOb; //declare magic object

	
	try
	{
		magicOb.getMagic(); //gets magic words from file
		magicOb.processPlayer();  //gets player's information from file
	}

	catch (...)
	{
		cerr << "ERROR: Program was unable to pull from 'Magic.txt' and cannot add the letters words to the tree";
	}
}
