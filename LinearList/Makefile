# 指定编译器
CC = gcc

# 编译选项
CFLAGS = -I.. -Wall

# 指定目标文件
TARGET = SqList SlList DlList

# 当前目录下所有 .c 文件
SRCS = $(wildcard *.c)
# 根据源文件生成的对象列表文件
OBJS = $(SRCS:.c=.o)

# 默认目标
all : $(TARGET)

# 目标文件链接依赖
SqList : SqList.o EgSqList.o
	$(CC) -o $@ $^

SlList : SlList.o EgSlList.o
	$(CC) -o $@ $^

DlList : DlList.o EgDlList.o
	$(CC) -o $@ $^

# 生成对象文件规则
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 依赖关系
$(OBJS): ../common.h
SqList.o EgSqList.o: SqList.h
SlList.o EgSlList.o: SlList.h
DlList.o DlSqList.o: DlList.h
# 运行命令
run_SqList: SqList
	@echo "顺序表具体例子:          Input: data.txt"
	./SqList < data.txt
run_SlList: SlList
	@echo "单链表具体例子:          Input: data.txt"
	./SlList < data.txt
run_DlList: DlList
	@echo "双链表具体例子:          Input: data.txt"
	./DlList < data.txt
run: SqList SlList DlList
	@echo "顺序表具体例子:          Input: data.txt"
	./SqList < data.txt
	@echo "单链表具体例子:          Input: data.txt"
	./SlList < data.txt
	@echo "双链表具体例子:          Input: data.txt"
	./DlList < data.txt
# 清理
.PONY : clean
clean :
	rm $(TARGET) $(OBJS)