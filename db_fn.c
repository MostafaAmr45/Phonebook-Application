#include <stdio.h>
#include <stdlib.h>
#include "db_fn.h"

#define MAX 256

FILE * fptr;
char fname[MAX] = "database.txt";
char name[20], phone[11] , email[30] ;

void menu(void)
{
    printf("\n\n");
    printf("What do u wanna do?\n");
    printf("========================\n");
    printf("1.View Database\n");
    printf("2.Add New Element\n");
    printf("3.Search for Element\n");
    printf("4.Edit an Element\n");
    printf("5.Delete Element\n");
    printf("6.Save and Exit\n");
    printf("\nInput your choice[1..6]: ");
}

void add_element(void)
{
    fptr = fopen(fname, "a");

    if (!fptr)
    {
        printf(" File not found or unable to open the input file!!\n");
        return;
    }

    /* Input contents from user to store in file */
    printf("Name : ");
    scanf("%s", name);
    printf("Phone : ");
    scanf("%s", phone);
    printf("Email : ");
    scanf("%s", email);

    /* Write data to file */
    fprintf(fptr, "%s | %s | %s \n", name, phone, email);

    fclose(fptr);

}

void display_db(void)
{
    char c;
    fptr = fopen(fname, "r");

    if (!fptr)
    {
        printf(" File not found or unable to open the input file!!\n");
        return;
    }

    printf("\n ################ DATABASE ################ \n");
    while ((c = getc(fptr)) != EOF) printf("%c", c);

    fclose(fptr);
}

void delete_element(void)
{
    int lno, ctr = 0;
    char ch;
    FILE *fptr2;
    char str[MAX], temp[] = "temp.txt";
    printf("\n\n Delete a specific record from a file :\n");
    printf("-----------------------------------------\n");

    fptr = fopen(fname, "r");
    if (!fptr)
    {
        printf(" File not found or unable to open the input file!!\n");
        return;
    }

    fptr2 = fopen(temp, "w"); // open the temporary file in write mode
    if (!fptr2)
    {
        printf("Unable to open a temporary file to write!!\n");
        fclose(fptr);
        return;
    }
    printf(" Input the line number of the record you want to remove : ");
    scanf("%d", &lno);
    // copy all contents to the temporary file except the specific line
    while (!feof(fptr))
    {
        strcpy(str, "\0");
        fgets(str, MAX, fptr);
        if (!feof(fptr))
        {
            ctr++;
            /* skip the line at given line number */
            if (ctr != lno)
            {
                fprintf(fptr2, "%s", str);
            }
        }
    }
    fclose(fptr);
    fclose(fptr2);
    remove(fname);  		// remove the original file
    rename(temp, fname); 	// rename the temporary file to original name

/*------ Read the file ----------------*/
    fptr=fopen(fname,"r");
    ch=fgetc(fptr);
    printf(" Now the content of the file %s is : \n",fname);
    while(ch!=EOF)
    {
        printf("%c",ch);
         ch=fgetc(fptr);
    }
    fclose(fptr);
/*------- End of reading ---------------*/
}

void print_element(void)
{
    int lno, ctr = 1;
    char str[MAX];
    fptr = fopen(fname, "r");

    printf("\n\n Input the line number of the record you want to display : ");
    scanf("%d", &lno);

    if ( fptr != NULL )
    {
        while (fgets(str, sizeof str, fptr) != NULL) /* read a line */
        {
            if (ctr == lno)
            {

            printf("\n %s ", str);
            fclose(fptr);
            return;

            }
            else
            {
                ctr++;
            }
        }
        fclose(fptr);
    }

}

void search_in_File(void)
{
    int line_num = 1;
    int find_result = 0;
    char temp[40];
    char str[MAX];

    fptr = fopen(fname, "r");

    if(fptr == NULL) {
        printf(" File not found or unable to open the input file!!\n");
        return;
    }

    printf("\n\n Input the name/phone number u want to search for : ");
    scanf("%s", str);

    while(fgets(temp, 40, fptr) != NULL) {
        if((strstr(temp, str)) != NULL) {
            printf("\nA match found on line: %d\n", line_num);
            printf("\n%s\n", temp);
            find_result++;
        }
        line_num++;
    }

    if(find_result == 0) {
        printf("\nSorry, couldn't find a match.\n");
    }

    fclose(fptr);

}

void edit_element(void)
{
    int lno, ctr = 0;
    char ch;
    FILE *fptr2;
    char str[MAX], temp[] = "temp.txt";
    printf("\n\n Delete a specific record from a file :\n");
    printf("-----------------------------------------\n");

    fptr = fopen(fname, "r");
    if (!fptr)
    {
        printf(" File not found or unable to open the input file!!\n");
        return;
    }

    fptr2 = fopen(temp, "w"); // open the temporary file in write mode
    if (!fptr2)
    {
        printf("Unable to open a temporary file to write!!\n");
        fclose(fptr);
        return;
    }
    printf(" Input the line number of the record you want to edit : ");
    scanf("%d", &lno);
    // copy all contents to the temporary file except the specific line
    while (!feof(fptr))
    {
        strcpy(str, "\0");
        fgets(str, MAX, fptr);
        if (!feof(fptr))
        {
            ctr++;
            if (ctr != lno)
            {
                fprintf(fptr2, "%s", str);
            }
            /* edit the given line */
            else
            {
                /* Input contents from user to store in file */
                printf("Name : ");
                scanf("%s", name);
                printf("Phone : ");
                scanf("%s", phone);
                printf("Email : ");
                scanf("%s", email);

                /* Write data to file */
                fprintf(fptr2, "%s | %s | %s \n", name, phone, email);
            }
        }
    }
    fclose(fptr);
    fclose(fptr2);
    remove(fname);  		// remove the original file
    rename(temp, fname); 	// rename the temporary file to original name

/*------ Read the file ----------------*/
    fptr=fopen(fname,"r");
    ch=fgetc(fptr);
    printf("\n Now the content of the file %s is : \n",fname);
    while(ch!=EOF)
    {
        printf("%c",ch);
         ch=fgetc(fptr);
    }
    fclose(fptr);
/*------- End of reading ---------------*/
}

