#include <element.h>

int update_FPLT(UPDATE_FUNC_ARGS)
{
    int r, rx, ry;
    for(rx=-2; rx<3; rx++)
        for(ry=-2; ry<3; ry++)
        {
            //Absorption
            if(x+rx>=0 && y+ry>0 &&
                    (x+rx<XRES && y+ry<YRES && (rx || ry)) &&
                    (pmap[y+ry][x+rx]&0xFF)!=0xFF)
            {
                r = pmap[y+ry][x+rx];
                if((r>>8)>=NPART || !r)
                    continue;
                //Cooling Effect or Heating Effect
                if(rand()%100<1)
                {
                    if(parts[r>>8].temp < 303.15)
                        parts[r>>8].temp++;
                    else
                        parts[r>>8].temp--;
                }
                if(((r&0xFF)==PT_WATR || (r&0xFF)==PT_DSTW || (r&0xFF)==PT_SLTW)&& 1>(rand()%250))
                {
                    parts[i].type = PT_FPLT;
                    parts[r>>8].type = PT_FPLT;
                }
                else if ((r&0xFF)==PT_SMKE && 1>(rand()%250))
                {
                    delete_part(x + rx, y + ry);
                }
                else if((r&0xFF)==PT_LAVA && 1>(rand()%250))
                {
                    parts[i].life = 4;
                    parts[i].type = PT_FIRE;
                }
                //Cover Others
                else if(((r&0xFF)>0) && ((r&0xFF)<PT_NUM) && (1>(rand()%5)) &&
                        ((r&0xFF)!=PT_PLNT) &&
                        ((r&0xFF)!=PT_NEUT) &&
                        ((r&0xFF)!=PT_STKM) &&
                        ((r&0xFF)!=PT_FIRE) &&
                        ((r&0xFF)!=PT_SMKE) &&
                        ((r&0xFF)!=PT_PLSM) &&
                        ((r&0xFF)!=PT_LAVA) &&
                        ((r&0xFF)!=PT_FPLT) &&
                        ((r&0xFF)!=PT_DSTW) &&
                        ((r&0xFF)!=PT_WATR) &&
                        ((r&0xFF)!=PT_SLTW) &&
                        ((r&0xFF)!=PT_SOAP) &&
                        ((r&0xFF)!=PT_PROT))
                {
                    int n, o;
                    for(n = -1; n < 2; n++)
                    {
                        for(o = -1; o < 2; o++)
                        {
                            if(x+rx+o>=0 && y+ry+n>0 &&
                                    (x+rx+o<XRES && y+ry+n<YRES && (rx || ry)) &&
                                    (pmap[y+ry+n][x+rx+o]&0xFF)!=0xFF)
                            {
                                if(!(n == 0 && o == 0))
                                {
                                    create_part(-1, rx+x+o, ry+y+n, PT_FPLT);
                                }
                            }
                        }
                    }
                }
            }
        }
}
