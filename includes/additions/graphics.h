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
if(t==PT_PRSN){
    int r = parts[i].any;
    int g = parts[i].any2;
    int b = parts[i].tmp;
    //Draw head
    drawpixel(vid, nx-2, ny - 2, r, g, b, 255);
    drawpixel(vid, nx-1, ny - 2, r, g, b, 255);
    drawpixel(vid, nx  , ny - 2, r, g, b, 255);
    drawpixel(vid, nx+1, ny - 2, r, g, b, 255);
    drawpixel(vid, nx+2, ny - 2, r, g, b, 255);
    drawpixel(vid, nx-2, ny + 2, r, g, b, 255);
    drawpixel(vid, nx-1, ny + 2, r, g, b, 255);
    drawpixel(vid, nx  , ny + 2, r, g, b, 255);
    drawpixel(vid, nx+1, ny + 2, r, g, b, 255);
    drawpixel(vid, nx+2, ny + 2, r, g, b, 255);
    drawpixel(vid, nx-2, ny - 1, r, g, b, 255);
    drawpixel(vid, nx-2, ny    , r, g, b, 255);
    drawpixel(vid, nx-2, ny + 1, r, g, b, 255);
    drawpixel(vid, nx+2, ny - 1, r, g, b, 255);
    drawpixel(vid, nx+2, ny    , r, g, b, 255);
    drawpixel(vid, nx+2, ny + 1, r, g, b, 255);
    //Draw legs
    drawpixel(vid, nx  , ny + 3, r, g, b, 255);
    drawpixel(vid, nx-1, ny + 4, r, g, b, 255);
    drawpixel(vid, nx+1, ny + 4, r, g, b, 255);
    drawpixel(vid, nx-1, ny + 5, r, g, b, 255);
    drawpixel(vid, nx+1, ny + 5, r, g, b, 255);
    drawpixel(vid, nx-1, ny + 6, r, g, b, 255);
    drawpixel(vid, nx+1, ny + 6, r, g, b, 255);
    drawpixel(vid, nx-2, ny + 7, r, g, b, 255);
    drawpixel(vid, nx+2, ny + 7, r, g, b, 255);
    drawpixel(vid, nx-2, ny + 8, r, g, b, 255);
    drawpixel(vid, nx+2, ny + 8, r, g, b, 255);
    drawpixel(vid, nx-2, ny + 9, r, g, b, 255);
    drawpixel(vid, nx+2, ny + 9, r, g, b, 255);
    drawpixel(vid, nx-2, ny + 10,r, g, b, 255);
    drawpixel(vid, nx+2, ny + 10,r, g, b, 255);
    drawpixel(vid, nx-2, ny + 11,r, g, b, 255);
    drawpixel(vid, nx+2, ny + 11,r, g, b, 255);
}
