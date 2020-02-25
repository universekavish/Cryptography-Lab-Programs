#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void encryption(int key, string message)
{
    int i;
    int length = message.length();
    for(i = 0; i < length ; i++)
    {
        if(message[i] !=' ')
        message[i] = (message[i] - 97 + key + 26) % 26  + 65;
    }
    cout<<"ENCRYPTION DONE"<<endl<<endl;

    ofstream fileOut;
    fileOut.open("Encrypt.txt");
    fileOut << message;
    fileOut.close();
}

void decryption(int key, string cipher)
{
    int i;
    int length = cipher.length();
    for(i = 0; i < length ; i++)
    {
        if(cipher[i]!=' ')
        cipher[i] = (cipher[i] - 65 - key + 26) % 26  + 97;
    }
    cout<<"DECRYPTION DONE"<<endl<<endl;

    ofstream fileOut;
    fileOut.open("Decrypt.txt");
    fileOut << cipher;
    fileOut.close();

}
int main()
{
    int choice;
    string message, cipher;
    int key;
    ifstream fileIn;
    ofstream fileOut;

    do
    {
        cout<<"1. Encryption "<<endl;
        cout<<"2. Decryption "<<endl;
        cout<<"3. Exit "<<endl;

        cin>>choice;
        cout<<endl;
        if(choice == 1)
        {
            cout<<"Enter the Key : ";
            cin>>key;
            cout<<endl;
            fileIn.open("Message.txt");
            getline(fileIn, message);
            fileIn.close();

            encryption(key, message);
        }
        else if(choice == 2)
        {
            fileIn.open("Encrypt.txt");
            getline(fileIn, cipher);
            fileIn.close();

            decryption(key, cipher);
        }

        else if(choice == 3)
            exit(0);

    }while(choice != 3);

}
