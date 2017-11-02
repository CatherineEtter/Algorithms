/*
============================================================
=   Catherine Etter
=   C Program for Programming II | Spring 2017
=   This program will:
=    Create and delete linked lists.
============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct languages
{
    char name[60];
    char fileExt[20];
    int releaseDate;
    int sizeIDE;
    struct languages *next;
};
struct languages *start,*ptemp,*current,*add;



void main(void)
{
    void printCollection();
    void getCollection();
    void editCollection(int option,int itemIndex);
    char input[20]; //User's answer
    int itemIndex; //Item to remove
    int counter=0; //Counts number of structures
    
    printf("This program creates a collection of programming languages.\n\n");
    start=NULL;
    while(strncmp("DONE",input,4)!=0 && strncmp("Done",input,4)!=0 && strncmp("done",input,4)!=0) //If DONE,Done, or done isn't entered.
    {
        printf("\nType DONE to stop or press enter to continue: ");
        fgets(input,20,stdin);
        
        if(strncmp("\n",input,1)==0){
            getCollection();
            counter++;
            editCollection(1,counter);
        }
    } 
    printCollection();
    strcpy(input," "); //Clean done from input
    while(strncmp("DONE",input,4)!=0 && strncmp("Done",input,4)!=0 && strncmp("done",input,4)!=0)
    {
        printf(" Enter ADD or DEL: ");
        fgets(input,20,stdin);
        if(strncmp("ADD",input,3)==0||strncmp("Add",input,3)==0||strncmp("add",input,3)==0){ //if add was entered
            printf(" Enter index to place: ");
            fgets(input,20,stdin);
            itemIndex=atoi(input);
            getCollection();
            editCollection(1,itemIndex);
        }
        if(strncmp("DEL",input,3)==0||strncmp("Del",input,3)==0||strncmp("del",input,3)==0){  //if del was entered
            printf(" Enter index to remove: ");
            fgets(input,20,stdin);
            itemIndex=atoi(input);
            editCollection(0,itemIndex);
        }
        printCollection();
    }
    return;
}



void getCollection() //Creates and adds a new item to collection
{
    char langName[60]; //Name of language
    char langFileExt[20]; //File extension
    char dateString[60]; //Release Date
    int dateNum; //Release Date
    int sizeNum; //Size of IDE

    printf(" Enter a language name: ");
    fgets(langName,60,stdin);
    langName[(strlen(langName)-1)]='\0'; //Replace the \n character with \0
    
    printf(" Enter language file Extension: ");
    fgets(langFileExt,60,stdin);
    langFileExt[(strlen(langFileExt)-1)]='\0'; //Replace the \n character with \0
    
    printf(" Enter language's release date: "); //Uses atoi in case non-integer
    fgets(dateString,60,stdin);
    dateNum=atoi(dateString);
    
    printf(" Enter language's IDE size (MB): "); //Uses atoi in case non-integer
    fgets(dateString,60,stdin);
    sizeNum=atoi(dateString);
        
    current=malloc(sizeof(struct languages));
    strcpy(current->name,langName);
    strcpy(current->fileExt,langFileExt);
    current->releaseDate=dateNum;
    current->sizeIDE=sizeNum;
    current->next=NULL;
    add=current; //copy of current structure for adding it to list
    
    return;
}



void printCollection() //Prints the collection
{
    int totalSize=0; //Counts total size in MB
    int counter=1; //Counts num of items
    
    current=start;
    printf("----------------------------------------------------------\n");
    printf("   LANGUAGE:\tFILE EXT:\tRELEASE:\tIDE SIZE:\n");
    while(current!=NULL){
        printf("%d: %-12s %-15s %-13d %5d MB\n",counter,current->name,current->fileExt,current->releaseDate,current->sizeIDE);
        totalSize+=current->sizeIDE;
        current=current->next;
        counter++;
    }
    printf(" Total Size of IDEs: %d MB\n\n",totalSize);
    return;
}



void editCollection(int option, int itemIndex) //Adds or removes from list
{
    int counter; //counts if adding/deleting first item
    current=start;
    ptemp=start;
    for(counter=1;counter<itemIndex;counter++){
        ptemp=current;
        current=current->next;
    }
    if(option==1){  //Adding index
        if(counter==1){ //first item in list
            start=add;
        }
        else{ //add new index above current
            ptemp->next=add;
        }
        add->next=current;
    }
    if(option==0){ //Deleting index
        if(counter==1){ //first item in list
            start=current->next;
        }
        else{ //bypass current
            ptemp->next=current->next;
        }
        current->next=NULL;
    }
    return;
}
/* JetBrains IDE size (MB)
Java - .jar - 1995 - 342 MB
C - .c - 1972 - 224
Ruby - .rb - 1995 - 196
Python - .py - 1991 - 179
C++ - .cpp - 1983 - 224
*/
