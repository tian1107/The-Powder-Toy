#include <element.h>

int update_EXPL(UPDATE_FUNC_ARGS)
{
    int nx, ny, r;
    if(abs(pv[y/CELL][x/CELL]) > 0.5 && rand()%10 < 1)
        create_part(-1, x + (rand()%5) -2, y + (rand()%5) -2, PT_PLSM);
    for(nx=-5; nx<5; nx++)
        for(ny=-5; ny<5; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if(((r&0xFF)==PT_FIRE || (r&0xFF)==PT_PLSM) && parts[i].temp != R_TEMP)
                {
                    pv[y/CELL][x/CELL] = 500.0f;
                    parts[i].temp = MAX_TEMP;
                    parts[r>>8].temp = MAX_TEMP;
                }
            }
}
