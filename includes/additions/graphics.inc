else if(t==PT_WAVE || t == PT_EWAVE){
	if(cmode == 7){
		blendpixel(vid, nx, ny, 0xFF, 0x00, 0x00, 192);
		}
	}
else if(t==PT_PROT)
{
    if(cmode == 3||cmode==4 || cmode==6)
    {
        vid[ny*(XRES+BARSIZE)+nx] = ptypes[t].pcolors;
        cr = 12;
        cg = 12;
        x = nx/CELL;
        y = ny/CELL;
        cg += fire_g[y][x];
        if(cg > 255) cg = 255;
        fire_g[y][x] = cg;
        cb += fire_b[y][x];
        if(cr > 255) cr = 255;
        fire_r[y][x] = cr;
    }
    else
    {
        cr = 0xDD;
        cg = 0xDD;
        cb = 0x00;
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