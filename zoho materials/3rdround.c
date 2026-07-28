#include<stdio.h>
int check(int r,int c)
{
	int k=1,q=0;
	int start1 = 0;
	int cnt1=0;
	int cnt2=0;
	for(int i=0;i<r;i++)
	{
		if(i%2==0)
		{
			k=1,q=0;
		}
		else
		{
			q=1;k=0;
		}
		for(int j=0;j<c;j++)
		{
			if(k)
			{
				cnt1++;
				k--;	
			}
			else
			{
				k++;
			}
			if(q)
			{
				cnt2++;
				q--;
			}
			else
			{
				q++;
			}	
		}
	}
	if(cnt1==cnt2)
	{
		return 2;
	}
	if(cnt1>cnt2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int r;
	int c;
	scanf("%d %d",&r,&c);
	int a[r][c];
	int prob;
	int k=check(r,c);
	if(k==2)
	{
		prob=2;
		k=1;
	}
	for(int i=0;i<r;i++)
	{
		if(i!=0)
		{
			if(i%2==0)
			{
				k=1;
			}
			else
			{
				k=0;
			}
		}
		for(int j=0;j<c;j++)
		{
			a[i][j]=k;
			if(k)
			{
				k--;
			}
			else
			{
				k++;
			}
		}
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("%d",prob);
}
