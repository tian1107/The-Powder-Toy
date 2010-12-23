//Fast growing plant
if(t==PT_FPLT)
{
    for(nx=-2; nx<3; nx++)
        for(ny=-2; ny<3; ny++)
        {
            //Absorption
            if(x+nx>=0 && y+ny>0 &&
                    (x+nx<XRES && y+ny<YRES && (nx || ny)) &&
                    (pmap[y+ny][x+nx]&0xFF)!=0xFF)
            {
                r = pmap[y+ny][x+nx];
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
                    t = parts[i].type = PT_FPLT;
                    parts[r>>8].type = PT_FPLT;
                }
                else if ((r&0xFF)==PT_SMKE && 1>(rand()%250))
                {
                    delete_part(x + nx, y + ny);
                }
                else if((r&0xFF)==PT_LAVA && 1>(rand()%250))
                {
                    parts[i].life = 4;
                    t = parts[i].type = PT_FIRE;
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
                            if(x+nx+o>=0 && y+ny+n>0 &&
                                    (x+nx+o<XRES && y+ny+n<YRES && (nx || ny)) &&
                                    (pmap[y+ny+n][x+nx+o]&0xFF)!=0xFF)
                            {
                                if(!(n == 0 && o == 0))
                                {
                                    create_part(-1, nx+x+o, ny+y+n, PT_FPLT);
                                }
                            }
                        }
                    }
                }
            }
        }
}
//Soap
if(t==PT_SOAP)
{
    for(nx=-1; nx<1; nx++)
        for(ny=-1; ny<1; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_SOAP)
                {
                    if (parts[r>>8].type == PT_ACID)
                    {
                        delete_part(x+nx,y+ny);
                        delete_part(x,y);
                        create_part(-1, x, y, PT_WATR);
                    }
                    else if((parts[r>>8].type == PT_WATR)&& rand()% 50 > 1)
                    {
                        parts[r>>8].type = PT_SOAP;
                    }
                    else if((parts[r>>8].type == PT_SLTW) && rand()% 50 > 1)
                    {
                        parts[r>>8].type = PT_SOAP;
                        create_part(-1, parts[i].x + rand()%5-2, parts[i].y + rand()%5-2, PT_SALT);
                    }
                    else if(parts[r>>8].type == PT_DSTW && rand()% 50 > 1)
                    {
                        parts[r>>8].type = PT_SOAP;
                    }
                    else if(((ptypes[parts[r>>8].type].menusection == SC_LIQUID) || (ptypes[parts[r>>8].type].menusection == SC_GAS) || (ptypes[parts[r>>8].type].menusection == SC_POWDERS) || ((ptypes[parts[r>>8].type].menusection == SC_EXPLOSIVE) && parts[r>>8].type != PT_PLEX && parts[r>>8].type != PT_RBDM) || parts[r>>8].type == PT_URAN || parts[r>>8].type == PT_PLUT)&& (rand()%100<1))
                    {
                        delete_part(x+nx,y+ny);
                        delete_part(x,y);
                    }
                }
            }
}
//Radio Wave Emitter
if(t==PT_SPRK&&parts[i].ctype==PT_REMT&&parts[i].life==1)
{
    /*int intf = 0;
    nearp = next_part(-1, PT_RREC);
    while(nearp != -1){
    intf = inbetween(i, nearp, PT_INTF);
    if(intf == -1){
    create_line(parts[i].x, parts[i].y, parts[nearp].x, parts[nearp].y, 0, PT_EWAVE);
    parts[i].type = PT_REMT;
    parts[i].ctype = PT_NONE;
    parts[i].life = 20;
    parts[nearp].type = PT_SPRK;
    parts[nearp].life = 9;
    parts[nearp].ctype = PT_RREC;
    }
    else{
    create_line(parts[i].x, parts[i].y, parts[intf].x, parts[intf].y, 0, PT_EWAVE);
    }
    nearp = next_part(nearp,PT_RREC);
    }*/
    circle(parts[i].x, parts[i].y, 50,PT_EWAVE);
}
//Radio Wave Receiver
if(t==PT_RREC && parts[i].life <= 1)
{
    for(nx=-24; nx<24; nx++)
    {
        for(ny=-24; ny<24; ny++)
        {
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_RREC)
                {
                    if (parts[r>>8].type == PT_WAVE && nx <= 3 && nx >= -3 && ny >= -3 && ny <= 3)
                    {
                        delete_part(x+nx, y+ny);
                        parts[i].type = PT_SPRK;
                        parts[i].life = 9;
                        parts[i].ctype = PT_RREC;
                        break;
                    }
                    else if(parts[r>>8].type == PT_EWAVE)
                    {
                        if(parts[parts[r>>8].any].tmp == parts[i].tmp || parts[i].tmp == 0 || parts[parts[r>>8].any].tmp == 0)
                        {
                            if(inbetween(i, parts[r>>8].any, PT_INTF) == -1)
                            {
                                parts[i].type = PT_SPRK;
                                parts[i].life = 9;
                                parts[i].ctype = PT_RREC;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
//Protons
if(t==PT_PROT)
{
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
//More waves
if(t == PT_URAN || t == PT_PLUT)
{
    if(rand() % 10 < 1)
        create_part(-1, x+rand()%10-5, y+rand()%10-5, PT_WAVE);
}
if(t == PT_EWAVE && parts[i].life == 1)
{
    if(parts[parts[i].any].type == PT_REMT || (parts[parts[i].any].type == PT_SPRK && parts[parts[i].any].ctype == PT_REMT))
        circle(parts[parts[i].any].x,parts[parts[i].any].y, parts[i].any2 + 50,PT_EWAVE);
}
//Powdered Glow
if(t==PT_PGLW)
{
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
//Infrared emitter
if(t==PT_SPRK && parts[i].ctype == PT_IEMT && parts[i].life == 1)
{
    create_line(x, 0, x, YRES, 1,1, PT_IWAVE);
    create_line(0, y, XRES, y, 1,1, PT_IWAVE);
    create_line(x - y, 0, YRES + x - y, YRES, 1,1, PT_IWAVE);
    create_line(x+y, 0, -YRES+x+y, YRES, 1,1, PT_IWAVE);
}
//Infrared receiver
if(t == PT_IREC)
{
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
//Heat generator
if(t == PT_HGEN && parts[i].life == 1)
{
    circle(parts[i].x, parts[i].y, 40,PT_HWAV);
    parts[i].life = 9;
}
if(t == PT_HWAV)
{
    for(nx=-1; nx<1; nx++)
        for(ny=-1; ny<1; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_HWAV && (r&0xFF)!=PT_INSL)
                {
                    parts[i].temp+=10;
                }
            }
}
if(t == PT_HWAV && parts[i].life == 1)
{
    if(parts[i].any2 != 80)
    {
        if(parts[parts[i].any].type == PT_HGEN)
            circle(parts[parts[i].any].x, parts[parts[i].any].y, parts[i].any2+40,PT_HWAV);
    }
}
if(t==PT_CHLN)
{
    for(nx=-1; nx<1; nx++)
        for(ny=-1; ny<1; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)!=PT_CHLN)
                {
                    if(((r&0xFF)==PT_WATR || (r&0xFF)==PT_DSTW) && rand()%10<1)
                    {
                        delete_part(x, y);
                        parts[r>>8].type = PT_ACID;
                        parts[r>>8].life = 500; //Acidic Acid!
                    }
                    else if(((r&0xFF)==PT_RBDM || (r&0xFF)==PT_LRBD) && rand()%10<1)
                    {
                        parts[r>>8].type = PT_SALT;
                        delete_part(x, y);
                    }

                }
            }
}
//Tunneler
if(t==PT_TUNN)
{
    int ceiling = PT_IRON;
    int ceiling2 = PT_BMTL;
    if(parts[i].vx > 0)
    {
        r = pmap[y][x+1];
        if((r>>8)>=NPART || !r)
            continue;
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
    else
    {
        r = pmap[y][x-1];
        if((r>>8)>=NPART || !r)
            continue;
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
    }
}
//Vertical Tunneler
if(t==PT_VTNN)
{
    int ceiling = PT_IRON;
    int ceiling2 = PT_BMTL;
    if(parts[i].vy > 0)
    {
        if(y+1 > YRES)
            continue;
        r = pmap[y+1][x];
        if((r>>8)>=NPART || !r)
            continue;
        if((r&0xFF) != 0xFF && (r&0xFF) != PT_TUNN && (r&0xFF) != PT_DMND && ((ptypes[r&0xFF].properties&TYPE_SOLID) || (ptypes[r&0xFF].properties&TYPE_PART)))
        {
            if ((pmap[y+1][x-1]&0xFF) != PT_TUNN && (pmap[y+1][x-1]&0xFF) != PT_DMND && ((ptypes[pmap[y+1][x-1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y+1][x-1]&0xFF].properties&TYPE_PART)))
            {
                if((pmap[y][x-1]&0xFF) == ceiling)
                    parts[pmap[y+1][x-1]>>8].type = ceiling2;
                else
                    parts[pmap[y+1][x-1]>>8].type = ceiling;
            }
            if ((pmap[y+1][x+1]&0xFF) != PT_TUNN && (pmap[y+1][x+1]&0xFF) != PT_DMND && ((ptypes[pmap[y+1][x+1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y+1][x+1]&0xFF].properties&TYPE_PART)))
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
            continue;
        if((r&0xFF) != 0xFF && (r&0xFF) != PT_TUNN && (r&0xFF) != PT_DMND && ((ptypes[r&0xFF].properties&TYPE_SOLID) || (ptypes[r&0xFF].properties&TYPE_PART)))
        {
            if ((pmap[y-1][x-1]&0xFF) != PT_TUNN && (pmap[y-1][x-1]&0xFF) != PT_DMND && ((ptypes[pmap[y-1][x-1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-1][x-1]&0xFF].properties&TYPE_PART)))
            {
                if((pmap[y][x-1]&0xFF) == ceiling)
                    parts[pmap[y-1][x-1]>>8].type = ceiling2;
                else
                    parts[pmap[y-1][x-1]>>8].type = ceiling;
            }
            if ((pmap[y-1][x+1]&0xFF) != PT_TUNN && (pmap[y-1][x+1]&0xFF) != PT_DMND && ((ptypes[pmap[y-1][x+1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-1][x+1]&0xFF].properties&TYPE_PART)))
            {
                if((pmap[y][x+1]&0xFF) == ceiling)
                    parts[pmap[y-1][x+1]>>8].type = ceiling2;
                else
                    parts[pmap[y-1][x+1]>>8].type = ceiling;
            }
            //Needs ceiling, top will fall
            if ((pmap[y-2][x]&0xFF) != PT_TUNN && (pmap[y-2][x]&0xFF) != PT_DMND && ((ptypes[pmap[y-2][x]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-2][x]&0xFF].properties&TYPE_PART)))
                parts[pmap[y-2][x]>>8].type = ceiling;
            if ((pmap[y-2][x+1]&0xFF) != PT_TUNN && (pmap[y-2][x+1]&0xFF) != PT_DMND && ((ptypes[pmap[y-2][x+1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-2][x+1]&0xFF].properties&TYPE_PART)))
                parts[pmap[y-2][x+1]>>8].type = ceiling2;
            if ((pmap[y-2][x-1]&0xFF) != PT_TUNN && (pmap[y-2][x-1]&0xFF) != PT_DMND && ((ptypes[pmap[y-2][x-1]&0xFF].properties&TYPE_SOLID) || (ptypes[pmap[y-2][x-1]&0xFF].properties&TYPE_PART)))
                parts[pmap[y-2][x-1]>>8].type = ceiling2;
        }
        kill_part(r>>8);
        kill_part(i);
    }
}
//Explosive
if(t == PT_EXPL)
{
    for(nx=-5; nx<5; nx++)
        for(ny=-5; ny<5; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)==PT_FIRE || (r&0xFF)==PT_PLSM)
                {
                    if(10>(rand()%20))
                    {
                        pv[y/CELL][x/CELL] = 500.0f;
                        parts[i].temp = MAX_TEMP;
                    }
                    else
                    {
                        pv[y/CELL][x/CELL] = -500.0f;
                        parts[i].temp = 0.0f;
                    }
                }
            }
}



