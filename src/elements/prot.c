#include <element.h>

int update_PROT(UPDATE_FUNC_ARGS)
{
    int r, nx, ny;
    for(nx=-3; nx<3; nx++)
        for(ny=-3; ny<3; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_PROT && rand()%20 < 1)
                {
                    if (parts[r>>8].type == PT_NEUT)
                    {
                        delete_part(x+nx,y+ny);
                    }
                    else if(rand()%30 < 1)
                    {
                        if(parts[r>>8].type != PT_PROT && parts[r>>8].type != PT_CLNE && parts[r>>8].type < PT_NUM-1)
                        {
                            int type = parts[r>>8].type + 1;
                            delete_part(x+nx, y+ny);
                            if(type == PT_CLNE) type++; //Skip clone
                            if(type == PT_NEUT) type++; //Skip neutrons
                            if(type == PT_PROT) type++; //Skip protons
                            if(type == PT_EWAVE) type++; //Skip Electronic Waves
                            if(type >= PT_NUM)
                            {
                                type = PT_NUM-1;
                                if(type == PT_EWAVE)
                                {
                                    type = PT_NUM-2;
                                }
                            }
                            create_part(-1, x+nx, y+ny, type);
                            delete_part(x,y);
                        }
                    }
                }

            }
}
