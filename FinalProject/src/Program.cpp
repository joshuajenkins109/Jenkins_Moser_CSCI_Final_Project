#include "Program.h"
#include <vector>
Program::Program()
{
    //ctor
}

Program::~Program()
{
    //dtor
}
 /*
    int CheckSum(string, int);
    This is just the basic function that determines
    the location for the word in the hashTable based on the ascii values.
    hashTable[checkSum("cat", 10)] = "cat";

    Pre-Conditions:
        Hashtable exists (so that you know the size to input)
        word is a string, siz is an int
    Post-Conditions:
        Returns location that word should be in hashTable

 */
int Program::checkSum(std::string word, int siz)
{
    int sum = 0;
    for(int i = 0; i < word.length(); i++)
    {
        sum = sum + (int)word[i];
    }

    sum = sum % siz;
    return sum;
}
/*
    bool wordExist(string);
    This function checks to see if the word already exists in the hashtable
    if(wordExist("cat") == false) ...
    Pre-Condition
        HashTable exist
        input expects string
    Post-Condition
        Returns true or false
            True if word exists in hashtable, false if it doesn't
*/
bool Program::wordExist(std::string word)
{
    bool exist = false;
    for(int i = 0; i < hashTable.size(); i++)
    {
        for(int j = 0; j < hashTable[i].words.size();j++)
        {
            if(hashTable[i].words[j] == word)
            {
                exist = true;
                break;
            }
        }
    }
    return exist;
}
/*
    void addWord(string)
    This function adds a word to the hashtable if it isn't already there
    addword("cat");
    Pre-Condition
        hashtable exists
        string input expected
    Post-Condition
        word is added to hashtable
*/
void Program::addWord(std::string word)
{
    if( wordExist(word) == false)
    {
        hashTable[checkSum(word,hashTable.size())].words.push_back(word);
    }

}
