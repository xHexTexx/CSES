#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 ;

class Fenwick {

    public :
        
        long long fw[N] ;

        void update(int idx , int val){
            for(; idx < N ; idx += (idx & -idx))fw[idx] += val ;
        }
        long long query(int idx){
            long long res = 0 ;
            for(; idx > 0 ; idx -= (idx & -idx))res += fw[idx] ;
            return res ;
        }

}fw;

int n , q , idx , cmd , l , r ;
long long val ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;
    
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> val ;
        fw.update(i , val);
        fw.update(i + 1, -val);
    }

    while(q -- ){
        cin >> cmd ;
        if(cmd == 1){
            cin >> l >> r >> val ;
            fw.update(l , val);
            fw.update(r + 1 , - val);
        }
        else {
            cin >> idx ;
            cout << fw.query(idx) << '\n' ;
        }
    }
    
    return 0 ;
}