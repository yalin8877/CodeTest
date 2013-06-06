#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int selectMin(int *array, int low, int high)
{
	int MIN=array[low];
	while(++low<=high)
		if(MIN>array[low])
			MIN=array[low];
	return MIN;
}

void selectsort(int *array, int n)
{
	int sorted_pos=0;
	while(sorted_pos<n-1)
	{
		int selected_pos=selectMin(array,sorted_pos,n-1);
		if(selected_pos!=sorted_pos)
		{
			int temp=array[selected_pos];
			array[selected_pos]=array[sorted_pos];
			array[sorted_pos]=temp;
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
    int *array=(int*)malloc(sizeof(int)*input.size());
    for(int i=0;i<input.size();i++)
    {
        array[i]=input[i];
    }
    
    selectsort(array,input.size());
    for(int i=0;i<input.size();i++)
        cout<<array[i]<<" ";

    return 0;
}
