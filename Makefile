CC = g++
CFLAGS = -g -Wall -c -lSDL2 -I.
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
OUTPUTFILE = libsdl.a 

all: $(OUTPUTFILE)

$(OUTPUTFILE): $(OBJS)
		ar rsc $(OUTPUTFILE) $(OBJS) 
clean:
		$(RM) *.a *.o *~ $(EXEC)
