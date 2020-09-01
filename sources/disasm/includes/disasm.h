/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschmele <fmelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:29:11 by rschmele          #+#    #+#             */
/*   Updated: 2019/04/12 16:28:42 by rschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_H
# define DISASM_H

# include "op.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdint.h>
# include "./libft.h"

typedef struct			s_com
{
	char				*name;
	int					*arg;
	uint8_t				args_typ;
	int					*t_arg;
	bool				type;
	int					am_arg;
	int					dir_size;
	struct s_com		*next;
}						t_com;

typedef struct			s_dasm
{
	t_com				*com;
	char				*name;
	char				*comment;
	int					code_size;
	uint8_t				*code;
	char				*file_name;
	int					in;
	t_com				*head;
}						t_dasm;

void					parse_all(int argc, char **argv, t_dasm *dasm);
t_dasm					*init_dasm();
t_com					*init_new_node();
void					transfer_operation(t_dasm *dasm);
bool					init_command(uint8_t op, t_com **com);
char					**init_arg(int len);
void					take_name(char *argv, t_dasm *dasm);
void					put_operation_in_file(t_dasm *dasm);
int32_t					bytecode_to_int(uint8_t *bytecode, size_t size);
void					free_all(t_dasm *dasm);
void					parse_magic(int fd);
void					parse_name(int fd, t_dasm *dasm);
void					parse_null(int fd);
void					parse_code_size(int fd, t_dasm *dasm);
void					parse_comment(int fd, t_dasm *dasm);
void					init_command1(uint8_t op, t_com **com);
void					init_command2(uint8_t op, t_com **com);
void					init_command3(uint8_t op, t_com **com);
void					init_command4(uint8_t op, t_com **com);
void					init_command5(uint8_t op, t_com **com);

#endif
