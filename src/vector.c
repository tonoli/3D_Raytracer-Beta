

float		dot_product(t_vect a, t_vect b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vect		add(t_vect a, t_vect b)
{
	t_vect v;

	v = init_vect(a.x + b.x, a.y + b.y, a.z + b.z);
	return (v);
}

t_vect		sub(t_vect a, t_vect b)
{
	t_vect	v;

	v = init_vect(a.x - b.x, a.y - b.y, a.z - b.z);
	return (v);
}

t_vect	mult(t_vect a, float t)
{
	t_vect	v;

	v.x = t * a.x;
	v.y = t * a.y;
	v.z = t * a.z;
	return (v);
}

t_vect	power_v(t_vect a, int n)
{
	t_vect	v;

	v.x = pow(a.x, n);
	v.y = pow(a.y, n);
	v.z = pow(a.z, n);
	return (v);
}
