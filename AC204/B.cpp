#include <cstdio>
#include <algorithm>
/**
 * 当大于10时,取除10以外的部分
**/

int main(){
    int t;
    scanf("%d", &t);
    int ret = 0;
    int x;
    for(int i = 0; i < t; i++) {
        scanf("%d", &x);
        ret += std::max(0, x - 10);
    }
    printf("%d", ret);

}