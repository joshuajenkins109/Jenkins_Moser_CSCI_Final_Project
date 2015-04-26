#include "Program.h"
#include <vector>
#include <sstream>
#include <iostream>

Program::Program()
{
    for(int i = 0; i < tableSize; i++)
    {
        HashNode _newNode;
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

void Program::printInventory()
{
    for(int i = 0; i < tableSize; i++)
    {
        std::cout<<i<<" : ";
        for(int j = 0; j < hashTable[i].words.size(); j++)
        {
            std::cout<<hashTable[i].words[j]<<" ; ";
        }
        std::cout<<std::endl;
    }
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

std::string Program::encrypt(std::string message, int key)
{
    std::stringstream ss(message);
    std::string in;
    int track;
    int start;
    std::string change = "";
    int collidecheck = 0;
    std::string encrypted = "";


    while(getline(ss,in,','))
    {
        track = 0;
        start = checkSum(in, hashTable.size());
        while(hashTable[start].words[collidecheck] != in)
        {
            collidecheck++;
        }
        while(change == "")
        {
            for(int i = collidecheck; i < hashTable[start].words.size(); i++)
            {
                if(track == key)
                {
                    change = hashTable[start].words[collidecheck];
                    break;
                }
                track++;

            }
            start++;
        }
        encrypted += change;

    }
}
