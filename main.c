/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:43:12 by jormoral          #+#    #+#             */
/*   Updated: 2024/09/16 10:55:25 by jormoral         ###   ########.fr       */
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

void handle_sigquit(int sig)
{
	(void)sig;
	printf("Quit (core dumped)\n");
	exit(131);
}

void	ft_lstadd_tok(t_token **lst, t_token *new)
{
	t_token	*ult;

	if (*lst == NULL)
		(*lst) = new;
	else
	{
		ult = *lst;
		while (ult->next != NULL)
			ult = ult->next;
		(ult)->next = new;
	}
}
t_token	*make_node(char *str)
{
	t_token	*l;

	l = malloc(sizeof(struct s_token));
	if (!l)
		return (NULL);
	l->str = str;
	l->type = 0;
	l->next = NULL;
	return (l);
}

int find_end_dquote(int i, char *str, char quot)
{
	while(str[i] && str[i] != quot)
		i++;
	return(i);
}

void print_tokens(t_token **tokens)
{
	t_token *aux;
	int i = 0;
	aux = *tokens;
	while(aux)
	{
		printf("token[%d] str: [%s] type: [%d]\n" , i, aux->str, aux->type);
		i++;
		aux = aux->next;
	}
}


void make_token(char *str, t_token **tokens)
{
	t_token *node;
	char	*new;
	int i;
	int j;
	int flag;
	flag = 0;

	i = 0;
	while(str[i])
	{
		while(str[i] && str[i] == ' ')
			i++;
		j = i;
		if(str[i] == '\"' || str[i] == '\'')
		{
			i = find_end_dquote(i + 1, str, str[i]);
			if(!str[i])
			{
				ft_putendl_fd("No end double quote", 2);
				break ;
			}
			new = ft_substr(str, j, i - j + 1);
			node = make_node(new);
			ft_lstadd_tok(tokens, node);
		}
		else if(str[i] == '<' || str[i] == '>'  || str[i] == '|')
		{
			if(str[i] == str[i + 1] && str[i] != '|')
				i++;
			new = ft_substr(str, j, i - j + 1);
			node = make_node(new);
			ft_lstadd_tok(tokens, node);
		}
		else 
		{
			while(str[i] && str[i] != ' ' && str[i] != '<' && str[i] != '>' && str[i] != '|')
				i++;
			new = ft_substr(str, j, i - j);
			node = make_node(new);
			ft_lstadd_tok(tokens, node);
		}
		i++;
	}
	print_tokens(tokens);
	
}

void	ft_freestack(t_token **a)
{
	t_token	*temp;
	t_token	*node;

	node = *a;
	if (!node)
		return ;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*a = NULL;
}



int main(int argc, char **argv, char **env)
{
	(void)argc;
	t_token *tokens;
	tokens = NULL;
	(void)argv;
	char *read_fd;
	(void)env;
	

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	while(1)
	{
		read_fd = readline("miniporonga/:");
		add_history(read_fd);
		if(!read_fd)
		{
			printf("exit\n");
			break;
		}
		make_token(read_fd, &tokens);
		free(read_fd);
		ft_freestack(&tokens);
		
		
	}
	return(0);
}