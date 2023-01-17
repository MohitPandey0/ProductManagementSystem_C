#include "Basics/Products.h"
#include "isExists.c"

int deleteproduct()
{
    FILE *fptr=fopen("storage.bin","rb");
    FILE *fptr2=fopen("tempstorage.bin","wb");
    user temp;
    int uid,found=0;
    printf("enter user id to be deleted:");
    scanf("%d",&uid);

    found=isExists(uid);
    
    if(!found)
    {
        printf("Record doesn't exist !! \n");
        printf("returning to main menu");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        fclose(fptr);
        fclose(fptr2);
        remove("tempstorage.bin");
        return 1;
    }
    while (fread(&temp, sizeof(user), 1, fptr))
    {
        if (uid != temp.id)
        {
            fwrite(&temp,sizeof(user),1,fptr2);
        }
    }
    fclose(fptr);
    fclose(fptr2);
    remove("storage.bin");
	rename("tempstorage.bin", "storage.bin");
    printf("record succesfully deleted!!\n");
    Sleep(1000);
}