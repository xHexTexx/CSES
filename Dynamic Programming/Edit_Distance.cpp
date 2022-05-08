#include<bits/stdc++.h>

using namespace std;

int m , n , dp[5001][5001] ;

string a , b ;

int min(int a , int b , int c){
    return min(a , min(b , c)) ;
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ; 

    cin >> a >> b ;
    m = a.size() , n = b.size() ;

    for(int i = 0 ; i <= n ; i ++ )dp[0][i] = i ;
    for(int i = 0 ; i <= m ; i ++ )dp[i][0] = i ;

    for(int i = 1; i <= m ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){

            if(a[i - 1] == b[j - 1])dp[i][j] = dp[i - 1][j - 1] ;
            else {
                dp[i][j] = min(dp[i - 1][j] , dp[i][j - 1] , dp[i - 1][j - 1]) + 1 ;
            }
        }
    }

    cout << dp[m][n] ;

    return 0 ;
}