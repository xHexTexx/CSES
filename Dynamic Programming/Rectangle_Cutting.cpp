#include<bits/stdc++.h>

using namespace std;

int dp[501][501] ;

int m , n ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> m >> n ;

    for(int i = 1 ; i <= 500 ; i ++ ){
        for(int j = 1 ; j <= 500 ; j ++ ){
            if(i == j)continue ;
            else dp[i][j] = INT_MAX ;
        }
    }

    for(int i = 1 ; i <= 500 ; i ++ ){
        for(int j = i + 1 ; j <= 500 ; j ++ ){

            for(int a = 1 ; a < j ; a ++ ){
                dp[i][j] = min(dp[i][j] , 1 + dp[i][a] + dp[i][j - a]) ;
            }

            for(int b = 1 ; b < i ; b ++ ){
                dp[i][j] = min(dp[i][j] , 1 + dp[b][j] + dp[i - b][j]) ;
            }

            dp[j][i] = dp[i][j] ;
        }
    }

    cout << dp[m][n] ;

    return 0 ;
}