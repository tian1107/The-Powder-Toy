#include <element.h>

int update_MERC(UPDATE_FUNC_ARGS)
{
    int nx, ny, r;
    for(nx=-1; nx<1; nx++)
        for(ny=-1; ny<1; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_MERC)
                {
                    if(parts[r>>8].type == PT_METL)
                        parts[r>>8].type = PT_MERC;
                    if(ptypes[(r&0xFF)].properties&PROP_LIFE){
                        kill_part(r>>8);
                    }
                }
                else
                {
                    parts[r>>8].temp = parts[i].temp;
                    if(parts[i].any > ((int)(parts[i].temp/200.0)))
                    {
                        kill_part(r>>8);
                        parts[i].any--;
                    }
                }

                if(parts[i].any < ((int)(parts[i].temp/200.0)))
                {
                    int rx = rand()%3-1, ry = rand()%3-1;
                    int rp = pmap[y+ry][x+rx];
                    if(create_part(-1, x+rx, y+ry, PT_MERC) != -1)
                    {
                        parts[rp>>8].temp = parts[i].temp;
                        parts[rp>>8].any = parts[i].any + 1;
                        parts[i].any++;
                    }
                }
            }
}
