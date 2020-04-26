all:
	cd Chapter_1 && make
	cd Chapter_2 && make

.PHONY:
clean:
	rm -rf ./bin