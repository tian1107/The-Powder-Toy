#include <element.h>

int update_TUNN(UPDATE_FUNC_ARGS)
{
    /*int nx, ny, r;
    int ceiling = PT_WOOD;
    int ceiling2 = PT_IRON;

    if(parts[i].vx > 0)
    {
        r = pmap[y][x+1];
        if((r>>8)>=NPART || !r)
            return;
        if((r&0xFF) != 0xFF && (r&0xFF) != PT_TUNN && (r&0xFF) != PT_DMND && ((ptypes[r&0xFF].properties&TYPE_SOLID) || (ptypes[r&0xFF].properties&TYPE_PART)))
        {
            if ((pmap[y-1][x+1]&0xFF) != PT_TUNN && (pmap[y-1][x+1]&0xFF) != PT_DMND && ((ptypes[pmap[y-1][x+1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-1][x+1]&0xFF].properties&TYPE_PART)))
            {
                delete_part(x+1, y-1);
                if((pmap[y-1][x]&0xFF) == ceiling)
                    create_part(-1, x+1, y-1, ceiling2);
                else
                    create_part(-1, x+1, y-1, ceiling);
            }
            if ((pmap[y-1][x+2]&0xFF) != PT_TUNN && (pmap[y-1][x+2]&0xFF) != PT_DMND && ((ptypes[pmap[y-1][x+2]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-1][x+2]&0xFF].properties&TYPE_PART)))
            {
                delete_part(x+2, y-1);
                if((pmap[y-1][x+1]&0xFF) == ceiling)
                    create_part(-1, x+2, y-1, ceiling2);
                else
                    create_part(-1, x+2, y-1, ceiling);
            }
            kill_part(r>>8);
            kill_part(i);
        }
    }

    else if(parts[i].vx < 0)
    {
        r = pmap[y][x-1];
        if((r>>8)>=NPART || !r)
            return;
        if((r&0xFF) != 0xFF && (r&0xFF) != PT_TUNN && (r&0xFF) != PT_DMND && ((ptypes[r&0xFF].properties&TYPE_SOLID) || (ptypes[r&0xFF].properties&TYPE_PART)))
        {
            if ((pmap[y-1][x-1]&0xFF) != PT_TUNN && (pmap[y-1][x-1]&0xFF) != PT_DMND && ((ptypes[pmap[y-1][x-1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-1][x-1]&0xFF].properties&TYPE_PART)))
            {
                delete_part(x-1, y-1);
                if((pmap[y-1][x]&0xFF) == ceiling)
                    create_part(-1, x-1, y-1, ceiling2);
                else
                    create_part(-1, x-1, y-1, ceiling);
            }
            if ((pmap[y-1][x-2]&0xFF) != PT_TUNN && (pmap[y-1][x-2]&0xFF) != PT_DMND && ((ptypes[pmap[y-1][x-2]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-1][x-2]&0xFF].properties&TYPE_PART)))
            {
                delete_part(x-2, y-1);
                if((pmap[y-1][x+1]&0xFF) == ceiling)
                    create_part(-1, x-2, y-1, ceiling2);
                else
                    create_part(-1, x-2, y-1, ceiling);
            }
            kill_part(r>>8);
            kill_part(i);
        }
    }*/
}

int update_VTNN(UPDATE_FUNC_ARGS)
{
    /*int nx, ny, r;
    int ceiling = PT_IRON;
    int ceiling2 = PT_BMTL;
    if(parts[i].vy > 0)
    {
        if(y+1 > YRES)
            return;
        r = pmap[y+1][x];
        if((r>>8)>=NPART || !r)
            return;
        if((r&0xFF) != 0xFF && (r&0xFF) != PT_VTNN && (r&0xFF) != PT_DMND && ((ptypes[r&0xFF].properties&TYPE_SOLID) || (ptypes[r&0xFF].properties&TYPE_PART)))
        {
            if ((pmap[y+1][x-1]&0xFF) != PT_VTNN && (pmap[y+1][x-1]&0xFF) != PT_DMND && ((ptypes[pmap[y+1][x-1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y+1][x-1]&0xFF].properties&TYPE_PART)))
            {
                if((pmap[y][x-1]&0xFF) == ceiling)
                    parts[pmap[y+1][x-1]>>8].type = ceiling2;
                else
                    parts[pmap[y+1][x-1]>>8].type = ceiling;
            }
            if ((pmap[y+1][x+1]&0xFF) != PT_VTNN && (pmap[y+1][x+1]&0xFF) != PT_DMND && ((ptypes[pmap[y+1][x+1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y+1][x+1]&0xFF].properties&TYPE_PART)))
            {
                if((pmap[y][x+1]&0xFF) == ceiling)
                    parts[pmap[y+1][x+1]>>8].type = ceiling2;
                else
                    parts[pmap[y+1][x+1]>>8].type = ceiling;
            }
            kill_part(r>>8);
            kill_part(i);
        }
    }
    else
    {
        if(y-1 <= 0)
            kill_part(i);
        r = pmap[y-1][x];
        if((r>>8)>=NPART || !r)
            return;
        if((r&0xFF) != 0xFF && (r&0xFF) != PT_VTNN && (r&0xFF) != PT_DMND && ((ptypes[r&0xFF].properties&TYPE_SOLID) || (ptypes[r&0xFF].properties&TYPE_PART)))
        {
            if ((pmap[y-1][x-1]&0xFF) != PT_VTNN && (pmap[y-1][x-1]&0xFF) != PT_DMND && ((ptypes[pmap[y-1][x-1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-1][x-1]&0xFF].properties&TYPE_PART)))
            {
                if((pmap[y][x-1]&0xFF) == ceiling)
                    parts[pmap[y-1][x-1]>>8].type = ceiling2;
                else
                    parts[pmap[y-1][x-1]>>8].type = ceiling;
            }
            if ((pmap[y-1][x+1]&0xFF) != PT_VTNN && (pmap[y-1][x+1]&0xFF) != PT_DMND && ((ptypes[pmap[y-1][x+1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-1][x+1]&0xFF].properties&TYPE_PART)))
            {
                if((pmap[y][x+1]&0xFF) == ceiling)
                    parts[pmap[y-1][x+1]>>8].type = ceiling2;
                else
                    parts[pmap[y-1][x+1]>>8].type = ceiling;
            }
            //Needs ceiling, top will fall
            if ((pmap[y-2][x]&0xFF) != PT_VTNN && (pmap[y-2][x]&0xFF) != PT_DMND && ((ptypes[pmap[y-2][x]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-2][x]&0xFF].properties&TYPE_PART)))
                parts[pmap[y-2][x]>>8].type = ceiling;
            if ((pmap[y-2][x+1]&0xFF) != PT_VTNN && (pmap[y-2][x+1]&0xFF) != PT_DMND && ((ptypes[pmap[y-2][x+1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-2][x+1]&0xFF].properties&TYPE_PART)))
                parts[pmap[y-2][x+1]>>8].type = ceiling2;
            if ((pmap[y-2][x-1]&0xFF) != PT_VTNN && (pmap[y-2][x-1]&0xFF) != PT_DMND && ((ptypes[pmap[y-2][x-1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-2][x-1]&0xFF].properties&TYPE_PART)))
                parts[pmap[y-2][x-1]>>8].type = ceiling2;
        }
        kill_part(r>>8);
        kill_part(i);
    }*/
}
