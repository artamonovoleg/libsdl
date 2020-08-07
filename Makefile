CC = clang++
CFLAGS = -std=c++11 -stdlib=libc++ -g -c -Wall
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
OUTPUTFILE = libsdl.a 

all: $(OUTPUTFILE)

$(OUTPUTFILE): $(OBJS)
		ar rsc $(OUTPUTFILE) $(OBJS) 

$(OBJS):
		$(CC) $(CFLAGS) $(SRCS)
clean:
		$(RM) *.a *.o *~ $(EXEC)
