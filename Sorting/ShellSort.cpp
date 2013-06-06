#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void swap(int *arr, int i, int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void ShellSort(int *arr, int n)
{
	for(int dim=n/2;dim>=1;dim/=2)
	{
		for(int j=dim;j<n;j++)
		{
			int value=arr[j];
			int m=j-dim;
			while(m>=0&&arr[m]>value)
			{
				arr[m+dim]=arr[m];
				m=m-dim;
			}
			arr[m+dim]=value;
		}
	}
}

int main()
{
    int temp;
    vector<int> input;
    input.clear();
    while(cin>>temp)
        input.push_back(temp);
    int *arr=(int*)malloc(sizeof(int)*input.size());
    for(int i=0;i<input.size();i++)
    {
        arr[i]=input[i];
    }
    
    ShellSort(arr,input.size());
    for(int i=0;i<input.size();i++)
        cout<<arr[i]<<" ";

    return 0;
}
