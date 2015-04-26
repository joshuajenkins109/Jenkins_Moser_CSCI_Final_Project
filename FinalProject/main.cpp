#include <iostream>
#include "Program.h"
#include <fstream>

using namespace std;

int main()
{
    Program H; //H for hashTable

    string word;
    ifstream infile("google-10000-english.txt");
    infile >> word;
    //cout<<word<<endl;
    H.addWord(word);
    while(!infile.eof())
    {
        infile >> word;
        //cout<<word<<endl;
        H.addWord(word);
    }
    infile.close();
    H.printInventory();
    return 0;
}
