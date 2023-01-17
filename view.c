#include "Basics/Products.h"
void read_item()
{
    FILE *fptr2=fopen("storage.bin","rb");
    // FILE *fptr2=fopen("tempstorage.bin","rb");
    user temp;
    printf("the users are :\n");
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
    fclose(fptr2);
}