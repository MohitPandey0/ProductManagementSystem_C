#include "Basics/Products.h"

int isExists(int uid)
{
    user temp;int found=0;
    FILE *fptr3=fopen("storage.bin","rb");
    while (fread(&temp, sizeof(user), 1, fptr3))
    {
        if(uid==temp.id)
        {
            found=1;
        }
    }
    fclose(fptr3);
    return found;
}