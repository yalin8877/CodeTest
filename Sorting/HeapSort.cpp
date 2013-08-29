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

void ShiftDown_Recursive(int *arr, int i, int n)
{
	int left=2*i+1;
	int right=2*i+2;

	if(left>n-1)
		return;
	int max = i;
	if(arr[left]>arr[max])
		max = left;
	if(right<n && arr[right]>arr[max])
		max = right;
	if(i != max)
	{
		swap(arr, i, max);
		ShiftDown_Recursive(arr,max,n);
	}
}

void ShiftDown(int *arr, int i, int n)
{
	int left=2*i+1;
	int right=2*i+2;
	int max=i;
	while(left<n)
	{
		if(arr[left] > arr[max])
			max=left;
		if(right<n && arr[right]>arr[max])
			max=right;
		if(i != max)
		{
			swap(arr,i,max);
			i=max;
			left=2*i+1;
			right=2*i+2;
		}
		else
			return;
	}
}

void HeapSort(int *arr, int n)
{
	//Build Heap
	int last_nleaf=n/2-1;
	for(int i=last_nleaf;i>=0;--i)
		ShiftDown_Recursive(arr,i,n);
	
	for(int last_sorted=n-1;last_sorted>0;--last_sorted)
	{
		swap(arr,last_sorted,0);
		ShiftDown_Recursive(arr,0,last_sorted);//如写成 ShiftDown(arr,0,last_sorted); 就会得到倒序排列，但只是个trick，不应通过此方法来得到倒序，效率问题，自己体会一下～
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
    
    HeapSort(arr,input.size());
    for(int i=0;i<input.size();i++)
        cout<<arr[i]<<" ";

    return 0;
}
