CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


world.o : world.cpp world.h
	$(COMPILE) $<

fish.o : fish.cpp fish.h
	$(COMPILE) $<

man.o : man.cpp man.h
	$(COMPILE) $<

pond.o : pond.cpp pond.h
	$(COMPILE) $<


main : maiNK) $@ $^

clean:
	@rm *.o