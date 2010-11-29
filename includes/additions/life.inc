if(t == PT_WAVE){
	parts[i].life = rand()%50 + 50;
	}
if(t == PT_EWAVE){
	parts[i].life = 25;
	}
if(t == PT_AWAVE){
	parts[i].life = 20;
	}
if(t == PT_BWAVE){
	parts[i].life = 15;
	}
if(t == PT_CWAVE){
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