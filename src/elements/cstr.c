#include <element.h>

int update_CSTR(UPDATE_FUNC_ARGS)
{
    int nx, ny, r;
    int charge, dist;
    for(nx=-1; nx<1; nx++)
        for(ny=-1; ny<1; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xff) == PT_NSCN && parts[i].any2 == 1)
                {
                    parts[r>>8].type = PT_SPRK;
                    parts[r>>8].ctype = PT_NSCN;
                    parts[r>>8].life = 4;
                    parts[i].any--;
                }
                else if(parts[r>>8].type == PT_SPRK && parts[r>>8].ctype == PT_PSCN && parts[r>>8].life == 1)
                {
                    parts[r>>8].type = PT_PSCN;
                    parts[r>>8].ctype = PT_NONE;
                    parts[i].any++;
                }
                else if((r&0xff) == PT_CSTR)
                {
                    charge = parts[i].any + parts[r>>8].any;
                    if(charge % 2 == 0)
                    {
                        parts[i].any = charge/2;
                        parts[r>>8].any = charge/2;
                    }
                    else
                    {
                        dist = rand()%2;
                        switch(dist)
                        {
                        case 0:
                            parts[i].any = (charge+1)/2;
                            parts[r>>8].any = (charge-1)/2;
                            break;
                        case 1:
                            parts[i].any = (charge-1)/2;
                            parts[r>>8].any = (charge+1)/2;
                            break;
                        }
                    }
                }
                if(parts[i].any <= 0) parts[i].any2 = 0;
                else if(parts[i].any >= 5) parts[i].any2 = 1;
            }
}
