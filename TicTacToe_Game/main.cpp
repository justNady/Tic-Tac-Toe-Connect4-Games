// Libraries
#include <bits/stdc++.h>
using namespace std;

void draw(char arr[4][4]){
    cout << "   1   2   3   4  \n";
    for(int i = 0; i < 4;i++)
    {
        cout << i+1 << ' ';
        for(int j = 0; j < 4; j++) {
            cout << ' ' << arr[i][j] ;
            if (j != 3) cout << " |";
        }
        cout<<endl;
    }
}


void if_not_int(){
        cin.clear();
        cin.ignore(100, '\n');
}

int main(){

    string k;

    char arr[4][4] = {0} ;

    do {

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr[i][j] = '.' ;
        }
    }

    bool win = 0;
    system("cls");
    cout << "Which player want to start ? \n";
    cout << "( X ) or ( O ) \n";
    string cc;
    cin >> cc;
    while ( cc.size() > 1 || (cc[0] != 'X' && cc[0] != 'O' && cc[0] != 'x' && cc[0] != 'o') ) {
        cout << "the character been entered isn't valid, please choose between ( X ) or ( O ) \n";
        cin >> cc;
    }

    bool ch;
    ch = (cc[0] == 'X' || cc[0] == 'x');

    bool player = 1;

    for (int i = 0; i < 16 ; ++i) {

        int row , col;

        system("cls");
        draw(arr);
        cout << "Player " << ( player ? 1 : 2 ) << " Enter the Row & Column for your next move \n";

        cin >> row >> col ;
        if_not_int();

        while( row < 1 || row > 4 || col < 1 || col > 4 ){
            cout << "Out of bounds! , try another one :\n";

            cin >> row >> col ;
            if_not_int();

        }

        while( arr[row-1][col-1] != '.' ){
            cout << "It's an occupied position! try another one :\n";

            cin >> row >> col ;
            if_not_int();

        }

        if ( ch ) {
            arr[row - 1][col - 1] = 'X';
        } else {
            arr[row - 1][col - 1] = 'O';
        }

        system("cls");
        draw(arr);

        char c ;

        if( ch ) c = 'X';
        else c = 'O';

        bool a = 1 , b = 1 , z = 1 , d = 1;

        for (int j = 0; j < 4; ++j) {
            if( arr[j][col - 1] != c ) a = 0;
            if( arr[row - 1][j] != c ) b = 0;
        }

        for (int j = 0; j < 4; ++j) {
            if( arr[j][j] != c ) z = 0;
        }

        for (int j = 0 , k = 3 ; j < 4 , k >= 0 ; ++j , k-- ) {
            if( arr[j][k] != c ) d = 0;
        }

        if( a || b || z || d ){
            player ? (cout << "Player 1 Wins \n") : (cout << "Player 2 Wins \n")  ;
            win = 1;
            break ;
        }

        ch = !ch;
        player = !player;

    }
        if(!win) cout << "Draw\n";

        cout << "Wanna Play again ?\n";
        cout << "Enter 'Y' or 'N'\n";
        cin >> k ;
        while( k.size() > 1 || k != "Y" && k != "y" && k != "N" && k != "n" ){
            cout << "Invalid input , pls try again: \n";
            cin >> k;
        }
    }while( k == "Y" || k == "y" );
    cout << "\nGame Over!\n";    

    system("pause");
    
    return 0;
}