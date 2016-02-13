#include "libvect.h"

t_vect3d	vec3_clamp(t_vect3d v, const double min, const double max)
{
	t_vect3d	r;

	r = v;
	r.x > max ? r.x = max : 0;
	r.y > max ? r.y = max : 0;
	r.z > max ? r.z = max : 0;
	r.x < min ? r.x = min : 0;
	r.y < min ? r.y = min : 0;
	r.z < min ? r.z = min : 0;
	return (r);
}
