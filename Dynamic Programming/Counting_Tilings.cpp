#include<bits/stdc++.h>

using namespace std;

long long dp[11][1001] ;

const int mod = 1e9 + 7 ;

int m , n ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> m >> n ;

    memset(dp ,0 , sizeof(dp));

    for(int i = 1 ; i <= m ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){

            if((i & 1) && (j & 1))dp[i][j] = 0 ;
            else if(i == 1 && !(j & 1))dp[i][j] = 1 ;
            else if(j == 1 && !(i & 1))dp[i][j] = 1 ;
            else {
                dp[i][j] = (dp[i][j - 2] + dp[i - 1][2] + dp[1][j - 2] + dp[i - 1][j] + dp[i][j - 1] + dp[i - 2][1] + dp[2][j - 1] + dp[i - 2][j]);
                dp[i][j] %= mod ;
            }
        }
    }

    for(int i = 1 ; i <= m ; i ++){
        for(int j = 1 ; j <= n ; j ++ ){
            cout << dp[i][j] << ' ';
        }
        cout << '\n' ;
    }

    return 0 ;
}