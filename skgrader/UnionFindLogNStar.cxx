int Find(int x)
{
    if(x==p[x])return x;
    return p[x]=Find(p[x]);
}
int Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    p[x]=y;
}
