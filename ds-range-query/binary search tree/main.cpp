#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int c;
class node
{
public:
    int v;
    node *left,*right;
    node(int x)
    {
        v=x;
        left=right=nullptr;
    }
};
class bTree
{
public:
    node *rt;
    bTree()
    {
        rt=nullptr;
    }
    node* root()
    {
        return rt;
    }
    void ins(int x)
    {
        if(rt==nullptr)
        {
            rt=new node(x);
        }
        else
        {
            ins(x,rt);
        }
    }
    void ins(int x,node *n)
    {
        c++;
        if(x<n->v)
        {
            if(n->left==nullptr)
                n->left=new node(x);
            else
                ins(x,n->left);
        }
        if(x>n->v)
        {
            if(n->right==nullptr)
                n->right=new node(x);
            else
                ins(x,n->right);
        }
    }
    node* check(int x)
    {
        return check(x,rt);
    }
    node* check(int x,node *n)
    {
        if(n==nullptr)
            return nullptr;
        if(x<n->v)
            return check(x,n->left);
        if(x>n->v)
            return check(x,n->right);
        return n;
    }
    node* mini(node* n)
    {
        if(n->left!=nullptr)
            return mini(n->left);
        return n;
    }
    node* maxi(node* n)
    {
        if(n->right!=nullptr)
            return mini(n->right);
        return n;
    }
    void del(int x)
    {
        del(rt,x);
    }
    void del(node *&n,int x)
    {
        if(n==nullptr)
            return;
        if(n->v>x)
            del(n->left,x);
        if(n->v<x)
            del(n->right,x);
        if(n->v==x)
        {
            if(n->left==nullptr&&n->right==nullptr)
            {
                delete n;
                n=nullptr;
            }
            else if(n->left==nullptr)
            {
                node *temp;
                temp=n->right;
                delete n;
                n=temp;
            }
            else if(n->right==nullptr)
            {
                node *temp;
                temp=n->left;
                delete n;
                n=temp;
            }
            else
            {
                x=mini(n->right)->v;
                n->v=x;
                del(n->right,x);
            }
        }
    }
    void inorder()
    {
        if(rt!=nullptr)
            inorder(rt);
    }
    void inorder(node* n)
    {
        if(n!=nullptr)
        {
            inorder(n->left);
            cout<<n->v<<"\n";
            inorder(n->right);
        }
    }
    void preorder()
    {
        if(rt!=nullptr)
            preorder(rt);
    }
    void preorder(node* n)
    {
        if(n!=nullptr)
        {
            cout<<n->v<<"\n";
            preorder(n->left);
            preorder(n->right);
        }
    }
    void postorder()
    {
        if(rt!=nullptr)
            postorder(rt);
    }
    void postorder(node* n)
    {
        if(n!=nullptr)
        {
            postorder(n->left);
            postorder(n->right);
            cout<<n->v<<"\n";
        }
    }
    void levelorder()
    {
        queue<node*>toV;
        node *temp;
        toV.push(rt);
        while(!toV.empty())
        {
            temp=toV.front();
            if(temp==nullptr)
            {
                cout<<". ";
                toV.pop();
            }
            else
            {
                cout<<temp->v<<" ";
                toV.push(temp->left);
                toV.push(temp->right);
                toV.pop();
            }
        }
    }
};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,x=0;
    bTree t;
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        t.ins(x);
    }
    cout<<endl;
    t.levelorder();
    cout<<endl;
    fori(0,n)
    {
        cin>>x;
        t.del(x);
        cout<<endl;
        t.levelorder();
        cout<<endl;
    }
    return 0;
}
