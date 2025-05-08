./build/main.exe: ./src/*.cpp ./src/individual/*.cpp
	g++ -I./include -o ./build/main.exe ./src/*.cpp ./src/individual/*.cpp

test: 
	./build/main.exe