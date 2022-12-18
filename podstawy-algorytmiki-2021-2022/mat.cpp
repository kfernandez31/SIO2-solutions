//TODO
#include <bits/stdc++.h>
using namespace std;

const string FAILURE = "KEEP CALM AND FOLLOW THE WHITE RABBIT";
const int NONE = 0;

const int maxK = 5 * 1e5;
const int maxN = 5 * 1e5;
const int maxM = 1e6;

int rep[maxN + 1];
int set_size[maxN + 1];
bool is_special[maxN + 1];
bool has_special[maxN + 1];
pair<int, pair<int, int>> edges[maxM + 1];
int num_components;
int n, m, k;

int find_set(int v) {
    if (rep[v] == NONE) {
        return NONE;
    }
    if (v == rep[v]) {
        return v;
    }
    return rep[v] = find_set(rep[v]);
}

void union_sets(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x != y) {
        if (set_size[x] < set_size[y]) {
            swap(x, y);
        }
        rep[y] = x;
        set_size[x] += set_size[y];

        num_components -= (has_special[x] && has_special[y]);
        has_special[x] |= has_special[y];
    }
}

void make_set(int v) {
    rep[v] = v;
    set_size[v] = 1;
    has_special[v] = is_special[v];
}

bool all_connected() {
    return num_components == 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    while (k--) {
        int v;
        cin >> v;
        is_special[v] = true;
    }

    num_components = k;
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    for (int i = 1; i <= m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        edges[i] = {t, {a, b}};
    }

    sort(edges + 1, edges + m + 1);

    int i = m;
    while (i >= 1) {
        int cur_t = edges[i].first;

        while (edges[i].first == cur_t) {
            auto [a, b] = edges[i].second;
            union_sets(a, b);
            i--;
        }

        if (all_connected()) {
            cout << i << "\n";
            return 0;
        }
        i++;
    }
    cout << FAILURE << "\n";
    return 0;
}
