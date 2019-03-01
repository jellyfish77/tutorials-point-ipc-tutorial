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
	cd src/process_image && $(MAKE)
	cd src/process_creation && $(MAKE)

	# link objects and libraries
	$(CC) $(CFLAGS) -o $(BIN_DIR)/processinfo $(SRC_DIR)/process_info/processinfo.o

	$(CC) $(CFLAGS) -o $(BIN_DIR)/segment_size1 $(SRC_DIR)/process_image/segment_size1.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/segment_size2 $(SRC_DIR)/process_image/segment_size2.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/segment_size3 $(SRC_DIR)/process_image/segment_size3.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/segment_size4 $(SRC_DIR)/process_image/segment_size4.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/segment_size5 $(SRC_DIR)/process_image/segment_size5.o

	$(CC) $(CFLAGS) -o $(BIN_DIR)/basicfork $(SRC_DIR)/process_creation/basicfork.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/atexit_sample $(SRC_DIR)/process_creation/atexit_sample.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/at_exit_sample $(SRC_DIR)/process_creation/at_exit_sample.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/pids_after_fork $(SRC_DIR)/process_creation/pids_after_fork.o

clean:
	cd lib && $(MAKE) clean
	cd src/process_info && $(MAKE) clean
	cd src/process_image && $(MAKE) clean
	cd src/process_creation && $(MAKE) clean
	rm -rf ./$(BIN_DIR)
