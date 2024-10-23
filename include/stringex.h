#pragma once

#include <util.h>

PP_TSTRUCT(string_t);
struct string_t {
    char*  str;
    size_t len;
    bool _const;
};

size_t ccp_len(const char* ccp);

#define ___string_handle_value_type(val) _Generic(\
    const char*:        val, \
    char*: (const char*)val, \
    string_t: (const char*)((string_t)val).str, \
    string_t*:(const char*)((string_t)val)->str,\
    const string_t: (const char*)((const string_t)val).str, \
    const string_t*:(const char*)((const string_t)val)->str,\
    const char: &val,\
    char: &val,\
    const short: &val,\
    default: static_assert(0, "Invalid value type")\
)
#define ___string_handle_value_type_len(val) _Generic(\
    const char*:        cpp_len(val), \
    char*: (const char*)cpp_len(val), \
    string_t: (const char*)((string_t)val).len, \
    string_t*:(const char*)((string_t)val)->len,\
    const string_t: (const char*)((const string_t)val).len, \
    const string_t*:(const char*)((const string_t)val)->len,\
    const char: 1,\
    char: 1,\
    default: static_assert(0, "Invalid value type")\
)

#define string(name, ...) string_t name = {0}; PP_CONCAT(___string_, PP_NARG(__VA_ARGS__))(name, __VA_ARGS__)
#define ___string_0(name)
#define ___string_1(name, value) string_new(&name, ___string_handle_value_type(value), 0, ___string_handle_value_type_len(value), 0)
#define ___string_2(name, value, len) string_new_ex(&name, ___string_handle_value_type(value), 0, len, 0)
#define ___string_3(name, value, start, len) string_new_ex(&name, ___string_handle_value_type(value), start, len, 0)
#define ___string_4(name, value, start, len, _const) string_new_ex(&name, ___string_handle_value_type(value), start, len, _const)

#define string_new(nameref, ...) PP_CONCAT(___string_new_, PP_NARG(__VA_ARGS__))(nameref, __VA_ARGS__)
#define ___string_new_0(nameref) static_assert(0, "Not enough arguments, at least 2 are required")
#define ___string_new_1(nameref, value) string_new_ex(&nameref, value, 0, ccp_len(value), 0)
#define ___string_new_2(nameref, value, len) string_new_ex(&nameref, value, 0, len, 0)
#define ___string_new_3(nameref, value, start, len) string_new_ex(&nameref, value, start, len, 0)
#define ___string_new_4(nameref, value, start, len, _const) string_new_ex(&nameref, value, start, len, _const)

#define cstrcast(...) PP_OVERLOAD(___cstrcast_, __VA_ARGS__)
#define ___cstrcast_0(...) static_assert(0, "Not enough arguments, at least 1 are required")
#define ___cstrcast_1(value) (string_t){.data = (char*)value, .len = ccp_len(value), .is_const = 0}
#define ___cstrcast_2(value, _len) (string_t){.data = (char*)value, .len = _len, .is_const = 0}
#define ___cstrcast_3(value, start, _len) (string_t){.data = (char*)value + start, .len = _len, .is_const = 0}
#define ___cstrcast_4(value, start, _len, _const) (string_t){.data = (char*)value + start, .len = _len, .is_const = _const}

#define string_copy(ret, _str) string_new_ex(&ret, str->_str, 0, str->len, 0)
void string_new_ex(string_t* ret, const char* str, size_t start, size_t end, bool const);
void string_free(string_t* ret);

#define to_string(ret, val) _Generic(\
    const char*:    string_new(&ret, ___string_handle_value_type(val), 0, ___string_handle_value_type_len(val), 0), \
    char*:          string_new(&ret, ___string_handle_value_type(val), 0, ___string_handle_value_type_len(val), 0), \
    string_t:       string_new(&ret, ___string_handle_value_type(val), 0, ___string_handle_value_type_len(val), 0), \
    string_t*:      string_new(&ret, ___string_handle_value_type(val), 0, ___string_handle_value_type_len(val), 0), \
    const string_t: string_new(&ret, ___string_handle_value_type(val), 0, ___string_handle_value_type_len(val), 0), \
    const string_t*:string_new(&ret, ___string_handle_value_type(val), 0, ___string_handle_value_type_len(val), 0), \
    const char:     string_new(&ret, ___string_handle_value_type(val), 0, ___string_handle_value_type_len(val), 0), \
    char:           string_new(&ret, ___string_handle_value_type(val), 0, ___string_handle_value_type_len(val), 0), \
    const short:    shorttostring(&ret, (short)val), \
    short:          shorttostring(&ret, (short)val), \
    const int:      inttostring(&ret, (int)val), \
    int:            inttostring(&ret, (int)val), \
    const long:     longtostring(&ret, (long)val), \
    long:           longtostring(&ret, (long)val), \
    const float:    floattostring(&ret, (float)val), \
    float:          floattostring(&ret, (float)val), \
    const double:   doubletostring(&ret, (double)val), \
    double:         doubletostring(&ret, (double)val), \
    default: static_assert(0, "Invalid value type")\
)

#define from_string(str, type) stringto##type(&str)

short  stringtoshort( string_t* str, size_t index);
int    stringtoint(   string_t* str, size_t index);
long   stringtolong(  string_t* str, size_t index);
float  stringtofloat( string_t* str, size_t index);
double stringtodouble(string_t* str, size_t index);
bool   stringtobool(  string_t* str, size_t index);

// There is no need for chartostring, it is already a string
void shorttostring( string_t* ret, short  val);
void inttostring(   string_t* ret, int    val);
void longtostring(  string_t* ret, long   val);
void floattostring( string_t* ret, float  val);
void doubletostring(string_t* ret, double val);
void booltostring(  string_t* ret, bool  val);