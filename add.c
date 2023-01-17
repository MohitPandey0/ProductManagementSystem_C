#include "Basics/Products.h"
int add_item()
{
    user u1;
    printf("enter id:\n");
    scanf("%d%*c",&u1.id);
    printf("enter name:\n");
    scanf("%[^\n]%*c",&u1.name);
    printf("enter city:\n");
    scanf("%[^\n]%*c",&u1.addr.city);
    printf("enter state:\n");
    scanf("%[^\n]%*c",&u1.addr.state);
    printf("enter pincode:\n");
    scanf("%d",&u1.addr.pincode);

    FILE *fptr;
    fptr=fopen("storage.bin","ab");

    // user u2={100,"Aman",{"noida","up",110096}};
    // user u3={101,"Aman Tiwari",{"delhi ncr","delhi",110097}};

    fwrite(&u1,sizeof(user),1,fptr);
    // fwrite(&u2,sizeof(user),1,fptr);
    // fwrite(&u3,sizeof(user),1,fptr);
    fclose(fptr);

    return 1;
}