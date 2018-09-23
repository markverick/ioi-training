#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
struct Node
{
    Node *p,*l,*r;
    int v;
    void progr(Node *x)
    {
        l=x->l;r=x->r;
        x->l->p=p;p->
        x->l=l;x->r=r;x->p=p;
            p=x->p,l=x->l,r=x->r;
        p->r=x;
        delete x;
    }
    void progl(Node *x)
    {
        if(!x)
            delete this;
        p=x->p;l=x->l;r=x->r;
        x->p->r=this;
        delete x;
    }
    void swp(Node *x)
    {
        swap(v,x->v);
    }
};
Node *root;
void insert(int v)
{
    if(!root)
    {
        root=new Node;
        root->l=NULL;
        root->r=NULL;
        root->p=NULL;
        return;
    }
    Node *id=root;
    while(135)
    {
        if(id->v==v)break;
        if(id->v<v)
        {
            if(id->l)
                id=id->l;
            else
            {
                id->l=new Node;
                id->l->p=id;
                id->l->r=NULL;
                id->l->l=NULL;
                id->l->v=v;
                id=id->l;
                break;
            }
        }
        else
        {
            if(id->r)
                id=id->r;
            else
            {
                id->r=new Node;
                id->r->p=id;
                id->r->l=NULL;
                id->r->r=NULL;
                id->r->v=v;
                id=id->r;
                break;
            }
        }
    }
}
void Inorder(Node *id)
{
    if(!id)return;
    Inorder(id->l);
    printf("%d -> ",id->v);
    Inorder(id->r);
}
Node* Find(int v)
{
    if(!root)return NULL;
    Node *id;
    while(135)
    {
        if(v<id->v)
        {
            if(id->l)
                id=id->l;
            else
                break;
        }
        else
        {
            if(id->r)
                id=id->r;
            else
                break;
        }
    }
    if(id->v==v)return id;
    return NULL;
}
bool Erase(int v)
{
    Node *id=Find(v),*R;
    if(!id)
        return 0;
    R=id->r;
    if(!R)
    {
        id.prog(id->l);
        return;
    }
    while(R->l)
    {
        R=R->l;
        R.swp(id);
        R.progr(R->r);
    }
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
    }
}
