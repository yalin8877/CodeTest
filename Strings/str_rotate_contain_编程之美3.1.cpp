#include<iostream>
#include<string.h>
using namespace std;

bool rotate_contain(const char *s1,const char *s2)
{
    int len1=strlen(s1);
    int len2=strlen(s2);
    if(len1<len2)
        return false;

    for(int pos1=0;pos1<len1;++pos1)
    {
        int temp1=pos1;
        int temp2=0;
        while(temp2<len2&&s1[temp1%len1]==s2[temp2])
        {
            ++temp1;
            ++temp2;
        }
        if(temp2==len2)
            return true;
    }    
    return false;
}

int main()
{
    string s1;
    string s2;
    while(cin>>s1>>s2)
        cout<<rotate_contain(s1.c_str(),s2.c_str())<<endl;

}
