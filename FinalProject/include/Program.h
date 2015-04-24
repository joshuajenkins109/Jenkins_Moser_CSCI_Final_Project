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
        void addWord(std::string word); //use this to add a word to the table
        int checkSum(std::string x, int s); //get sum of word ascii values and % by size of table
        bool wordExist(std::string word);
        std::string encrypt(std::string x, int key); //encrypt obviously
        std::string decrypt(std::string x, int key); //decrypt obviously..

        //What other functions could we include? we need 10

    protected:
    private:
//<<<<<<< HEAD
        std::vector<HashNode> hashTable; //upon creation, increases table to have predefined # of empty HashNodes
        int tableSize = 0; //defining number for size of hashTable
//=======
        //std::vector<HashNode> hashTable; //upon creation, increases table to have predefined # of empty HashNodes
         //defining number for size of hashTable
//>>>>>>> 72083d34a51dbea9a07d033087581c0cb439ee83
};

#endif // PROGRAM_H
