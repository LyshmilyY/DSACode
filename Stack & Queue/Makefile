# 指定编译器
CC = gcc

# 编译选项
CFLAGS = -I.. -Wall

# 指定目标文件
TARGET = Stack Queue

# 当前目录下所有 .c 文件
SRCS = $(wildcard *.c)
# 根据源文件生成的对象列表文件
OBJS = $(SRCS:.c=.o)

# 默认目标
all : $(TARGET)

# 目标文件链接依赖
Stack : Stack.o EgStack.o
	$(CC) -o $@ $^
Queue : Queue.o EgQueue.o
	$(CC) -o $@ $^
# 生成对象文件规则
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 依赖关系Sq
$(OBJS): ../common.h
Stack.o EgStack.o: Stack.h
Queue.o EgQueue.o: Queue.h

# 运行命令
run_Stack: Stack
	@echo "栈具体例子:"
	./Stack
run_Queue: Queue
	@echo "队列具体例子:"
	./Queue
# 清理
.PONY : clean
clean :
	rm $(TARGET) $(OBJS)