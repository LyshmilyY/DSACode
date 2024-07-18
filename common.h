#ifndef COMMON_H
#define COMMON_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

// 定义数据域
typedef struct elem
{
    char name[20];
    int Math;
    int English;
    int Politics;
    int Computer; 
}elem;

#endif