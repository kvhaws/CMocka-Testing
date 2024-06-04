// Includes
#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "file.c"

// Dummy wrapMe function to snuff out linking errors
int32_t wrapMe(const int32_t *num) {
    return 0;
}

// Wrapped function of above wrapMe. Returns the mock type, checks if the function was fed the correct argument.
int32_t __wrap_wrapMe(const int32_t *num)
{
   check_expected_ptr(num);

   return mock_type(int32_t);
}

// Tells the wrapped function to expect any parameter, assigns it to return 36, then checks that using an assertion.
static void test_wrap(void **state)
{
    int num = 0; 
    expect_any(__wrap_wrapMe, num);
    will_return(__wrap_wrapMe, 36);
    assert_int_equal(__wrap_wrapMe(&num), 36);
}

// Runs the test_wrap function.
int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_wrap)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
