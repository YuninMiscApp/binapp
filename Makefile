

OBJS := main.o service_idle.o  service_master.o  service_sys.o

all: ${OBJS}
	gcc -Wall -o binapp -L . ${OBJS} -lglib-2.0 -lpthread 


%.o:%.c
	gcc -o $@ -c $<


clean:
	@rm -f *.o *.a *.so *.bak
	@rm -f binapp

