#include<bits/stdc++.h>

using namespace std;

int n , m , k , i = 0 , j = 0 , res = 0 ; 

int apart[200000] ;
int guest[200000] ;

int main(){

    //Solve by HexTex 
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m >> k ;
    
    for(int i = 0 ; i < n ; i ++ ){
        cin >> apart[i] ;
    }
    for(int i = 0 ; i < m ; i ++ ){
        cin >> guest[i] ;
    }

    sort(apart , apart + n) ;
    sort(guest , guest + m) ;
    
    while(i < n && j < m){

        if(abs(apart[i] - guest[j]) <= k){
            res ++ ;
            i ++ ;
            j ++ ;
        }

        else if (apart[i] - guest[j] > k){
            j ++ ;
        }

        else {
            i ++ ;
        }
    }

    cout << res ;

    return 0 ;
}