.DEFAULT_GOAL:= build
fileName := sampleapp
files := "./*.cpp"
CC = g++

LINKER_FLAGS  = -lmingw32
BUILD_DIR := ./bin


build:
	@echo "Build started"
	@echo "Creating Build Directory"
	rm -rf ${BUILD_DIR} || true
	mkdir ${BUILD_DIR}
	@echo "Compiling code"
	g++ -o ${BUILD_DIR}/${fileName} ${files} -I. -I./include ${LINKER_FLAGS}
	@echo "Build completed"

clean:
	@echo "Cleaning up"
	rm -rf ${BUILD_DIR} || true