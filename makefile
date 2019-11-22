CC:=g++
exe:=buildTree
obj:=controller/V-Tree.o controller/Vehicle.o controller/vertex.o controller/distanceMatrix.o buildTree.o

all:$(obj)
	$(CC) -o $(exe) $(obj)

buildTree.o:buildTree.cpp
	$(CC) -c buildTree.cpp

controller/%.o:controller/%.cpp
	$(CC) -c $^ -o $@



.PHONY:clean
clean:
	rm -rf $(obj) $(exe)
