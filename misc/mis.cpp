//TODO

#include <bits/stdc++.h>
using namespace std;

#define maxN 100000

int M,N;
int koszt[maxN + 1];
int charyzma[maxN + 1];
vector<int> podlegli[maxN + 1];
long long result;

template <class T>
std::vector<T> sortedMerge(std::vector<T> &v1, std::vector<T> &v2) {
    size_t i = 0, j = 0;
    //std::vector<T> res(v1.size() + v2.size());
    std::vector<T> res;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j])
            res.push_back(v1[i++]);
        else if (v1[i] > v2[j])
            res.push_back(v2[j++]);
        else {
            res.push_back(v1[i++]);
            res.push_back(v2[j++]);
        }
    }
    if (i < v1.size() && j == v2.size())
        res.insert(res.end(), v1.begin() + i, v1.end());
    else if (i == v1.size() && j < v2.size())
        res.insert(res.end(), v2.begin() + j, v2.end());

    return res;
}

vector<int> misja(int idx) {
    vector<int> costs = {koszt[idx]};

    for (int child : podlegli[idx]) {
        vector<int> vect = misja(child);
        //TODO: pomyśleć nad zoptymalizowaniem tego, może użycie sortedmerge
        costs.insert(costs.end(), vect.begin(), vect.end());
    }
    sort(costs.begin(), costs.end()); //można by zmerge'ować

    int sum = 0;
    int i = 0;
    for (; i < costs.size() && sum <= M; i++) {
        sum += costs[i];
    }
    if (sum > M)
        i--; // prevents cost overflow

    result = max(result, (long long)i * (long long)charyzma[idx]);
    return costs;
}

/*vector<int> misja(int idx, vector<int> &costs) {
    costs.push_back(koszt[idx]);

    for (int child : podlegli[idx]) {
        misja(child, costs);
    }
    sort(costs.begin(), costs.end()); //można by zmerge'ować

    int sum = 0;
    int i = 0;
    for (; i < costs.size() && sum <= M; i++) {
        sum += costs[i];
    }
    if (sum > M)
        i--; // prevents cost overflow

    result = max(result, (long long)i * (long long)charyzma[idx]);
    return costs;
}*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        int szef;
        cin >> szef >> koszt[i] >> charyzma[i];
        podlegli[szef].push_back(i);
    }
    
    misja(1);

    cout << result << "\n";
    return 0;
}


