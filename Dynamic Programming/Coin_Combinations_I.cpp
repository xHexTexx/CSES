#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1 , mod = 1e9 + 7 ;
long long n , k , dp[N] , arr[101];

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> k ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
    }

    dp[0] = 1 ;

    for(int i = 1 ; i <= k ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            if(i >= arr[j])dp[i] += dp[i - arr[j]] ;
            dp[i] %= mod ;
        }
    }

    cout << dp[k] ;

    return 0 ; 
}