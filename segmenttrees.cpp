#include<bits/stdc++.h>
using namespace std;
struct segtree
{
	double seg[10000][3];// 0th column is for min,1 is for max, 2 is for sum.
public:
	 void build(int arr[],int idx,int low,int high)
	  {
			if(low==high)
			{
				for(int i=0;i<3;i++)
		       seg[idx][i]=arr[low];
		       return;
			}
			int mid=(low+high)/2;

			build(arr,2*idx+1,low,mid);

			build(arr,2*idx+2,mid+1,high);

		seg[idx][0]= min( seg[2*idx+1][0], seg[2*idx+2][0]);
		seg[idx][1]= max(seg[2*idx+1][1],seg[2*idx+2][1]);
		seg[idx][2] = seg[2*idx+1][2]+seg[2*idx+2][2];
	  }
     void update(int idx,int low,int high,int newidx,int newval)
     {
     	if(high < newidx || low>newidx)return;
     	if(low==high)
     	{
     		for(int i=0;i<3;i++)
     		seg[idx][i]=newval;
     		return;
     	}
     	int mid=(low+high)/2;
     	update(2*idx+1,low,mid,newidx,newval);
     	update(2*idx+2,mid+1,high,newidx,newval);
     	seg[idx][0] = min(seg[2*idx+1][0],seg[2*idx+2][0]);
     	seg[idx][1] = max(seg[2*idx+1][1],seg[2*idx+2][1]);
     	seg[idx][2] = (seg[2*idx+1][2]+seg[2*idx+2][2]);
     }
   double query(int type,int idx,int low,int high,int l,int r)
     {
		if(l<=low && high<=r)return seg[idx][type];
		else if(high<l || low>r) {
			if(type==0)return INT_MAX;
			else if(type==1)return INT_MIN;
			else return 0;
		}
	    else 
		{
		   int mid=(low+high)/2;
		   if(type==2)
		   return query(type,2*idx+1,low,mid,l,r)+query(type,2*idx+2,mid+1,high,l,r);
		   else if(type==0)
		   	return min(query(type,2*idx+1,low,mid,l,r),query(type,2*idx+2,mid+1,high,l,r));
           else 
            return max(query(type,2*idx+1,low,mid,l,r),query(type,2*idx+2,mid+1,high,l,r));
           		   
		}
     }
};

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	segtree s;
	s.build(arr,0,0,n-1);
	int q;cin >> q;
	for(int i=0;i<q;i++)
	{
		int qtype; cin >> qtype;
		if(qtype==0)
		{
			int idx,newval; cin >> idx >> newval;
			s.update(0,0,n-1,idx,newval);
			arr[idx]=newval;
		}
		else if (qtype==4)
		{
			int l,r; cin >> l >> r;
			cout << s.query(2,0,0,n-1,l,r)/(r-l+1) << endl;
		}
		else 
		{
			int l,r; cin >> l >> r;
			cout << s.query(qtype-1,0,0,n-1,l,r) << endl;
		}
	}
}