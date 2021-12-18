LIBS = -lraylib -lGL -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -lrt

all:
	g++ src/*.cpp -o main $(LIBS) 

run:
	./main