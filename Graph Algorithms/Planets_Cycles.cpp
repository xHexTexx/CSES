#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 ;
int n , x ;
vector<int>adj[N] ;

int visited[N] , visited2[N] , low[N] , ti = 1 , dp[N];
bool instack[N] ;
stack<int>st , group;

void dfs(int now){

    low[now] = visited[now] = ti ++ ;
    instack[now] = true ;
    st.push(now) ;

    for(auto i : adj[now]){
        if(!visited[i]){
            dfs(i) ;
            low[now] = min(low[now] , low[i]) ;
            dp[now] = dp[i] + 1 ;
        }
        else if(instack[i]){
            low[now] = min(low[now] , low[i]);
        }
    }


    if(visited[now] == low[now]){

        int sz = 0 ;

        while(st.top() != now){
            sz ++ ;
            instack[st.top()] = false ;
            group.push(st.top()) ;
            st.pop() ;
        }
        sz ++ ;
        instack[st.top()] = false ;
        group.push(st.top());
        st.pop() ;

        while(!group.empty()){
            dp[group.top()] = sz ;
            group.pop();
        }
    }
}

void dfs2(int now){

    for(auto i : adj[now]){
        if(visited2[now])continue ;
        dfs2(i) ;
        if(low[now] = low[i]){
            continue ;
        }
        else {
            dp[now] = dp[i] + 1 ;
        }
    }

}
int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> x ;
        adj[i].push_back(x) ;
    }

    for(int i = 1 ; i <= n ; i ++){
        if(!visited[i])dfs(i) ;
    }
    for(int i = 1 ; i <= n ; i ++ ){
        if(!visited2[i])dfs2(i) ; 
    }

    for(int i = 1; i <= n ; i ++){
        cout << dp[i] << ' ' ;
    }

    return 0 ;
}