CC=g++
S = $(wildcard *.h)
C_SRCS = $(wildcard *.c)
CPP_SRCS = $(wildcard *.cpp)
CXX_SRCS = $(wildcard *.cxx)
OBJS = $(patsubst %.cpp, %.o, $(CPP_SRCS)) $(patsubst %.c, %.o, $(C_SRCS)) $(patsubst %.cxx, %.o, $(CXX_SRCS))

CFLAGS := -g -c -D_POSIX_THREADS
GSOAP_FLAGS := -DWITH_PURE_VIRTUAL

INCLUDE_DIR = -I. \
	-I../sipgw \
	-I..
#	-I/usr/local/gsoap \
	-I/usr/local/gsoap/share/gsoap/ \


all:$(OBJS)
.PHONY : all

%.o:%.cxx
	$(CC) $(CFLAGS)  ${GSOAP_FLAGS} $(INCLUDE_DIR) $< -o $@
	$(if $(wildcard $(BIN_DIR)), mv $@ $(BIN_DIR), )
%.o:%.cpp
	$(CC) $(CFLAGS)  ${GSOAP_FLAGS} $(INCLUDE_DIR) $< -o $@
	$(if $(wildcard $(BIN_DIR)), mv $@ $(BIN_DIR), )

clean:
	rm -rf *.o $(TARGET)
