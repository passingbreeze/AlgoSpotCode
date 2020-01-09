#include <bits/stdc++.h>

using namespace std;

vector<int> factors(int n)
{
    vector<int> v;
    v.push_back(1);

    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            v.push_back(i);
            if (n / i != i) {
                v.push_back(n / i);
            }
        }
    }

    return v;
}

bool checkAbundant(int n)
{
    vector<int> v;

    int sum = 0;

    v = factors(n);
    for (int i : v) {
        sum += i;
    }
    return sum > n;
}
bool checkSemiPerfect(int n)
{
    vector<int> v;
    v = factors(n);
    sort(v.begin(), v.end());
    int r = v.size();
    vector<vector<bool>> subset(r+1, vector<bool>(n+1));
    for (int i = 0; i <= r; i++)
        subset[i][0] = true;

    for (int i = 1; i <= n; i++)
        subset[0][i] = false;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= n; j++) {

            if (j < v[i - 1])
                subset[i][j] = subset[i - 1][j];
            else {
                subset[i][j] = subset[i - 1][j] ||
                               subset[i - 1][j - v[i - 1]];
            }
        }
    }

    return subset[r][n] != 0;
}

bool checkweird(int n)
{
    return checkAbundant(n)&&!checkSemiPerfect(n);
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int cases, n;
    cin >> cases;
    while(cases--){
        cin >> n;
        if (checkweird(n))
            cout << "weird\n";
        else
            cout << "not weird\n";
    }
    return 0;
}
