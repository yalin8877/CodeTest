#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void bubblesort(int *array, int n)
{
	bool changed=true;
    int pos=0;
    while(pos<n-1&&changed)
    {
        changed=false;
        for(int i=0;i<n-pos-1;i++)
        {
            if(array[i]>array[i+1])
            {
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                changed=true;
            }
        }
        ++pos;
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
    
    bubblesort(array,input.size());
    for(int i=0;i<input.size();i++)
        cout<<array[i]<<" ";

    return 0;
}
