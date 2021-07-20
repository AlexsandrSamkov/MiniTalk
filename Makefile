NAME		=	minitalk
CL			=	client
CL_HEAD		=	includes/client.h
SRC_PATH	=	srcs/
CL_OBJ_PATH	=	cl_objs/
CL_SRC_LST	=	utills_client.c client.c
CL_SRC		=	$(addprefix $(SRC_PATH), $(CL_SRC_LST))
CL_OBJ_LST	=	$(patsubst %.c, %.o, $(CL_SRC_LST))
CL_OBJ		=	$(addprefix $(CL_OBJ_PATH), $(CL_OBJ_LST))
SV			=	server
SV_HEAD		=	includes/server.h
SV_OBJ_PATH	=	sv_objs/
SV_SRC_LST	=	server.c
SV_SRC		=	$(addprefix $(SRC_PATH), $(SV_SRC_LST))
SV_OBJ_LST	=	$(patsubst %.c, %.o, $(SV_SRC_LST))
SV_OBJ		=	$(addprefix $(SV_OBJ_PATH), $(SV_OBJ_LST))
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
all: $(NAME)

$(NAME): $(CL) $(SV)

$(CL): $(CL_OBJ_PATH) $(CL_OBJ)
	$(CC) -I $(CL_HEAD) $(CL_FLAGS) $(CL_OBJ) -o $(CL)

$(CL_OBJ_PATH):
	mkdir -p $(CL_OBJ_PATH)

$(CL_OBJ_PATH)%.o : $(SRC_PATH)%.c $(CL_HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(SV):$(SV_OBJ_PATH) $(SV_OBJ)
	$(CC) -I $(SV_HEAD) $(SV_FLAGS) $(SV_OBJ) -o $(SV)

$(SV_OBJ_PATH):
	mkdir -p $(SV_OBJ_PATH)

$(SV_OBJ_PATH)%.o : $(SRC_PATH)%.c $(SV_HEAD)
	$(CC) $(FLAGS) -c $< -o $@

cl: $(CL)

sv: $(SV)

clean:
	$(RM) $(SV_OBJ_PATH) $(CL_OBJ_PATH)

fclean: clean
	$(RM) $(SV) $(CL)

re: clean all

 .PHONY: all clean sv cl fclean re