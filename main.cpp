/*Echo Liu
 *Project 1
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include  <ctime>

using namespace std;
const int rows = 5;
const int columes = 5;
string matrix[rows][columes];

//set up the matrix first
void set(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columes; j++){
            matrix[i][j] = " ";
        }
    }
}

//set up the symbol of matrix
void origMatrix(){
    matrix[0][1]="!";
    matrix[0][3]="!";
    matrix[1][0]="~~~~~~~~~~";
    matrix[2][1]="!";
    matrix[2][3]="!";
    matrix[3][0]="~~~~~~~~~~";
    matrix[4][1]="!";
    matrix[4][3]="!";

    for(int i=0; i<rows; i++){
        for(int j=0; j<columes; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int R;
int C;
void shipLocation(){
    srand(int(time(0)));
    R = rand() % 3 + 1;
    C = rand() % 3 + 1;
}



void userLocation(int x, int y) {
    cout << endl << "Please guess a location on the matrix" << endl << "Location (row[1-3] column[1-3]): ";
    int gtime = 1;
    while (gtime>0) {
        cin >> x >> y;
        if (x == R && y == C) {
            matrix[2*(x-1)][2*(y-1)] = "O" ;
            origMatrix();
            cout << "You sunk my battleship!" << " (" << gtime << " guesses)";
            break;
        } else {
            gtime++;
            matrix[2*(x-1)][2*(y-1)] = "X" ;
            origMatrix();
            cout << "Try again: ";
            continue;
        }
    }
}




int main() {
    int userVal;
    set();
    origMatrix();
    shipLocation();
    userLocation(userVal, userVal);



    return 0;
}
