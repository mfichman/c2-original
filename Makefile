CC = clang
CFLAGS = -g -O0 -Wall -Werror -Wpedantic -Wno-extra-semi -MMD -MP -MF bld/$*.d -MT $@ 
LD = clang
LDFLAGS = 
VPATH = src

SOURCES = main.c parse.c
OBJECTS = $(patsubst %.c,bld/%.o,$(SOURCES))
DEPS = $(patsubst %.c,bld/%.d,$(SOURCES))

bin/c2: $(OBJECTS) 
	$(LD) $(LDFLAGS) $^ -o $@

bld/%.o: %.c bld
	$(CC) $(CFLAGS) -c $< -o $@

bld/%.d: ;

bld:
	mkdir -p bld bin

clean: 
	rm -rf $^ $(OBJECTS) $(DEPS) c2

.PHONY: clean

-include $(patsubst %.c,bld/%.d,$(SOURCES))
