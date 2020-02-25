#include<bits/stdc++.h>
using namespace std;
int main()
{
    string msg,key,encrypted,decrypted;
    int i;
    msg="wearediscoveredsaveyourself";
    key="deceptive";
    int m=msg.length(),k=key.length();
    for(i=0;i<m;i++)
    {
        encrypted+=(((msg[i]-97) ^ (key[i %k]-97)) +65);
    }
    cout<<"ENCRYPTED MESSAGE : "<<encrypted<<"\n";
    for(i=0;i<m;i++)
    {
        decrypted+=(((encrypted[i]-65) ^ (key[i %k]-97))+97);
    }
    cout<<"DECRYPTED MESSAGE : "<<decrypted<<"\n";
    return 0;
}
