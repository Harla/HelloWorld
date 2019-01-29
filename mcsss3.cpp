#include<iostream>
using namespace std;
class maxsum
{
    private:

    public: 
    int divideNconquer(int n,int b[100],int beg,int end);

};
int maxsum::divideNconquer(int n,int b[100],int beg,int end)
{
	int ls,rs,rosum,losum,rsum,lsum,mid,msum,i;
	
	if(beg==end)
		{
			if(b[beg]<0)
			return 0;
			else
			return b[beg];
			
		}
		mid=(beg+end)/2;
		ls=divideNconquer(n,b,beg,mid);
		rs=divideNconquer(n,b,mid+1,end);
		lsum=0;
		rsum=0;
		rosum=0;
		losum=0;
		for(i=mid;i<n;i++)
		{
			rsum+=b[i];
			if(rsum>rosum)
			rosum=rsum;
		}
		
		for(i=mid-1;i>=beg;i--)
		{
			lsum+=b[i];
			if(lsum>losum)
			losum=lsum;
		
		}
		msum=losum+rosum;
		if(rs>=ls&&rs>=msum)
		return rs;
		else if(ls>=rs&&ls>=msum)
		return ls;
		else
		return msum;
}

int main()
{
    int a[100],i,n;
    maxsum m;
    cout<<"Enter the number of elements of array\n";
	cin>>n;
	cout<<"Enter the values of the array of father A/T/G/C\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
    }
    cout<<m.divideNconquer(n,a,0,n-1)<<"\n";
    return 0;
}