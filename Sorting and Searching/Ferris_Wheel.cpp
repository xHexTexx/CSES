#include<bits/stdc++.h>

using namespace std;

int n , k , res = 0 , arr[200000] , sum = 0 ;
bitset<200000>selected ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> k ;

    for(int i = 0 ; i < n ; i ++ )cin >> arr[i] ;

    sort(arr , arr + n) ;

    int l = 0 , r = n - 1 ;

    while(l < r){

        if(arr[l] + arr[r] <= k){
            selected[l] = selected[r] = true ;
            res ++ ;
            l ++ ;
            r -- ;
        }

        else {
            r -- ;
        }
    }

    for(int i = 0 ; i < n ; i ++ ){
        if(!selected[i])res ++ ;
    }
    
    cout << res ;
    
    return 0 ;
}