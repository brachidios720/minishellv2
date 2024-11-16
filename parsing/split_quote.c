#include "../include/minishell.h"

int	ft_is_in_quote(char *str, int i)
{
	int	count;
	int	ind;

	count = 0;
	ind = 0;
	while (ind < i)
	{
		if (str[ind] == '\'')
			count++;
		ind++;
	}
	return (count % 2 == 1);
}

int	ft_is_in_doublequote(char *str, int i)
{
	int	count;
	int	ind;

	count = 0;
	ind = 0;
	while (ind < i)
	{
		if (str[ind] == '\"')
			count++;
		ind++;
	}
	return (count % 2 == 1);
}

char *ft_strdupsizee(const char *s, int size) 
{
    int i = 0;
    char *stock;

    stock = (char *)malloc(sizeof(char) * (size + 1));
    if (!stock)
        return (NULL);
    while (i < size) {
        stock[i] = s[i];
        i++;
    }
    stock[size] = '\0';
    return (stock);
}

int ft_nbredemott(char const *s, char c) 
{
    int i = 0;
    int nbrmot = 0;

    while (s[i] != '\0')
	{
        while (s[i] == c && s[i] != '\0')
            i++;
        if (s[i] != c && s[i] != '\0')
            nbrmot++;
        while (s[i] != '\0' && (s[i] != c || (s[i] == c && \
		(ft_is_in_quote((char *)s, i) || ft_is_in_doublequote((char *)s, i)))))
            i++;
    }
    return (nbrmot);
}

char **ft_splitt(char const *s, char c) 
{
    char **new;
    int nbrmot = ft_nbredemott(s, c);
    int compteur = 0;
    int size;
    int i = 0;

    new = malloc(sizeof(char *) * (nbrmot + 1));
    if (!new)
        return (NULL);
    while (compteur < nbrmot)
	{
        size = 0;
        while (s[i] == c) 
            i++;
        int start = i;
        while (s[i] && (s[i] != c || (s[i] == c && \
		(ft_is_in_quote((char *)s, i) || ft_is_in_doublequote((char *)s, i))))) 
		{
            i++;
            size++;
        }
        new[compteur] = ft_strdupsizee(s + start, size);
        compteur++;
    }
    new[compteur] = NULL;
    return (new);
}