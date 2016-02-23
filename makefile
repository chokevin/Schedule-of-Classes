
CC = g++
CFLAGS = -ansi

datest: driver.o datime.o time.o common.o display.o container.o
	$(CC) -o datest driver.o datime.o time.o common.o display.o container.o

driver.o: datime.h time.h display.h container.h

datime.o: datime.h common.h time.h

time.o: time.h common.h

display.o: display.h container.h

container.o: container.h datime.h time.h

clean:
	rm -f *.o

real_clean: clean
	rm -f datest
