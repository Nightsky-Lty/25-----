#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
struct node
{
    int x,y;
    node() {}
    node(int _x,int _y) : x(_x), y(_y) {}
    node operator + (const node a)const
    {
        return node(x + a.x,y + a.y);
    }
    node operator - (const node a)const
    {
        return node(x - a.x, y - a.y);
    }
    node operator * (const int a)const
    {
        return node(x * a, y * a);
    }
    bool operator < (const node &a)const
    {
        return x == a.x ? y < a.y : x < a.x;
    }
}p[MAXN];
int cross(node a,node b)
{
    return a.x * b.y - a.y * b.x;
}
int dot(node a,node b)
{
    return a.x * b.x + a.y * b.y;
}
bool used[MAXN];
int st[MAXN];
void get_convex(int n)
{
    sort(p + 1, p + 1 + n);
    int top = 1;st[top] = 1;
    for(int i = 2; i <= n; ++i)
    {
        while(top >= 2 && cross(p[st[top]] - p[st[top - 1]],p[i] - p[st[top]]) <= 0) used[st[top--]] = 0;
        st[++top] = i;
        used[i] = 1;
    }
    int siz = top;
    for(int i = n - 1; i >= 1; --i)
    {
        if(used[i]) continue;
        while(top >= siz + 1 && cross(p[st[top]] - p[st[top - 1]],p[i] - p[st[top]]) <= 0) used[st[top--]] = 0;
        st[++top] = i;
    }
}