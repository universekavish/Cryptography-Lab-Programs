#include<bits/stdc++.h>
using namespace std;

string decrypt(string encr,int m,string key,int n)
{
    int i=0,j=0;
    string s4;
    while(i<m)
    {
        if(encr[i]==' ')
        {
            s4+=' ';
            i++;
        }
        else
        {

            int d=encr[i]-97-(key[j]-97);
            s4+=(d%26 +26)%26 +97;
            i++;
            j++;
        }
        if(i<m && j==n)
            j=0;
    }
    return s4;
}

string encrypt(string msg,int m,string key,int n)
{
    int i=0,j=0;
    string s3;
    while(i<m)
    {
        if(msg[i]==' ')
        {
            s3+=' ';
            i++;
        }
        else
        {
            s3+=(msg[i]-97+key[j]-97)%26 + 97;
            i++;
            j++;
        }
        if(i<m && j==n)
            j=0;
    }
    return s3;;
}

int main()
{
    string msg,key,encrypted,decrypted;
    msg="we are discovered save yourself";
    key="deceptive";
    int m=msg.length(),k=key.length();
    encrypted=encrypt(msg,m,key,k);
    cout<<"Encrypted message : "<<encrypted<<"\n";
    decrypted=decrypt(encrypted,m,key,k);
    cout<<"Decrypted message : "<<decrypted<<"\n";
    return 0;
}
