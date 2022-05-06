#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 ;

long long dp[N + 1] , arr[101] , n , k ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> k ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
    }
    for(int i = 1 ; i <= N ; i ++ ){
        dp[i] = INT_MAX ;
    }

    dp[0] = 0 ;

    for(int i = 1 ; i <= k ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            if(arr[j] <= i){
                dp[i] = min(dp[i] , 1 + dp[i - arr[j]]);
            }
        }
    }

    if(dp[k] >= INT_MAX)cout << -1 ;
    else cout << dp[k] ;

    return 0 ;
}