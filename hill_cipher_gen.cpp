#include <iostream>
using namespace std;
#define n 3
void getKeyMatrix(string key, int keyMatrix[][n])
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}
void encrypt(int cipherMatrix[][1],int keyMatrix[][n],int messageVector[][1])
{
    int x, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;

             for (x = 0; x < n; x++)
                cipherMatrix[i][j] +=keyMatrix[i][x] * messageVector[x][j];

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

int det(int keyMatrix[][n])
{
    if(n==3)
    {
    int d=keyMatrix[0][0]*(keyMatrix[1][1]*keyMatrix[2][2]-keyMatrix[2][1]*keyMatrix[1][2])-
            keyMatrix[0][1]*(keyMatrix[1][0]*keyMatrix[2][2]-keyMatrix[2][0]*keyMatrix[1][2])+
            keyMatrix[0][2]*(keyMatrix[1][0]*keyMatrix[2][1]-keyMatrix[2][0]*keyMatrix[1][1]);
    return d;
    }
    else if(n==2)
        return (keyMatrix[0][0]*keyMatrix[1][1]-keyMatrix[1][0]*keyMatrix[0][1]);
}

int modInv(int d)
{
    int i;
    for(i=0;i<26;i++)
    {
        if((d*i)%26==1)
            return i;
    }
}
int cofact(int i,int j,int keyMatrix[][n])
{
    int temp[n-1][n-1],p,q,a=0,b=0;
    for(p=0;p<n;p++)
    {
        for(q=0;q<n;q++)
        {
            if(q!=j && p!=i)
            {
                temp[a][b]=keyMatrix[p][q];
                b++;
            }
            if(b==n-1)
            {
                b=0;
                a++;
            }
        }
    }
    int x;
    if(n==3)
        x=temp[0][0]*temp[1][1]-temp[1][0]*temp[0][1];
    else
        x=temp[0][0];
    return x;
}

void getInv(int invMat[][n],int val,int keyMatrix[][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            int s;
            if((i+j)%2==0)
                s=1;
            else
                s=-1;
            invMat[j][i]=s*cofact(i,j,keyMatrix)*val;
            invMat[j][i]=(26+(invMat[j][i]%26))%26;
        }
    }
}

void decrypt(int cipherMatrix[][1],int keyMatrix[][n])
{
    cout<<" Plain Text : ";
    int d=det(keyMatrix);
    int val=modInv(d);
    int invMat[n][n],i,j,k;
    getInv(invMat,val,keyMatrix);
    int mainMat[n][1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<1;j++)
        {
            mainMat[i][j]=0;
            for(k=0;k<n;k++)
                mainMat[i][j]+=invMat[i][k] * cipherMatrix[k][j];
            mainMat[i][j]=mainMat[i][j]%26;
            cout<<(char)(mainMat[i][j]+65);
        }

    }
    cout<<"\n";
}

void HillCipher(string message, string key)
{
    int keyMatrix[n][n];
    getKeyMatrix(key, keyMatrix);
    int k=0,j,i;
    for(j=0;j<message.length();j+=n)
    {
        int messageVector[n][1];
        for (i=0; i < n; i++)
         {
           messageVector[i][0] = (message[k]) % 65;
            k++;
        }
    int cipherMatrix[n][1];
    encrypt(cipherMatrix, keyMatrix, messageVector);

    string CipherText;
    for (int i = 0; i < n; i++)
        CipherText += cipherMatrix[i][0] + 65;

    cout << " Ciphertext: " << CipherText<<"\n";
    decrypt(cipherMatrix,keyMatrix);
    }
}

int main()
{
    string message = "ACTINGISLIFENG";
    string key = "GYBNQKURP";
    HillCipher(message, key);
    cout<<"\n";
    return 0;
}
