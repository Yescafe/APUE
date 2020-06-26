cc      := cc
ccflags := -std=c99 -Wall -lapue

pwd          := $(shell pwd)
sub_dir      := $(notdir $(pwd))
out_dir      := $(addsuffix $(sub_dir),../bin/)
target_name  := $(shell ls *.c | grep -v "longjmp\.c" | grep -v "autovar.c")
target_name  := $(patsubst %.c,%,$(target_name))
target       := $(addprefix $(out_dir)/,$(target_name))

all: $(out_dir) $(target) $(out_dir)/longjmp_O0 $(out_dir)/longjmp_O1

$(out_dir)/%: %.c
	gcc $^ -o $@ $(ccflags)

$(out_dir):
	mkdir -p $(out_dir)

$(out_dir)/longjmp_O0: longjmp.c
	gcc longjmp.c -o $(out_dir)/longjmp_O0 $(ccflags) -O0

$(out_dir)/longjmp_O1: longjmp.c
	gcc longjmp.c -o $(out_dir)/longjmp_O1 $(ccflags) -O1

.PHONY:
clean:
	rm -rf $(out_dir)
