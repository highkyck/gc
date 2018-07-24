CFLAGS := \
	-Wall -std=c99 \
	-I. -MMD

OBJS := \
	gc.o \
	object.o \
	vm.o \
	main.o

DIST = main

deps := $(OBJS:%.o=%.d)

all: $(DIST)
$(DIST): $(OBJS)

clean:
	$(RM) $(deps) $(OBJS)

-include $(deps)
