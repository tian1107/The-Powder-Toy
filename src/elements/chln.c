#include <element.h>

int update_CHLN (UPDATE_FUNC_ARGS)
{
    int nx, ny, r;
    for(nx=-1; nx<1; nx++)
        for(ny=-1; ny<1; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_CHLN)
                {
                    if(((r&0xFF)==PT_WATR || (r&0xFF)==PT_DSTW || (r&0xFF)==PT_WTRV) && rand()%10<1)
                    {
                        delete_part(x, y);
                        parts[r>>8].type = PT_ACID; //H2O + CL2 -> 2HCl + 1/2 O2
                        parts[r>>8].life = 500; //Acidic Acid!
                        if(rand()%2 < 1)
                        {
                            create_part(-1, x+rand()%3-1, y+rand()%3-1, PT_O2);
                        }
                    }
                    else if(((r&0xFF)==PT_RBDM || (r&0xFF)==PT_LRBD) && rand()%10<1)
                    {
                        parts[r>>8].type = PT_SALT; //CL2 + Rb -> RbCL2
                        delete_part(x, y);
                    }
                    else if((r&0xFF)==PT_H2 && rand()%10<1)
                    {
                        parts[r>>8].type = PT_ACID; //H2 + CL2 -> 2HCL
                        parts[r>>8].life = 500; //Acidic Acid!
                        delete_part(x, y);
                    }
                }
            }
}
