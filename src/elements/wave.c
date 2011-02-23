#include <element.h>

int update_EWAVE(UPDATE_FUNC_ARGS)
{
    int cy = (int)(parts[parts[i].any].y + 0.5f);
    int cx = (int)(parts[parts[i].any].x + 0.5f);
    if(parts[i].life == 1)
        circle(cx, cy, parts[i].any2 + 50,PT_EWAVE);
}
