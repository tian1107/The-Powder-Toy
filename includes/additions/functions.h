//Declarations
#if defined(_WIN32) && !defined(__GNUC__)
_inline int inrange(int i, int t, int range);
#else
inline int inrange(int i, int t, int range);
#endif

#if defined(_WIN32) && !defined(__GNUC__)
_inline int sqdistance(int i, int t);
#else
inline int sqdistance(int i, int t);
#endif

#if defined(_WIN32) && !defined(__GNUC__)
_inline int isbetween(int a, int b, int c);
#else
inline int isbetween(int a, int b, int c);
#endif

#if defined(_WIN32) && !defined(__GNUC__)
_inline int inbetween(int i, int j, int t);
#else
inline int inbetween(int i, int j, int t);
#endif

#if defined(_WIN32) && !defined(__GNUC__)
_inline int next_part(int j, int t);
#else
inline int next_part(int j, int t);
#endif

#if defined(_WIN32) && !defined(__GNUC__)
_inline void circle(int cx, int cy, int radius, int t);
#else
inline void circle(int cx, int cy, int radius, int t);
#endif

#if defined(_WIN32) && !defined(__GNUC__)
_inline void plot4points(int cx, int cy, int x, int y, int t, int r);
#else
inline void plot4points(int cx, int cy, int x, int y, int t, int r);
#endif

#if defined(_WIN32) && !defined(__GNUC__)
_inline void plot8points(int cx, int cy, int x, int y, int t, int r);
#else
inline void plot8points(int cx, int cy, int x, int y, int t, int r);
#endif

int inrange(int i, int t, int range)
{
    int j;
    int srange = range*range;
    for(j = 0; j < NPART; j++)
    {
        if(parts[j].type == t && sqdistance(i,j) <= srange)
        {
            return j;
        }
    }
    return -1;
}

int sqdistance(int i, int j)
{
    float result = pow((parts[j].x-parts[i].x),2)+pow((parts[j].y-parts[i].y),2);
    return result;
}

int next_part(int j, int t)
{
    int i;
    for(i=j + 1; i<NPART; i++)
    {
        if(parts[i].type==t&&!parts[i].life)
        {
            return i;
        }
    }
    return -1;
}

int inbetween(int i, int j, int t)
{
    int hx, hy, lx, ly;
    int intf = next_part(0, t);
    if(parts[i].x > parts[j].x)
    {
        hx = parts[i].x;
        lx = parts[j].x;
    }
    else
    {
        hx = parts[j].x;
        lx = parts[i].x;
    }
    if(parts[i].y > parts[j].y)
    {
        hy = parts[i].y;
        ly = parts[j].y;
    }
    else
    {
        hy = parts[j].y;
        ly = parts[i].y;
    }
    return -1;
}

int isbetween(int a, int b, int c)
{
    int epsilon = 150;
    int crossproduct = (parts[c].y - parts[a].y) * (parts[b].x - parts[a].x) - (parts[c].x - parts[a].x) * (parts[b].y - parts[a].y);
    int dotproduct = (parts[c].x - parts[a].x) * (parts[b].x - parts[a].x) + (parts[c].y - parts[a].y)*(parts[b].y - parts[a].y);
    int squaredlengthba = (parts[b].x - parts[a].x)*(parts[b].x - parts[a].x) + (parts[b].y - parts[a].y)*(parts[b].y - parts[a].y);
    if (abs(crossproduct) >= epsilon) return 0;
    if (dotproduct < 0) return 0;
    if (dotproduct > squaredlengthba) return 0;
    return 1;
    //return ((parts[b].x - parts[a].x)/(parts[b].y - parts[a].y) == (parts[c].x - parts[b].x)/(parts[c].y - parts[b].y));
}

//Copied mostly from wiki
// 'cx' and 'cy' denote the offset of the circle centre from the origin.
void circle(int cx, int cy, int radius, int t)
{
    int error = -radius;
    int x = radius;
    int y = 0;

    // The following while loop may altered to 'while (x > y)' for a
    // performance benefit, as long as a call to 'plot4points' follows
    // the body of the loop. This allows for the elimination of the
    // '(x != y') test in 'plot8points', providing a further benefit.
    //
    // For the sake of clarity, this is not shown here.
    while (x >= y)
    {
        plot8points(cx, cy, x, y, t, radius);

        error += y;
        ++y;
        error += y;

        // The following test may be implemented in assembly language in
        // most machines by testing the carry flag after adding 'y' to
        // the value of 'error' in the previous step, since 'error'
        // nominally has a negative value.
        if (error >= 0)
        {
            --x;
            error -= x;
            error -= x;
        }
    }
}

void plot8points(int cx, int cy, int x, int y, int t, int r)
{
    plot4points(cx, cy, x, y, t, r);
    if (x != y) plot4points(cx, cy, y, x, t, r);
}

// The '(x != 0 && y != 0)' test in the last line of this function
// may be omitted for a performance benefit if the radius of the
// circle is known to be non-zero.
void plot4points(int cx, int cy, int x, int y, int t, int r)
{
    int center = pmap[cy][cx]>>8;
    if(create_part(-1, cx+x, cy+y, t)!= -1)
    {
        parts[pmap[cy+y][cx+x]>>8].any = center;
        parts[pmap[cy+y][cx+x]>>8].any2 = r;
    }
    if (x != 0)
    {
        if(create_part(-1, cx-x, cy+y, t) != -1)
        {
            parts[pmap[cy+y][cx-x]>>8].any = center;
            parts[pmap[cy+y][cx-x]>>8].any2 = r;
        }
    }
    if (y != 0)
    {
        if(create_part(-1, cx+x, cy-y, t) != -1)
        {
            parts[pmap[cy-y][cx+x]>>8].any = center;
            parts[pmap[cy-y][cx+x]>>8].any2 = r;
        }
    }
    if (x != 0 && y != 0)
    {
        if(create_part(-1, cx-x, cy-y, t) != -1)
        {
            parts[pmap[cy-y][cx-x]>>8].any = center;
            parts[pmap[cy-y][cx-x]>>8].any2 = r;
        }
    }
}
