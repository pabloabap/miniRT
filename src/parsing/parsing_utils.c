#include "mini_rt.h"

int is_space(char c)
{
    return (c == ' ' || c == '\t' || 
            c == '\r' || c == '\f' || c == '\v');
}


int skip_num(char *line)
{
    int i = 0;
    if (line[i] == '+' || line[i] == '-')
        i++;
    while (('0' <= line[i] && line[i] <= '9') || line[i] == '.')
		i++;
    while (is_space(line[i]))
        i++;
    return (i);
}

int skip_vec(char *line)
{
    int i = 0;
    while (line[i] && !is_space(line[i]) && line[i] != '\n')
        i++;
    while (is_space(line[i]))
        i++;
    return (i);
}

double  add_decimal(float n, char *line)
{
    int i;
    float div;

    i = 0;
    div = 10.0;
    while ('0' <= line[i] && line[i] <= '9')
	{
		n += (line[i] - '0')/ div;
		div *= 10.0;
        i++;
	}
    return (n);
}

double  ft_atod(char *line)
{
    double  n;
    int     i;
    int     neg;

    n = 0;
    i = 0;
    neg = 1;

    while (is_space(line[i]))
        i++;
    if (line[i] == '-')
    {
        neg = -1;
        i++;
    }
    else if (line[i] == '+')
        i++;
    while (line[i] == '0')
        i++;
    while ('0' <= line[i] && line[i] <= '9')
	{
		n = 10 * n + line[i] - '0';
		i++;
	}
    if (line[i] == '.')
        n = add_decimal(n, &line[i + 1]);
    return (neg * n); 
}

double  ft_atod_val(char *line)
{
    if (is_val(line) == -1)
        exit(printf("value format error\n"));
    return (ft_atod(line)); 
}

t_tuple read_vec(char *line)
{
    double  x;
    double  y;
    double  z;
    t_tuple vec;

    if (is_vector(line))
    {
        printf("vector format error\n");
        exit(1);
    }
    x = ft_atod(line);
    line += skip_num(line) + 1;
    y = ft_atod(line);
    line += skip_num(line) + 1;
    z = ft_atod(line);
    vec = ft_build_tuple(x, y, z, VECTOR);
    return (vec);
}

t_tuple read_point(char *line)
{
    double  x;
    double  y;
    double  z;
    t_tuple point;

    if (is_vector(line))
    {
        printf("point format error\n");
        exit(1);
    }
    x = ft_atod(line);
    line += skip_num(line) + 1;
    y = ft_atod(line);
    line += skip_num(line) + 1;
    z = ft_atod(line);
    point = ft_build_tuple(x, y, z, POINT);
    return (point);
}

int read_color(char *line)
{
    int  c;
    int  r;
    int  g;
    int  b;

    if (is_vector(line))
    {
        printf("color format error\n");
        exit(1);
    }
    r = ft_atoi(line);
    line += skip_num(line) + 1;
    g = ft_atoi(line);
    line += skip_num(line) + 1;
    b = ft_atoi(line);
    c = set_rgb(r, g, b);
    return (c);
}

int set_rgb(int r, int g, int b) {
    return (255 << 24 | r << 16 | g << 8 | b);
}

int get_red(int c) {
    return (c >> 16) & 0xFF;
}

int get_green(int c) {
    return (c >> 8) & 0xFF;
}

int get_blue(int c) {
    return c & 0xFF;
}