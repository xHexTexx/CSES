#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7 ;
char graph[1001][1001] ;
long long dp[1001][1001] ;

int n ; 

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    dp[1][1] = 1 ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> graph[i][j] ;
        }
    }
    
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            if(graph[i][j] == '*')dp[i][j] = 0 ;
            else dp[i][j] += ((dp[i - 1][j] % mod) + (dp[i][j - 1] % mod)) % mod ;
        }
    }

    cout << dp[n][n] ;

    return 0 ;
}