#include <iostream>
#include <stdlib.h>    
 
using namespace std;

char player2=' ' , player1=' ';
char tb[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
int  row=0, col=0, times=1 ,row1=0,row2=0,col1=0,col2=0;

void printTable(char tb[3][3]){
 cout <<"---------------------------\n";
	for(int a = 0; a < 3; a++)
  {
    for(int b = 0; b < 3; b++)
    {
      cout<<"| "<<"\t"<<tb[a][b];
    }
    cout <<" |"<< endl<<"---------------------------\n";
  } 

}

bool checkVictory (char tb[3][3], char player, int x){   
    if((tb[0][0] == player && tb[0][0] == tb[1][0] && tb[1][0] == tb[2][0])
    || (tb[0][1] == player && tb[0][1] == tb[1][1] && tb[1][1] == tb[2][1])
    || (tb[0][2] == player && tb[0][2] == tb[1][2] && tb[1][2] == tb[2][2])
    || (tb[0][0] == player && tb[0][0] == tb[0][1] && tb[0][1] == tb[0][2])
    || (tb[1][0] == player && tb[1][0] == tb[1][1] && tb[1][1] == tb[1][2])
    || (tb[2][0] == player && tb[2][0] == tb[2][1] && tb[2][1] == tb[2][2])
    || (tb[0][0] == player && tb[0][0] == tb[1][1] && tb[1][1] == tb[2][2])
    || (tb[0][2] == player && tb[0][2] == tb[1][1] && tb[1][1] == tb[2][0]))
    {cout << "Player" << x << " has won!\n";
      exit (0);
    }
return true;
}

void SymbolsChoice(){
	cout<<"Player 1 choose your symbol:\n";
	cin>>player1;


	while(player1!= 'X' && player1!='x'&& player1!='O'&&player1 !='o'){ 
		cout<<"Error .Try again";
		cin >> player1;
	}

	if (player1=='X'||player1=='x') 
		player2 = 'O';
	else if(player1 =='O'|| player1 =='o') 
		player2 ='X';

	cout<<"\nPlayer1 has '"<< player1 <<"'  and Player2 has '"<< player2<< "'.\nPlayer 1 give me the dimensions of the cell you choose:\n" ;

}

void CheckCell(int row , int col ,char player){
    cin>>row>>col;
    
    while((tb[row][col] !=' ')||(row<0||row>2||col>2||col<0)){
		cout<<"Try again.This cell is taken or invalid option:\n";
		cin>>row>>col;}
    tb[row][col] = player ;
		
    if((checkVictory(tb,player1,1)!=true)||(checkVictory(tb,player2,2)!=true))
		exit(0);
}

void PlayRound(){
    cout<<"Player 1:\n";
	CheckCell(row1,col1,player1);
	cout<<"Player 2:\n";
    CheckCell(row2,col2,player2);
    printTable(tb);
	times++;
}

void Game(){
    while (times<=5)
    PlayRound();
}
int main(){
    	
	  cout<<"DIMI'S NOUGHTS AND CROSSES\n Alex you are playing.\n";
	  cout<<"Dimensions of the board go like this: \n|00|01|02|\n|10|11|12|\n|20|21|22|\n";
    SymbolsChoice();
    Game();
}