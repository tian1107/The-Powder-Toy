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
