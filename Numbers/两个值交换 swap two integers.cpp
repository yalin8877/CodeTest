void swap1(int &v1,int &v2)    //v1+v2可能导致溢出
{
	if(v1==v2)
		return;
	v1=v1+v2;
	v2=v1-v2;
	v1=v1-v2;
	return;
}

void swap2(int &v1,int &v2)
{
	if(v1==v2)
		return;
	v1=v1^v2;
	v2=v1^v2;
	v1=v1^v2;
	return;
}