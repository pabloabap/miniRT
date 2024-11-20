#include "mini_rt.h"

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
    neg = 1;
    i = skip_space(line);
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