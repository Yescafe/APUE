all:
	cd Chapter_1 && make
	cd Chapter_2 && make
	cd Chapter_3 && make

.PHONY:
clean:
	rm -rf ./bin
