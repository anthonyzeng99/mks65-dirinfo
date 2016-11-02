all:
	gcc dirinfo.c -o dirinfo

run: dirinfo
	./dirinfo

clean:
	rm *~
