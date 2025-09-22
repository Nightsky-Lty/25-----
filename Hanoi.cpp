#include<bits/stdc++.h>
using namespace std;
void solve(int st,int ed,int cnt)
{
    if(cnt == 0) return ;
    solve(st,6 - st - ed,cnt - 1);
    cout << st << " -> " << ed << endl;
    solve(6 - st - ed,ed,cnt - 1); 
}
//solve(st,ed,cnt) 表示将 cnt 个圆盘从 st 挪到 ed 的方案
int main()
{
    int n = 5;
    solve(1,3,n);
}