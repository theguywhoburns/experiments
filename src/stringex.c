#include <assert.h>
#include <stdlib.h>
#include <stringex.h>
#include <string.h>
#include <ctype.h>
size_t ccp_len(const char* ccp) {
    const char* t = ccp;
    while(*t++);
    return t - ccp - 1;
}

void string_new_ex(string_t* ret, const char* str, size_t start, size_t end, bool const) {
    assert(ret != NULL && "ret must not be NULL");
    assert(str != NULL && "str must not be NULL");
    assert(start <= end && "start must be less or equal than end");

    string_t _ret = {0};

    _ret.str = (char*)malloc(end - start + 1);
    _ret.str[end - start] = '\0';
    _ret.len = end - start;

    string_free(ret);
    *ret = _ret;
}

void string_free(string_t* ret) {
    assert(ret != NULL && "ret must not be NULL");
    if(ret->str && !ret->_const)free(ret->str);
    *ret = (string_t){0};
}

short stringtoshort(string_t* str, size_t index) {
    assert(str != NULL && "str must not be NULL");
    assert(index < str->len && "index must be less than str len");

    short ret = 0;
    while(index < str->len && isspace(str->str[index])) index++;
    bool neg = str->str[index] == '-';
    if(neg) index++;
    while(index < str->len && (str->str[index] >= '0' || str->str[index] <= '9' || isspace(str->str[index]))) {
        while(index < str->len && isspace(str->str[index])) index++;
        short old = ret;
        ret *= 10;
        ret += str->str[index++] - '0';
        if(old > ret) assert(0 && "overflow");
    }
    return neg ? -ret : ret;
}

int stringtoint(string_t* str, size_t index) {
    assert(str != NULL && "str must not be NULL");
    assert(index < str->len && "index must be less than str len");

    int ret = 0;
    while(index < str->len && isspace(str->str[index])) index++;
    bool neg = str->str[index] == '-';
    if(neg) index++;
    while(index < str->len && (str->str[index] >= '0' || str->str[index] <= '9' || isspace(str->str[index]))) {
        while(index < str->len && isspace(str->str[index])) index++;
        int old = ret;
        ret *= 10;
        ret += str->str[index++] - '0';
        if(old > ret) assert(0 && "overflow");
    }
    return neg ? -ret : ret;
}

long stringtolong(string_t* str, size_t index) {
    assert(str != NULL && "str must not be NULL");
    assert(index < str->len && "index must be less than str len");

    long ret = 0;
    while(index < str->len && isspace(str->str[index])) index++;
    bool neg = str->str[index] == '-';
    if(neg) index++;
    while(index < str->len && (str->str[index] >= '0' || str->str[index] <= '9' || isspace(str->str[index]))) {
        while(index < str->len && isspace(str->str[index])) index++;
        long old = ret;
        ret *= 10;
        ret += str->str[index++] - '0';
        if(old > ret) assert(0 && "overflow");
    }
    return neg ? -ret : ret;
}

float stringtofloat(string_t* str, size_t index) {
    return 0.0f;
}

double stringtodouble(string_t* str, size_t index) {
    return 0.0f;
}

bool stringtobool(string_t* str, size_t index) {
    assert(str != NULL && "str must not be NULL");
    assert(index < str->len && "index must be less than str len");

    char* end = str->str + str->len;
    char* start = str->str + index;
    char* curr = start;
    while (curr != end && isspace(*curr)) curr++;

    if (index + 4 < str->len && strncmp(curr, "true", 4) == 0) {
        return 1;
    } else if (index + 5 < str->len && strncmp(curr, "false", 5) == 0) {
        return 0;
    } else if (index + 1 < str->len && strncmp(curr, "1", 1) == 0) {
        return 1;
    } else if (index + 1 < str->len && strncmp(curr, "0", 1) == 0) {
        return 0;
    }
    return 0;
}


// There is no need for chartostring, it is already a string
void shorttostring(string_t* ret, short val) {
    short tmp = val;
    short str_len = 0;
    do {
        tmp /= 10;
        str_len++;
    } while (tmp != 0);

    char* str = malloc(str_len + 1);
    char* curr = str + str_len;
    *curr = '\0';
    curr--;
    do {
        *curr = val % 10 + '0';
        curr--;
        val /= 10;
    } while (val != 0);

    ret->str = str;
    ret->len = str_len;
}

void inttostring(string_t* ret, int val) {

}

void longtostring(string_t* ret, long val) {

}

void floattostring(string_t* ret, float val) {

}

void doubletostring(string_t* ret, double val) {

}

void booltostring(string_t* ret, bool val) {

}
