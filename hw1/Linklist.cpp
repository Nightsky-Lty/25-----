#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        node *nxt;
        int val;
        node(int _v) : val(_v),nxt(nullptr) {}
};
class LinkList
{
    public:
        node *head;
        int len;
        LinkList(node *hd) : len(1), head(hd) {}
        LinkList() : len(0), head(nullptr) {}
    void insert(int val,int pos = -1)
    {
        if(pos == -1) pos = len;
        node *cur = head,*nd = new node(val);
        if(pos == 0) nd -> nxt = head,head = nd;
        else
        {
            while(--pos) cur = cur -> nxt;
            nd -> nxt = cur -> nxt;
            cur -> nxt = nd;
        }
        ++len;
    }
};