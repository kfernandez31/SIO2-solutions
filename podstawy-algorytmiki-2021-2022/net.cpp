#include <bits/stdc++.h>
using namespace std;

template <typename T> class Graph {
private:
    struct node {
        T rep;
        int size;
    };
    map<T, node> nodes;
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

Graph<string> g;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        string command, a, b;
        cin >> command >> a >> b;
        if (command == "connect") {
            if (!g.contains(a)) {
                g.insert(a);
            }
            if (!g.contains(b)) {
                g.insert(b);
            }
            g.join(a, b);
        } else /*if (command == "sending")*/ {
            if (!g.contains(a) || !g.contains(b)) {
                cout << "Nie\n";
            } else {
                cout << (g.find(a) == g.find(b)? "Tak" : "Nie") << "\n";
            }
        }
    }

    return 0;
}
