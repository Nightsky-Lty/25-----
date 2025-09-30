#include <bits/stdc++.h>
using namespace std;

class BinaryTree 
{
public:
    struct Node 
    {
        int data;
        Node* ls;
        Node* rs;
        bool lson,rson;//1 表示线索化

        Node(int val) : data(val), ls(nullptr), rs(nullptr) {lson = rson = 1;}
    };
    Node* rt;
    void destroyTree(Node* node) 
    {
        if(node) 
        {
            if(!(node -> lson)) destroyTree(node -> ls);
            if(!(node -> rson)) destroyTree(node -> rs);
            delete node;
        }
    }
    
    void preorder(Node* node,vector<Node*> &list)
    {
        if(node) 
        {
            list.push_back(node);
            if(!(node -> lson)) preorder(node -> ls,list);
            if(!(node -> rson)) preorder(node -> rs,list);
        }
    }

    void inorder(Node* node,vector<Node*> &list)
    {
        if(node)
        {
            if(!(node -> lson)) inorder(node -> ls,list);
            list.push_back(node);
            if(!(node -> rson)) inorder(node -> rs,list);
        }
    }

    void postorder(Node* node,vector<Node*> &list)
    {
        if(node)
        {
            if(!(node -> lson)) postorder(node -> ls,list);
            if(!(node -> rson)) postorder(node -> rs,list);
            list.push_back(node);
        }
    }
    
    BinaryTree() : rt(nullptr) {}

    BinaryTree(const std::vector<int>& levelOrderList) 
    {
        if (levelOrderList.empty() || levelOrderList[0] == -1) 
        {
            rt = nullptr;
            return;
        }

        rt = new Node(levelOrderList[0]);
        queue<Node*> q;
        q.push(rt);

        int i = 1;
        while(!q.empty() && i < levelOrderList.size()) 
        {
            Node* p = q.front();
            q.pop();

            if(i < levelOrderList.size() && levelOrderList[i] != -1)
            {
                p -> ls = new Node(levelOrderList[i]);
                p -> lson = 0;
                q.push(p -> ls);
            }
            i++;

            if(i < levelOrderList.size() && levelOrderList[i] != -1)
            {
                p -> rs = new Node(levelOrderList[i]);
                p -> rson = 0;
                q.push(p -> rs);
            }
            i++;
        }
    }

    void Threaded(int type)
    {
        vector<Node*> list;
        if(type == 0) preorder(rt,list);
        if(type == 1) inorder(rt,list);
        if(type == 2) postorder(rt,list);
        Node* pre = nullptr;
        for(auto cur : list)
        {
            if(cur -> lson) cur -> ls = pre;
            if(pre && pre -> rson) pre -> rs = cur;
            pre = cur;
        }
    }
    ~BinaryTree() 
    {
        destroyTree(rt);
    }
};

int main() 
{    
    return 0;
}