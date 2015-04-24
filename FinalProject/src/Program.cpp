#include "Program.h"

Program::Program()
{
    for(int i = 0; i < tableSize; i++)
    {
        new HashNode _newNode;
        _newNode.value = i;
        hashTable.push_back(_newNode);
    }
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
