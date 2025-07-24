#include <cs50.h>
#include <stdio.h>


long two(long number);
long one(long number);
long count(long number);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while(number < 0);

    long temp = number;

    // 取得最前兩位數
    while (temp >= 100)
    {
        temp /= 10;
    }

    int first_two = (int)temp;
    int first = first_two / 10;

    printf("第一位數字是：%d\n", first);
    printf("前兩位數字是：%d\n", first_two);
    
    long final = two(number)+one(number);

    if (final%10==0)
    {
        if(count(number)==15)
        {
            printf("AMEX\n");
        }
        else if(count(number)==16)
        {
            printf("MasterCard\n");
        }
        else if(count(number)==13)
        {
            printf("Visa\n");
        }else
        {
            printf("other\n");
        }
    }
    else
    {
        printf("invalid\n");
    }

}

long count(long number)
{
    int count=1;
    while(number>9)
    {
        number=number/10;
        count++;
    }
    return count;
}

long two(long number)
{
    long x=0;
    number=number/10;
    while(number>0)
    {
        if(2*(number%10)>=10)
        {
            x+=((2*(number%10))%10)+((2*(number%10))/10);
        }else
        {
            x+=2*(number%10);
        }
        number=number/100;
    }
    return x;
}
long one(long number)
{
    long x=0;
    while(number>0)
    {
        x+=number%10;
        number=number/100;
    }
    return x;
}
