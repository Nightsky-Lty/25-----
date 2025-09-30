#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct Huffman
{
    vector <int> ls,rs,W;
    Huffman(const vector<int>&w) {init(w);}
    Huffman() {}
    void init(const vector <int> &w)
    {
        ls.clear();rs.clear(),W.clear();
        for(auto x : w) W.push_back(x),ls.push_back(0),rs.push_back(0);
    }
    void build()
    {
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i = 0; i < W.size(); ++i) q.push({W[i],i});
        while(q.size() > 1)
        {
            auto lson = q.top();q.pop();
            auto rson = q.top();q.pop();
            W.push_back(lson.first + rson.first);
            ls.push_back(lson.second);
            rs.push_back(rson.second);
            q.push({W.back(),W.size() - 1});
        }
    }
};
int main()
{
    
    return 0;
}