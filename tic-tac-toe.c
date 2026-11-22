#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gameboard();
char board[]={'0','1','2','3','4','5','6','7','8','9'};
int wincon();

void main()
{
printf("==TIC TAC TOE GAME==\n\n");
int x;
printf("1: PLAYER VS COMPUTER\n2: PLAYER VS PLAYER\n\n");
printf("Enter your choice :");
scanf("%d",&x);
printf("\n\n");
switch(x)
{
case 1:
{
int player=1,input,status=0,cpu=2;
char sign_1, sign_2;
srand(time(NULL));

char player1[20];   
printf("Enter first player name :");
scanf("%s",&player1);
printf("\n\n");
gameboard();
printf("\n\n\n");

int s;
printf("PRESS 1 TO ASSIGN PLAYER 1 AS 'X' AND PLAYER 2 AS 'O'\n");
printf("PRESS 2 TO ASSIGN PLAYER 1 AS 'O' AND PLAYER 2 AS 'X'\n");
printf("ENTER YOUR CHOICE :");
scanf("%d",&s);
printf("\n\n");

if(s==1)
{
sign_1='X';
sign_2='O';
}
else
{
sign_1='O';
sign_2='X';
}

while(status==0)
{
if(player%2!=0)
{
player=1;
}
else
{
player=cpu;
}

if(player%2!=0)
{
printf("Your turn player 1, enter the box number where you want to play\n\n");
printf("Enter the box number where you want to play your move :");
scanf("%d",&input);
if( input<=0 || input>9 || board[input]=='X' || board[input]=='O')
{
printf("Invalid Input from player \n\n");
continue;
}
else
{
board[input]=sign_1;
}
}

else
{
printf("Computer is thinking...\n\n");
for(input=1; input<10; input++)
{
input=(rand() % 9 + 1);
if(board[input]!='X' && board[input]!='O')
{
board[input]=sign_2;
break;
}
}
}
gameboard();
player ++;

int result=wincon();
if(result==1)
{
printf("Winner");
break;
}
else if(result==0)
{
printf("It's a Draw");
break;
}
else if(result==2)
{
printf("Computer is the winner");
break;
}
}
break;
}

case 2:
{
int player=1,input, status=0;
char sign_1, sign_2;

char player1[20];
    
printf("Enter first player name :");
scanf("%s",&player1);
    
char player2[20];
    
printf("Enter second player name :");
scanf("%s",&player2);
printf("\n\n\n");

int s;
printf("PRESS 1 TO ASSIGN PLAYER 1 AS 'X' AND PLAYER 2 AS 'O'\n");
printf("PRESS 2 TO ASSIGN PLAYER 1 AS 'O' AND PLAYER 2 AS 'X'\n");
printf("ENTER YOUR CHOICE :");
scanf("%d",&s);
printf("\n\n");

if(s==1)
{
sign_1='X';
sign_2='O';
}
else
{
sign_1='O';
sign_2='X';
}

gameboard();
printf("\n\n");

while(status==0)
{

if(player%2==0)
{
player=2;
}
else
{
player=1;
}
  
printf("Your turn Player %d \n\n",player);
  
printf("Enter the box number where you want to play your move :");
scanf("%d",&input);
printf("\n\n");
if( input<=0 || input>9 || board[input]=='X' || board[input]=='O')
{
printf("Invalid Input from player, please enter a valid input \n\n");
continue;
}
else
{
board[input]='O';
}
gameboard();
player++;

int result=wincon();
if(result==1)
{
printf("Player 1 is the winner");
break;
}
else if(result==0)
{
printf("It's a Draw");
break;
}
else if(result==2)
{
printf("Player 2 is the winner");
}
}
}
return;
}
}

void gameboard()
{
printf("      |        |       \n");
printf("  %c   |   %c    |   %c   \n",board[1],board[2],board[3]);
printf("______|________|_______\n");
printf("      |        |       \n");
printf("  %c   |   %c    |   %c   \n",board[4],board[5],board[6]);
printf("______|________|_______\n");
printf("      |        |       \n");
printf("  %c   |   %c    |   %c   \n",board[7],board[8],board[9]);
printf("      |        |       \n");
    
}

int wincon()
{
int drawcount=0;
//row wincon
if(board[1]==board[2] && board[2]==board[3])
{
return 1;
}
else if(board[4]==board[5] && board[5]==board[6])
{
return 1;
}
else if(board[7]==board[8] && board[8]==board[9])
{
return 1;
}
//column wincon
else if(board[1]==board[4] && board[4]==board[7])
{
return 1;
}
else if(board[2]==board[5] && board[5]==board[8])
{
return 1;
}
else if(board[3]==board[6] && board[6]==board[9])
{
return 1;
}
//diagonal wincon
else if(board[1]==board[5] && board[5]==board[9])
{
return 1;
}
else if(board[3]==board[5] && board[5]==board[7])
{
return 1;
}
//checking for draw
 for(int input=1; input<10; input++)
 {
 if(board[input]=='X' || board[input]=='O')
 {
 drawcount++;
 }
 }
 if(drawcount==9)
 {
 return 0;
 }
}
