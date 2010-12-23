/*Moved to powder.c
if(t == PT_CHAN){
    int emt = pmap[y][x];
    if(parts[emt>>8].life != 0)
        return -1;
    if((emt&0xFF)==PT_REMT || (emt&0xFF)==PT_RREC){
        parts[emt>>8].any++;
        if(parts[emt>>8].any % 2 == 0){
            parts[emt>>8].any = 0;
            parts[emt>>8].tmp++;
            parts[emt>>8].tmp %= 4;
            }
        }
        return emt>>8;
    }*/
if(t == PT_WAVE)
{
    parts[i].life = rand()%50 + 50;
}
if(t == PT_EWAVE)
{
    parts[i].life = 25;
}
if(t==PT_IWAVE)
{
    parts[i].life = 10;
}
if(t==PT_PROT)
{
    float r = (rand()%128+128)/127.0f;
    float a = (rand()%360)*3.14159f/180.0f;
    parts[i].life = rand()%480+480;
    parts[i].vx = r*cosf(a);
    parts[i].vy = r*sinf(a);
}
if(t==PT_HGEN)
{
    parts[i].life = 10;
    parts[i].life--;
}
if(t==PT_HWAV)
{
    parts[i].life = 50;
}
if(t==PT_TUNN)
{
    parts[i].vx = 1;
}
if(t==PT_VTNN)
{
    parts[i].vy = 1;
}
if(t==PT_PRSN)
{
    parts[i].any = rand()%255;
    parts[i].any2 = rand()%255;
    parts[i].tmp = rand() %255;
    parts[i].life = 100;
}
