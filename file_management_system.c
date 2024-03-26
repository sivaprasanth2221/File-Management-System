#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>

int main() {
    system("color 0");
    printf("\n\n");
    printf(" FILE MANAGEMENT SYSTEM\n");

    system("pause");
    //system("cls");

    char option[10];
    system("color 0");

menu:
    printf("\n");
    printf("          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
    printf("          x     FILE  MANAGEMENT SYSTEM     x\n");
    printf("          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
    printf("          x [1] - Save to a file            x\n");
    printf("          x [2] - View file content         x\n");
    printf("          x [3] - Obtain file size          x\n");
    printf("          x [4] - File Details              x\n");
    printf("          x [5] - Clear the file            x\n");
    printf("          x [6] - Delete the file           x\n");
    printf("          x [7] - Exit Program              x\n");
    printf("          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
    printf("\n          Enter Your Choice: ");
    fgets(option, sizeof(option), stdin);
    option[strlen(option) - 1] = '\0';

    if (strcmp(option, "1") == 0) {
        //system("cls");
        system("color 0");
        char textToSave[1000];
        printf("        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
        printf("        w  ENTER THE STRING YOU WANT TO SAVE   x\n");
        printf("        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n");
        printf("        HERE: ");
        fgets(textToSave, sizeof(textToSave), stdin);
        textToSave[strlen(textToSave) - 1] = '\0';
	

        FILE *saveFile = fopen("file.txt", "a+");
        fprintf(saveFile, "%s", textToSave);
        char newLine[5];
	newLine[0] = '\n';
	newLine[1] = '\0';
	fprintf(saveFile, "%s", newLine);
	printf("\n\n\n\n\n\n");
        fclose(saveFile);

        system("pause");
        //system("cls");

        goto menu;
    }

    if (strcmp(option, "2") == 0) {
        system("color 0");
        //system("cls");
        FILE *loadFile = fopen("file.txt", "r");
        printf("        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
        printf("        x     THE FILE CONTAINS THE STRING     x\n");
        printf("        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n");
        printf("        ");
        int c;
        while ((c = getc(loadFile)) != EOF) {
            putchar(c);
        }
        printf("\n\n\n\n\n\n");
        fclose(loadFile);

        system("pause");
        //system("cls");

        goto menu;
    }

    if (strcmp(option, "3") == 0) {

    //system("cls");
    system("color f");
    FILE *fp;
    long begin, end;
    fp = fopen("file.txt", "rb");
    fseek(fp, 0, SEEK_END);
    end = ftell(fp);
    rewind(fp);
    begin = ftell(fp);
    fclose(fp);
    printf("        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
    printf("        x            THE FILE SIZE IS          x\n");
    printf("        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n");
    printf("\n\n\n\t\t\t%ld bytes.\n", end - begin);
    printf("\n\n\n\n");

    system("pause");
    //system("cls");

    goto menu;
    }

    if (strcmp(option, "4") == 0) {
    //system("cls");
    struct stat fileInfo;

    if (stat("file.txt", &fileInfo) != 0) {
        system("color 04");
        printf("\n\n\n\n\n\n\n");
        printf("        wwwwwwwwwwwwwwwwww\n");
        printf("        x      ERROR     x\n");
        printf("        wwwwwwwwwwwwwwwwww\n\n");
        printf("        %s\n", strerror(errno));
        printf("\n\n\n\n\n\n\n");
        return 0;
    }

    system("color 0");
    printf("     wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
    printf("     x  Size               : %ld bytes\n", (long)fileInfo.st_size);
    printf("     x  Drive letter saved : %c\n", (char)(fileInfo.st_dev + 'A'));
    printf("     x  Created            : %s", ctime(&fileInfo.st_ctime));
    printf("     x  Modified           : %s", ctime(&fileInfo.st_mtime));
    printf("     wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
    printf("\n\n\n");
    system("pause");
    //system("cls");
    goto menu;
    }

    if (strcmp(option, "5") == 0) {
    //system("cls");
    system("color 0");
    printf("\n\n\n\n\n\n\n");
    printf(" wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
    printf(" x FILE SUCCESSFULLY CLEARED x\n" );
    printf(" wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n");

    FILE *clearFile;
    clearFile = fopen("file.txt", "w");
    fclose(clearFile);

    printf("\n\n\n\n\n\n\n");
    system("pause");
    //system("cls");

    goto menu;
    }

    if (strcmp(option, "6") == 0) {
        //system("cls");
        system("color 0");
        printf("\n\n\n\n\n\n\n");
        printf("        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
        printf("        x          FILE SUCCESSFULLY DELETED       x\n");
        printf("        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n");
        remove("file.txt");
        printf("\n\n\n\n\n\n\n");
        system("pause");
        //system("cls");

        goto menu;
    }

    if (strcmp(option, "7") == 0 ){
    system("color 0");
    //system("cls");
    printf("\n\n");
    printf("PROGRAM IS CLOSING \n BYE\n");
    system("pause");
    return 0;
} else {
    //system("cls");
    printf("\n\n\n\n\n\n");
    printf("BYE");
    printf("\t\t\tPlease input a valid number.\n");
    printf("\t\t\tPress any key to go back to the Menu.\n\n\n\n\n\n\n");
    system("pause");
    //system("cls");
    goto menu;
}

system("pause");
return 0;

}
