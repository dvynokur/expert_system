#----- Colors -----
BLACK	= "\033[1;30m"
RED	 	= "\033[1;31m"
GREEN	= "\033[1;32m"
YELLOW	= "\033[1;33m"
BLUE	= "\033[1;34m"
MAGENTA	= "\033[1;35m"
CYAN	= "\033[1;35m"
PURPLE	= "\033[1;36m"
WHITE	= "\033[1;37m"
EOC	 	= "\033[0;0m"
RESET	= "\x1b[0m"
#==================

.PHONY: all
all: expert_system 

.PHONY: clean
clean:
	@echo $(RED)"$@"$(RESET)
	@rm -rf build/


.PHONY: fclean
fclean: clean
	@echo $(RED)"$@"$(RESET)
	@rm -rf expert_system

.PHONY: re
re: fclean all

.PHONY: expert_system
expert_system:
	@echo $(YELLOW)"\nCompiling $@ \n"$(RESET)
	@mkdir -p build
	@(cd build && cmake ../ && make)
