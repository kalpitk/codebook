struct fenTree{
	ll tree[N],maxm;
	void construct(ll low,ll high,ll pos) {	
		rep(i,1,N+1) update(i,a[i]); 
	}
	void update(ll i,ll value) {
		for(;i<=N;i+=(i&-i))
			tree[i]=max(tree[i],value);
	}
	void update(ll x,ll y,ll val) {
		update(x,val),update(y+1,-val);
	}
	void findarrval(ll x) {
		for(sum=0;i>0;i-=(i&-i))
			sum+=tree[i];
		return sum+a[b];
	}
	ll query(ll i) {
		for(maxm=0;i>0;i-=(i&-i))
			maxm=max(maxm,tree[i]);
		return maxm;
	}
	ll query(ll x,ll y) {
		return query(y)-query(x-1);
	}
}
