if(cmode == CM_WAVE)
{
    if(t == PT_EWAVE)
    {
        switch(parts[parts[i].any].tmp)
        {
        case 0:
            blendpixel(vid, nx, ny, 0xFF, 0xFF, 0xFF, 192);
            break;
        case 1:
            blendpixel(vid, nx, ny, 0xFF, 0x00, 0x00, 192);
            break;
        case 2:
            blendpixel(vid, nx, ny, 0x00, 0xFF, 0x00, 192);
            break;
        case 3:
            blendpixel(vid, nx, ny, 0x00, 0x00, 0xFF, 192);
            break;
        }
    }
    else if(t == PT_WAVE)
    {
        blendpixel(vid, nx, ny, 0xFF, 0xFF, 0xFF, 192);
    }
    else if(t==PT_IWAVE)
    {
        blendpixel(vid, nx, ny, 0xFF, 0xFF, 0x00, 192);
    }
    else if(t==PT_HWAV)
    {
        blendpixel(vid, nx, ny, 0xFF, 0xAA, 0x00, 192);
    }
}
if(t == PT_REMT)
{
    switch(parts[i].tmp)
    {
    case 0:
        blendpixel(vid, nx, ny, 0x80, 0x80, 0x80, 192);
        break;
    case 1:
        blendpixel(vid, nx, ny, 0xFF, 0x80, 0x80, 192);
        break;
    case 2:
        blendpixel(vid, nx, ny, 0x80, 0xFF, 0x80, 192);
        break;
    case 3:
        blendpixel(vid, nx, ny, 0x80, 0x80, 0xFF, 192);
        break;
    }
}
if(t == PT_RREC)
{
    switch(parts[i].tmp)
    {
    case 0:
        blendpixel(vid, nx, ny, 0xA0, 0xA0, 0xA0, 192);
        break;
    case 1:
        blendpixel(vid, nx, ny, 0xFF, 0xA0, 0xA0, 192);
        break;
    case 2:
        blendpixel(vid, nx, ny, 0xA0, 0xFF, 0xA0, 192);
        break;
    case 3:
        blendpixel(vid, nx, ny, 0xA0, 0xA0, 0xFF, 192);
        break;
    }
}
if(t==PT_PRSN)
{
    /*
    if(mousex>(nx-3) && mousex<(nx+3) && mousey<(ny+3) && mousey>(ny-3))  //If mous is in the head
    {
        char hp[10];
        itoa(parts[i].life, hp, 10);
        drawtext(vid, mousex, mousey-12, hp, 255, 255, 255, 255);
        //drawtext(vid, mousex-8-2*(parts[i].life<100)-2*(parts[i].life<10), mousey-12, ptypes[parts[i].any].name, 255, 255, 255, 255);
    }*/
    int r = PIXR(ptypes[parts[i].any].pcolors);
    int g = PIXG(ptypes[parts[i].any].pcolors);
    int b = PIXB(ptypes[parts[i].any].pcolors);
    //Draw head
    drawpixel(vid, nx-2, ny - 13, r, g, b, 255);
    drawpixel(vid, nx-1, ny - 13, r, g, b, 255);
    drawpixel(vid, nx  , ny - 13, r, g, b, 255);
    drawpixel(vid, nx+1, ny - 13, r, g, b, 255);
    drawpixel(vid, nx+2, ny - 13, r, g, b, 255);
    drawpixel(vid, nx-2, ny - 9, r, g, b, 255);
    drawpixel(vid, nx-1, ny - 9, r, g, b, 255);
    drawpixel(vid, nx  , ny - 9, r, g, b, 255);
    drawpixel(vid, nx+1, ny - 9, r, g, b, 255);
    drawpixel(vid, nx+2, ny - 9, r, g, b, 255);
    drawpixel(vid, nx-2, ny - 12, r, g, b, 255);
    drawpixel(vid, nx-2, ny - 10, r, g, b, 255);
    drawpixel(vid, nx-2, ny - 11, r, g, b, 255);
    drawpixel(vid, nx+2, ny - 12, r, g, b, 255);
    drawpixel(vid, nx+2, ny - 11, r, g, b, 255);
    drawpixel(vid, nx+2, ny - 10, r, g, b, 255);
    //Draw legs
    drawpixel(vid, nx  , ny - 8, r, g, b, 255);
    drawpixel(vid, nx-1, ny - 7, r, g, b, 255);
    drawpixel(vid, nx+1, ny - 7, r, g, b, 255);
    drawpixel(vid, nx-1, ny - 6, r, g, b, 255);
    drawpixel(vid, nx+1, ny - 6, r, g, b, 255);
    drawpixel(vid, nx-1, ny - 5, r, g, b, 255);
    drawpixel(vid, nx+1, ny - 5, r, g, b, 255);
    drawpixel(vid, nx-2, ny - 4, r, g, b, 255);
    drawpixel(vid, nx+2, ny - 4, r, g, b, 255);
    drawpixel(vid, nx-2, ny - 3, r, g, b, 255);
    drawpixel(vid, nx+2, ny - 3, r, g, b, 255);
    drawpixel(vid, nx-2, ny - 2, r, g, b, 255);
    drawpixel(vid, nx+2, ny - 2, r, g, b, 255);
    drawpixel(vid, nx-2, ny - 1,r, g, b, 255);
    drawpixel(vid, nx+2, ny - 1,r, g, b, 255);
    drawpixel(vid, nx-2, ny + 0,r, g, b, 255);
    drawpixel(vid, nx+2, ny + 0,r, g, b, 255);
}
if(t == PT_FLCT)
{
    float ttemp = (float)parts[i].life;
    int caddress = restrict_flt(restrict_flt(ttemp, 0.0f, 200.0f)*3, 0.0f, (200.0f*3)-3);
    uint8 R = hflm_data[caddress];
    uint8 G = hflm_data[caddress+1];
    uint8 B = hflm_data[caddress+2];
    if (cmode == CM_FIRE||cmode==CM_BLOB || cmode==CM_FANCY)
    {
        cr = R/8;
        cg = G/8;
        cb = B/8;
        x = nx/CELL;
        y = ny/CELL;
        cg += fire_g[y][x];
        if (cg > 255) cg = 255;
        fire_g[y][x] = cg;
        cb += fire_b[y][x];
        if (cb > 255) cb = 255;
        fire_b[y][x] = cb;
        cr += fire_r[y][x];
        if (cr > 255) cr = 255;
        fire_r[y][x] = cr;
    }
    else
    {
        cr = R;
        cg = G;
        cb = B;
        blendpixel(vid, nx, ny, cr, cg, cb, 192);
        blendpixel(vid, nx+1, ny, cr, cg, cb, 96);
        blendpixel(vid, nx-1, ny, cr, cg, cb, 96);
        blendpixel(vid, nx, ny+1, cr, cg, cb, 96);
        blendpixel(vid, nx, ny-1, cr, cg, cb, 96);
        blendpixel(vid, nx+1, ny-1, cr, cg, cb, 32);
        blendpixel(vid, nx-1, ny+1, cr, cg, cb, 32);
        blendpixel(vid, nx+1, ny+1, cr, cg, cb, 32);
        blendpixel(vid, nx-1, ny-1, cr, cg, cb, 32);
    }
}
