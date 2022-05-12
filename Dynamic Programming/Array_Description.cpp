#include<bits/stdc++.h>

using namespace std;

long long dp[100001][102] , n , m , arr[100001] ;
const int mod = 1e9 + 7 ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
    }

    for(int i = 1 ; i <= n ; i ++ ){

        if(i == 1){
            if(arr[i] == 0){
                for(int j = 1 ; j <= m ; j ++ ){
                    dp[i][j] = 1 ;
                }
            }
            else {
                dp[i][arr[i]] = 1 ;
            }
        }
        
        else {
            if(arr[i] == 0){
                for(int j = 1 ; j <= m ; j ++ ){
                    dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1] ;
                    dp[i][j] %= mod ;
                }
            }
            else {
                dp[i][arr[i]] += dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]] + dp[i - 1][arr[i] + 1] ; 
                dp[i][arr[i]] %= mod ;
            }
        }

    }

    long long res = 0;
    for(int j = 1 ; j <= m ; j ++ ){
        res += dp[n][j] ;
        res %= mod ;
    }

    cout << res ;

    return 0 ;
}