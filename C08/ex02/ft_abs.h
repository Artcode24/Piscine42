#ifndef FT_ABS_H
# define FT_ABS_H

int	ft_abs(int x)
{
	if (x < 0)
		return (-x)
	else
		return (x)
}

# define ABS(Value) ft_abs(Value)