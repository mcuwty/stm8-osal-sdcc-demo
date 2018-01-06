#工程名称
TARGET 			= stm8-osal-sdcc

#运行平台
PLATFORM 		= stm8

#设置编译器
CC     			= sdcc

#获取当前工作目录
TOP=.

#设置源文件后缀，c或cpp
EXT				= c

#设置源文件搜索路径
VPATH			+= $(TOP)/APP:$(TOP)/HARDWARE
VPATH			+= $(TOP)/OSAL/application:$(TOP)/OSAL/hal:$(TOP)/OSAL/osal

#设置自定义源文件目录
APP_DIR			= $(TOP)/APP
HARD_DIR		= $(TOP)/HARDWARE

#设置中间目标文件目录
OBJ_DIR			= $(TOP)/OBJ

#设定头文件包含目录
INC_FLAGS 		+= -I $(TOP)/APP
INC_FLAGS 		+= -I $(TOP)/HARDWARE
INC_FLAGS 		+= -I $(TOP)/OSAL/include

#编译选项
CFLAGS 			+= -m$(PLATFORM)
CFLAGS 			+= --std-c99
# CFLAGS 			+= -Wall

#链接选项
LFLAGS 			+= -l$(PLATFORM)

#链接启动文件和链接脚本

#固定源文件添加
# C_SRC			+= $(shell find $(TOP)/APP  -name '*.$(EXT)')
C_SRC			+= $(shell find $(TOP)/OSAL  -name '*.$(EXT)')

#自定义源文件添加
C_SRC			+= $(HARDWARE)/led.c $(HARDWARE)/uart.c

#中间目标文件
C_SRC_NODIR		= $(notdir $(C_SRC))
C_OBJ 			= $(patsubst %.$(EXT), $(OBJ_DIR)/%.rel,$(C_SRC_NODIR))

#依赖文件
C_DEP			= $(patsubst %.$(EXT), $(OBJ_DIR)/%.d,$(C_SRC_NODIR))

.PHONY: all clean rebuild flash test ctags space

all:$(C_OBJ)
	@$(CC) $(INC_FLAGS) $(CFLAGS) $(LFLAGS) $(C_OBJ) -o $(OBJ_DIR)/$(TARGET).ihx
	@grep REL,CON $(OBJ_DIR)/$(TARGET).map
# $(CC) $(INC_FLAGS) $(CFLAGS) $(LFLAGS) $(wildcard $(OBJ_DIR)/*.rel) -o $(OBJ_DIR)/$(TARGET).ihx
	
#静态模式
#$(C_OBJ):%.rel:%.$(EXT)
#	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/%.rel:%.$(EXT)
	@mkdir -p OBJ
	@echo "building $<"
	@$(CC) -c $(CFLAGS) $(INC_FLAGS) -o $@ $<

-include $(C_DEP)
$(OBJ_DIR)/%.d:%.$(EXT)
	@mkdir -p OBJ
	@echo "making $@"
	@set -e;rm -f $@;$(CC) -MM $(CFLAGS) $(INC_FLAGS) $< > $@.$$$$;sed 's,\($*\)\.rel[ :]*,$(OBJ_DIR)/\1.rel $(OBJ_DIR)/\1.d:,g' < $@.$$$$ > $@;rm -f $@.$$$$

# How to build any .rel file from its corresponding .c file
# GNU would have you use a pattern rule for this, but that's GNU-specific
# .c.rel:
# 	@mkdir -p $(OBJ_DIR)
# 	$(CC) -c $(INC_FLAGS) $(CFLAGS) $(LFLAGS) $< -o$(OBJ_DIR)/

# Suffixes appearing in suffix rules we care about.
# Necessary because .rel is not one of the standard suffixes.
.SUFFIXES: .c .rel

clean:
	-rm -f $(OBJ_DIR)/*

rebuild: clean all

test:
	@echo "Test !"

ctags:
	@ctags -R *

flash:
	sudo stm8flash -c stlinkv2 -p stm8s003f3 -w $(OBJ_DIR)/$(TARGET).ihx

space:
	grep REL,CON $(OBJ_DIR)/$(TARGET).map
