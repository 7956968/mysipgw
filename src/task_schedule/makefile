CC=g++


#$(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))

C_SRCS += $(wildcard *.c)
CPP_SRCS += $(wildcard *.cpp)
CXX_SRCS += $(wildcard *.cxx)

OBJS = $(patsubst %.cpp, %.o, $(CPP_SRCS)) $(patsubst %.c, %.o, $(C_SRCS)) $(patsubst %.cxx, %.o, $(CXX_SRCS))

INCLUDE_DIR = -I. \
	-I../inside_message \
	-I../sipua \
	-I/usr/local/resip/include \
	-I.. \

SO_LIB_DIR = 

SO_LIB_LIST = 


%.o:%.cxx
	$(CC) $(INCLUDE_DIR) -c -g $< -o $@
	$(if $(wildcard $(BIN_DIR)), mv $@ $(BIN_DIR), )
%.o:%.cpp
	$(CC) $(INCLUDE_DIR) -c -g $< -o $@
	$(if $(wildcard $(BIN_DIR)), mv $@ $(BIN_DIR), )

all:$(OBJS)
	
clean:
	rm -rf *.o $(TARGET)
	
