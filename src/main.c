#include <util.h>

#define CONSOLE_RGB(...) PP_OVERLOAD(CONSOLE_RGB_, __VA_ARGS__)
typedef struct RGB {
    unsigned char R;
    unsigned char G;
    unsigned char B;
} RGB;
#define CONSOLE_RGB_0(...) "\033[0m"
#define CONSOLE_RGB_1(...) PP_STATIC_ASSERT(false, "0-4, 6 args")
#define CONSOLE_RGB_2(...) PP_STATIC_ASSERT(false, "0-4, 6 args")
#define CONSOLE_RGB_3(r, g, b) "\033[38;2;"#r";"#g";"#b"m"
#define CONSOLE_RGB_4(...) PP_STATIC_ASSERT(false, "0-4, 6 args")
#define CONSOLE_RGB_5(...) PP_STATIC_ASSERT(false, "0-4, 6 args")
#define CONSOLE_RGB_3(bg_r, bg_g, bg_b, fg_r, fg_g, fg_b) "\033[48;2;"#bg_r";"#bg_g";"#bg_b";38;2"#fg_r";"#fg_g";"#fg_b"m"
#define CONSOLE_RGB_7(...) PP_STATIC_ASSERT(false, "0-4, 6 args")
int main() {

}