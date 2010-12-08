if(cmode == CM_WAVE){
	if(t == PT_EWAVE || t == PT_WAVE){
		blendpixel(vid, nx, ny, 0xFF, 0xFF, 0xFF, 192);
		}
	else if(t==PT_IWAVE){
		blendpixel(vid, nx, ny, 0xFF, 0xFF, 0x00, 192);
		}
	else if(t==PT_AWAVE){
		blendpixel(vid, nx, ny, 0xFF, 0x00, 0x00, 192);
		}
	else if(t==PT_BWAVE){
		blendpixel(vid, nx, ny, 0x00, 0xFF, 0x00, 192);
		}
	else if(t==PT_CWAVE){
		blendpixel(vid, nx, ny, 0x00, 0x00, 0xFF, 192);
		}
	}