#ifndef STRING_HPP_
#define STRING_HPP_

typedef long long unsigned int size_t;

int strcmp(const char* str1, char* str2);
char* strcpy(char* dest, const char* src);
char* strcat(char* dest, const char* src);
int strlen(const char* str);

#endif