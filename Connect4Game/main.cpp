#include "iostream"
using namespace std;


int position_of_row( char arr[7][7] , int col , bool ch ){
    int row;
    for (int i = 0; i < 7 ; ++i) {
        if( arr[i+1][col] != '.' ){
            row = i ;
            if( ch ){
                arr[i][col] = 'X';
            }else
                arr[i][col] = 'O';
            break;
        }
    }
    return row;
}

bool check_row( char arr[7][7] , int row , char c ){
    int cnt = 0;
    for (int j = 0; j < 7; ++j) {
        if( arr[row][j] == c ) cnt++;
        else {
            if( cnt >= 4 ) return 1;
            else cnt = 0;
        }
    }
    return ( cnt >= 4 );
}

bool check_col( char arr[7][7] , int col , char c ){
    int cnt = 0;
    for (int j = 0; j < 7; ++j) {
        if( arr[j][col] == c ) cnt++;
        else {
            if( cnt >= 4 ) return 1;
            else cnt = 0;
        }
    }
    return ( cnt >= 4 ) ;
}

void draw( char arr[7][7] ){
    cout << "1   2   3   4   5   6   7\n";
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            cout << arr[i][j] ;
            if( j != 6 ) cout << " | ";
        }
        cout << endl;
    }
}

void if_not_int(){
        cin.clear();
        cin.ignore(100, '\n');
}

int main() {

    char arr[7][7];

    string k ;

    do{
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            arr[i][j] = '.';
        }
    }
    bool win = 0;
    system("cls");
    cout << "Which player want to start ? \n";
    cout << "( X ) or ( O ) \n";
    string cc;
    cin >> cc;
    while ( cc.size() > 1 || (cc[0] != 'X' && cc[0] != 'O' && cc[0] != 'x' && cc[0] != 'o') ) {
        cout << "the character been entered isn't valid , please choose between ( X ) or ( O ) \n";
        cin >> cc;
    }

    bool ch;
    ch = (cc[0] == 'X' || cc[0] == 'x');

    bool player = 1;

    // show the grid for the player before any play :
    draw(arr);

    for ( int i = 0; i < 7 * 7 ; ++i ) {

        cout << "Player " << ( player ? 1 : 2 ) << " Enter the Column for your next move \n";
        int col ; cin >> col;
        if_not_int();

        while( col < 1 || col > 7 ){
            cout << "Sorry, it's out of bounds! enter another one : \n";
            cin >> col;
            if_not_int();
        }
    
        while( arr[0][col-1] != '.' ){
            cout << "Sorry, The column is full, enter another one : \n";
            cin >> col;
            if_not_int();
        }

        col--;

        // check the position & set the pos
        int row = position_of_row(arr, col, ch);

        system("cls");
        draw(arr);

        char c = (ch ? 'X' : 'O');

        bool a = 0, b = 0;
        a = check_row(arr, row, c);
        b = check_col(arr, col, c);

        if ( a || b ) {
            player ? (cout << "Player 1 Wins\n") : (cout << "Player 2 Wins\n") ;
            win = 1;
            break;
        }

        int cnt1 = 0, cnt2 = 0 ;
        int tmp_row = row , tmp_col = col;

        bool diagonal = 0;

        // check the principal diagonal
        while( tmp_row > 0 && tmp_row < 6 && tmp_col > 0 && tmp_col < 6 )
        tmp_row++ , tmp_col++;

        for( ; tmp_row >= 0 , tmp_col >= 0 ; tmp_row-- , tmp_col-- ){
            if( arr[tmp_row][tmp_col] == c ) cnt1++;
            else cnt1 = 0;

            if( cnt1 == 4 ) diagonal = 1;
        }

        tmp_row = row , tmp_col = col;

        // check the secondary diagonal
        while( tmp_row > 0 && tmp_row < 6 && tmp_col > 0 && tmp_col < 6  )
        tmp_row++ , tmp_col--;

        for( ; tmp_row >= 0 , tmp_col < 7 ; tmp_row-- , tmp_col++  ){
            if( arr[tmp_row][tmp_col] == c ) cnt2++; 
            else cnt2 = 0;

            if( cnt2 == 4 ) diagonal = 1;
        }

        if( diagonal ){
            player ? (cout << "Player 1 Wins\n") : (cout << "Player 2 Wins\n") ;
            win = 1;
            break;
        }
        
        ch = !ch;
        player = !player;
    }

        if (!win){ cout << "Draw!\n"; }

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