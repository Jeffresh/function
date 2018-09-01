CXX = clang++
OBJS =  tests.o

all: main

main: $(OBJS)
	$(CXX) $(OBJS)  -o testfunction

clean:
	$(RM) main $(OBJS) core *~

