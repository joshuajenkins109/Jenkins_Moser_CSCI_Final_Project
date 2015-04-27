#include <iostream>
#include "Program.h"
#include <fstream>

using namespace std;

void dispMenu();

int main()
{
    Program H; //H for hashTable

    H.createHashtable();

    dispMenu();
    bool quit = false;
    while(!quit)
    {
        int cmd = -1;
        string rawInput;
        getline(cin,rawInput);
        cin.clear();
        cmd = atoi(rawInput.c_str());
        switch(cmd)
        {
            case 1:
                //insert encryption
                dispMenu();
                break;
            case 2:
                //insert decryption
                dispMenu();
                break;
            case 3:
                H.printHashTable();
                dispMenu();
                break;
            case 4:
                quit = true;
                break;
            default:
                cout<<"error: not a valid command"<<endl;
                dispMenu();
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
    cout<<"4.quit"<<endl;
    cout<<"========================"<<endl;
}
