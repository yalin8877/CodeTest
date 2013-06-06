//Õ·×ªÏà³ı·¨

int gcd(int v1,int v2)
{
	if(v1==0||v2==0)
		return 0;
	if(v1<0)
		v1=-v1;
	if(v2<0)
		v2=-v2;
	do
	{
		int modulo=v1%v2;
		v1=v2;
		v2=modulo;
	}
	while(v2);
	return v1;
}