#include "get_next_line.h"
#include "libft/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

static char	*extract_line(char *stash)
{
    char	*line;
    size_t	i = 0;

    if (!stash || !stash[0])
        return NULL;
    while (stash[i] && stash[i] != '\n')
        i++;
    line = ft_substr(stash, 0, stash[i] == '\n' ? i + 1 : i);
    return line;
}

static char	*update_stash(char *stash)
{
    size_t	i = 0;
    char	*new_stash;

    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return NULL;
    }
    new_stash = ft_strdup(stash + i + 1);
    free(stash);
    return new_stash;
}

static char	*read_and_stash(int fd, char *stash)
{
    char	buffer[BUFFER_SIZE + 1];
    ssize_t	bytes_read;
    char	*tmp;

    bytes_read = 1;
    while (bytes_read > 0 && (!stash || !ft_strchr(stash, '\n')))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        tmp = stash;
        stash = tmp ? ft_strjoin(tmp, buffer) : ft_strdup(buffer);
        free(tmp);
    }
    return stash;
}

char	*get_next_line(int fd)
{
    static char	*stash;
    char		*line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    stash = read_and_stash(fd, stash);
    if (!stash)
        return NULL;
    line = extract_line(stash);
    stash = update_stash(stash);
    return line;
}