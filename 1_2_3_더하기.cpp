#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int t;
    cin >> t;

    int n;
    for(int i=0; i<t; i++){
        cin >> n;
        vector<int> dp(n+1);

        if(n==1){
            cout << 1 << '\n';
        }else if(n==2){
            cout << 2 << '\n';
        }else if(n==3){
            cout << 4 << '\n';
        }else{
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;
    
            for(int i=4; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            }
            cout << dp[n] << '\n';
        }
    }

    return 0;
}