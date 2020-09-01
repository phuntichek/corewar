/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by coconroy          #+#    #+#             */
/*   Updated: 2013/11/06 14:21:46 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3
# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define REG_NUMBER				16
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10
# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB                  8
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3
# define KICK_BIT_1				192
# define KICK_BIT_2				240
# define KICK_BIT_3				252
# define BYTE_HEAD				(sizeof(COREWAR_EXEC_MAGIC) + PROG_NAME_LENGTH)
# define BYTE_CODE_HEAD			(BYTE_HEAD + 4 + 4 + COMMENT_LENGTH + 4)
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_gc
{
	void				*memory;
	struct s_gc			*next;
}						t_gc;

typedef struct			s_reader
{
	int					num;
	char				*path;
	struct s_reader		*next;
}						t_reader;

typedef struct			s_flags
{
	bool				dump;
	bool				aff;
	int					print_style;
	int					cycle_num;
}						t_flags;

typedef struct			s_operations
{
	int					delay[16];
	bool				carry[16];
	bool				arg_type[16];
	int					arg_num[16];
	int					t_dir_size[16];
	bool				arg_valid[16][256];
}						t_operations;

typedef struct			s_champions
{
	int					num;
	unsigned char		*name;
	unsigned char		*comment;
	int					code_size;
	unsigned char		*exec_code;
	struct s_champions	*next;
}						t_champions;

typedef struct			s_carriage
{
	int					carr_id;
	int					position;
	bool				carry;
	int					last_live;
	unsigned char		operation_code;
	int					operation_delay;
	int					reg[REG_NUMBER];
	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_corewar
{
	t_champions			*all_champ;
	t_carriage			*all_carr;
	t_flags				flags;
	t_operations		operations;
	unsigned char		*arena;
	int					the_last_champ;
	int					cycles;
	int					total_cycles;
	int					live_operations;
	int					cycles_to_die;
	int					checks;
}						t_corewar;

t_gc					*g_memory;

int						ft_atoi(const char *str);
int						ft_strcmp(const char *s1, const char *s2);
size_t					ft_strlen(const char *s);
int						ft_numlen(size_t n);
char					*ft_itoa(int n);

void					print_usage_2(int flag);
void					print_usage(t_corewar **corewar, int flag);
void					error(void);

void					gc_free(void);
void					**gc_malloc(size_t bytes);

void					dump_flag(char **argv, int argc, int *ac,\
						t_corewar **corewar);
int						number_flag(char **argv, int argc, int *ac,\
						t_reader **with_flag);
void					push_arg(t_reader **arg_list, char *path, int num);
void					arguments_reader_2(t_corewar **corewar,\
						char **argv, int argc, int *ac);
void					arguments_reader(int argc, char **argv,\
						t_corewar **corewar);

void					find_in_no(t_corewar **corewar,\
						t_reader **no_flag, int current_num);
int						find_in_with(t_corewar **corewar,\
						t_reader **with_flag, int current_num);
void					bytecode_reader(t_reader **no_flags,\
						t_reader **with_flag, t_corewar **corewar);

void					pars_champ_param(t_corewar **corewar,\
						unsigned char *exec_code, unsigned char *buf,\
						int current_num);
int						oper(unsigned char *buf, int start);
void					validator(t_corewar **corewar,\
						t_reader **champ, int current_num);

void					init_carriages(t_corewar **corewar,\
						int	position, int champ_num);
void					arena_filler(t_corewar **corewar,\
						unsigned char *filler, int start, int size);
void					init_arena(t_corewar **corewar);

void					winner(t_corewar **corewar);
void					intro_contestants(t_corewar **corewar);

void					free_carriages(t_corewar **corewar);
void					del_carriage(t_carriage **prev,\
						t_carriage **head, t_corewar **corewar);
void					cycles_to_die_check(t_corewar **corewar);

int						get_size(t_corewar **corewar, int arg);
int						check_registr_2(t_corewar **corewar,\
						int arg_1, int arg_2, int arg_3);
int						check_registr(t_corewar **corewar, int arg_type);
int						kick_bit(t_corewar **corewar);
void					pre_execute(t_corewar **corewar, t_carriage **head);

void					the_game_2(t_corewar **corewar, t_carriage **head);
void					the_game(t_corewar **corewar);

void					setter(t_corewar **corewar);

void					operation_distributor_2(t_corewar **corewar,\
						int arg_type, t_carriage **head);
void					operation_distributor(t_corewar **corewar,\
						int arg_type, t_carriage **head);
void					skip_operation(t_corewar **corewar,\
						int arg_type, int skip);

int						atc(int arg_1, int arg_2, int arg_3);
int						get_arg_minus(int arg, int arg_size);
int						get_arg(t_corewar **corewar,\
						int first_byte, int arg_size);
void					live(t_corewar **corewar);

void					hexer_2(unsigned char byte_num);
void					hexer_1(int str_num);
void					print_arena(t_corewar **corewar);

void					free_champ(t_corewar **corewar);

void					ld(t_corewar **corewar, int arg_type);

void					write_in_mem(t_corewar **corewar,\
						int first_byte, int arg);
void					st(t_corewar **corewar, int arg_type);

void					add(t_corewar **corewar);

void					sub(t_corewar **corewar);

void					and(t_corewar **corewar, int arg_type);

void					or(t_corewar **corewar, int arg_type);

void					xor(t_corewar **corewar, int arg_type);

int						ft_mod(int arg_1, int arg_2);
void					zjmp(t_corewar **corewar);

void					ldi(t_corewar **corewar, int arg_type);

void					sti(t_corewar **corewar, int arg_type);

void					ft_fork(t_corewar **corewar, t_carriage **head);

void					lld(t_corewar **corewar, int arg_type);

void					lldi(t_corewar **corewar, int arg_type);

void					lfork(t_corewar **corewar, t_carriage **head);

void					aff(t_corewar **corewar, int arg_type);
#endif
