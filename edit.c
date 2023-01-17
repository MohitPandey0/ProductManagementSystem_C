#include "Basics/Products.h"

int edit_item()
{

    FILE *fptr = fopen("storage.bin", "rb");
    FILE *fptr2 = fopen("tempstorage.bin", "wb");
    user temp, temp2;
    int uid;
    printf("enter user id to be Edited:");
    scanf("%d%*c", &uid);

    int found=0;
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
            fwrite(&temp, sizeof(user), 1, fptr2);
        }
        else
        {
            printf("\n\t*****  User Record found  *****");
				printf("\nUser Name  \t\t: %s",temp.name);
				printf("\nUser City\t\t: %s",temp.addr.city);
				printf("\nUser State \t\t: %s",temp.addr.state);
				printf("\nUser Pincode \t\t: %d",temp.addr.pincode);

				printf("\n\n\t*** New User Record ***\n");
            printf("enter new id:");
            scanf("%d%*c", &temp2.id);
            printf("enter new name:");
            scanf("%[^\n]%*c", &temp2.name);
            printf("enter new city:");
            scanf("%[^\n]%*c", &temp2.addr.city);
            printf("enter new state:");
            scanf("%[^\n]%*c", &temp2.addr.state);
            printf("enter new pincode:");
            scanf("%d%*c", &temp2.addr.pincode);

            printf("Press 'y' to Edit the existing record or any key to cancel...");
            char Edit;
            scanf("%c", &Edit);
            if (Edit == 'y' || Edit == 'Y')
            {
                fwrite(&temp2, sizeof(user), 1, fptr2);
                printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
            }
        }
    }
    fclose(fptr);
    fclose(fptr2);
    remove("storage.bin");
    rename("tempstorage.bin", "storage.bin");
}