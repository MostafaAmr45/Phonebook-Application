#include <stdio.h>
#include <stdlib.h>
#include "db_fn.h"

uint8_t main(void)
{
    uint8_t choice = 0;
    do
    {
        do
        {
            menu();
            scanf("%c", &choice);
            fflush(stdin);
        } while ((choice < (uint8_t)1) || (choice > (uint8_t)6));
        switch (choice)
        {
        case (uint8_t)1:
            display_db();
            printf("\n\nPress Enter to continue.....");
            getchar();
            break;
        case (uint8_t)2:
            add_element();
            printf("\n\nPress Enter to continue.....");
            getchar();
            getchar();
            break;
        case (uint8_t)3:
            search_in_File();
            printf("\n\nPress Enter to continue.....");
            getchar();
            getchar();
            break;
        case (uint8_t)4:
            edit_element();
            printf("\n\nPress Enter to continue.....");
            getchar();
            getchar();
            break;
        case (uint8_t)5:
            delete_element();
            printf("\n\nPress Enter to continue.....");
            getchar();
            getchar();
            break;
        default:
            /* choice is not in range */
            break;
        }
    } while (choice != (uint8_t)6);
    return (uint8_t)0;

}
