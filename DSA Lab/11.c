#include<stdio.h>
#include<stdlib.h>
int a[10][10],n,m,i,j,source,vis[10],visited[10],count=0;

void create()
{
	printf("Enter the no. of vertices of the digraph: ");
	scanf("%d",&n);
	printf("\nEnter the adj. matrix: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			visited[i]=0;
		}
	}
}

void bfs()
{
	int q[10],u,front=0,rear=-1;
	printf("\nEnter the source vertex: \n");
	scanf("%d",&source);
	q[++rear]=source;
	printf("\nReachable vertices are: ");
	while(front<=rear)
	{
		u=q[front++];
		for(i=1;i<=n;i++)
		{
			if(a[u][i]==1 && visited[i]==0)
			{
				q[++rear]=i;
				visited[i]=1;
				printf("%d\t",i);
			}
		}
	}
}

void dfs(int source)
{
	int v;
	vis[source]=1;
	for(v=1;v<=n;v++)
	{
		if(a[source][v]==1 && vis[v]==0)
		{
			count++;
			dfs(v);
		}
	}
}

void main()
{
	int ch;
	while(1)
	{
		printf("\n1.creat\n2.bfs\n3.Check graph connected  or not (dfs)\n4.exit\n");
		printf("enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();break;
			case 2:bfs();break;
			case 3:count=1;
					for(i=1;i<=n;i++)
						if(vis[i]==0)
							dfs(i);
	
					if(count==n)			
						printf("\nGraph is connected");					
					else
						printf("\nGraph is not connected");			
					break;
			case 4:exit(0);
		}
	}
}
