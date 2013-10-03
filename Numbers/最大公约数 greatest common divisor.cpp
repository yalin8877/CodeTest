//Õ·×ªÏà³ý·¨

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

unsigned GCD(unsigned x, unsigned y)
{
    if (x == 0)
        return y;
    if (y == 0)
        return x;
    
    bool dx = x & 0x1;
    bool dy = y & 0x1;
    if (dx == 0 && dy == 0)
        return GCD(x >> 1, y >> 1) << 1;
    else if (dx == 0)
        return GCD(x >> 1, y);
    else if (dy == 0)
        return GCD(x, y >> 1);
    else
    {
        if (x < y)
        	return GCD(x, y - x);
        else
            return GCD(x - y, y);
    }
}

unsigned GCD(unsigned x, unsigned y)
{
    unsigned result = 1;
    do
    {
        if (x == y)
            break;
    	bool dx = x & 0x1;
    	bool dy = y & 0x1;
    	if (dx == 0 && dy == 0)
    	{
        	x >>= 1;
        	y >>= 1;
        	result <<= 1;
    	}
    	else if (dx == 0)
    	{
        	x >>= 1;
    	}
    	else if (dy == 0)
    	{
        	y >>= 1;
    	}
    	else
    	{
     	   	if (x < y)
     	   		y -= x;
    	    else
    	        x -= y;
    	}
    }while (x != 0 && y != 0);
    if (!x)
        return result *= y;
    else
        return result *= x;
}
