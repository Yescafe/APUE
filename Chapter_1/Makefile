cc      := cc
ccflags := -std=c99 -Wall -lapue -ansi -DMACOS -D_DARWIN_C_SOURCE

pwd          := $(shell pwd)
sub_dir      := $(notdir $(pwd))
out_dir      := $(addsuffix $(sub_dir),../bin/)
target_name  := $(shell ls *.c)
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
