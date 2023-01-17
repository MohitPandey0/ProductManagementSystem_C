#include "add.c"
#include "delete.c"
#include "view.c"
#include "edit.c"

int main()
{
    int choice;
    char ch;

    do
    {
        system("cls");
        printf("\n======== Welcome to Products Management System =========");
        printf("                                                                                           ");
        system("color 02");
        printf("\n\t\tEnter 1: Add Products");
        printf("\n\t\tEnter 2: Delete Products");
        printf("\n\t\tEnter 3: View Products");
        printf("\n\t\tEnter 4: Edit Products");
        printf("\n\t\tEnter 5: Exit!");

        printf("\n\n\t\tEnter your choice[1-5]:");
        scanf("%d%*c", &choice);

        system("cls");

        switch (choice)
        {
            case 1:
                add_item();
                break;
            case 2:
                deleteproduct();
                break;

            case 3:
                read_item();
                break;
            case 4:
                edit_item();
                break;
            case 5:
                printf("System Exit");
                exit(0);
                break;
            default:printf("Invalid input !!\n");
                break;
        }
            printf("Press Enter to Continue!!");
        scanf("%c", &ch);
    } while (ch == '\n');

    return 0;
}
