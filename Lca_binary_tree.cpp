        vector<ll> adj[200005];
ll level[200005];
ll parent[200005][18];
void dfs(int node,int par, int lvl=1)
{
    level[node]=lvl;
    parent[node][0]=par;
    for(int i=1;i<18;i++)
    {
       parent[node][i]=parent[parent[node][i-1]][i-1];
    }
    for(auto i: adj[node])
    {
       if(i!=par)
        dfs(i,node,lvl+1);
    }
}
ll LCA(ll u,ll v)
{
   if(level[u]<level[v])swap(u,v);
   ll k=level[u]-level[v];
   // making the level of both same 
   ll cnt=0;
   while(k)
   {
     if(k&1)
     {
        u=parent[u][cnt];
     }
     cnt++;
     k=k>>1;
   }
   //cout<<u<<" ";
   // checking if this point is itself lca
    if(u==v)return u;

    // binary lifting

    for(int i=17;i>=0;i--)
    {
       if(parent[u][i]!=parent[v][i])
       {
         u=parent[u][i];
         v=parent[v][i];
       }
    }
    return parent[u][0];
}
