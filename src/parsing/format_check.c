#include "mini_rt.h"

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
    while ((line[i] >= '0' && line[i] <= '9'))
        i++;
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
        i += skip_num2(&line[i + 1]) + 1;
    //i += skip_space(&line[i]);
    if (!end)
    {
        i += skip_space(&line[i]);
        if (line[i] != ',')
            return (-1);
    }
    else
    {
        if (line[i] && !is_space(line[i]) && line[i] != '\n')
            return (-1);
    }
    return (i);
}

int is_vector(char *line)
{
    int i;

    i = 0;
    if (is_num(&line[i], 0) == -1)
        return (EXIT_FAILURE);
    i += skip_num2(&line[i]) + 1;
    if (is_num(&line[i], 0) == -1)
        return (EXIT_FAILURE);
    i += skip_num2(&line[i]) + 1;
    if (is_num(&line[i], 1) == -1)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}