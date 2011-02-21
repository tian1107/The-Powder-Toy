#include <element.h>

int update_RREC(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
    for(rx=-24; rx<24; rx++)
    {
        for(ry=-24; ry<24; ry++)
        {
            if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_RREC)
                {
                    if (parts[r>>8].type == PT_WAVE && rx <= 3 && rx >= -3 && ry >= -3 && ry <= 3)
                    {
                        delete_part(x+rx, y+ry);
                        parts[i].type = PT_SPRK;
                        parts[i].life = 9;
                        parts[i].ctype = PT_RREC;
                        break;
                    }
                    else if(parts[r>>8].type == PT_EWAVE)
                    {
                        if(parts[parts[r>>8].any].tmp == parts[i].tmp || parts[i].tmp == 0 || parts[parts[r>>8].any].tmp == 0)
                        {
                            if(inbetween(i, parts[r>>8].any, PT_INTF) == -1)
                            {
                                parts[i].type = PT_SPRK;
                                parts[i].life = 9;
                                parts[i].ctype = PT_RREC;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
