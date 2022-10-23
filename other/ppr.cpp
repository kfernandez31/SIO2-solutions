#include <bits/stdc++.h>
using namespace std;

#define UPDATE 0
#define QUERY 1

const int MOD = 1e9 + 7;
const int base = 1 << 17 - 1;

int f(int a, int b) {
    return max(a, b);
}

template <typename T> class PunktPrzedzial {
private:
    T neutral_element;
    T (*f) (T, T);
    T tree[2 * base];
public:
    PunktPrzedzial(T neutral_element, T (*f) (T, T)) {
        this->neutral_element = neutral_element;
        this->f = f;
        for (int i = 0; i < 2 * base; i++) {
            tree[i] = neutral_element;
        }
    }
    PunktPrzedzial(T neutral_element, T (*f) (T, T), T *arr) {
        this->neutral_element = neutral_element;
        this->f = f;
        int i = 0;
        for (; i < base; i++) {
            tree[i] = neutral_element;
        }
        for (; i < 2 * base; i++) {
            tree[i] = arr[i - base];
        }
    }

    void update(int v, T x) {
        v += base;
        tree[v] = x;
        for (v /= 2; v > 0; v /= 2) {
            tree[v] = f(tree[2 * v], tree[2 * v + 1]);
        }
    }

    T query(int l, int r) {
        T res = neutral_element;
        for (
            l += base - 1, r += base + 1;
            r - l > 1;
            l /= 2, r /= 2
        ) {
            if (l % 2 == 0) {
                res = f(res, tree[l + 1]);
            }
            if (r % 2 == 1) {
                res = f(res, tree[r - 1]);
            }
        }
        return res;
    }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    PunktPrzedzial<int> tree(1, f);

    int q;
    cin >> q;
    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == QUERY) {
            cout << tree.query(a, b) << "\n";
        } else if (type == UPDATE) {
            tree.update(a, b);
        }
    }

    return 0;
}
