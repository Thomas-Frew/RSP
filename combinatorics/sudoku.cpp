#include <iostream>
using namespace std;

// Little (2x2) sudoku
const int DIMENSION = 5;
const int SQUARES = DIMENSION*DIMENSION;

struct Point {
    int x;
    int y;
};

class Sudoku {
    public:
        bool finished = false;
        int gameboard[DIMENSION][DIMENSION];
        int freeCount = SQUARES + 1;
        int nMoves = 0;
        Point move[SQUARES];

        Sudoku() {
            for (int i = 0; i < DIMENSION; i++) {
                for (int j = 0; j < DIMENSION; j++) {
                    gameboard[i][j] = 0;
                    move[DIMENSION*i+j] = {0,0};
                }
            }
        }
};

void makeMove(Sudoku* s, Point move, int value) {
    s->gameboard[move.x][move.y] = value;
    s->move[s->nMoves] = move;
    s->nMoves++;
}

void printSudoku(Sudoku* s) {
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            cout << s->gameboard[i][j] << " ";
        }
        cout << endl;
    }
}

bool sudokuSolved(Sudoku* s) {
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            if (s->gameboard[i][j] == 0) { return false; }
        }
    }

    return true;
}

Point findNextOpen(Sudoku* s) {
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            if (s->gameboard[i][j] == 0) { 
                return {i,j}; 
            };
        }
    }
}

void findLegality(Sudoku* s, Point targetSquare, bool* isIllegal) {
    int r = targetSquare.x;
    int c = targetSquare.y;

    int cMove = 0;
    while (cMove < DIMENSION) {
        if (s->gameboard[r][cMove] != 0) { 
            isIllegal[s->gameboard[r][cMove]] = true; 
        }
        cMove++;
    }

    int rMove = 0;
    while (rMove < DIMENSION) {
        if (s->gameboard[rMove][c] != 0) { 
            isIllegal[s->gameboard[rMove][c]] = true; 
        }
        rMove++;
    }
}

void generateCandidates(int k, Sudoku* s, int* candidates, int* nCandidates) {

    Point targetSquare = findNextOpen(s);
    s->move[k].x = targetSquare.x;
    s->move[k].y = targetSquare.y;

    bool* isIllegal = new bool[DIMENSION + 1];
    *nCandidates = 0;

    for (int i = 1; i <= DIMENSION; i++) { isIllegal[i] = false; }

    findLegality(s, targetSquare, isIllegal);

    for (int i = 1; i <= DIMENSION; i++) {
        if (isIllegal[i] == false) {
            candidates[*nCandidates] = i;
            *nCandidates = *nCandidates + 1;
        }
    }
    
    delete[] isIllegal;
}

void backtrack(Sudoku* s, int k) {
    if (sudokuSolved(s)) {
        s->finished = true;
        printSudoku(s);
        return;
    } else {
        k = k + 1;

        int* nCandidates = new int;
        int* candidates = new int[DIMENSION + 1];

        generateCandidates(k, s, candidates, nCandidates);

        for (int i = 0; i < *nCandidates; i++) {
            makeMove(s,{s->move[k].x, s->move[k].y},candidates[i]);
            backtrack(s,k);

            if (s->finished) return;
        }

        delete nCandidates;
        delete[] candidates;
    }
}

int main() {
    Sudoku* s = new Sudoku();

    makeMove(s,{0,1},4);
    makeMove(s,{1,3},1);
    makeMove(s,{3,0},2);
    makeMove(s,{3,2},3);
    
    printSudoku(s);
    cout << endl;
    
    backtrack(s,-1);


    return 0;
}