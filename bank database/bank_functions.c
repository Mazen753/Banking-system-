#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
typedef struct Customer
{
    char name[30];
    double cash;
    char type[7];
    int id;
}Customer;
Customer customer[SIZE];
int counter=0;//to count the number of customers
char*ptr_type1="debit";//to compare with the input
char*ptr_type2="credit";//to compare with the input

void add_new_customer(void)
{
    if(counter<SIZE)
    {

        printf("enter the name of the customer%d\n",counter+1);
        fflush(stdin);
        gets(customer[counter].name);
        printf("enter the cash of the customer%d\n",counter+1);
        scanf("%lf",&customer[counter].cash);
        //to check that the cash is positive number
        while(customer[counter].cash<0)
        {
            printf("please enter positive number\n");
            printf("enter the cash of the customer%d\n",counter+1);
            scanf("%lf",&customer[counter].cash);
        }
        printf("enter the type of the customer%d is (debit or credit)\n",counter+1);
        fflush(stdin);
        gets(customer[counter].type);
        //to check is the input only debit or credit
        while(strcmp(ptr_type1,customer[counter].type) && strcmp(ptr_type2,customer[counter].type))
        {
            printf("please enter only debit or credit\n");
            fflush(stdin);
            gets(customer[counter].type);
        }
        printf("enter the id number of the customer%d\n",counter+1);
        scanf("%d",&customer[counter].id);
        //to check that the id can not be repeated
        while(customer[counter].id==customer[counter-1].id)
        {
            printf("please don't repeat the id number\nenter the id number\n");
            scanf("%d",&customer[counter].id);
        }


        counter++;
    }
    else
    {
       printf("\nwe reached max number of customers\n\n");
    }
}


void view_customer_information(void)
{
    int id,i;
    printf("what is the id of the customer\n");
    scanf("%d",&id);
    for(i=0;i<SIZE;i++)
    {
        if(customer[i].id==id)
        {
            printf("the name of the customer is %s\n",customer[i].name);
            printf("the cash of the customer is %.2f\n",customer[i].cash);
            printf("the type of the customer is %s\n",customer[i].type);
            printf("the id of the customer is %d\n\n",customer[i].id);
            break;
        }
    }
}

void edit_customer_information(void)
{
    int id,i,j;
    printf("what is the id of the customer\n");
    scanf("%d",&id);
    for(i=0;i<SIZE;i++)
    {
        if(customer[i].id==id)
        {
            printf("enter the new name of the customer\n");
            fflush(stdin);
            gets(customer[i].name);
            printf("enter the new cash of the customer\n");
            scanf("%lf",&customer[i].cash);
            printf("enter the new type of the customer\n");
            fflush(stdin);
            gets(customer[i].type);
            //to check that the input is only debit or credit
            while(strcmp(ptr_type1,customer[i].type) && strcmp(ptr_type2,customer[i].type))
            {
                printf("please enter only debit or credit\n");
                fflush(stdin);
                gets(customer[i].type);
            }
            printf("enter the new id\n");
            scanf("%d",&customer[i].id);
            //to check that there is no id equal to the new one
            for(j=0;j<SIZE;j++)
            {
                if(i==j)
                {
                    j++;
                }
                if(customer[j].id==customer[i].id)
                {
                    printf("please don't repeat the id number\n");
                    printf("enter the new id\n");
                    scanf("%d",&customer[i].id);
                    j=0;
                }
            }

            break;
        }
    }
}

void cash_transfer(void)
{
    int id1,id2,i;
    double money;
    char flag1=0,flag2=0;
    Customer *ptr1,*ptr2;
    printf("enter the id of the customer who will transfer from\n");
    scanf ("%d",&id1);
    //to check if the id existed or not
    while(flag1==0)
    {
        for(i=0;i<SIZE;i++)
        {
            if(id1==customer[i].id)
            {
                flag1=1;
                ptr1=customer+i;
                break;
            }
        }
        if(flag1==1)
        {
            break;
        }
        printf("that id is not valid please enter existed id\n");
        printf("enter the id of the customer who will transfer from\n");
        scanf ("%d",&id1);
    }
    printf("enter the id of the customer who will transfer to\n");
    scanf ("%d",&id2);
    //to check if the id existed or not
    while(flag2==0)
    {
        for(i=0;i<SIZE;i++)
        {
            if(id2==customer[i].id)
            {
                flag2=1;
                ptr2=customer+i;
                break;
            }
        }
        if(flag2==1)
        {
            break;
        }
        printf("that id is not please enter existed id\n");
        printf("enter the id of the customer who will transfer from\n");
        scanf ("%d",&id2);
    }
    printf("enter the amount of money will be transfered\n");
    scanf ("%lf",&money);
    while(money>(ptr1->cash))
    {
        printf("that cash is greater than the cash of the customer enter valid cash\n");
        printf("enter the amount of money will be transfered\n");
        scanf ("%lf",&money);
    }
    ptr1->cash-=money;
    ptr2->cash+=money;
}

void delete_customer(void)
{
    int id,i,flag=0,pos;
    printf("enter the id of the customer you want to delete\n");
    scanf("%d",&id);
    //to check if the id existed or not
    while(flag==0)
    {
        for(i=0;i<SIZE;i++)
        {
            if(id==customer[i].id)
            {
                flag=1;
                pos=i;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
        printf("that id is not valid please enter existed id\n");
        printf("enter the id of the customer who will transfer from\n");
        scanf ("%d",&id);
    }
    //to delete and shift the customer
    for(i=pos;i<SIZE-1;i++)
    {
        customer[i]=customer[i+1];
    }
    counter--;
}
