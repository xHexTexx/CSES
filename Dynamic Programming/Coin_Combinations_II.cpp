#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1 , mod = 1e9 + 7 ;

int dp[101][N] , arr[101] , n , k ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> k ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
    }

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 0 ; j <= k ; j ++ ){
           if(j == 0)dp[i][j] = 1 ;
           else {
               dp[i][j] = dp[i - 1][j] ;
               if(j >= arr[i]){
                   dp[i][j] += dp[i][j - arr[i]] ;
               }
               dp[i][j] %= mod ;
           }
        }
    }

    cout << dp[n][k] ;

    return 0 ;
}