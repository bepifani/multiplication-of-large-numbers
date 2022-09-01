/*
    This is example routine making multilication of 
    signed integers written in the textual form
*/
#include <stdio.h>
#include <string.h>
#define MAXLEN 25    // maximum length of strings

const struct
{
    const char* op1;
    const char* op2;
}
array_ []= {
{"1234","-287643"},
{"-74374547637","84374376436"},
{"1348352837373","8978484348432323"},
{"-2425226272828262","-262627262788"},
{"384843843","7237237"},
{"-8945845845384538453","-8423784237423"},
{"756456454646","7637636436"},
{"1111567789","-333345567"},
{"748787879245124","-98734987379875"},
{"98749587349752547265","-765653432645326453254"},
{"489757638","983492874928749287"},
{"-2834643823","356627"},
{"38476","9287349287942"},
{"-143645","41233"}
};

int ft_atoi(char c)
{
    int i = 0;
    i = i + c - '0';
    return(i);
}
char ft_itoa(int i)
{
    char c;
    c = i + '0';
    return (c);
}

void ft_make_num(char *str, int n)
{
    int i = strlen(str);
    while (n >= 0)
    {
        str[i] = '0';
        i++;
        n--;
    }
    str[i] = '\0';
}

char *ft_sum(char *s1, char *s2)
{
    int i = strlen(s1) - 1;
    int j = strlen(s2) - 1;
    char *str;
    int b = 0;
    str[i+2] = '\0';
    while(j >= 0)
    {
        str[i +1] = ft_itoa((b + ft_atoi(s1[i]) + ft_atoi(s2[j])) % 10);
        b = (b + ft_atoi(s1[i]) + ft_atoi(s2[j])) / 10;
        j--;
        i--;
    }
    while (i >= 0)
    {
        str[i + 1] = ft_itoa((b + ft_atoi(s1[i])) % 10);
        b = (b + ft_atoi(s1[i])) / 10;
        i--;
    }
    str[0] = ft_itoa(b);
    if (str[0] == '0')
    {
        i = 0;
        while (str[i] != '\0')
        {
            str[i] = str[i + 1];
            i++;
        }
        str[i] = '\0';
    }
    return (str);
}

char *mul(const char* op1, const char* op2)
{
    char mas[255][255];
    char *str;
    int i = strlen(op1) - 1;
    int j = strlen(op2) - 1;
    int a = 0;
    while(i >= 0 && op1[i] != '-')
    {
        j = strlen(op2) - 1;
        mas[i][j + 2] = '\0';
        a = 0;
        while (j >= 0 && op2[j] != '-')
        {
            if (a + (ft_atoi(op2[j]) * ft_atoi(op1[i])) % 10 >= 10)
                mas[i][j+1] = ft_itoa((a + (ft_atoi(op2[j]) * ft_atoi(op1[i])) % 10) % 10);
            else
                mas[i][j+1] = ft_itoa(a + (ft_atoi(op2[j]) * ft_atoi(op1[i])) % 10);
            a = (a + (ft_atoi(op2[j]) * ft_atoi(op1[i]))) / 10;
            j--;
        }
        if (op2[0] != '-')
            mas[i][0] = ft_itoa(a);
        else
        {
            mas[i][1] = ft_itoa(a);
            mas[i][0] = '0';
        }
        j = 0;
        while (mas[i][0] == '0')
        {
            j = 0;
            while (mas[i][j] != '\0')
            {
                mas[i][j] = mas[i][j + 1];
                j++;
            }
            mas[i][j] = '\0';
        }
        ft_make_num(mas[i], strlen(op1) - i - 2);
        i--;
    }
    if (op1[0] == '-')
    {
        str = ft_sum(mas[1], mas[2]);
        i = 3;
    }
    else
    {
        str = ft_sum(mas[0], mas[1]);
        i = 2;
    }
    while(i < strlen(op1))
    {
        str = ft_sum(str, mas[i]);
        i++;
    }
    if ((op1[0] != '-' && op2[0] == '-') || (op1[0] == '-' && op2[0] != '-'))
    {
        i = strlen(str);
        str[i + 1] = '\0';
        while (i > 0)
        {
            str[i] = str[i - 1];
            i--;
        }
        str[0] = '-';
    }
    return(str);
}

void main ()
{
    int k;
    char *res;
    for (k=0; k<sizeof(array_)/sizeof(array_[0]); k++)
    {
        printf("%s * %s = %s\n\n", array_[k].op1,array_[k].op2,mul(array_[k].op1,array_[k].op2));
    }
}
