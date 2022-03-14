ll a[200005],seg[200005],lazy[200005];
void build(ll ind, ll low, ll high)
{
  if(low==high)
  {
    seg[ind]=a[low];
    return;
  }
  int mid=(low+high)>>1;
  build(2*ind+1,low,mid);
  build(2*ind+2,mid+1,high);

  seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
void update(ll ind, ll low, ll high, ll l, ll r, ll val){
  //whenever you reach a segment tree node,
  //1st check if any previous update is pending or not
  //if a update is pending , do that update and then decide for the current node 
  if(lazy[ind]!=0)
  {
    seg[ind]+=((high-low+1)*lazy[ind]);
    //propagate down words , if children exist
    if(low!=high){
      lazy[2*ind+1]+=lazy[ind];
      lazy[2*ind+2]+=lazy[ind];
    }
    lazy[ind]=0;
  }


  //No overlap
  if(l>high or r<low)return ;

  //Complete overlap
  if(low>=l and high<=r){
    //do the update
    seg[ind]+=(val*(high-low+1));
    if(low!=high)
    {
      lazy[2*ind+1]+=val;
      lazy[2*ind+2]+=val;
    }
    return;
  }


  //Partial Overlap

   ll mid=(low+high)>>1;
   update(2*ind+1,low,mid,l,r,val);
   update(2*ind+1,mid+1,high,l,r,val);


   seg[ind]=seg[2*ind+1]+ seg[2*ind+2];
}


ll range_sum(ll ind, ll low, ll high, ll l, ll r)
{
  if(lazy[ind]!=0)
  {
    seg[ind]+=((high-low+1)*lazy[ind]);
    //propagate down words , if children exist
    if(low!=high){
      lazy[2*ind+1]+=lazy[ind];
      lazy[2*ind+2]+=lazy[ind];
    }
    lazy[ind]=0;
  }
  //No overlap
  if(l>high or r<low)return 0;
  //Complete Overlap
  if(low>=l and high<=r)return seg[ind];
  //Partial Overlap
  ll mid=(low+high)>>1;
  ll left=range_sum(ind*2+1,low,mid,l,r);
  ll right=range_sum(ind*2+2,mid+1,high,l,r);

  return left+right;
}
