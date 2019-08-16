CC := /usr/local/occlum/bin/musl-gcc
CFLAGS :=
LFLAGS :=
BUILD_DIR := build

BIN = $(BUILD_DIR)/main
BIN_OBJ = $(BUILD_DIR)/main.o
BIN_SRC = main.c

all: $(BUILD_DIR) $(BIN)
	readelf -a $(BIN) > $(BUILD_DIR)/main.readelf
	objdump -d $(BIN) > $(BUILD_DIR)/main.objdump

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN): $(BIN_OBJ) $(LIB_SO)
	$(CC) $(LFLAGS) -o $@ $<

$(BIN_OBJ): $(BIN_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean $(BUILD_DIR)
