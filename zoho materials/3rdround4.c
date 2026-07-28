#include<stdio.h>
int col;
int check(int a[][col],int r,int c,int pathcol)
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
			if(j!=pathcol)
			{
				if(k && a[i][j]!=9)
				{
					cnt1++;
					k--;	
				}
				else if(k==1 && a[i][j]==9) 
				{
					k--;
				}
				else
				{
					k++;
				}
				if(q && a[i][j]!=9)
				{
					cnt2++;
					q--;
				}
				else if(q==1 && a[i][j]==9)
				{
					q--;
				}
				else
				{
					q++;
				}
			}
			else
			{
				if(k==0 && i%2==0)
				{
					k++;
				}
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
	col=c+1;
	int a[r+1][c+1];
	c++;//include vertical asle
	r++;
	int n;
	int pathcol;
	int pathrow;
	printf("\n no of seats to be excluded:");
	scanf("%d",&n);
	int br[n];
	int y=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&br[i]);
	}
	printf("\n include vertical asile after:");
	scanf("%d",&pathcol);
	printf("\n include horizontal asile after:");
	scanf("%d",&pathrow);
//	printf("%d",pathcol);
	for(int i=0;i<r;i++)
	{
		a[i][pathcol] = 2;
	}
	for(int i=0;i<c;i++)
	{
		a[pathrow][i] = 2;
	}
	for(int i=0;i<n;i++)
	{
		y=1;
		for(int x=0;x<r;x++)
		{
			
			if(x%2==0)
			{
				for(int j=0;j<c;j++)
				{
					if(j==pathcol || x==pathrow)
					{
						a[x][j] = 2;
					}
					else
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
			}
			else
			{
				for(int j=c-1;j>=0;j--)
				{
					if(j==pathcol || x==pathrow)
					{
						a[x][j] = 2;
					}
					else
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
			}
//			printf("\n");
		}
	}
	int prob=1;
	int k=check(a,r,c,pathcol);
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
			if(j!=pathcol && i!=pathrow)
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
			else
			{
					if(k==0 && i%2==0)
					{
						k++;
					}
					else if(k==1 && i%2==1)
					{
						k--;
					}
			}
		}
	}
//	for(int i=0;i<r;i++)
//	{
//		for(int j=0;j<c;j++)
//		{
//			int f=0;
//			if(a[i][j]==0)
//			{
//				if(a[i][j+1] >c && a[i][j+1] == 9 || a[i][j+1] == 0) && (a[i][j-1] <0 && a[i][j-1] == 9 || a[i][j-1] == 0) && (a[i+1][j] <r && a[i+1][j] == 9 || a[i+1][j] == 0) && (a[i-1][j] >0 && a[i-1][j] == 9 || a[i-1][j] == 0) && (a[i-1][j] >0 && a[i-1][j] == 9 || a[i-1][j] == 0)
//			}
//		}
//	}
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
