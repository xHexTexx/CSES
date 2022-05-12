#include<bits/stdc++.h>

using namespace std;

bool dp[2][1000001] ;
int arr[101] ;
int pre = 0 , now = 1 , n ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    dp[0][0] = true ;
    dp[1][0] = true ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ )cin >> arr[i] ;

    for(int i = 1 ; i <= n ; i++ ){

        for(int j = 1 ; j <= 1000000 ; j ++ ){
            if(arr[i] <= j){
                if(dp[pre][j - arr[i]])dp[now][j] = true ;
            }
            dp[now][j] |= dp[pre][j] ;
        }

        swap(pre , now) ;
    }

    int cnt = 0 ;
    for(int i = 1 ; i <= 1000000 ; i ++ ){
        if(dp[pre][i])cnt ++ ;
    }
    cout << cnt << '\n' ;
    for(int i = 1 ; i <= 1000000 ; i ++ ){
        if(dp[pre][i])cout << i << ' ' ;
    }
    return 0 ;
}