#include <iostream>
using namespace std;

class setUnion {
    public:
        int* parentTree;
        int* setSize;
        int nVertices;

        setUnion(int n) {
            parentTree = new int[n];
            setSize = new int[n];
            nVertices = n;

            for (int i = 0; i < n; i++) {
                parentTree[i] = i;
                setSize[i] = 1;
            }
        }
};

int find(setUnion* s, int x) {
    if (s->parentTree[x] != x) {
        find(s, s->parentTree[x]);
    }
    return x;
}


void unionSets(setUnion* s, int s1, int s2) {
    int r1 = find(s,s1);
    int r2 = find(s,s2);

    if (r1 == r2) return;

    if (s->setSize[r1] < s->setSize[r2]) {
        s->setSize[r1] += s->setSize[r2];
        s->parentTree[r1] = r2;
    } else {
        s->setSize[r2] += s->setSize[r1];
        s->parentTree[r2] = r1;
    }

}


bool isSameComponent(setUnion* s, int s1, int s2) {
    return (find(s,s1) == find(s,s2));
}


int main() {
    setUnion* s = new setUnion(10);

    unionSets(s,9,8);
    unionSets(s,6,7);

    unionSets(s,2,3);

    unionSets(s,6,2);


    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << s->parentTree[i] << endl;
    }


    return 0;
}