#include <bits/stdc++.h>
using namespace std;

#define UPDATE 0
#define QUERY 1

const int MOD = 1e9 + 7;
const int base = 1 << 17 - 1;

inline int safe_mod(int x) {
    return (x % MOD + MOD) % MOD;
}

int f(int a, int b) {
    return safe_mod(a * b);
}

template <typename T> class PrzedzialPunkt {
private:
    T neutral_element;
    T (*f) (T, T);
    T tree[2 * base];
public:
    PrzedzialPunkt(T neutral_element, T (*f) (T, T)) {
        this->neutral_element = neutral_element;
        this->f = f;
        for (int i = 0; i < 2 * base; i++) {
            tree[i] = neutral_element;
        }
    }
    PrzedzialPunkt(T neutral_element, T (*f) (T, T), T *arr) {
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

    void update(int l, int r, T x) {
        for (
            l += base - 1, r += base + 1;
            r - l > 1;
            l /= 2, r /= 2
        ) {
            if (l % 2 == 0) {
                tree[l + 1] = f(tree[l + 1], x);
            }
            if (r % 2 == 1) {
                tree[r - 1] = f(tree[r - 1], x);
            }
        }
    }

    T query(int v) {
        T res = neutral_element;
        for (v += base; v > 0; v /= 2) {
            res = f(res, tree[v]);
        }
        return res;
    }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    PrzedzialPunkt<int> tree(1, f);

    int q;
    cin >> q;
    while (q--) {
        int type, a, b;
        cin >> type >> a;
        if (type == QUERY) {
            cout << tree.query(a) << "\n";
        } else if (type == UPDATE) {
            int c;
            cin >> b >> c;
            tree.update(a, b, c);
        }
    }

    return 0;
}
