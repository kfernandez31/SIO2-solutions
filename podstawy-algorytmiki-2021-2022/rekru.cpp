#include <bits/stdc++.h>
using namespace std;

#define LSB(n) ((n) & 1)

vector<int> createGoodArray(long n) {
    int logn = log2(n);
    vector<int> result;

    for (long acc = 1; n != 0; n >>= 1, acc <<= 1) {
        if (LSB(n))
            result.push_back(acc);
    }
    
    return result;
}

vector<int> getQueryResults(long n, vector<vector<int>> queries) {
    vector<int> result;
    vector<int> goodArray = createGoodArray(n);
    vector<__uint128_t> prefProduct;

    prefProduct.push_back(1);
    for (int i = 0; i < goodArray.size(); i++) {
        prefProduct.push_back(prefProduct[i] * goodArray[i]);
    }

    for (int i = 0; i < queries.size(); i++) {
        vector<int> query = queries[i];
        int l = query[0], r = query[1], m = query[2];
        int prod = (prefProduct[r] / prefProduct[l - 1]) % m;
        result.push_back(prod);
    }
    return result;   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, qsize;
    cin >> n >> q >> qsize;

    vector<vector<int>> queries;
    for (int i = 0; i < q; i++) {
        vector<int> query;
        for (int j = 0; j < qsize; j++) {
            int x;
            cin >> x;
            query.push_back(x);
        }
        queries.push_back(query);
    }

    auto res = getQueryResults(n, queries);

    for (auto x : res) 
        cout << x << "\n";
    cout << endl;


    return 0;
}
