#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int a[maxn];
bool dp[maxn * 100];

int main(){
    int n; scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for(int i = 0; i <= sum; i++) dp[i] = false;
    dp[0] = true;
    for(int i = 0; i < n; i++){
        for(int j = sum; j >= a[i]; j--){
            dp[j] |= dp[j-a[i]];
        }
    }
    for(int i = sum / 2 + sum % 2; i <= sum; i++){
        if(dp[i]){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}