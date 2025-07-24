#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

bool only_digits(string s);
string convert(string s, int key);

int main(int argc, string argv[])
{
    int key = 0;

    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
    }else
    {
        string user = get_string("plaintext: ");
        key = atoi(argv[1]);
        string converted = convert(user, key);
        printf("cyphertext: %s\n", converted);
    }
}

string convert(string s, int key)
{
    string convertedstring = s;
    int x[strlen(s)];

    for(int i=0, len=strlen(s); i<len; i ++)
    {
        if(s[i]>96 && s[i]<123)
        {
            x[i] = (s[i]-97);
            x[i] = (x[i]+key)%26;
            convertedstring[i] = x[i]+97;
        }
        if(s[i]>64 && s[i]<91)
        {
            x[i] = (s[i]-65);
            x[i] = (x[i]+key)%26;
            convertedstring[i] = x[i]+65;
        }
    }

    return convertedstring;
}

bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
