#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
 
typedef struct{
    int l, t, r, b;
} square;
 
int n;
square s[36];
 
int check(int arr[]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(s[arr[i * n + j]].r != s[arr[i * n + j + 1]].l){
                return 0;
            }
        }
    }
 
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n - 1; i++){
            if(s[arr[i * n + j]].b != s[arr[(i + 1) * n + j]].t){
                return 0;
            }
        }
    }
    return 1;
}
void print(int arr[]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d%c", arr[i * n + j], (j == n - 1) ? '\n' : ' ');
        }
    }
}
 
int dfs(int arr[], int used[], int now_idx){
	print(arr);
    if(now_idx == n * n){
        if(check(arr)){
            print(arr);
            return 1;
        }
        else{
            return 0;
        }
        return 0;
    }
    else{
        for(int i = 0; i < n * n; i++){
            if(used[i] == 0){
                if(now_idx % n != 0){
                    if(s[arr[now_idx - 1]].r != s[i].l) continue;
                }
                if(now_idx >= n){
                    if(s[arr[now_idx - n]].b != s[i].t) continue;
                }
 
                used[i] = 1, arr[now_idx] = i;
                int rtv = dfs(arr, used, now_idx + 1);
                if(rtv) return 1;
                used[i] = 0; arr[now_idx] = -1;
            }
        }
        return 0;
    }
}
 
int main(){
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n * n; i++) scanf("%d %d %d %d", &s[i].l, &s[i].t, &s[i].r, &s[i].b);
        int arr[36] = {0}, used[36] = {0};
        int rtv = dfs(arr, used, 0);
        if(!rtv) printf("no solution\n");
    }
}
