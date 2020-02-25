#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<vector>
using namespace std;

vector <int> encode(26);
vector <int> decode(26);

string encryption(string message)
{
    int i;
    int mLength = message.length();
    string encrypted;
    for(i = 0; i < mLength; i++)
    {
        if(message[i]==' ')
            encrypted+=' ';
        else
        encrypted += encode[message[i] - 97] + 65;
    }
    return encrypted;
}

string decryption(string cipher)
{
    int i;
    int cLength = cipher.length();
    string decrypted;
    for(i = 0; i < cLength; i++)
    {
        if(cipher[i]==' ')
            decrypted+=' ';
        else
        decrypted += decode[cipher[i] - 65] + 97;
    }
    return decrypted;
}
int main()
{
    int choice;
    int check[26] = {0};
    string message, cipher, decrypted;
    string key;
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
            fileIn.open("Key.txt");
            getline(fileIn, key);
            fileIn.close();
           // cout<<"\n"<<key<<" "<<key.length()<<"\n";
            int Keylength = key.length();
            if(Keylength != 26)
            {
                cout<<"INVALID KEY !!! "<<endl;
                break;
            }

            int i;
            for(i = 0; i < Keylength; i++)
            {
                if(check[key[i] - 97] == 0)
                {
                    check[key[i] - 97] = 1;
                    encode[i] = key[i] - 97;
                    decode[key[i] - 97] = i;
                }
                else if(check[key[i] - 97] == 1)
                {
                    cout<<"INVALID KEY !!! "<<endl;
                    break;
                }
            }
            if(i != Keylength)
                break;
            fileIn.open("Message.txt");
            getline(fileIn, message);
            fileIn.close();
            cipher = encryption(message);
            cout<<"ENCRYPTION DONE "<<endl;
            fileOut.open("Encrypt.txt");
            fileOut << cipher;
            fileOut.close();
        }
        else if(choice == 2)
        {
            fileIn.open("Encrypt.txt");
            getline(fileIn, cipher);
            fileIn.close();

            decrypted = decryption(cipher);
            cout<<"DECRYPTION DONE "<<endl;
            fileOut.open("Decrypt.txt");
            fileOut << decrypted;
            fileOut.close();
        }

        else if(choice == 3)
            exit(0);

    }while(choice != 3);

}
