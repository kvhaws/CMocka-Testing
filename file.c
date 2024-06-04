#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <setjmp.h>

#include <cmocka.h>

int32_t wrapMe(const int *num);

bool sendCommand(int32_t num) {
    bool function_return = false;
    if (wrapMe(&num) == num)
        function_return = true;
    
    return function_return;
}
