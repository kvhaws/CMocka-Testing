#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "file.c"

int32_t wrapMe(const int32_t *num) {
    return 0;
}

int32_t __wrap_wrapMe(const int32_t *num)
{
   check_expected_ptr(num);

   return mock_type(int32_t);
}

static void test_wrap(void **state)
{
    int num = 0; 
    expect_any(__wrap_wrapMe, num);
    will_return(__wrap_wrapMe, 36);
    assert_int_equal(__wrap_wrapMe(&num), 36);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_wrap)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
