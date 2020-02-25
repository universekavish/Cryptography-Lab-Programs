#include<iostream>
#include<string>
#include<fstream>
using namespace std;


int main()
{
    string key, message;
    int array[26] = {0};
    char matrix[6][6];

    cout<<"Key : ";
    cin >> key;
    cout<<"Plain Text : ";
    cin >> message;

    int i,j;
    int keyLength = key.length();
    int mLength = message.length();
    int col = 0;
    int row = 0;
    for(i = 0; i < keyLength; i++)
    {
        if(key[i] == 106)
            key[i] = 105;
        if(col == 5)
        {
            row = row + 1;
            col = 0;
        }
        if(array[key[i] - 97] == 0)
        {
            array[key[i] - 97] = 1;
            matrix[row][col] = key[i];
            col++;
        }
    }
    for(i = 0; i < 26; i++)
    {
        if(i == 9)
            continue;
        if(col == 5)
        {
            row = row + 1;
            col = 0;
        }
        if(array[i] == 0)
        {
            array[i] = 1;
            matrix[row][col] = i + 97;
            col++;
        }
    }
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }

    for(i = 0; i < mLength; i++)
    {
        if((i % 2 == 1) && (message[i-1] == message[i]))
        {
            message.insert(i,"x",1);
        }
    }
    mLength = message.length();
    if(mLength % 2 == 1)
        message.push_back('x');

    cout<<endl;
    cout<<"x is appended : "<<endl;
    cout<<message;

    int col1= 0, col2 = 0, row1 = 0, row2 = 0;
    int flag = 0;
    int index = 0;
    string Cipher;
    while(index < mLength-1)
    {
        flag = 0;
        for(i= 0; i < 5; i++)
        {
            for(j = 0; j < 5; j++)
            {
                if(matrix[i][j] == message[index])
                {
                    col1 = j;
                    row1 = i;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }

        flag = 0;

        for(i= 0; i < 5; i++)
        {
            for(j = 0; j < 5; j++)
            {
                if(matrix[i][j] == message[index+1])
                {
                    col2 = j;
                    row2 = i;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }

//        cout<<col1<<" "<<row1<<endl;
//        cout<<col2<<" "<<row2<<endl;
        if(col1 == col2)
        {
            Cipher += matrix[(row1 + 1) % 5][col1];
            Cipher += matrix[(row2 + 1) % 5][col2];
        }
        else if(row1 == row2)
        {
            Cipher += matrix[row1][(col1+1) % 5];
            Cipher += matrix[row2][(col2+1) % 5];
        }
        else
        {
            Cipher += matrix[row1][col2];
            Cipher += matrix[row2][col1];
        }
        index = index + 2;
    }
    cout<<endl;
    cout<<"Cipher Text  :  "<<endl;
    cout<<Cipher<<endl;

    index = 0;
    string decrypted;
    while(index < mLength-1)
    {
        flag = 0;
        for(i= 0; i < 5; i++)
        {
            for(j = 0; j < 5; j++)
            {
                if(matrix[i][j] == Cipher[index])
                {
                    col1 = j;
                    row1 = i;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }

        flag = 0;

        for(i= 0; i < 5; i++)
        {
            for(j = 0; j < 5; j++)
            {
                if(matrix[i][j] == Cipher[index+1])
                {
                    col2 = j;
                    row2 = i;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }

//        cout<<col1<<" "<<row1<<endl;
//        cout<<col2<<" "<<row2<<endl;
        if(col1 == col2)
        {
            decrypted += matrix[(row1 - 1) % 5][col1];
            decrypted += matrix[(row2 - 1) % 5][col2];
        }
        else if(row1 == row2)
        {
            decrypted += matrix[row1][(col1-1) % 5];
            decrypted += matrix[row2][(col2-1) % 5];
        }
        else
        {
            decrypted += matrix[row1][col2];
            decrypted += matrix[row2][col1];
        }
        index = index + 2;
    }
    cout<<endl;
    cout<<"Decrypted Text : "<<endl;
    cout<<decrypted<<endl;
    return 0;
}

