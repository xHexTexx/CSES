#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 , mod = 1e9 + 7 ;

int dp[N + 1] ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n ; cin >> n ;

    dp[0] = 1 ;

    for(int i = 1 ; i <= n ; i ++ ){
        
        for(int j = 1 ; j <= 6 ; j ++ ){
            if(j <= i){
                dp[i] += dp[i - j] ;
                dp[i] %= mod ;
            }
        }

    }

    cout << dp[n] ;


    return 0 ;
}