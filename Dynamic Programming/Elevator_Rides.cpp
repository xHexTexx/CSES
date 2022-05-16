#include<bits/stdc++.h>

using namespace std;

struct elevator {
    long long cnt , w ;
    elevator(){}
    elevator(long long count , long long weight){
        cnt = count ;
        w = weight ;
    }
};

int n , k , arr[21];

elevator dp[1 << 20] ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> k ;

    for(int i = 0 ; i < n ; i ++ )cin >> arr[i] ;

    for(int i = 1 ; i < 1 << 20 ; i ++ ){
        dp[i] = elevator(INT_MAX , INT_MAX) ;
    }

    dp[0] = elevator(1 , 0) ;

    for(int i = 1 ; i < (1 << n) ; i ++ ){

        for(int j = 0 ; j < n ; j ++ ){
            int bit = 1 << j ;
            if(i & bit){

                elevator temp = dp[i ^ bit] ;
                if(temp.w + arr[j] > k){
                    temp.cnt ++ ;
                    temp.w = arr[j] ;
                }
                else {
                    temp.w += arr[j] ;
                }

                if(temp.cnt < dp[i].cnt){
                    dp[i] = temp ;
                }
                else if(dp[i].cnt == temp.cnt){
                    dp[i].w = min(dp[i].w , temp.w) ;
                }
            }
        }

    }

    cout << dp[(1 << n) - 1].cnt ;

    return 0 ;
}