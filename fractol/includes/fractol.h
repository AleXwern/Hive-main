/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:12:21 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/17 16:01:08 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "value.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

/*
** Struct for complex number presentation.
** r is real part.
** i is imaginary part.
*/
typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

/*
** Image handling
** void *img = image pointer
** char *data = ????
** int sizel = ????
** int bpp = bytes per pixel
** int endn = big or small endian
*/
typedef struct	s_image
{
	void		*img;
	char		*data;
	int			sizel;
	int			bpp;
	int			endn;
}				t_image;

/*
** Colors!!
** int set = what the current set is;
** int 1-4 = different palette elements.
*/
typedef struct	s_color
{
	unsigned int	set;
	unsigned int	one;
	unsigned int	two;
	unsigned int	three;
	unsigned int	four;
}				t_color;


/*
** General toolbox for handling information.
** void *mlx = generic mlx pointer.
** void *win = generil mlx window pointer.
** int winbool = 0 or 1 if window exists. Mlx wants to seq fault sometimes.
** int fractol = id of fractol type. -1 equals error.
** 0 Mandelbrot
** 1 Julia
** 2 Bship
** t_image = is image data.
** t_color = has color data.
** int zoom = is exponent for zoom modifer.
** int ishelp = 0 or -1 if help window is shown.
** int fixjulia = 0 or -1 if julia follows mouse.
** t_complex max = 
** t_complex min =
*/
typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	int			winbool;
	t_image		*img;
	t_color		color;
	int			fractol;
	double		zoom;
	int			iter;
	int			ishelp;
	int			fixjulia;
	t_complex	max;
	t_complex	min;
	t_complex	factor;
	t_complex	c;
	t_complex	jul;
}				t_fractol;

void	error_out(char *msg, t_fractol *frc);
void	fractol_main(t_fractol *frc);
void	help_window(t_fractol *frc);
void	set_default(t_fractol *frc);
void	testdraw(t_fractol *frc, int rd);

int		define_set(t_fractol *frc);
int		julia_move(int x, int y, t_fractol *frc);
int		key_main(int key, t_fractol *frc);
int		mouse_main(int key, int x, int y, t_fractol *frc);

t_image		*init_image(t_fractol *frc);
t_color		color_set(int set, double y, t_color color);
t_color		get_color(int iter, t_fractol *frc);
t_complex	set_complex(double rn, double in);

#endif
