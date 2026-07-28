#include<stdio.h>
int ob[10][10];
int vb[10][10];
int n;
int visi;
void setvisit(int x,int y)
{
//	int n=10;
//	printf("%d %d\n",x,y);
	if(vb[x][y]==0)
	{
		return;
	}
	if(ob[x][y]!=0)
	{
		vb[x][y]=0;
		visi++;
		return ;
	}
	else if(vb[x][y])
	{
		vb[x][y]=0;
		visi++;
		if(y+1 < n)
		{
			setvisit(x,y+1);
		}
		if(x+1 < n && y+1<n)
		{
			setvisit(x+1,y+1);
		}
		if(y-1 >= 0)
		{
			setvisit(x,y-1);	//2 1	
		}
		if(x-1 >= 0 && y-1 >= 0)
		{
			setvisit(x-1,y-1);	// 1 1	
		}
		if(x+1 < n)
		{
			setvisit(x+1,y);	//3 2	
		}
		if(x+1 <n && y-1 >=0)
		{
			setvisit(x+1,y-1);		//3 1	
		}
		if(x-1 >= 0)
		{
			setvisit(x-1,y);	//1 2	
		}
		if(x-1 >=0 && y+1 < n)
		{
			setvisit(x-1,y+1);	//1 3	
		}	
	}
}
int main()
{
	n=10;
	int notopen = 100;
	int totalflags = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			vb[i][j] = 1;
			ob[i][j] = 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		int bomb = rand();
		bomb = bomb%100;
		int x = bomb/10;
		int y = bomb%10;
		ob[x][y] = -1;
		if(y+1 < n)
		{
			if(ob[x][y+1]!= -1)
			{
				ob[x][y+1]++;
			}
				//2 3
		}
		if(x+1 < n && y+1<n)
		{
			if(ob[x+1][y+1] !=-1)
			{
				ob[x+1][y+1]++;	//3 3	
			}
		}
		if(y-1 >= 0)
		{
			if(ob[x][y-1]!=-1)
			{
				ob[x][y-1]++;	//2 1	
			}
		}
		if(x-1 >= 0 && y-1 >= 0)
		{
			if(ob[x-1][y-1] != -1)
			{
				ob[x-1][y-1]++;	// 1 1	
			}
		}
		if(x+1 < n)
		{
			if(ob[x+1][y] != -1)
			{
				ob[x+1][y]++;	//3 2	
			}
		}
		if(x+1 <n && y-1 >=0)
		{
			if(ob[x+1][y-1] != -1)
			{
				ob[x+1][y-1]++;		//3 1	
			}
		}
		if(x-1 >= 0)
		{
			if(ob[x-1][y] != -1)
			{
				ob[x-1][y]++;	//1 2	
			}
		}
		if(x-1 >=0 && y+1 < n)
		{
			if(ob[x-1][y+1] !=-1)
			{
				ob[x-1][y+1]++;	//1 3	
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%2d ",ob[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	int gameover = 0;
	while(!gameover && notopen!=n) //&& notopen==n
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i+1>=10 && j+1>=10)
				printf("%2d%2d ",i+1,j+1);
				else if(i+1>=10)
				printf("%2d%d ",i+1,j+1);
				else if(j+1>=10)
				printf("%2d%2d ",i+1,j+1);
				else
				printf("%2d%d ",i+1,j+1);
			}
			printf("\n");
		}
		printf("\n");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(vb[i][j]==1)
				{
					printf("* ");
				}
				else if(vb[i][j]==2)
				{
					printf("F ");
				}
				else
				{
					printf("%d ",ob[i][j]);
				}
			}
			printf("\n");
		}
		int open;
		int openx;
		int openy;
		int flag=0;
		printf("select 1 for open or 2 for flag ");
		scanf("%d",&flag);
		if(flag==1)
		{
			printf("select which * to be opened: ");
			scanf(" %d",&open);
			if(open<100)
			{
				openx = open/10;
				openy = open%10;
			}
			else if(open < 1000)
			{
				if(open%10 == 0)
				{
					openx = open/100;
					openy = open%100;
				}
				else
				{
					openx = open/10;
					openy = open%10;
				}
			}
			else
			{
				openx = open/100;
				openy = open%100;
			}
			openx--;
			openy--;
	//		printf("%d %d",openx,openy);
			if(ob[openx][openy]==-1)
			{
				gameover = 1;
			}
			else
			{
	//			printf("hii");
				if(vb[openx][openy]==2)
				{
					totalflags--;
					printf("flag had been removed and opened ");
					getch();
				}
				visi = 0;
				setvisit(openx,openy);
				notopen = notopen-visi;
	//			printf("hii");
			}
			printf("total unvisited = %d\n",notopen);
		}
		else
		{
			int select = 0;
			printf("Select 1-flag or 2-unflag");
			scanf("%d",&select);
			printf("select which * to be flaged/unflaged: ");
			scanf(" %d",&open);
			if(open<100)
			{
				openx = open/10;
				openy = open%10;
			}
			else if(open < 1000)
			{
				if(open%10 == 0)
				{
					openx = open/100;
					openy = open%100;
				}
				else
				{
					openx = open/10;
					openy = open%10;
				}
			}
			else
			{
				openx = open/100;
				openy = open%100;
			}
			openx--;
			openy--;
			if(totalflags > n)
			{
				printf("reached maximum flag limits so unflag to flag this\n");
				getch();
			}
			else
			{
				if(select==1)
				{
					if(vb[openx][openy])
					{
						vb[openx][openy] = 2;
						totalflags++;
					}
					else
					{
						printf("already opened can't be flaged\n");
						getch();
					}
				}
				else
				{
					if(vb[openx][openy]==2)
					{
						vb[openx][openy] = 1;
						totalflags--;
					}	
					else
					{
						printf("can't unflag the given tile choose correctly!!\n");
						getch();
					}
				}
			}	
		}	
//		gameover=1;
	}
	if(gameover)
	{
		printf("\nooopsi landed on mine");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(ob[i][j] == -1)
				{
					printf("-1 ");
				}
				else
				{
					printf("0 ");
				}
			}
			printf("\n");
		}
	}
	else
	{
		printf("\nCongratZzzZ champ you nailed it !!!");
	}
}
