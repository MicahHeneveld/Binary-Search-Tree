#include "Magic.h"
using std::cout;  // used to display messages to the console

//Constructor
Magic::Magic()
{
	outFile.open("Output.txt");
	out.linkStream(cout); //Outputs to the console
	out.linkStream(outFile); //Outputs to the outfile
}

//Destructor
Magic::~Magic()
{
	outFile.close();
}

/*
Gets the magic words from the magic word file and assigns them to a string array(vector)
*/
void Magic::getMagic()
{
	string MagicWord;  //declares string named MagicWord
	ifstream magicFile;  //file to get magic words from
	magicFile.open("Magic.txt");  //opens magic word file
	if (magicFile.fail())  //makes sure the file containing the magic words can be opened
	{
		throw ("File can not open.\n");
		return;
	}



	while (magicFile >> MagicWord)  //reads the words from the input file into the MagicWord variable
	{
		magicWords.push_back(convert(MagicWord));
	}
	magicFile.close();  //closes the magic word input file

	
	/*
	Outputs the magic words to the output file and console(through the use of teebuff)
	*/

	out << "The Magic words are:\n\n--------------------";

	for (auto& magic_word : magicWords)
	{
		out << "\n\n" << magic_word;
	}
	out << std::endl << std::endl;
}


/*
Processes the player's input
*/
void Magic::processPlayer()
{
	string word, line, type;  //declares string variables
	ifstream playerInput;  //declares input file that contains that player's input
	playerInput.open("TextPass.txt");  
	if (playerInput.fail())     //makes sure the player input file can be opened
	{
		throw ("ERROR: 'TextPass.txt' could not be opened.");
		return;
	}



	while (playerInput >> type, getline(playerInput, line))  //reads in the player input and stores it in local variables
	{
		line.erase(line.begin(), std::find_if(line.begin(), line.end(),
			std::bind1st(std::not_equal_to<char>(),
				' ')));

		//Remove trailing newline
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		if (type == "1")  //if user name
		{
			names = line;
			out << "\n" << names << " said, \"";
		}

		else if (type == "2")  //if user answer
		{
			out << line << "\"" << std::endl;
			// Used to split string around spaces.
			std::stringstream ss(line);
			//string word;
			while (ss >> word)
			{
				phrase.PutItem(convert(word)); // Put words in BST
			}

			MatchNPrint();  //looks up result and prints it
		}
	}

	playerInput.close();  //closes input file
}

/*
Removes the formatting of a string
*/
std::string Magic::convert(string text)
{
	text.erase(std::remove_if(text.begin(), text.end(), ::ispunct), text.end());
	transform(text.begin(), text.end(), text.begin(), ::tolower);

	return text;
}


/*
Match the user input with matching magic words, if there are any, and then print the results to both the console and output file
*/
void Magic::MatchNPrint()
{
	for (auto& magicWord : magicWords)  //find any matching magic words
	{
		magicWord = phrase.GetItem(magicWord, present);  //mark the magic word as present
		if (!present)
		{
			missedMagicWords.push_back(magicWord);
		}
	}
	if (missedMagicWords.empty())  //if all magic words have been matched, display a winning message
	{
		out << "\nGreat job " << names << "!!!  You won the game!!!\n";
	}

	
	else   //if not all magic words have been matched, display a losing message
	{
		out << "\nBummer " << names << "!  You lost the game by missing some words.\n\nHere are the words that you missed\n";

		for (auto& missed_word : missedMagicWords)  //display missed magic words
		{
			out << "\n\n" << missed_word;
		}


		/*
		clears the missed magic words list
		*/
		phrase.MakeEmpty();
		missedMagicWords.clear();
		out << "\n\n";
	}
}
