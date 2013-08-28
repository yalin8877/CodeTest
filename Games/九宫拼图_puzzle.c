#include"iostream"
#include<vector>
using namespace std;

struct node{
	int nodesun[4][4];
	int pre;
	int x,y;
}path[3000];

int zx[4]={-1,0,1,0};
int zy[4]={0,-1,0,1};
int front,rear;
int desti[4][4]={0,0,0,0,0,1,2,3,0,4,5,6,0,7,8,0};

int detect(struct node *p)
{	
	int i,j;
	for(i=1;i<4;i++)
		for(j=1;j<4;j++)
			if(p->nodesun[i][j]!=desti[i][j])
				return 0;
	return 1;
}

void printlj()
{
	vector<int> vec;
	vec.clear();

	int tempt=rear;
	while(tempt!=0)
	{    
		vec.push_back(tempt);
		tempt=path[tempt].pre;
	}
	for(int m=vec.size()-1;m>=0;m--)
	{
		tempt=vec[m];
		for(int i=1;i<4;i++)
			for(int j=1;j<4;j++)
			{
				cout<<path[tempt].nodesun[i][j]<<" ";
			}
		cout<<endl;
	}
}

int main()
{ 
	int i,j,m,n,f;
	int temp,find=0;
	front=rear=1;
	path[1].pre=0; 
	for(i=1;i<4;i++)
	{
		for(j=1;j<4;j++)
		{
			cin>>temp;
			path[1].nodesun[i][j]=temp;
			if(temp==0)
			{
				path[1].x=i;
				path[1].y=j;
			}
		}
	}
	
	while(front<=rear&&!find)
	{ 
		m=path[front].x;
		n=path[front].y ;
		for(f=0;f<4;f++)
		{
			i=m+zx[f];
			j=n+zy[f];
			if(i>=1&&i<=3&&j>=1&&j<=3)
			{
				rear++;
				path[rear]=path[front];
				path[rear].nodesun[m][n]=path[front].nodesun[i][j];
				path[rear].nodesun[i][j]=0;
				path[rear].pre=front;
				path[rear].x=i;
				path[rear].y=j;

				if(detect(&path[rear]))
				{
					printlj();
					find=1;
					break;
				}
			}
		}
		front++;
	}
	return 0;
}
