# ------------  PROJECT  ----------------------------------------------------- #
NAME_COREWAR	=		corewar
NAME_ASM		=		asm
NAME_DASM		=		dasm

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_COREWAR_DIR	=		sources/corewar/src
HDR_COREWAR_DIR	=		sources/corewar/includes
OBJ_COREWAR_DIR	=		sources/corewar/objs
SRC_ASM_DIR		=		sources/asm/srcs
HDR_ASM_DIR		=		sources/asm/includes
OBJ_ASM_DIR		=		sources/asm/objs
SRC_DASM_DIR	=		sources/disasm/sources
HDR_DASM_DIR	=		sources/disasm/includes
OBJ_DASM_DIR	=		sources/disasm/objs

# ------------  LIBFT  ------------------------------------------------------- #
LFT				=		libft.a
FTP				=		libftprintf.a
LFT_ASM_DIR		=		sources/asm/libft
FTP_ASM_DIR		=		sources/asm/ft_printf
LHS_ASM_DIR		=		$(LFT_ASM_DIR)
FTPHS_ASM_DIR	=		$(FTP_ASM_DIR)
LFT_DASM_DIR	=		sources/disasm/libft
LHS_DASM_DIR	=		$(LFT_DASM_DIR)

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_COREWAR_FLS	=		main.c gc_malloc.c champion_reader.c bytecode_reader.c init_arena.c print_arena.c\
						del_carriage.c distributor.c pre_execute.c setter.c the_game.c\
						intro.c usage.c bytecode_reader_2.c the_game_2.c lib_func.c lib_func_2.c\
						add.c aff.c and.c ft_fork.c ld.c\
						ldi.c lfork.c live.c lld.c lldi.c\
						or.c st.c sti.c sub.c xor.c\
						zjmp.c
SRC_ASM_FLS		=		add_args.c bait_get1.c bait_get2.c binary_code.c command.c\
						error.c ft_free.c get_label.c main.c measure_size.c\
						measure_typeargs.c must_be.c parce_arg.c parce.c parce_code.c\
						skip.c utillits2.c utillits.c valid_args.c valid_header.c
SRC_DASM_FLS	=		main.c tools.c parse.c init.c code.c \
						parse_tools.c extra_init.c free.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS_COREWAR	=		$(addprefix $(SRC_COREWAR_DIR)/, $(SRC_COREWAR_FLS))
OBJS_COREWAR	=		$(patsubst $(SRC_COREWAR_DIR)/%.c,$(OBJ_COREWAR_DIR)/%.o, $(SRCS_COREWAR))
DEPS_COREWAR	=		$(OBJS_COREWAR:.o=.d)
SRCS_ASM		=		$(addprefix $(SRC_ASM_DIR)/, $(SRC_ASM_FLS))
OBJS_ASM		=		$(patsubst $(SRC_ASM_DIR)/%.c,$(OBJ_ASM_DIR)/%.o, $(SRCS_ASM))
DEPS_ASM		=		$(OBJS_ASM:.o=.d)
SRCS_DASM		=		$(addprefix $(SRC_DASM_DIR)/, $(SRC_DASM_FLS))
OBJS_DASM		=		$(patsubst $(SRC_DASM_DIR)/%.c,$(OBJ_DASM_DIR)/%.o, $(SRCS_DASM))
DEPS_DASM		=		$(OBJS_DASM:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC				=		gcc
RM				=		rm -rf
CFLGS			=		-Wall -Werror -Wextra
DFLGS			=		-MMD -MP
DEBUG			=		-g
IFLGS_COREWAR	=		-I $(HDR_COREWAR_DIR)
IFLGS_ASM		=		-I $(HDR_ASM_DIR) -I $(LHS_ASM_DIR) -I $(FTPHS_ASM_DIR)
LFLGS_ASM		=		 $(LFT_ASM_DIR)/$(LFT) $(FTP_ASM_DIR)/$(FTP)
IFLGS_DASM		=		-I $(HDR_DASM_DIR) -I $(LHS_DASM_DIR)
LFLGS_DASM		=		-L $(LFT_DASM_DIR) -lft

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME_COREWAR) $(NAME_ASM) $(NAME_DASM)

# ------------  COREWAR  ----------------------------------------------------- #
-include $(DEPS_COREWAR)
$(OBJ_COREWAR_DIR)/%.o: $(SRC_COREWAR_DIR)/%.c | $(OBJ_COREWAR_DIR)
	@$(CC) -c -o $@ $< $(IFLGS_COREWAR)

$(OBJ_COREWAR_DIR):
	@mkdir -p $(OBJ_COREWAR_DIR)

$(NAME_COREWAR): $(OBJS_COREWAR)
	@echo "Building $(NAME_COREWAR)..."
	@$(CC) $(CFLGS) -o $(NAME_COREWAR) $(OBJS_COREWAR)

# ------------  ASM  --------------------------------------------------------- #
$(LFT_ASM_DIR)/$(LFT):
	@echo "Building $(LFT) library..."
	@$(MAKE) -C $(LFT_ASM_DIR)

$(FTP_ASM_DIR)/$(FTP):
	@echo "Building $(FTP) library..."
	@$(MAKE) -C $(FTP_ASM_DIR)

-include $(DEPS_ASM)
$(OBJ_ASM_DIR)/%.o: $(SRC_ASM_DIR)/%.c | $(OBJ_ASM_DIR)
	@$(CC) -c -o $@ $< $(IFLGS_ASM)

$(OBJ_ASM_DIR):
	@mkdir -p $(OBJ_ASM_DIR)

$(NAME_ASM): $(LFT_ASM_DIR)/$(LFT) $(FTP_ASM_DIR)/$(FTP) $(OBJS_ASM)
	@echo "Building $(NAME_ASM)..."
	@$(CC) $(CFLGS) -o $(NAME_ASM) $(OBJS_ASM) $(LFLGS_ASM)

# ------------  DASM  -------------------------------------------------------- #
$(LFT_DASM_DIR)/$(LFT):
	@echo "Building $(LFT) library..."
	@$(MAKE) -C $(LFT_DASM_DIR)

-include $(DEPS_DASM)
$(OBJ_DASM_DIR)/%.o: $(SRC_DASM_DIR)/%.c | $(OBJ_DASM_DIR)
	@$(CC) -g -c -o $@ $< $(IFLGS_DASM)

$(OBJ_DASM_DIR):
	@mkdir -p $(OBJ_DASM_DIR)

$(NAME_DASM): $(LFT_DASM_DIR)/$(LFT) $(OBJS_DASM)
	@echo "Building $(NAME_DASM)..."
	@$(CC) $(CFLGS) -g -o $(NAME_DASM) $(OBJS_DASM) $(LFLGS_DASM)

clean:
	@echo "Cleaning..."
	@$(RM) $(OBJ_COREWAR_DIR)
	@$(MAKE) -C $(LFT_ASM_DIR) clean
	@$(MAKE) -C $(FTP_ASM_DIR) clean
	@$(RM) $(OBJ_ASM_DIR)
	@$(MAKE) -C $(LFT_DASM_DIR) clean
	@$(RM) $(OBJ_DASM_DIR)

fclean: clean
	@$(RM) $(NAME_COREWAR)
	@$(MAKE) -C $(LFT_ASM_DIR) fclean
	@$(MAKE) -C $(FTP_ASM_DIR) fclean
	@$(RM) $(NAME_ASM)
	@$(MAKE) -C $(LFT_DASM_DIR) fclean
	@$(RM) $(NAME_DASM)

re: fclean all
