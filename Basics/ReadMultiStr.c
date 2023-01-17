#include<stdio.h>
#include "Products.h"

int main()
{
    FILE *fptr2=fopen("test1.bin","rb");
    user temp;
    while (fread(&temp, sizeof(user), 1, fptr2))
    {
        printf("\n----------------------------\n");
        printf(" id: %d \n", temp.id);
        printf(" name: %s \n", temp.name);
        printf(" city: %s \n", temp.addr.city);
        printf(" state: %s \n", temp.addr.state);
        printf(" pincode: %d \n", temp.addr.pincode);
        printf("\n----------------------------\n");
    }
    return 0;
}
