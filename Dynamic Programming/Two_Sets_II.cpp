#include<bits/stdc++.h>

using namespace std;

const int N = 125251 , mod = 1e9 + 7;

int dp[501][N] ;

int n ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    int k = n * (n + 1) / 2 ;

    if(k & 1){
        cout << 0 ;
        return 0 ;
    }
    else {
        k /= 2 ;
    }
    dp[0][0] = 1 ;

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= k ; j ++ ){
            if(j >= i){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i] ;
                dp[i][j] %= mod ;
            }
            else dp[i][j] = dp[i - 1][j] %= mod ;
        }
    }
    cout << dp[n][k] ;

    return 0 ;
}