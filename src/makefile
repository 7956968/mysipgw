#******************************************************************************
#   The Makefile of Compiling Rules for all
#   #   Created ---------- yangdong, 2018-10-09
#******************************************************************************
export ROOT_DIR:=$(shell pwd)
export BIN_DIR:=$(ROOT_DIR)/../bin

DIRS := sipua \
	webservice \
	sipgw \
	task_schedule \
	inside_message \
	configure_manager\
	utils\
	dlogger\


OBJS := $(BIN_DIR)/*.o \


SO_LIB_DIR = -L/usr/local/resip/lib\

SO_LIB_LIST = -ldum \
	-lresip \
	-lrutil \
	-lresipares \

TARGET = sipgw.out

.PHONY: all clean $(DIRS)

all:
	@$(foreach dir, $(DIRS), $(MAKE) -C $(dir);)
	g++ $(OBJS) $(SO_LIB_DIR) $(SO_LIB_LIST) -lpthread -o $(TARGET)
	mv $(TARGET) ../bin

clean:
	@$(foreach dir, $(DIRS), $(MAKE) -C $(dir) clean;)
	rm -rf $(BIN_DIR)/*.o $(BIN_DIR)/$(TARGET) $(BIN_DIR)/core.*
