#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b) {
    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();
    int count = 0;
    while((maxSum>a[i] && maxSum>b[j]) && ( i<n && j<m )){

        if(a[i] <= b[j]){
            count++;
            maxSum -= a[i++];
        }
        else if(a[i]>b[j]){
            count++;
            maxSum -= b[j++];
        }
    }
    while(i<n && maxSum>a[i]){
        count++;
        maxSum -= a[i++];
    }
    while(j<m && maxSum>b[j]){
        count++;
        maxSum -= b[j++];
    }
    return count;
}

int main()
{

    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int result = portfolio_profit_maximisation(x, a, b);
    cout << result;
    return 0;
    
}