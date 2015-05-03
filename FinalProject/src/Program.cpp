#include "Program.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

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
    void createHashtable();
    This function creates the hashtable by adding words from an outside source
    to the table.
    H.createHashtable();
    Pre-Condition
        file to read words from exists
    Post-condition
        hashtable contains all words from read in file
*/

void Program::createHashtable()
{
    std::string word;
    std::ifstream infile("google-10000-english.txt");
    infile >> word;
    //cout<<word<<endl;
    addWord(word);
    while(!infile.eof())
    {
        infile >> word;
        //cout<<word<<endl;
        addWord(word);
    }
    infile.close();
}

/*
    int CheckSum(string);
    This is just the basic function that determines
    the location for the word in the hashTable based on the ascii values.
    hashTable[checkSum("cat")] = "cat";

    Pre-Conditions:
        Hashtable exists (so that you know the size to input)
        word is a string
    Post-Conditions:
        Returns location that word should be in hashTable
*/

int Program::checkSum(std::string word)
{
    int sum = 0;
    for(int i = 0; i < word.length(); i++)
    {
        sum = sum + (int)word[i];
    }

    sum = sum % tableSize;
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
    int hsh = checkSum(word);
    bool exist = false;
    for(int i = 0; i < hashTable[hsh].words.size(); i++)
    {
        if(hashTable[hsh].words[i] == word)
        {
            exist = true;
            break;
        }
    }
    return exist;
}

/*
    void printHashTable();
    This function goes through the hashtable and prints every word
    Pre-Condition
        hashtable exists
        there should be words added to the table(though it wont cause an error without them)
    Post-Condition
        all words in hashtable printed
*/

void Program::printHashTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        if(hashTable[i].words.size() > 0)
        {
            std::cout<<i<<" : ";
            for(int j = 0; j < hashTable[i].words.size(); j++)
            {
                std::cout<<hashTable[i].words[j]<<" ; ";
            }
            std::cout<<std::endl;
        }
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
    if(wordExist(word) == false)
    {
        hashTable[checkSum(word)].words.push_back(word);
    }
}
/*
    void delWord(word)
    this is a function added to meet number requirements, it deletes
    words from the hashtable if you wanted to do that for some reason.

    Pre-Condition
        word exist in existing hashtable
    Post-condition
        word is no longer in hashtable
*/
void Program::delWord(std::string word)
{
    if(wordExist(word) == true)
    {
        int hsh = checkSum(word);
        bool found = false;
        int i = 0;
        while(i < hashTable[hsh].words.size() && !found)
        {
            if(hashTable[hsh].words[i] == word)
            {
                found = true;
            }
            i++;
        }
        while(i < hashTable[hsh].words.size() - 1)
        {
            std::string temp = hashTable[hsh].words[i+1];
            hashTable[hsh].words[i+1] = hashTable[hsh].words[i];
            hashTable[hsh].words[i] = temp;
        }
        hashTable[hsh].words.pop_back();
    }
}

/*
    string encrypt(string, key)
    This function takes in a string of words and shifts them into different words
    based on the key by going [key] number of words away from the word

    encrypt("The cat says meow", 10)

    Pre-Condition
        The hashtable is built, words should be added, however if they aren't
        encrypt will add the words from the sentence and the encrypt just wont work as well
        message needs to be a string of words and the key needs to be a integer
    Post-Condition
        All words in message or shifted by key number and a new [encrypted]
        sentence is built
*/

std::string Program::encrypt(std::string message, int key)
{
    std::stringstream ss(message);
    std::string in;
    int track;
    int start;
    std::string change = "";
    int collidecheck = 0;
    std::string encrypted = "";


    while(getline(ss,in,' '))
    {
        //::cout<<"in is: "<<in<<std::endl;
        track = 0;
        collidecheck = 0;
        start = checkSum(in);
        change = "";
        if(wordExist(in) == false)
        {
            addWord(in);
            //std::cout<<"FAILED FAILED FAILED"<<std::endl;
        }
        while(hashTable[start].words[collidecheck] != in)
        {
            collidecheck++;
        }
        while(change == "")
        {
            if(start == tableSize)
            {
                start = 0;
            }
            for(int i = collidecheck; i < hashTable[start].words.size(); i++)
            {
                if(track == key)
                {
                    change = hashTable[start].words[i];
                    break;
                }
               //std::cout<<"ON THE MOVE:  "<< hashTable[start].words[i];
               track++;
            }
            start++;
        }
        //std::cout<<"change is: "<<change<<std::endl;
        encrypted = encrypted +" "+ change;
    }
    return encrypted;
}

/*
string decrypt(string);
Decrypt is the opposite of encrypt, it shifts the words backwards
through the table based on the key
string message = decrypt("cat family far tribe tickle")
Pre-Condition
    hashTable is built and words have been added to it
    Decrypt assumes message was previously encrypted(so all words
    should exist in table) it also assumes no words have been added since
    it was encrypted because this could cause an error in decryption as of
    right now.
Post-Condition
    sentence is decrypted, and returns to the original message that was encrypted
*/

std::string Program::decrypt(std::string message, int key)
{
    //key = -key;
    std::stringstream ss(message);
    std::string in;
    int track;
    int start;
    std::string change = "";
    int collidecheck = 0;
    std::string decrypted = "";

    while(getline(ss,in,' '))
    {
        //std::cout<<"in is: "<<std::endl;
        track = 0;
        start = checkSum(in);
        collidecheck = 0;
        change = "";
        while(hashTable[start].words[collidecheck] != in)
        {
            collidecheck++;
        }
        while(change == "")
        {
            if(start == -1)
            {
                start = tableSize - 1;
            }
            for(int i = collidecheck; i >= 0; i--)
            {
                if(track == key)
                {
                    change = hashTable[start].words[i];
                    //break;
                }
                track++;
            }
            start--;
        }
        //std::cout<<"change is: "<<change<<std::endl;
        decrypted = decrypted + " "+ change;
    }
    return decrypted;
}
/*
    void findWord(string);
    findWOrd will search the hashtable and tell you if the word is found in it. if it is
    found it prints out the index and the words found with it.
    Pre-
        Hashtable exists
    Post-
        prints out if word is found or not
*/
void Program::findWord(std::string word)
{
    int h = checkSum(word);
    bool found = false;
    for(int i = 0; i < hashTable[h].words.size(); i++)
    {
        if(hashTable[h].words[i] == word)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        std::cout<<"found at hash value: "<<h<<std::endl;
        std::cout<<"along with: ";
        for(int i = 0; i < hashTable[h].words.size(); i++)
        {
            if(hashTable[h].words[i] != word)
            {
                std::cout<<hashTable[h].words[i]<<"; ";
            }
        }
        std::cout<<std::endl;
    }
    else
    {
        std::cout<<"word not found"<<std::endl;
    }
}
