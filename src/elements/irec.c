#include <element.h>

int update_IREC(UPDATE_FUNC_ARGS)
{
    int nx, ny, r;
    for(nx=-1; nx<1; nx++)
        for(ny=-1; ny<1; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_IREC)
                {
                    if (parts[r>>8].type == PT_IWAVE)
                    {
                        parts[i].type = PT_SPRK;
                        parts[i].life = 9;
                        parts[i].ctype = PT_IREC;
                        break;
                    }
                }
            }
}
