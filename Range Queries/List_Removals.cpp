#include<bits/stdc++.h>

using namespace std ;

const int N = 2e5 + 1 ;

int n  , idx , arr[N];

class Fenwick {

    public :

        int fw[N] ;

        void update(int idx , int val){
            for(; idx < N ; idx += (idx & -idx))fw[idx] += val ;
        }

        int query(int idx){
            int res = 0 ;
            for(; idx > 0 ; idx -= (idx & -idx))res += fw[idx] ;
            return res ;
        }

        int get(int idx){
            int l = 1 , r = N - 1 ;
            while(l < r){
                int mid = (l + r) >> 1 ;
                if(query(mid) >= idx)r = mid ;
                else l = mid + 1 ;
            }
            return l ;
        }
}fw;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;
  
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
        fw.update(i , 1);
    }

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> idx ;
        idx = fw.get(idx);
        cout << arr[idx] << ' ';
        fw.update(idx , -1); 
    }

    return 0 ;
}