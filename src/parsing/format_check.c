#include "mini_rt.h"

int check_line_end(char *line)
{
    int i;
    
    i = 0;
    while (line[i])
    {
        if (!is_space(line[i]) && line[i] != '\n')
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}

int valid_char(char c)
{
    return  (c == ',' || c == '.' || (c >= '0' && c <= '9') \
            || c == '+' || c == '-' || is_space(c) || c == '\n');
}

int check_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (!valid_char(line[i]))
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}

int skip_space(char *line)
{
    int i;

    i = 0;
    while (is_space(line[i]))
        i++;
    return (i);
}

int skip_num2(char *line)
{
    int i;

    i = 0;
    if (line[i] == '-')
        i++;
    while (line[i] == '+')
        i++;
    while ((line[i] >= '0' && line[i] <= '9'))
        i++;
    return (i);
}

int is_val(char *line)
{
    int i;

    i = 0;
    i += skip_space(line);
    if (line[i] == '-')
        i++;
    while (line[i] == '+')
        i++;
    i += skip_num2(&line[i]);
    if (line[i] == '.')
    {
        if (!ft_isdigit(line[i + 1]))
            return (-1); 
        i += skip_num2(&line[i + 1]) + 1;
    }
    if (!is_space(line[i]) && line[i] != '\n')
        return (-1);
    return (i);
}

int is_num(char *line, int end)
{
    int i;

    i = 0;
    i += skip_space(line);
    if (line[i] == '-')
        i++;
    while (line[i] == '+')
        i++;
    i += skip_num2(&line[i]);
    if (line[i] == '.')
    {
        if (!ft_isdigit(line[i + 1]))
            return (-1); 
        i += skip_num2(&line[i + 1]) + 1;
    }
    if (!end)
    {
        i += skip_space(&line[i]);
        if (line[i] != ',')
            return (-1);
    }
    else if (line[i] && !is_space(line[i]) && line[i] != '\n')
            return (-1);
    return (i);
}

int is_vector(char *line)
{
    int i;

    i = 0;
    if (is_num(&line[i], 0) == -1)
        return (EXIT_FAILURE);
    i += is_num(&line[i], 0) + 1;
    if (is_num(&line[i], 0) == -1)
        return (EXIT_FAILURE);
    i += is_num(&line[i], 0) + 1;
    if (is_num(&line[i], 1) == -1)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}