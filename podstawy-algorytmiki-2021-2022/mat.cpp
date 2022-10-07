#include <bits/stdc++.h>
using namespace std;

const int maxK = 5 * 1e5;
const int maxN = 5 * 1e5;
const int maxM = 1e6;

template <typename T> class graph {
private:
    struct node {
        T rep;
        int size;
    };
    T nodes[maxKN];
public:
    bool contains(T x) {
        return nodes.contains(x);
    }

    void insert(T x) {
        nodes[x] = { x, 1 };
    }

    T find(T x) {
        if (nodes[x].rep != x) {
            nodes[x].rep = find(nodes[x].rep);
        }
        return nodes[x].rep;
    }

    void join(T x, T y) {
        if (find(x) == find(y)) {
            return;
        }
        if (nodes[x].size < nodes[y].size) {
            swap(x, y);
        }
        nodes[x].size += nodes[y].size;
        nodes[y].rep = nodes[x].rep;
    }
};

graph<int> g;
int n, m, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    while (k--) {
        cin >> a >> b >> t;
    }
// a, b - wierzcholki, t - czas zanikniecia krawedzi
// k - wybrane wierzcholki, do ktorych ma miec dostep Neo

[...] [,,,] [ooo]
0. posortuj czasy
1. wez maksymalny czas - graf jest wtedy bez krawedzi
2. iteruj sie po czasach od najwiekszych do najmniejszych, dodawaj krawędzie przypisane do tych czasów
3. pod koniec lub kiedykolwiek brak dojscia do kazdej budki? -1
4. zawsze dojscie do kazdej budki? KEEP CALM

    while (m--) {
        cin >> a >> b >> t;
    }

    return 0;
}
