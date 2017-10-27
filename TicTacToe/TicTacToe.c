//===========================================================
//   Catherine Etter
//   Tic - Tac - Toe
//===========================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COLS 3
#define ROWS 3

int main()
{
    void GameDriver();
    printf("======================\n");
    printf("Welcome to Tic-Tac-Toe\nBy: Catherine Etter\n");
    printf("======================\n\n");
    GameDriver();
    
    system("PAUSE");
    return 0;
}
void GameDriver()
{
    void setBoard(char board[ROWS][COLS]);
    void printBoard(char board[ROWS][COLS]);
    int checkWinner(char board[ROWS][COLS]);
    void changeBoard(char board[ROWS][COLS],int rowChange,int colChange,char c);
    char board[ROWS][COLS];
    char c='X';
    char playAgain;
    int rowChange,colChange;
       
    setBoard(board);
    
    while(checkWinner(board)==0) //0=None 1=X wins 2=O wins 3=tie
    {
        printf("\nIt is %c's turn.\n",c); //Player x is always first
        printBoard(board);
        
        printf("Enter Row and Column, separate using a space: "); scanf("%d%d",&rowChange,&colChange);
        rowChange--;
        colChange--;
        changeBoard(board,rowChange,colChange,c);    
        c=='X'? c='O' : printf("",c='X');
    }
    printf("\n");
    switch(checkWinner(board))
    {
        case 1:
            printf("X wins!\n");
            break;
        case 2:
            printf("O wins!\n");
            break;
        case 3:
            printf("It's a tie!\n");
            break;
        default:
            break;
    }
    printBoard(board);
    printf("Play again? (Y/N):"); scanf(" %c",&playAgain);
    
    if(playAgain=='Y')
    {
        GameDriver();
    }
    return;
}
void setBoard(char board[ROWS][COLS])
{
    int r;
    printf("Setting up board...\n");
    for(r=0;r<ROWS;r++)
    {
        int c;
        for(c=0;c<COLS;c++)
        {
            board[r][c]=' ';
        }
    }
    return;
}
void printBoard(char board[ROWS][COLS])
{
    int r;
    printf("   1 2 3\n");
    for(r=0;r<ROWS;r++)
    {
        int c;
        printf(" %d",r+1);
        for(c=0;c<COLS;c++)
        {
            printf("|");
            printf("%c",board[r][c],r,c);
        }
        printf("|\n");
    }
    return;
}
void changeBoard(char board[ROWS][COLS],int rowChange,int colChange,char c)
{
    board[rowChange][colChange]==' '? board[rowChange][colChange]=c : printf("That cell is already taken!\n");
}
int checkWinner(char board[ROWS][COLS])
{  
    int r,c;
    int spaceCount=0;

    for(r=0;r<ROWS;r++) //Checks each row for matching characters
    {
        if((board[r][0]!=' ')&&(board[r][0]==board[r][1])&&(board[r][0]==board[r][2]))
        {
            return(board[r][0]=='X' ? 1 : 2);
        }
    }
    for(c=0;c<COLS;c++) //Checks each column for matching characters
    {
        if((board[0][c]!=' ')&&(board[0][c]==board[1][c])&&(board[0][c]==board[2][c]))
        {
            return(board[0][c]=='X' ? 1 : 2);
        }
    }
    //The folowing if statements check if the diagonals are equal
    if((board[0][0]!=' ')&&(board[0][0]==board[1][1])&&(board[0][0]==board[2][2]))
    {
        return(board[0][0]=='X' ? 1 : 2);
    }
    if((board[0][2]!=' ')&&(board[0][2]==board[1][1])&&(board[0][2]==board[2][0]))
    {
        return(board[0][2]=='X' ? 1 : 2);
    }
    for(r=0;r<ROWS;r++) //Checks if board has been filled up.
    {
        int c;
        for(c=0;c<COLS;c++)
        {
            if(board[r][c]==' ')
            {
                spaceCount++;
            }
        }
    }
    if(spaceCount==0)
    {
        return 3;
    }
    return 0;
}
