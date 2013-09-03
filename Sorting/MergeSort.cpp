#include<iostream>
#include<vector>
#include<cstring>
#include<malloc.h>
using namespace std;

void swap(int *& p1, int *& p2)
{
	int * temp = p1;
	p1 = p2;
	p2 = temp;
	temp = NULL;
}

void Merge(int *src_arr, int *dst_arr, int s1, int e1, int s2, int e2)
{
	if (!src_arr || !dst_arr)
		return;
	int sorted_pos=s1;
	while(s1<=e1&&s2<=e2)
	{
		if(src_arr[s1]<=src_arr[s2])
			dst_arr[sorted_pos++]=src_arr[s1++];
		else
			dst_arr[sorted_pos++]=src_arr[s2++];
	}
	if(s1>e1)
		while(s2<=e2)
			dst_arr[sorted_pos++]=src_arr[s2++];
	else
		while(s1<=e1)
			dst_arr[sorted_pos++]=src_arr[s1++];
}

void MergeSort(int *&arr, int n)//change the original array
{
	int *arr2=(int*)malloc(sizeof(int)*n);
	int *src_arr=arr;
	int *dst_arr=arr2;

	for(int interv=1;interv<n;interv*=2)
	{
		for(int s1=0;s1<n;s1+=2*interv)
		{
			int e1=(s1+interv-1<n?(s1+interv-1):(n-1));
			int s2=e1+1;
			int e2=(s2+interv-1<n?(s2+interv-1):(n-1));
			Merge(src_arr, dst_arr, s1, e1 , s2, e2);
		}
		int *temp=src_arr;
		src_arr=dst_arr;
		dst_arr=temp;
	}

	arr=src_arr;
	delete dst_arr;
}
void MergeSort(int *arr, int n, int *&sorted)//not change the original array
{
	if (!arr || n<=1)
		return;
	int totalSize = sizeof(int)*n;
	sorted=(int*)malloc(totalSize);
	int *unsorted=(int*)malloc(totalSize);
	memcpy(unsorted, arr, totalSize);

	for(int interv = 1; interv < n; interv <<= 1)
	{
		for(int s1 = 0; s1 < n; s1 += interv << 1)
		{
			int s2=s1+interv;
			int e1=(s2-1<n?(s2-1):(n-1));
			int e2=(s2+interv-1<n?(s2+interv-1):(n-1));
			Merge(unsorted, sorted, s1, e1 , s2, e2);
		}
		swap(sorted,unsorted);
	}
	swap(sorted,unsorted);
	delete unsorted;
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
    int * sorted = NULL;
	//MergeSort(arr, input.size());
    MergeSort(arr,input.size(),sorted);
	for(int i=0;i<input.size();i++)
        cout<<arr[i]<<" ";
	cout << endl;
    for(int i=0;i<input.size();i++)
        cout<<sorted[i]<<" ";

    return 0;
}

