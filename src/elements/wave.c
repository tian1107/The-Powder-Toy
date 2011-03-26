#include <element.h>

int update_EWAVE(UPDATE_FUNC_ARGS)
{
    int cy = (int)(parts[parts[i].any].y + 0.5f);
    int cx = (int)(parts[parts[i].any].x + 0.5f);
    if(parts[i].life == 1)
        circle(cx, cy, parts[i].any2 + 50,PT_EWAVE);
}

int update_HWAV(UPDATE_FUNC_ARGS)
{
    int nx, ny, r;
    for(nx=-1; nx<1; nx++)
        for(ny=-1; ny<1; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_HWAV && (r&0xFF)!=PT_INSL)
                {
                    parts[i].temp+=10;
                }
            }
}
