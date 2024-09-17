/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:55:44 by jormoral          #+#    #+#             */
/*   Updated: 2024/09/14 13:40:11 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "Lib/Libft/libft.h"
# include <readline/readline.h> //-lreadline
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>


# define WORD 0
# define QUOTE 1
# define DQUOTE 2
# define RL 3
# define RR 4
# define RRL 5
# define RRR 6
# define PIPE 7


typedef struct s_token
{
	char *str;
	int	type;
	struct s_token *next;
}t_token;



#endif