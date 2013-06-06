#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int selectMin(int *arr, int low, int high)
{
	int MIN=arr[low];
	int pos=low;
	while(++low<=high)
		if(MIN>arr[low])
		{
			MIN=arr[low];
			pos=low;
		}
	return pos;
}

void selectsort(int *arr, int n)
{
	int sorted_pos=0;
	while(sorted_pos<n-1)
	{
		int selected_pos=selectMin(arr,sorted_pos,n-1);
		//cout<<sorted_pos<<":	"<<arr[selected_pos]<<endl;
		if(selected_pos!=sorted_pos)
		{
			int temp=arr[selected_pos];
			arr[selected_pos]=arr[sorted_pos];
			arr[sorted_pos]=temp;
		}
		++sorted_pos;
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
    
    selectsort(arr,input.size());
    for(int i=0;i<input.size();i++)
        cout<<arr[i]<<" ";

    return 0;
}
