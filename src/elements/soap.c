#include <element.h>

int update_SOAP(UPDATE_FUNC_ARGS)
{
    int r, rx, ry;
    for(rx=-1; rx<1; rx++)
        for(ry=-1; ry<1; ry++)
            if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_SOAP)
                {
                    if (parts[r>>8].type == PT_ACID)
                    {
                        delete_part(x+rx,y+ry);
                        delete_part(x,y);
                        create_part(-1, x, y, PT_WATR);
                    }
                    else if((parts[r>>8].type == PT_WATR)&& rand()% 50 > 1)
                    {
                        parts[r>>8].type = PT_SOAP;
                    }
                    else if((parts[r>>8].type == PT_SLTW) && rand()% 50 > 1)
                    {
                        parts[r>>8].type = PT_SOAP;
                        create_part(-1, parts[i].x + rand()%5-2, parts[i].y + rand()%5-2, PT_SALT);
                    }
                    else if(parts[r>>8].type == PT_DSTW && rand()% 50 > 1)
                    {
                        parts[r>>8].type = PT_SOAP;
                    }
                    else if(((ptypes[parts[r>>8].type].menusection == SC_LIQUID) || (ptypes[parts[r>>8].type].menusection == SC_GAS) || (ptypes[parts[r>>8].type].menusection == SC_POWDERS) || ((ptypes[parts[r>>8].type].menusection == SC_EXPLOSIVE) && parts[r>>8].type != PT_PLEX && parts[r>>8].type != PT_RBDM) || parts[r>>8].type == PT_URAN || parts[r>>8].type == PT_PLUT)&& (rand()%100<1))
                    {
                        delete_part(x+rx,y+ry);
                        delete_part(x,y);
                    }
                }
            }
}
