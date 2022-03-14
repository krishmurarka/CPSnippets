struct node
{
   ll hello;
   node(){
    hello=0;
   }
   node (ll x)
   {
     hello=x;
   }
};
ll n;  // array size
node t[(int)4e5 +5];
node combine(node a, node b)
{
  node ret;
  return ret;
}
void build() 
{
  for (ll i = n - 1; i > 0; --i) 
  t[i] = combine(t[i<<1],t[i<<1|1]);
}
 
node query(ll l, ll r) 
{
  node resl, resr;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
  {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}
 
void modify(ll p,ll value) 
{
  for (t[p += n] = node(value); p >>= 1; ) 
  t[p] = combine(t[p<<1], t[p<<1|1]);
}
