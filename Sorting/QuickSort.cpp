#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void quicksort(int *arr, int low, int high)
{
   if(low>=high)   
       return;
   int pivot=arr[low];
   int bklow=low;
   int bkhigh=high;
   while(low<high)
    {
       while(low<high&&arr[high]>=pivot)
           --high;
       arr[low]=arr[high];
       while(low<high&&arr[low]<=pivot)
           ++low;
       arr[high]=arr[low];
    }
   arr[low]=pivot;
   //以上部分也可单独写个partition函数，返回low值作为下面递归的参数
   quicksort(arr,bklow,low-1);
   quicksort(arr,low+1,bkhigh);  
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
    
    quicksort(array,0,input.size()-1);
    for(int i=0;i<input.size();i++)
        cout<<array[i]<<" ";

    return 0;
}
