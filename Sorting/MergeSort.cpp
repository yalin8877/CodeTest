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

void Merge(int *src_arr, int *dst_arr, int s1, int e1, int s2, int e2)
{
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

void MergeSort(int *&arr, int n)
{
	int *arr2=(int*)malloc(sizeof(int)*n);
	int *src_arr=arr;
	int *dst_arr=arr2;

	for(int interv=1;interv<n;interv*=2)
	{
		//cout<<"interval: "<<interv<<endl;
		for(int s1=0;s1<n;s1+=2*interv)
		{
			int e1=(s1+interv-1<n?(s1+interv-1):(n-1));
			int s2=e1+1;
			int e2=(s2+interv-1<n?(s2+interv-1):(n-1));
			Merge(src_arr, dst_arr, s1, e1 , s2, e2);
		}

		/*for(int i=0;i<n;i++)
		{
			cout<<dst_arr[i]<<" ";
		}
		cout<<endl;*/

		int *temp=src_arr;
		src_arr=dst_arr;
		dst_arr=temp;
	}

	arr=src_arr;
	delete dst_arr;
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
    
    MergeSort(arr,input.size());
    for(int i=0;i<input.size();i++)
        cout<<arr[i]<<" ";

    return 0;
}
