/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:35:33 by jormoral          #+#    #+#             */
/*   Updated: 2024/09/16 11:38:33 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void handle_sigint(int sig)
{
	(void)sig;
	printf("\n"); // saltamos a una nueva linea;
	rl_on_new_line(); // te marca una nueva linea, sin esto pare heredoc shita,
	rl_replace_line("", 0);// te muestra la nueva linea limpia;
	rl_redisplay(); // te muestra la nueva linea;
}

/* Aplicar en el main con la funcion signal
signal(SIGINT, handle_signint)
SIGINT numero de identificiacion para ctrl C*/

void handle_sigquit(int sig)
{
	(void)sig;
	printf("Quit (core dumped)\n");
	exit(131);
}

// handle_sigint = señal ctrl+C
// handle sigquit = señal ctrl+\
// ctrl+D significa End of line, si el prompt
// esta vacio el valor de read_line es null y ctrl+D puede aplicarse.