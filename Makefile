CXX			= clang++
CXXFLAGS	= -std=c++11
# CXXFLAGS	= -std=c++11 -Wall -Wextra -Werror
FILE		= main.cpp source/ExceptionExpSys.cpp source/Reading.cpp source/Checker.cpp source/Expert_System.cpp
NAME		= expert_system
OFILE		= main.o source/ExceptionExpSys.o source/Reading.o source/Checker.o source/Expert_System.o

all: $(NAME)

$(NAME): $(OFILE)
	clang++ $(CXXFLAGS) -o $@ $^ 

%.o: %.c
	clang++ -o $@ -c $< 

clean:
	rm -f $(OFILE)

fclean:
	rm -f $(OFILE)
	rm -f $(NAME)

re: fclean all