#pragma once
#include <stdarg.h>
#include <stdio.h>

#define DEBUG 1

#if DEBUG
#define LOG(type, fmt, args...)\
    do{\
        printf("%s, %s@%s, line:%d\n***Loginfo[", type, __FILE__, __FUNCTION__, __LINE__);\
        printf(fmt, ##args);\
        printf("]\n\n");\
    }while(0)


#define Debug(fmt, args...) LOG("DEBUG", fmt, ##args);
#define Error(fmt, args...) do{LOG("ERROR", fmt, ##args); exit(0);}while(0)
#else
#define LOG(fmt, args...)
#define Debug(fmt, args...)
#define Error(fmt, args...)
#endif