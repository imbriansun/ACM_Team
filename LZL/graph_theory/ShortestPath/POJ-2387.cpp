#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<cstdlib>
#include<utility>
#include<cstring>
using namespace std;

using pa = pair<int,int>;
int m,n;
int tmpa,tmpb,tmpc;
struct node{
    int to,w;
};
const int maxn = 2000+10;
const int INF = 0x3f3f3f3f;
vector<node> G[maxn];
int dis[maxn];
int Dijkstra(){
    priority_queue<pa,vector<pa>,greater<pa> >que;
    fill(dis,dis+maxn,INF);
    dis[n] = 0;
    que.emplace(make_pair(0,n));
    while(!que.empty()){
        pa temp = que.top();
        que.pop();
        int u = temp.first;
        int v = temp.second;
        if(dis[v] < u) continue;
        size_t len = G[v].size();
        for(int i=0;i<len;++i){
            node &x = G[v][i];
            if(u + x.w < dis[x.to]){
                dis[x.to] = u+x.w;
                que.emplace(make_pair(dis[x.to],x.to));
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> m >> n;
    for(int i=0;i<m;++i){
        cin >> tmpa >> tmpb >> tmpc;
        G[tmpa].push_back({tmpb,tmpc});
        G[tmpb].push_back({tmpa,tmpc});
    }
    Dijkstra();
    cout << dis[1] << endl;
    return 0;
}