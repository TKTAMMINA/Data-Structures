#include<stdio.h>
#include<ctype.h>
#define stack_size 20
void push(int *top,char stack[],char ele)
{
    stack[++(*top)]=ele;
}
char pop(int *top,char stack[])
{
    return stack[(*top)--];
}
int prece(char a)
{
    if(a=='^')
    {
        return 3;
    }
    else if(a=='*' || a=='/')
    {
        return 2;
    }
    else if(a=='+'|| a=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void intopo(char infix[],char postfix[])
{
    char ele;
    char stack[stack_size];
    int i=0,j=0,top=-1;
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
        }
        else if(infix[i]=='(')
        {
            push(&top,stack,infix[i]);
        }
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                postfix[j]=pop(&top,stack);
                j++;
            }
            ele=pop(&top,stack);
        }
        else
        {
            while(prece(stack[top])>=prece(infix[i]))
            {
                postfix[j]=pop(&top,stack);
                j++;
            }
                push(&top,stack,infix[i]);
        }
         i++;
    }
    while(top!=-1)
    {
        postfix[j]=pop(&top,stack);
        j++;
    }
    postfix[j]='\0';
}
void main()
{
    char infix[20],postfix[20];
    printf("enter the infix expression\n");
    scanf("%s",infix);
    intopo(infix,postfix);
    printf("the postfix expression is: %s\n",postfix);
}
