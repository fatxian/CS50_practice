#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

bool isalphabet(string s);
bool isdifferent(string s);
string convert(string user_input, string key);

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./substitution key\n");
    }
    else if(strlen(argv[1])!=26)
    {
        printf("Key must contain 26 characters.\n");
    }
    else if(!isalphabet(argv[1]))
    {
        printf("Usage: ./substitution key\n");
    }
    else if(!isdifferent(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
    }
    else
    {
        string key = argv[1];
        string user_input = get_string("plaintext: ");
        string output = convert(user_input, key);
        printf("ciphertext: %s\n", output);
    }
}

bool isalphabet(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isalpha(s[i]))  // 只要遇到不是字母的，就失敗
        {
            return false;
        }
    }
    return true;  // 全部都是字母才 return true
}

bool isdifferent(string s)
{
    for(int i = 0, len = strlen(s); i < len; i++)
    {
        for (int j = i + 1; j < strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                return false;
            }
        }
    }
    return true;
}

string convert(string user_input, string key)
{
    //userinput轉會成ASCII
    int len = strlen(user_input);
    int s[len];

    string output = malloc(len + 1);  // +1 是為了字串結尾的 '\0'
    if (output == NULL)
    {
        printf("記憶體分配失敗\n");
        exit(1);
    }

    for(int i = 0; i < len; i++)
    {
        if(user_input[i]>96 && user_input[i]<123)
        {
            s[i] = user_input[i]-97;
        }
        if(user_input[i]>64 && user_input[i]<91)
        {
            s[i] = user_input[i]-65;
        }
    }
    //將ASCII當成key的位置
    for(int i = 0; i < len; i++)
    {
        output[i] = key[s[i]];
    }
    return output;
}
