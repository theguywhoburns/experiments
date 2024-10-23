#pragma once
#include <util.h>

typedef struct string {
    char *data;
    size_t len;
    bool is_const;
} string_t;

size_t ccp_len(const char* str);

// Modified PP_OVERLOAD macro
#define string(name, ...) string_t name = {0}; PP_CONCAT(___string_, PP_NARG(__VA_ARGS__))(name, ##__VA_ARGS__)
#define ___string_0(name) 
#define ___string_1(name, ccp) string_new_ex(&name, ccp, 0, ccp_len(ccp), 0)
#define ___string_2(name, ccp, len) string_new_ex(&name, ccp, 0, len, 0)
#define ___string_3(name, ccp, start, len) string_new_ex(&name, ccp, start, len, 0)
#define ___string_4(name, ccp, start, len, const) string_new_ex(&name, ccp, start, len, const)

#define cstring(name, ...) string_t name = {0}; PP_CONCAT(___cstring_, PP_NARG(__VA_ARGS__))(name, ##__VA_ARGS__)
#define ___cstring_0(name) name.const = 1;
#define ___cstring_1(name, ccp) string_new_ex(&name, ccp, 0, ccp_len(ccp), 1)
#define ___cstring_2(name, ccp, len) string_new_ex(&name, ccp, 0, len, 1)
#define ___cstring_3(name, ccp, start, len) string_new_ex(&name, ccp, start, len, 1)

#define cstring_cast(...) PP_OVERLOAD(___cstring_cast_, __VA_ARGS__)
#define ___cstring_cast_0(...) (string_t){.is_const = 1}
#define ___cstring_cast_1(ccp) (string_t){.data = (char*)ccp, .len = ccp_len(ccp), .is_const = 1} 
#define ___cstring_cast_2(ccp, len) (string_t){.data = (char*)ccp, .len = len, .is_const = 1}

#define string_npos SIZE_MAX

enum strfind_flags {
    STRING_FIND_FIRST = 1,
    STRING_FIND_LAST = 2
};

void string_new(string_t* ret, const char* str);
void string_new_ex(string_t* ret, const char* str, size_t start, size_t end, bool const);
void string_free(string_t* ret);
void string_set(string_t* ret, string_t* str);
void string_add(string_t* ret, string_t str1, string_t str2);
size_t string_find(string_t* str, string_t tofind, char flags);
size_t string_findc(string_t* str, char tofind, char flags);
bool string_equal(string_t* str1, string_t* str2);