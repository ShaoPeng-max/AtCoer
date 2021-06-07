#include <cstdio>
/**
 * 石头剪刀布,三个人打成平手
 * 当其他人相同时,出一样的,不一样时,出不一样的
**/ 

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", x == y ? x : 3 - x - y);
    return 0;
}