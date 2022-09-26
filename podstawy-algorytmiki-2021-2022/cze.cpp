//TODO
#include <bits/stdc++.h>
using namespace std;

#define X true
#define Y false

const int maxN = 5 * 1e5, maxM = 5 * 1e5;
pair<int, bool> cuts[maxN + maxM];
int n, m;

int solve() {
    int res = 0;
    int cnt[2] = {0, 0};

    auto cmp = [&](pair<int, bool> a, pair<int, bool> b) { return a.first > b.first; };
    sort(cuts, cuts + n, cmp);

    for (int i = 0; i < n + m; i++) {
        res += max(0, cnt[1 - cuts[i].second] - 1) * cuts[i].first;
        cnt[cuts[i].second]++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        cin >> cuts[i].first;
        cuts[i].second = i < n? X : Y;
    }

    cout << solve() << "\n";
    return 0;
}
