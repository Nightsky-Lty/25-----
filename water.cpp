#include<bits/stdc++.h>
using namespace std;
void bfs(int a,int b,int c)
{
    map <pair<int,int>,pair<int,int>> mp;//记录前驱
    queue <pair<int,int>> q;
    q.push({0,0});
    mp[{0,0}] = {0,0};
    while(!q.empty())
    {
        auto[cur_a,cur_b] = q.front();
        auto cur = q.front();
        q.pop();
        if(!mp.count({cur_a,0}))
        {
            mp[{cur_a,0}] = cur;
            q.push({cur_a,0});
        }
        if(!mp.count({cur_a,b}))
        {
            mp[{cur_a,b}] = cur;
            q.push({cur_a,b});
        }
        if(!mp.count({0,cur_b}))
        {
            mp[{0,cur_b}] = cur;
            q.push({0,cur_b});
        }
        if(!mp.count({a,cur_b}))
        {
            mp[{a,cur_b}] = cur;
            q.push({a,cur_b});
        }
        int d = min(b - cur_b,cur_a);
        if(!mp.count({cur_a - d,cur_b + d}))
        {
            mp[{cur_a - d,cur_b + d}] = cur;
            q.push({cur_a - d,cur_b + d});
        }
        d = min(a - cur_a,cur_b);
        if(!mp.count({cur_a + d,cur_b - d}))
        {
            mp[{cur_a + d,cur_b - d}] = cur;
            q.push({cur_a + d,cur_b - d});
        }
    }
    auto cur = make_pair(c,0);
    vector<pair<int,int>> res;
    while(cur != make_pair(0,0))
    {
        res.push_back(cur);
        cur = mp[cur];
    }
    res.push_back({0,0});
    reverse(res.begin(),res.end());
    for(auto [cur_a,cur_b] : res) printf("当前状态: %d %d\n",cur_a,cur_b);
}
int main()
{
    int a = 10,b = 7,c = 5;
    bfs(a,b,c);
    return 0;
}