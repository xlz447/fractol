NAME	=	fractol

NOC		=	\033[0m
GREEN	=	\033[0;32m
BLUE	=	\033[0;34m
RED		=	\033[0;31m

SRC		= main.c fractol.c calc.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
C_FLAGS = -Wall -Wextra -Werror

MLX		= ./minilibx/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./minilibx
MLX_LNK	= -L ./minilibx -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

THR_LNK = -l pthread

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./objs/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		@make -C $(FT)

$(MLX_LIB):
		@make -C $(MLX)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) $(THR_LNK) -lm -o $(NAME)
		@echo "$(GREEN)FDF ✓ fractol ready$(NOC)"

clean:
		@rm -rf $(OBJDIR)
		@make -C $(FT) clean
		@make -C $(MLX) clean
		@echo "$(BLUE)FDF ✓ Removed .o files$(NOC)"

fclean: clean
		@make -C $(FT) fclean
		@rm -rf $(NAME)
		@echo "$(RED)FDF ✓ Removed fractol executable$(NOC)"

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re