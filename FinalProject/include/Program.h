#ifndef PROGRAM_H
#define PROGRAM_H
#include <string>

class Program
{
    public:
        Program();
        virtual ~Program();

        void createHashtable(); ///this is where we build the Hashtable
        void addWord(std::string word); ///use this to add a word to the table
        int checkSum(std::string x, int s); ///get sum of word ascii values
        std::string encrypt(std::string x, int key); ///encrypt obviously
        std::string decrypt(std::string x, int key); ///decrypt obviously..
        ///What other functions could we include? we need 10


    protected:
    private:
        ///need to decide how we will create our hashtable and what type it will be, what size, ect.
};

#endif // PROGRAM_H
