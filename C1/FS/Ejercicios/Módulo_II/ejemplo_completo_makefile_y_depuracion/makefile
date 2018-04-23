#Nombre archivo: makefile
#Uso: make
#	make clean
#	make install
#	make uninstall
#	make debug
#Descripción: mantiene todas las dependencias entre los módulos y la biblioteca que utiliza el programa2

CC=g++
CPPFLAGS=-Wall

SRCS=main2.cpp factorial.cpp hello.cpp
OBJS=$(SRCS:.cpp=.o)

INCLUDE_DIR=./includes

EXECUTABLE=programa2.out

LIB_NAME=libmates.a
LIB_DIR=./
LIB_SRCS=sin.cpp cos.cpp tan.cpp
LIB_OBJS=$(LIB_SRCS:.cpp=.o)

INSTALL_DIR=/tmp

EXECUTABLE_DEBUG=programa2_depurable.out

all: $(EXECUTABLE) $(LIB_NAME)

$(EXECUTABLE): $(OBJS) $(LIB_NAME)
	$(CC) $(CPPFLAGS) -L$(LIB_DIR) -o $@ $^
	
$(OBJS): $(SRCS)
	$(CC) $(CPPFLAGS) -I$(INCLUDE_DIR) -c $^
	
$(LIB_NAME): $(LIB_OBJS)
	ar -rvs $@ $^
	
$(LIB_OBJS): $(LIB_SRCS)
	$(CC) $(CPPFLAGS) -I$(INCLUDE_DIR) -c $^
	
clean:
	rm $(OBJS) $(LIB_NAME) $(LIB_OBJS)
	
install:
	mv $(EXECUTABLE) $(INSTALL_DIR)
	
uninstall:
	rm $(INSTALL_DIR)/$(EXECUTABLE)
	
debug: $(EXECUTABLE_DEBUG) $(LIB_NAME)
	
$(EXECUTABLE_DEBUG): $(OBJS) $(LIB_NAME)
	$(CC) -g -L$(LIB_DIR) -o $@ $^
