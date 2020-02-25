#include<bits/stdc++.h>
using namespace std;
int main()
{
    string message, Cipher, decrypted;
    cout<<"Enter Plain Text : "<<endl;
    cin>>message;
    int mLength = message.length();
    int rowLength = 0;
    int i;
    for(i = 0; i < mLength; i = i + 2)
    {
        Cipher+=message[i];
        rowLength++;
    }
    for(i = 1; i < mLength; i = i + 2)
    {
        Cipher+=message[i];
    }
    cout<<endl;
    cout<<"Cipher Text is : "<<endl;
    cout<<Cipher<<endl<<endl;
    for(i = 0; (i + rowLength) < mLength; i++)
    {
        decrypted+=Cipher[i];
        decrypted+=Cipher[i+rowLength];
    }
    cout<<"Decrypted Text is : "<<endl;
    cout<<decrypted<<endl<<endl;
    return 0;
}
