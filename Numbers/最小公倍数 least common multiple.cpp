unsigned LCM(unsigned x, unsigned y)
{
    if (x <= 0 || y <= 0)
        return -1;
    if (x == y)
        return x;
    if (x < y)
        return LCM(y, x);
    int d = x - y;
    int v = x;
    unsigned max = numeric_limits<unsigned>::max() - d;
    do
    {
		if (v % x == 0 && v % y == 0)
            return v;
        v += d;
    }while(v <= max);
    return 0;
}

unsigned LCM(unsigned x, unsigned y)
{
    if (x == y)
        return x;
    return x * y / GCD(x, y);
}