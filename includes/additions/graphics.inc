if(t == PT_EWAVE || t == PT_WAVE){
	if(cmode == CM_WAVE){
		blendpixel(vid, nx, ny, 0xFF, 0xFF, 0xFF, 192);
		}
	}
else if(t==PT_IWAVE){
	if(cmode == CM_WAVE){
		blendpixel(vid, nx, ny, 0xFF, 0xFF, 0x00, 192);
		}
	}
else if(t==PT_AWAVE){
	if(cmode == CM_WAVE){
		blendpixel(vid, nx, ny, 0xFF, 0x00, 0x00, 192);
		}
	}
else if(t==PT_BWAVE){
	if(cmode == CM_WAVE){
		blendpixel(vid, nx, ny, 0x00, 0xFF, 0x00, 192);
		}
	}
else if(t==PT_CWAVE){
	if(cmode == CM_WAVE){
		blendpixel(vid, nx, ny, 0x00, 0x00, 0xFF, 192);
		}
	}
else if(t==PT_PROT)
{
	if(cmode == CM_FIRE||cmode==CM_BLOB || cmode==CM_FANCY)
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