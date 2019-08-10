
APPNAME := BinApp

CFLAGS := -Wall
CFLAGS += -I /usr/include/glib-2.0
CFLAGS += -L .

OBJS := main.o service_idle.o  service_master.o  service_sys.o


all: ${OBJS}
	gcc  ${CFLAGS} -o ${APPNAME} ${OBJS} -lglib-2.0 -lpthread 


%.o:%.c
	gcc ${CFLAGS} -o $@ -c $<


clean:
	@rm -f *.o *.a *.so *.bak
	@rm -f ${APPNAME}

