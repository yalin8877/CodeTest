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

void InsertSort(int *arr, int n)
{
	for(int i=1;i<n;i++)
	{
		int value=arr[i];
		int j=i;
		while(--j>=0&&arr[j]>value)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=value;
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
    
    InsertSort(arr,input.size());
    for(int i=0;i<input.size();i++)
        cout<<arr[i]<<" ";

    return 0;
}
