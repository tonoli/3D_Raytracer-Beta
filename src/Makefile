#!/usr/bin/make -f

NAME			=	rt
PUNCHLINE		=	simulate new universe

SRC_BASE		=	$(shell find sources | grep '\.c' | cut -c 9- | sort)

CC				=	gcc

FLAGS			= -O3
FLAGS			+=	-Wall -Wextra -Werror

OPENCL	= -framework OpenCL
OPENGL	= -framework OpenGL
APPKIT = -framework AppKit

SDL2_F		= -framework SDL2 -framework SDL2_ttf -framework SDL2_image  -F ./frameworks/
SDL2_P		= -rpath @loader_path/frameworks/
SDL2_I		= -I ./frameworks/SDL2.framework/Headers
SDL2_TTF_I	= -I ./frameworks/SDL2_ttf.framework/Headers
SDL2_IMG_I	= -I ./frameworks/SDL2_image.framework/Headers

SRC_DIR			=	sources/
INC_DIR			=	includes/
OBJ_DIR			=	objs/

SRCS			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))


LIBFT_DIR		=	libraries/libft/
LIBFT_LIB		=	$(LIBFT_DIR)libft.a
LIBFT_INC		=	$(LIBFT_DIR)includes/

MLX				=	libraries/libmlx/libmlx.a $(OPENGL) $(APPKIT)
MLX_INC			=	libraries/libmlx/



all:
					@printf "\n["
					@make -s -C $(MLX_INC)
					@make -s -C $(LIBFT_DIR)
					@make -s -j $(NAME)
					@printf "]\n"
					@printf "\n=> \x1B[32m$(NAME) ready to $(PUNCHLINE) ! ( ͡° ͜ʖ ͡°) \x1B[37m\n"

$(NAME):			$(MLX_INC) $(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
					@$(CC) $(FLAGS) $(OBJS) -o $(NAME) -I $(INC_DIR) -I $(LIBFT_INC) $(LIBFT_LIB) $(MLX)
					# Copile with SDL @$(CC) $(FLAGS) $(OBJS) -o $(NAME) -I $(INC_DIR) -I $(LIBFT_INC) $(LIBFT_LIB) $(OPENCL) $(SDL2_P) $(SDL2_F) $(SDL2_I) $(SDL2_TTF_I) $(SDL2_IMG_I)

$(LIBFT_LIB):
					make -C $(LIBFT_DIR)

$(MLX_INC):
					make -C $(MLX_INC)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c | $(OBJ_DIR) $(INC_DIR)
					@$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC) -I $(MLX_INC)
					@printf "\x1B[32m▒\e[0m"

clean:
					@printf "=> \x1B[31mDeleting $(NAME) .obj files...\x1B[37m\n"
					@rm -rf $(OBJ_DIR)
					@printf "=> \x1B[31mDeleting libft .obj files...\x1B[37m\n"
					@make -C $(LIBFT_DIR) clean
					@printf "=> \x1B[31mDeleting libmlx .obj files...\x1B[37m\n"
					@make -C $(MLX_INC) clean

fclean:				clean
					@printf "=> \x1B[31mDeleting $(NAME)...\x1B[37m\n"
					@rm -f $(NAME)
					@printf "=> \x1B[31mDeleting libft.a.. \x1B[37m\n"
					@make -C $(LIBFT_DIR) fclean
					@make -C $(MLX_INC) clean

re:					fclean all

norme:
					@norminette $(INC_DIR)/*
					@norminette $(SRC_DIR)/*

.PHONY:				all clean fclean re norme
