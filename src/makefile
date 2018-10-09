#******************************************************************************
#   The Makefile of Compiling Rules for all
#   #   Created ---------- yangdong, 2018-10-09
#******************************************************************************
DIRS := sipua \
	webservice \
	sipgw
OBJS := sipua/*.o \
	webservice/*.o \
	sipgw/*.o

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

clean:
	@$(foreach dir, $(DIRS), $(MAKE) -C $(dir) clean;)
	rm -rf $(TARGET)
