#include<bits/stdc++.h>

#define ull unsigned long long

using namespace std;

ull dp[501][501] ;

int n , m , q , x , y  ;
ull w ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m >> q ;
    
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            if(i == j)continue ;
            dp[i][j] = LLONG_MAX ;
        }
    }

    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y >> w ;
        dp[x][y] = min(dp[x][y] , w) ;
        dp[y][x] = min(dp[y][x] , w) ;
    }

    for(int k = 1 ; k <= n ; k ++ ){
        for(int i = 1 ; i <= n ; i ++ ){
            for(int j = 1 ; j <= n ; j ++ ){
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]) ;
            }
        }
    }

    while(q -- ){
        cin >> x >> y ;
        (dp[x][y] == LLONG_MAX) ? cout << -1 << '\n' : cout << dp[x][y] << '\n' ;
    }
   
    return 0 ;
}