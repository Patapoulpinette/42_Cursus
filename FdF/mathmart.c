/                           1 -  Bresenham's algorithm   (le plus simple)                               /
/                           2 -  Xiaolin Wu's algorithm  (anti aliasing)                                /

/  Pour faciliter l'utilisation des points et de leurs transformation, utilise une logique de VERTEX    /
/  de plus, tu prendras de l'avance sur les modules suivant....                                         /


void    bresenham_line(t_point p0, t_point p1, t_datadata, int color)
{
	int dx =  abs (p1.x - p0.x);
	int dy = -abs (p1.y - p0.y);
	int sx = p0.x < p1.x ? 1 : -1;
	int sy = p0.y < p1.y ? 1 : -1;
	int err = dx + dy;
	int e2 = err;

	while (1)
	{
		//Put px
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			p0.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			p0.y += sy;
		}
	}
}
Petit mémo avec quelques pistes
		Regarde les algos de bresenham
Tu auras tout ce que tu auras besoin
/*  STRUCT  */

typedef struct s_list
{
	void            *content;
	struct s_list    next;
}                t_list;

typedef struct s_vec2
{
	float    x;
	float    y;
}                t_vec2;

typedef struct s_vec3
{
	float    x;
	float    y;
	float    z;
}                t_vec3;

typedef struct s_vec2int
{
	int        x;
	int        y;
}                t_vec2int;

typedef struct s_vec3int
{
	int        x;
	int        y;
	int        z;
}                t_vec3int;

typedef struct s_mat
{
	float  x[4];
	float  y[4];
	float  z[4];
	float  w[4];
}                t_mat;

typedef struct s_color
{
	/ NOUVELLE NOTION /
	/ r:8 signifie que l'on declare une variable 'r' de 8 bits, 8b = une taille de 256 (2 pow 8) max donc (0,255) pour un unsigned int /

	/           width                     minimum                         maximum  /
	/ signed    8 bit                        -128                            +127  /
	/ signed   16 bit                     -32 768                         +32 767  /
	/ signed   32 bit              -2 147 483 648                  +2 147 483 647  /
	/ signed   64 bit  -9 223 372 036 854 775 808      +9 223 372 036 854 775 807  /
	/ unsigned  8 bit                           0                            +255  /
	/ unsigned 16 bit                           0                         +65 535  /
	/ unsigned 32 bit                           0                  +4 294 967 295  /
	/ unsigned 64 bit                           0     +18 446 744 073 709 551 615  /

	unsigned int    r:8;
	unsigned int    g:8;
	unsigned int    b:8;
	unsigned int    a:8;
}                t_color;

typedef struct s_vertex {
	t_vec3        local;
	t_vec3        world;
	/ AND MORE */
}                t_vertex;
============  Theorie  ============

For Y-Axis Rotation
Xnew = Zold x sinθ + Xold x cosθ
		Ynew = Yold
Znew = Yold x cosθ – Xold x sinθ

		For Y-Axis Rotation
Xnew = Zold x sinθ + Xold x cosθ
		Ynew = Yold
Znew = Yold x cosθ – Xold x sinθ

		For Z-Axis Rotation
Xnew = Xold x cosθ – Yold x sinθ
		Ynew = Xold x sinθ + Yold x cosθ
		Znew = Zold

			   ============  Exemples  ============

			   point (1, 2, 3)
θ = 90º

For X-Axis Rotation (theta)
Xnew = Xold = 1
Ynew = Yold x cosθ – Zold x sinθ = 2 x cos90° – 3 x sin90° = 2 x 0 – 3 x 1 = -3
Znew = Yold x sinθ + Zold x cosθ = 2 x sin90° + 3 x cos90° = 2 x 1 + 3 x 0 = 2

For Y-Axis Rotation (phi)
Xnew = Zold x sinθ + Xold x cosθ = 3 x sin90° + 1 x cos90° = 3 x 1 + 1 x 0 = 3
Ynew = Yold = 2
Znew = Yold x cosθ – Xold x sinθ = 2 x cos90° – 1 x sin90° = 2 x 0 – 1 x 1 = -1

For Z-Axis Rotation (psi)
Xnew = Xold x cosθ – Yold x sinθ = 1 x cos90° – 2 x sin90° = 1 x 0 – 2 x 1 = -2
Ynew = Xold x sinθ + Yold x cosθ = 1 x sin90° + 2 x cos90° = 1 x 1 + 2 x 0 = 1
Znew = Zold = 3