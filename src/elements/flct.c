#include <element.h>

int update_FLCT(UPDATE_FUNC_ARGS)
{
    int r, rx, ry;
    for(rx=-1; rx<1; rx++)
        for(ry=-1; ry<1; ry++)
            if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_FLCT)
                {
                    if (parts[r>>8].type == PT_NBLE && parts[i].any2 > parts[r>>8].any2 && parts[i].life > 40)
                    {
                        parts[r>>8].life = rand()%150+50;
                        part_change_type(r>>8,x+rx,y+ry,PT_FLCT);
                        parts[i].temp = 0;
                        parts[r>>8].any2 = parts[i].any2;
                    }
                }
            }
    if(parts[i].life < 2)
    {
        parts[i].type = PT_NBLE;
        parts[i].ctype = PT_NONE;
        parts[i].life = 0;
    }
}
