The Binary-Search-Tree code was written as a response to the following prompt:

Groucho Marx used to have a game show called "You Bet Your Life" in which he would have a conversation with the contestant and try to get him or her to say a specified "magic word." If the contestant said the magic word, a duck would drop down, signaling that the contestant had won a prize. This program deals with a similar game, which will have a specified set of magic words. The input consists of several passages of text. Read in each passage, see if it includes all the magic words, and print whether or not the person wins the prize. You must use a binary search tree ADT to store the magic words from the “Magic.txt” file to speed up searching for these magic words. You must use the binary search tree ADT code from our textbook.

Input

The magic words are listed, one word per line, in the text file "Magic.txt".
Example of the “Magic.txt” file:

Line 1:     rosebud

Line 2:     programming

Line 3:     rainbow

Line 4:     fish

Line 5:     hashtag

Line 6:     tweet

The text passages are input from a second text file, "TextPass.txt". Each line in this text file starts with a number indicating what type of data this is where 1 is the contestants name and 2 is a text passage. You will want to ignore passage ending punctuation such as “!” and “?”. There can be more than one contestant in the “TextPass.txt” file.
Example of two contestants in the “TextPass.txt” file:

Line 1:     1 Bob

Line 2:     2 What am I doing here?

Line 3:     1 Mary

Line 4:     2 I am about to tweet hashtag rainbow fish and by the way, did you write the new programming assignment named rosebud?

Output

All program output is to be written to a text file "Output.txt", which is printed and turned in with your program listing.

Echo print the list of magic words. (Echo means that you are to print to the console and the output text file)
Echo print each section as it is read. Label the contestant's name.
In processing each text passage, keep track of which magic words were said, and at the end of the section, print out one of the following messages:
Congratulations, <name>, you have won the prize.

Sorry, <name>, you failed to say the following magic words:

   <list of unsaid magic words>

Sample Output

List of magic words:

fish

hashtag

programming

rainbow

rosebud

tweet

 

Bob says:

What am I doing here?

Sorry, Bob, you failed to say the following magic words:

 

fish

hashtag

programming

rainbow

rosebud

tweet

 

Mary says:

I am about to tweet hashtag rainbow fish and by the way, did you write the new programming assignment named rosebud?

Congratulations, Mary, you have won the prize.
