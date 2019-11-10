# Let's make something.

TARGET := nproc

VERSION := 0.1

SRC_DIRS := source
INC_DIRS := include

SRCS := $(shell find $(SRC_DIRS) -name "*.c")
OBJS += $(filter %.o, $(patsubst %.c, %.o, $(SRCS)))

CFLAGS := -Wall -Wextra -std=c18 -Og
CFLAGS += $(foreach dir, $(INC_DIRS), -I$(dir))
CFLAGS += -DVERSION=\"$(VERSION)\"

.PHONY: all install clean

all: $(TARGET)

install: all
	install -m 557 $(TARGET) /usr/local/bin

clean:
	-rm -rf $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)