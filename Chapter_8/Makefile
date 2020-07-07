cc      := cc
ccflags := -std=c99 -Wall -lapue

pwd          := $(shell pwd)
sub_dir      := $(notdir $(pwd))
out_dir      := $(addsuffix $(sub_dir),../bin/)
target_name  := $(shell ls *.c | grep -v "vfork\.c")
target_name  := $(patsubst %.c,%,$(target_name))
target       := $(addprefix $(out_dir)/,$(target_name))

all: $(out_dir) $(target)

$(out_dir)/%: %.c
	gcc $^ -o $@ $(ccflags)

$(out_dir):
	mkdir -p $(out_dir)

.PHONY:
clean:
	rm -rf $(out_dir)
