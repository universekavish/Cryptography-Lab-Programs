#include<bits/stdc++.h>
using namespace std;
string encryptMessage(string msg,int a,int b)
{
    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        if(msg[i]!=' ')
            cipher+=(char) ((((a * (msg[i]-'A') ) + b) % 26) + 'A');
        else
            cipher += msg[i];
    }
    return cipher;
}

string decryptCipher(string cipher,int a,int b)
{
    string msg = "";
    int a_inv = 0;
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < cipher.length(); i++)
    {
        if(cipher[i]!=' ')
            msg = msg +(char) (((a_inv * ((cipher[i]+'A' - b)) % 26)) + 'A');
        else
            msg += cipher[i];
    }

    return msg;
}
int main(void)
{
    int a,b;
    string msg;
    cout<<"enter message\n";
    cin>>msg;
    cout<<"Enter mul_value and add_value  ";
    cin>>a>>b;
    string cipherText = encryptMessage(msg,a,b);
    cout << "Encrypted Message is : " << cipherText<<endl;
    cout << "Decrypted Message is: " << decryptCipher(cipherText,a,b);

    return 0;
}
