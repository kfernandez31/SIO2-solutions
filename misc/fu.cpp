#include <bits/stdc++.h>
using namespace std;

struct set {
    int rep;
    int size;
}

const int maxN = ???;
int n;
int components;
set graph[maxN];


int find(int x) {
    if (graph[x].rep != x) {
        graph[x].rep = find(graph[x].rep);
    }
    return graph[x].rep;
}

void join(int x, int y) {
    if (find(graph[x] == find(graph[y]) {
        return;
    }
    if (graph[x].size < graph[y].size) {
        swap(x, y);
    }
    graph[x].size += graph[y].size;
    graph[y].rep = graph[x].rep;
    components--;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    

    return 0;
}
