clean:
	rm -rf build

run:
	make clean
	mkdir build
	clang *.cpp -L lib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a -o build/gfx-fun -std=c++11