#include<stdio.h>
#include<process.h>
#define que_size 3
void enque(int que[],int *front,int *rear,int ele)
{
    if(*rear==que_size-1)
    {
        printf("\n que overflow");
    }
    else
    {
        que[++(*rear)]=ele;
    }
}
int deque(int que[],int *front,int *rear)
{
    int del_ele;
    if((*front)>*rear)
    {
        printf("\nstack underflow");
    }
    else
    {
        del_ele=que[(*front)++];
    }
    return del_ele;
}
void display(int que[],int *front,int *rear)
{
    if(*front>*rear)
    {
        printf("\nstack is empty");
    }
    else
    {
        for(int i=*front;i<*rear+1;i++)
        {
            printf("\n element is %d",que[i]);
        }
    }
}
void main()
{
    int que[que_size],front=0,rear=-1,ele,ch,del_ele;
    do
    {
        printf("\n enter 1 for enque\n enter 2 for deque\n enter 3 for display\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                printf("\nenter the element to add:");
                scanf("%d",&ele);
                enque(que,&front,&rear,ele);
                printf("\nelement added to %d position",rear);
                break;
            }
        case 2:
            {
                del_ele=deque(que,&front,&rear);
                printf("\ndeleted element is %d at %d position",del_ele,front-1);
                break;
            }
        case 3:
            {
                display(que,&front,&rear);
                break;
            }

        default:
            {
                exit(0);
            }
       }
   }while(1);
}

