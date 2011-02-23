#include <element.h>

int update_PGLOW(UPDATE_FUNC_ARGS)
{
    int nx, ny, r;
    for(nx=-1; nx<1; nx++)
        for(ny=-1; ny<1; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_PGLW)
                {
                    if ((parts[r>>8].type == PT_DSTW || parts[r>>8].type == PT_WATR) && rand()%10<1)
                    {
                        delete_part(x+nx,y+ny);
                        delete_part(x,y);
                        create_part(-1, x, y, PT_GLOW);
                    }
                }
            }
}
