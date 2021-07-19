NAME			=	Mintalk
SV				=	server
CL				=	client
OBJS_PATH_SV	=	objects_sv/
OBJS_PATH_CL	=	objects_cl/
SRCS_PATH		=	source/
HEAD_CL			=	includes/client.h
HEAD_SV			=	includes/server.h
SRCS_LIST_SV	=	server.c
SRCS_LIST_CL	= 	client.c utils_clinet.c 

SRCS_CL			=	$(addprefix $(SRCS_PATH), $(SRCS_LIST_CL))
SRCS_SV			=	$(addprefix $(SRCS_PATH), $(SRCS_LIST_SV))	
OBJS_LIST_CL	=	$(patsubst %.c, %.o, $(SRCS_LIST_CL))

OBJS_CL			=	$(addprefix $(OBJS_PATH_CL), $(OBJS_LIST_CL))
OBJS_LIST_SV	=	$(patsubst %.c, %.o, $(SRCS_LIST_SV))
OBJS_SV			=	$(addprefix $(OBJS_PATH_SV),$(OBJS_LIST_SV))
RM				= 	rm -rf
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(CL)

$(CL): $(OBJS_PATH_CL) $(OBJS_CL) $(HEAD_CL)
	$(CC) $(CFLAGS) -I $(HEAD_CL) $(OBJS_CL) -o $(CL)

$(SV): $(OBJS_PATH_SV)
	$(CC) $(CFLAGS) -I $(HEAD_SV) $(OBJS_SV) -o $(SV)

$(OBJS_PATH_SV):
	mkdir -p $(OBJS_PATH_SV)

$(OBJS_PATH_SV)%.o : $(SRCS_SV)%.c  $(HEAD_SV)
	$(CC) $(CFLAGS) -c -I $(HEAD_SV)  $< -o $@

$(OBJS_PATH_CL):
	mkdir -p $(OBJS_PATH_CL)	

$(OBJS_PATH_CL)%.o : $(SRCS_CL)%.c  $(HEAD_CL)	
	$(CC) $(CFLAGS) -c $< -o $@	

clean:
	$(RM) $(OBJS_PATH_SV) $(OBJS_PATH_CL)

fclean: clean
	$(RM) $(SV) $(CL)

re: fclean all

.PHONY:	all clean fclean re
