cc      := cc
ccflags := -std=c99 -Wall -lapue -ansi -DMACOS -D_DARWIN_C_SOURCE

pwd          := $(shell pwd)
sub_dir      := $(notdir $(pwd))
out_dir      := $(addsuffix $(sub_dir),../bin/)
target_name  := $(shell ls *.c)
target_name  := $(patsubst %.c,%,$(target_name))
target       := $(addprefix $(out_dir)/,$(target_name))

all: $(out_dir) $(target) $(out_dir)/testinterp.txt $(out_dir)/awkexample

$(out_dir)/%: %.c
	gcc $^ -o $@ $(ccflags)

$(out_dir)/testinterp.txt:
	echo "#! ../Chapter_7/echoarg foo" 1> $(out_dir)/testinterp.txt
	chmod u+x $(out_dir)/testinterp.txt

$(out_dir)/awkexample:
	echo -e "#!/usr/bin/awk -f\n\
	# Note: on Solaris, use nawk instead\n\
	BEGIN {\n\
	\tfor (i = 0; i < ARGC; i++)\n\
	\t\tprintf(\"ARGV[%d] = %s\\\n\", i, ARGV[i])\n\
	\texit\n\
	}" 1> $(out_dir)/awkexample
	chmod u+x $(out_dir)/awkexample

$(out_dir):
	mkdir -p $(out_dir)

.PHONY:
clean:
	rm -rf $(out_dir)
