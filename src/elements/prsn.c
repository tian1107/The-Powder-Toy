#include <element.h>

int update_PRSN(UPDATE_FUNC_ARGS)
{
    parts[i].life++;
    if(parts[i].life > 100)
        parts[i].life = 100;
    int nx, ny, r;
    for(nx=-3; nx<3; nx++)
        for(ny=-13; ny<0; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r&0xff) == 0xff || (r&0xff) != 0)
                {
                    if ((r&0xFF)==PT_ACID)  //If on acid
                        parts[i].life -= 5;

                    if ((r&0xFF)==PT_PLUT)  //If on plut
                        parts[i].life -= 1;

                    if((r&0xFF)==PT_SPRK && r && (r>>8)<NPART)  //If on charge
                    {
                        parts[i].life -= (int)(rand()/1000)+38;
                    }

                    if(r>0 && (r>>8)<NPART)  //If hot or cold
                    {
                        if(parts[r>>8].temp>=323 || parts[r>>8].temp<=243)
                        {
                            parts[i].life -= 2;

                        }
                    }

                    if ((r&0xFF)==PT_CHLN)  //If on chlorine
                        parts[i].life -= 2;

                    if(parts[i].life <= 0)
                    {
                        create_part(-1, x-2, y - 2, parts[i].any);
                        create_part(-1, x-1, y - 2, parts[i].any);
                        create_part(-1, x  , y - 2, parts[i].any);
                        create_part(-1, x+1, y - 2, parts[i].any);
                        create_part(-1, x+2, y - 2, parts[i].any);
                        create_part(-1, x-2, y + 2, parts[i].any);
                        create_part(-1, x-1, y + 2, parts[i].any);
                        create_part(-1, x  , y + 2, parts[i].any);
                        create_part(-1, x+1, y + 2, parts[i].any);
                        create_part(-1, x+2, y + 2, parts[i].any);
                        create_part(-1, x-2, y - 1, parts[i].any);
                        create_part(-1, x-2, y    , parts[i].any);
                        create_part(-1, x-2, y + 1, parts[i].any);
                        create_part(-1, x+2, y - 1, parts[i].any);
                        create_part(-1, x+2, y    , parts[i].any);
                        create_part(-1, x+2, y + 1, parts[i].any);
                        kill_part(i);
                    }
                }
            }
}
