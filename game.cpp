#include<iostream>
using namespace std;
#define CPU '#'
#define PLAYER 'O'
#define WIN_SCORE 10
#define LOOSE_SCORE -10
#define MAX_PLAYER CPU      
#define MIN_PLAYER PLAYER

char* getBoard();
void showBorad(char* board);
bool move(char* board, char player, int location);
bool checkWin(char* board);
bool moves_left(char* board);
int find_best_move(char* board);
int min_max(char* board, int depth, bool isMaximizingPlayer);

int main() {
    char* board = getBoard();
    int n;
    int move_num = 1;
    char player;
    bool win;
    do {
        // player = (move_num%2 == 0) ? PLAYER : CPU ;
        player = (move_num%2 == 0) ? CPU : PLAYER ;
        if (player == CPU) {
            int move = find_best_move(board);
            board[move] = player;
        } else {
            showBorad(board);
            cout<<"Enter your move: ";cin>>n;
            if (!move(board, player, n-1)) {
                cout<<"Cannot move there"<<endl;
                continue;
            }
        }

        win = checkWin(board);
        if (win)    break;
        
        move_num++;
    } while (!win && move_num<10);
    showBorad(board);
    if (win)    cout<<player<<" wins"<<endl;
    else        cout<<"match draw"<<endl;
    return 0;
}

char* getBoard() {
    static char board[] = {' ', ' ', ' ',
                           ' ', ' ', ' ',
                           ' ', ' ', ' '};
    return board;
}

void showBorad(char* board) {
    for (int i=0; i<9; i++) {
        cout<<*(board+i);
        if ((i+1)%3 == 0 && i != 8) {
            cout<<endl;
            cout<<"---------";
            cout<<endl;
        } else if (i!= 8) {
            cout<<" | ";
        }
    }
    cout<<endl<<endl;
}
bool move(char* board, char player, int location) {
    if (board[location] == ' ') {
        board[location] = player;
        return true;
    }
    return false;
}
bool checkWin(char* board) {
    bool win = false;
    if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8])
        win = true;
    else if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6])
        win = true;
    else if (board[0] != ' ' && board[0] == board[1] && board[1] == board[2])
        win = true;
    else if (board[3] != ' ' && board[3] == board[4] && board[4] == board[5])
        win = true;
    else if (board[6] != ' ' && board[6] == board[7] && board[7] == board[8])
        win = true;
    else if (board[0] != ' ' && board[0] == board[3] && board[3] == board[6])
        win = true;
    else if (board[1] != ' ' && board[1] == board[4] && board[4] == board[7])
        win = true;
    else if (board[2] != ' ' && board[2] == board[5] && board[5] == board[8])
        win = true;
    return win;
}

bool moves_left(char* board) {
    for (int i=0; i<9 ; i++) {
        if (board[i] == ' ')    
            return true;
    }
    return false;
}

int find_best_move(char* board) {
    
    int best_score = -1000;
    int best_move;
    int move_score;
    for (int i=0; i<9 ; i++) {
        if (board[i] == ' ') {
            
            board[i] = MAX_PLAYER;
            
            move_score = min_max(board, 1, false);
            if (best_score <= move_score) {
                best_move = i;
                best_score = move_score;
            }
            board[i] = ' ';
        }
    }
    return best_move;
}

int min_max(char* board, int depth, bool isMaximizingPlayer) {

    int win = checkWin(board);
    if (win && !isMaximizingPlayer) 
        return WIN_SCORE - depth;
    else if (win && isMaximizingPlayer) 
        return LOOSE_SCORE + depth;

    if (!moves_left(board)) 
        return 0;

    if (isMaximizingPlayer) {
        int best_score = -1000;
        for (int i=0; i<9 ; i++) {
            if (board[i] == ' ') {
                board[i] = MAX_PLAYER;
                best_score = max(best_score, min_max(board, depth+1, false));
                board[i] = ' ';
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for (int i=0; i<9 ; i++) {
            if (board[i] == ' ') {
                board[i] = MIN_PLAYER;
                best_score = min(best_score, min_max(board, depth+1, true));
                board[i] = ' ';
            }
        }
        return best_score;
    }
}

