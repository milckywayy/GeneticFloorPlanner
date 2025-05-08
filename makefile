./build/main.exe: ./src/*.cpp
	g++ -o ./build/main.exe ./src/*.cpp

test: 
	./build/main.exe