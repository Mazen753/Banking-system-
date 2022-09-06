#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank_functions.h"

int main()
{

    int choice;
    while(1)
    {

        printf("please press the number of the option to select it\n\n");
        printf("1-create a new customer\n");
        printf("2-edit customer information\n");
        printf("3-delete customer\n");
        printf("4-view customer information\n");
        printf("5-cash transfer from customer to another\n");
        printf("6-exit\n\n");
        printf("please enter your choice\n");
        fflush(stdin);
        scanf("%d",&choice);
        if(choice==1)
        {
            add_new_customer();
        }
        else if(choice==2)
        {
            edit_customer_information();
        }
        else if(choice==3)
        {
            delete_customer();
        }
        else if(choice==4)
        {
            view_customer_information();
        }
        else if(choice==5)
        {
            cash_transfer();
        }
        else if(choice==6)
        {
            break;
        }
    }
    return 0;
}
