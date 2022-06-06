#include<bits/stdc++.h>

using namespace std;

long long dp[5001][5001] , qs[5001] , arr[5001] ;

long long sum(int l , int r){
    return qs[r] - qs[l - 1];
}

long long solve(int l , int r){
    if(dp[l][r])return dp[l][r] ;
    if(l == r)return arr[l] ;
    return dp[l][r] = max(arr[l] + sum(l + 1 , r) - solve(l + 1 , r) , arr[r] + sum(l , r - 1) - solve(l , r - 1));
}
int main(){
    
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    int n ; cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
        qs[i] = arr[i] + qs[i - 1] ;
    }

    cout << solve(1 , n);
    return 0;
}