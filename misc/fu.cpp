#include <bits/stdc++.h>
using namespace std;

struct node {
    int rep;
    int size;
};

const int maxN = 1e6;
int n;
int components;
node graph[maxN];


int find(int x) {
    if (graph[x].rep != x) {
        graph[x].rep = find(graph[x].rep);
    }
    return graph[x].rep;
}

void join(int x, int y) {
    if (find(graph[x]) == find(graph[y])) {
        return;
    }
    if (graph[x].size < graph[y].size) {
        swap(x, y);
    }
    graph[x].size += graph[y].size;
    graph[y].rep = graph[x].rep;
    components--;
}
