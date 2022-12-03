#include <iostream>
#include <cstring>
using namespace std;

struct Cell {
    int cost;
    int parent;
};

const int MAXLEN = 10;

int MATCH = 0;
int INSERT = 1;
int DELETE = 2;

int indel() { return 1; }

int match(char s, char t) { 
    if (s == t) { return 0; }
    else { return 1; }
}

void goalCell(char *s, char *t, int *i, int *j)
{
    *i = strlen(s) - 1;
    *j = strlen(t) - 1;
}

void rowInit(Cell cells[MAXLEN+1][MAXLEN+1], int i)
{
    cells[0][i].cost = i;

    if (i>0) {
        cells[0][i].parent = INSERT;
    } else {
        cells[0][i].parent = -1;
    }

}

void columnInit(Cell cells[MAXLEN+1][MAXLEN+1], int i)
{
    cells[i][0].cost = i;

    if (i>0) {
        cells[i][0].parent = DELETE;
    } else {
        cells[i][0].parent = -1;
    }
}

int stringCompare(Cell cells[MAXLEN+1][MAXLEN+1], char* s, char* t) {
    int i, j, k;
    int opt[3];

    for (int i = 0; i <= MAXLEN; i++) {
        rowInit(cells,i);
        columnInit(cells,i);
    }

    for (i = 1; i < strlen(s); i++) {
        for (j = 1; j < strlen(t); j++) {

            opt[MATCH] =  cells[i-1][j-1].cost + match(s[i],t[j]);
            opt[INSERT] = cells[i][j-1].cost + indel();
            opt[DELETE] = cells[i-1][j].cost + indel();

            cells[i][j].cost = opt[MATCH];
            cells[i][j].parent = MATCH; 

            for (int k = INSERT; k <= DELETE; k++) {
                if (opt[k] < cells[i][j].cost) {
                    cells[i][j].cost = opt[k];
                    cells[i][j].parent = k; 
                }
            }
        }
    }

    goalCell(s,t,&i,&j);
    return cells[i][j].cost;
}

int main() {

    Cell table[MAXLEN+1][MAXLEN+1];

    char search[4] = "ll";
    char text[13] = "hello there!";

    cout << stringCompare(table, search, text) << endl;

    return 0;
}