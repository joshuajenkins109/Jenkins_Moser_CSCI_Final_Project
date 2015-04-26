#ifndef PROGRAM_H
#define PROGRAM_H
#include <string>
#include <vector>

struct HashNode
{
    int value = -1;
    std::vector<std::string> words;
};

class Program
{
    public:
        Program();
        virtual ~Program();

        void createHashtable(); //this is where we build the Hashtable
        void addWord(std::string word); //use this to add a word to the table //done
        int checkSum(std::string x); //get sum of word ascii values and % by size of table //done
        bool wordExist(std::string word);//Checks to see if word is in hashtable //done
        void printInventory(); //this is to view the hashTable's contents //done
        std::string encrypt(std::string x, int key); //encrypts message //done
        std::string decrypt(std::string x, int key); //decrypt obviously..

        //What other functions could we include? we need 10

    protected:
    private:
        std::vector<HashNode> hashTable; //upon creation, increases table to have predefined # of empty HashNodes
        int tableSize = 2500; //defining number for size of hashTable
};

#endif // PROGRAM_H
