#include <iostream>
#include <cstdlib>
using namespace std;

char tb[6][7];
char player1 = ' ';
char player2 = ' ';
int row = 0, col = 0, col1 = 0, col2 = 0, times = 1;

void printTable(char tb[6][7]) {
    cout << "-------------\n";
    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 7; b++) {
            cout << "|" << tb[a][b];
        }
        cout << "|" << endl << "---------------\n";
    }
}

bool checkWin(char tb[6][7],char player,int x) {

    // Horizontal checker
    for (int j = 0; j < 6; ++j) {
        for (int i = 3; i < 7; ++i) {
            if (tb[j][i] == tb[j][i - 1] &&
                tb[j][i - 1] == tb[j][i - 2] &&
                tb[j][i - 2] == tb[j][i - 3] &&
                tb[j][i] == player) {
                cout << "Player " << x << " has won!\n";
           exit(0);
            }
        }
    }

    // Vertical checker
    for (int i = 0; i < 7; ++i) {
        for (int j = 3; j < 6; ++j) {
            if (tb[j][i] == tb[j - 1][i] &&
                tb[j - 1][i] == tb[j - 2][i] &&
                tb[j - 2][i] == tb[j - 3][i] &&
                tb[j][i] == player) {
                cout << "Player " << x << " has won!\n";
        exit(0);
            }
        }
    }

    // Diagonal checker
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((tb[j][i] == tb[j + 1][i + 1] &&
                 tb[j + 1][i + 1] == tb[j + 2][i + 2] &&
                 tb[j + 2][i + 2] == tb[j + 3][i + 3] &&
                 tb[j][i] == player) ||
                (tb[j + 3][i] == tb[j + 2][i + 1] &&
                 tb[j + 2][i + 1] == tb[j + 1][i + 2] &&
                 tb[j + 1][i + 2] == tb[j][i + 3] &&
                 tb[j + 3][i] == player)) {
                     cout << "Player " << x << " has won!\n";
   exit(0);
            }
        }
    }

    return true;
}

void colorChoice() {
    cout << "Player 1, choose your color: (R/r for red, Y/y for yellow)\n";
    cin >> player1;
    while (player1 != 'R' && player1 != 'r' && player1 != 'Y' && player1 != 'y') {
        cout << "Invalid option. Try again: ";
        cin >> player1;
    }

    if (player1 == 'R' || player1 == 'r') {
        player1 = 'R';
        player2 = 'Y';
    } else if (player1 == 'Y' || player1 == 'y') {
        player1 = 'Y';
        player2 = 'R';
    }

    cout << "Player 1 has '" << player1 << "' and Player 2 has '" << player2 << "'\n";
}


void PlayRound(char player1, char player2) {
  
    for (int i = 5; i >= 0; i--) {
        cout << "Player 1, choose a column (0-6): ";
        cin >> col1;

        while (col1 < 0 || col1 > 6) {
            cout << "Invalid option. Try again: ";
            cin >> col1;
        }

           for(int j=5 ; j>0 ;j--){
           
            if(tb[j][col1] ==' ' ) 
            {tb[j][col1] = player1;
            break;  
            }
        }
       printTable(tb);
        
        cout << "Player 2, choose a column (0-6): ";
        cin >> col2;

        
        while (col2 < 0 || col2 > 6) {
            cout << "Invalid option. Try again: ";
            cin >> col2;
        }
            for(int j=5 ; j>0 ;j--){
            if(tb[j][col2] ==' ' ) 
            {tb[j][col2] = player2;
            break;  
            }
        }
       printTable(tb);  
      if((checkWin(tb,player1,1)!=true)||(checkWin(tb,player2,2)!=true))exit(0);
        }}

int main() {
    
    cout << "DIMI'S Connect4!\nAlex, you are playing.\n";
//Initiallization of the empty array 
    for (auto i = 0; i < 6; ++i) {
        for (auto j = 0; j < 7; ++j) {
            tb[i][j] = ' ';
        }
    }

    printTable(tb);
    colorChoice();

    while(checkWin(tb,player1,1)==true||checkWin(tb,player2,2)==true)
    PlayRound(player1, player2);

    return 0;}

