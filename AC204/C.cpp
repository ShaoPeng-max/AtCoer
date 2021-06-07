#include <bits/stdc++.h>
using namespace std;

/**
 * 简单dfs
**/

const int maxn = 2005;
vector<int> a[maxn];
int vsisted[maxn];

void dfs(int i){
    if(vsisted[i]) return;
    vsisted[i] = 1;
    for(int j: a[i]) dfs(j);
}

int main(){
    memset(a, 0, sizeof(a));
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
    }
    int ret = 0;
    for(int i = 1; i <= n; i++){
        memset(vsisted, 0, sizeof(vsisted));        
        dfs(i);
        for(int i = 1; i <= n; i++) ret += vsisted[i];
    }
    printf("%d\n", ret);
}