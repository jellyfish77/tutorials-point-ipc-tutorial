# If make is run, same outcome as make all
.DEFAULT_GOAL := all

# Define make as Phony target - i.e. run even if file named "make" exists
.PHONY: all

BIN_DIR = bin
SRC_DIR = src
LIB_DIR = lib

libs:
	cd lib && $(MAKE)

all: libs
	# set up /bin output
	mkdir -p bin

	# build objects by calling makefiles in sub dirs
	cd src/process_info && $(MAKE)

	# link objects and libraries
	$(CC) $(CFLAGS) -o $(BIN_DIR)/processinfo $(SRC_DIR)/process_info/processinfo.o

clean:
	cd lib && $(MAKE) clean
	cd src/process_info && $(MAKE) clean
	rm -rf ./$(BIN_DIR)
