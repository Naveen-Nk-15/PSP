#include<stdio.h>
int col;
int check(int a[][col],int r,int c)
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
			if(k && a[i][j]!=9)
			{
				cnt1++;
				k--;	
			}
//			else if(k==1 && a[i][j]==9) 
//			{
//				k--;
//			}
			else if(k==0)
			{
				k++;
			}
			if(q && a[i][j]!=9)
			{
				cnt2++;
				q--;
			}
//			else if(q==1 && a[i][j]==9)
//			{
//				q--;
//			}
			else if(q==0)
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
	col=c;
	int a[r][c];
	int n;
	printf("\n no of seats to be excluded:");
	scanf("%d",&n);
	int br[n];
	int y=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&br[i]);
		y=1;
		for(int x=0;x<r;x++)
		{
			if(x%2==0)
			{
				for(int j=0;j<c;j++)
				{
					if(a[x][j]!=9)
					{
						a[x][j]=0;	
					}
					if(y==br[i])
					{
//						printf("%d %d\n",x,j);
						a[x][j]=9;
					}
					y++;
//					printf("%d %d = %d ",x,j,a[x][j]);
				}
			}
			else
			{
				for(int j=c-1;j>=0;j--)
				{
					if(a[x][j]!=9)
					{
						a[x][j]=0;	
					}
//					printf("%d %d\n",x,j);
					if(y==br[i])
					{
						a[x][j]=9;
					}
					y++;
//					printf("%d %d = %d ",x,j,a[x][j]);
				}
			}
//			printf("\n");
		}
	}
	int prob=1;
	int k=check(a,r,c);
	if(k==2)
	{
		prob=2;
		k=1;
	}
	int no=0;
	for(int i=0;i<r;i++)
	{
		if(i!=0)
		{
			if(k)
			{
				k=0;
			}
			else
			{
				k=1;
			}
		}
		for(int j=0;j<c;j++)
		{
			if(a[i][j]!=9)
			{
				a[i][j]=k;
				if(k)
				{
					no++;
					k--;
				}
				else
				{
					k++;
				}
				
			}
			else
			{
				if(k==0)
				{
					k++;
				}
//				else
//				{
//					k++;
//				}
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
	printf("no of seats = %d",no);
}
