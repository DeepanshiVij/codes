//check if a string is palindrome or not using stacks
#include <stdio.h>
#include <stdlib.h>
#define size 20
void push (char [],int *,char);
char pop (char[],int *);
char ret (char[] , int);
int main()
{
    char str[size],a[size],a1[size],ch,ch1;
    int top1,top2,i,j,flag;
    top1=top2=-1;
    flag=i=0;
    printf("Enter string :");
    gets(str);
    for (i=0;str[i]!='\0';i++)
    {
        ch=ret(str,i);
        push(a,&top1,ch);
    }
    for (j=(i-1);j>=0;j--)
    {
        ch=ret(str,j);
        push(a1,&top2,ch);
    }
    while (top1>=0)
    {
        ch=pop(a,&top1);
        ch1=pop(a1,&top2);
        if (ch!=ch1)
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
        printf("\nString is not palindrome");
    else
        printf("\nString is palindrome");
    return 0;
}
void push (char a[],int *top,char ch)
{
    if (*top==(size-1))
        printf("Overflow");
    else
    {
        *top=*top+1;
        a[*top]=ch;
    }
}
char pop (char a[],int *top)
{
    char ch;
    ch=a[*top];
    *top=*top-1;
    return ch;
}
char ret (char a[],int i)
{
    int j;
    char ch;
    for (j=0;a[j]!='\0';j++)
    {
        if (j==i)
        {
            ch=a[j];
            break;
        }
    }
    return ch;
}
