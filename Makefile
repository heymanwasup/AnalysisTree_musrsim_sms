CXX       := g++
INCLUDES  := $(shell root-config --cflags)
LIBS  := $(shell root-config --glibs) 
OBJ = main.o t1.o SimpleHistSVC.o
INC = t1.h SimpleHistSVC.h

%.o: %.C $(INC)
	$(CXX) $(INCLUDES)  -c -o $@ $< $(LIBS)

main.exe : $(OBJ)
	$(CXX) -o $@ $^ $(INCLUDES) $(LIBS)

clean :
	-rm $(OBJ) main.exe logs/*