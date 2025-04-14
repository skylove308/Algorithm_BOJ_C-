#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int K;
        cin >> K;
        vector<int> files(K);
        for(int i=0; i<K; i++){
            cin >> files[i];
        }
        vector<vector<int>> dp(K, vector<int>(K));
        vector<int> sum(K);
        for(int i=0; i<K; i++){
            sum[i] = sum[i-1] + files[i];
        }

        for(int len=2; len<=K; len++){
            for(int i=0; i<=K-len; i++){ 
                int j=i+len-1;
                dp[i][j] = INT_MAX;
                for(int k=i+1; k<=j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j] + sum[j] - sum[i-1]);
                }
            }
        }

        cout << dp[0][K-1] << '\n';
    }

    return 0;
}