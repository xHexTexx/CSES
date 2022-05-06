#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1 ;

long long dp[N] , n ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    dp[0] = 0 ;

    cin >> n ;

    
    for(int i = 1 ; i <= n ; i ++ ){

        dp[i] = INT_MAX ;

        int temp = i ;

        while(temp){
            dp[i] = min(dp[i] , 1 + dp[i - temp % 10]) ;
            temp /= 10 ;
        }

    }

    cout << dp[n] ;

    return 0 ;
}