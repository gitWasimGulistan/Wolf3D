#include "../includes/wolf3d.h"

void		pixel_put_to_image(t_env *e, double x, double y, int color)
{
	int		pos;

	pos = ((y * e->img[0].sline) + (x * (e->img[0].bpp / 8)));
	if (e->img[0].endian)
	{
		e->img[0].data[pos] = (color & 0xFF0000) >> 16;
		e->img[0].data[pos + 1] = (color & 0x00FF00) >> 8;
		e->img[0].data[pos + 2] = (color & 0x0000FF);
	}
	else
	{
		e->img[0].data[pos] = (color & 0x0000FF);
		e->img[0].data[pos + 1] = (color & 0x00FF00) >> 8;
		e->img[0].data[pos + 2] = (color & 0xFF0000) >> 16;
	}
}

void		sky_put_to_image(t_env *e, double x, double y)
{
	int		pos;

	pos = ((y * e->img[0].sline) + (x * (e->img[0].bpp / 8)));
	e->img[0].data[pos] = e->img[1].data[pos];
	e->img[0].data[pos + 1] = e->img[1].data[pos + 1];
	e->img[0].data[pos + 2] = e->img[1].data[pos + 2];
}

void		ground_put_to_image(t_env *e, double x, double y)
{
	int		pos;

	pos = ((y * e->img[0].sline) + (x * (e->img[0].bpp / 8)));
	e->img[0].data[pos] = e->img[2].data[pos];
	e->img[0].data[pos + 1] = e->img[2].data[pos + 1];
	e->img[0].data[pos + 2] = e->img[2].data[pos + 2];
}

int 		draw_vertical_line(t_env *e, double x, int start, int end)
{
	int y;

	y = 0;
	while (y < start)
	{
		sky_put_to_image(e, x, y);
		y++;
	}
	y = start;
	while (y < end)
	{
		if (e->w->side_dist_x < e->w->side_dist_y / 2)
		{
			pixel_put_to_image(e, x, y, 0xCC0000);
		}
		if (e->w->side == 0)
		{
			if (e->w->step_x <= 0)
				pixel_put_to_image(e, x, y, 0xFF0000);
			else
				pixel_put_to_image(e, x, y, 0xFFFF00);
		}
		else
		{
			if (e->w->step_y <= 0)
				pixel_put_to_image(e, x, y, 0x00FF00);
			else
				pixel_put_to_image(e, x, y, 0x0000FF);
		}
		y++;
	}
	y = end;
	while (y < HEIGHT)
	{
		sky_put_to_image(e, x, HEIGHT - y - 1);
		ground_put_to_image(e, x, y);
		y++;
	}
	return (1);
}
