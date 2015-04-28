#include <iostream>
#include "Program.h"
#include <fstream>

using namespace std;

void dispMenu();

int main()
{
    Program H; //H for hashTable
    H.createHashtable(); //Read in our file with all words

    //dispMenu();
    bool quit = false;
    while(!quit)
    {
        dispMenu();
        int cmd = -1;
        string rawInput;
        int key = -1;
        string msg;
        getline(cin,rawInput);
        cin.clear();
        cmd = atoi(rawInput.c_str());
        //dispMenu();
        switch(cmd)
        {
            case 1:
                ///something is broken with enc/dec methods
                //fix encryption
                cout<<"please enter a message to be encrypted:"<<endl;
                getline(cin,msg);
                cin.clear();
                cout<<"enter integer for encryption key:"<<endl;
                cin >> key;
                cin.clear();
                cout<<H.encrypt(msg,key)<<endl;
               // dispMenu();
                break;
            case 2:
                //fix decryption
                cout<<"please enter a message to be decrypted:"<<endl;
                getline(cin,msg);
                cin.clear();
                cout<<"enter integer for decryption key:"<<endl;
                cin >> key;
                cin.clear();
                cout<<H.decrypt(msg,key)<<endl;
                //dispMenu();
                break;
            case 3:
                H.printHashTable();
                //dispMenu();
                break;
            case 4:
                cout<<"enter a word to search inventory for:"<<endl;
                getline(cin,msg);
                cin.clear();
                H.findWord(msg);
                break;
            case 5:
                quit = true;
                break;
            default:
                cout<<"error: not a valid command"<<endl;
                //dispMenu();
                break;
        }
    }
    return 0;
}

void dispMenu()
{
    cout<<"==========Menu=========="<<endl;
    cout<<"1.encrypt"<<endl;
    cout<<"2.decrypt"<<endl;
    cout<<"3.print inventory"<<endl;
    cout<<"4.find word"<<endl;
    cout<<"5.quit"<<endl;
    cout<<"========================"<<endl;
}
