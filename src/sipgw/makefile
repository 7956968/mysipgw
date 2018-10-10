CC=g++
C_SRCS = $(wildcard *.c)
CPP_SRCS = $(wildcard *.cpp)
CXX_SRCS = $(wildcard *.cxx)
OBJS = $(patsubst %.cpp, %.o, $(CPP_SRCS)) $(patsubst %.c, %.o, $(C_SRCS)) $(patsubst %.cxx, %.o, $(CXX_SRCS))

INCLUDE_DIR = -I. \
	-I/usr/local/resip/include \
	-I/usr/local/gsoap \
	-I/usr/local/gsoap/share/gsoap \
	-I../ \
	-I../webservice \
	-I/usr/local/resip/include \
	-I../sipua

SO_LIB_DIR = -L/usr/local/resip/lib\

SO_LIB_LIST = -ldum \


%.o:%.cxx
	$(CC) $(INCLUDE_DIR) -c -g $< -o $@
%.o:%.cpp
	$(CC) $(INCLUDE_DIR) -c -g $< -o $@

all:$(OBJS)

clean:
	rm -rf *.o $(TARGET)
