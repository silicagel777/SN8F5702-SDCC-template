BIN := blink
BUILD_DIR := ./build
SRC_DIRS := ./src
FLASH_SIZE := 4096
IRAM_SIZE := 256
XRAM_SIZE := 0
XRAM_LOC := 0
PORT := 

CC := sdcc
AS := sdas8051
MAKEBIN := makebin
FLASH := sonixflash
AWK := "$(shell awk 'BEGIN {print "awk"}' || busybox awk 'BEGIN {print "busybox awk"}')"

SRCS := \
  $(shell find $(SRC_DIRS) -name "*.c") \
  $(shell find $(SRC_DIRS) -name "*.asm")
OBJS := $(SRCS:%=$(BUILD_DIR)/%.rel)
DEPS := $(OBJS:.rel=.d)

INC_DIRS := $(SRC_DIRS)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS := $(INC_FLAGS) -mmcs51 --opt-code-size --no-xinit-opt --model-small \
  --xram-size $(XRAM_SIZE) --xram-loc $(XRAM_LOC) --iram-size $(IRAM_SIZE) \
  --code-size $(FLASH_SIZE) --out-fmt-ihx --std-sdcc11 -MMD --Werror
ASFLAGS := -los $(INC_FLAGS)
LDFLAGS :=

.PHONY: all
all: $(BUILD_DIR)/$(BIN).bin $(BUILD_DIR)/$(BIN).hex size

$(BUILD_DIR)/$(BIN).bin: $(BUILD_DIR)/$(BIN).hex
	$(MAKEBIN) -s $(FLASH_SIZE) $< $@

$(BUILD_DIR)/$(BIN).hex: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.c.rel: %.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) -c $< -o $@

$(BUILD_DIR)/%.asm.rel: %.asm Makefile
	mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $@ $<

.PHONY:
size: $(BUILD_DIR)/$(BIN).hex
	@echo "------------------"
	@echo "FLASH: $(shell $(AWK) '$$1 == "ROM/EPROM/FLASH"      {print $$4}' $(BUILD_DIR)/$(BIN).mem) bytes"
	@echo "IRAM:  $(shell $(AWK) '$$1 == "Stack"           {print 248-$$10}' $(BUILD_DIR)/$(BIN).mem) bytes"
	@echo "XRAM:  $(shell $(AWK) '$$1 == "EXTERNAL" {print $(XRAM_LOC)+$$5}' $(BUILD_DIR)/$(BIN).mem) bytes"
	@echo "------------------"

.PHONY: flash
flash: all
ifndef PORT
	$(error Variable PORT is not provided. Please use "make flash PORT=<port>")
endif
	$(FLASH) --port $(PORT) write --file $(BUILD_DIR)/$(BIN).hex

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

-include $(DEPS)
