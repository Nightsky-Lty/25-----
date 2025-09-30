#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int totmoves = (1 << n) - 1,cur = 0,d = n % 2 == 1 ? 2 : 1;
    vector <int> r[3];
    for(int i = 0; i < 3; ++i) r[i].push_back(n + 1);
    for(int i = n; i >= 1; --i) r[0].push_back(i);
    //0,1,2 三个柱子
    for(int i = 1; i <= totmoves; ++i)
    {
        if(i & 1)
        {
            cout << cur << "->" << (cur + d) % 3 << endl;
            r[cur].pop_back();
            cur = (cur + d) % 3;
            r[cur].push_back(1);
        }
        else
        {
            int st = 0;
            if(cur == 0) st = r[1].back() < r[2].back() ? 1 : 2;
            if(cur == 1) st = r[0].back() < r[2].back() ? 0 : 2;
            if(cur == 2) st = r[0].back() < r[1].back() ? 0 : 1;
            int ed = 3 - cur - st;
            cout << st << "->" << ed << endl;
            r[ed].push_back(r[st].back());
            r[st].pop_back();
        }
    }
    return 0;
}