#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void test_file_example(void **state) {
    (void) state; 
    assert_int_not_equal(1, 7);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_file_example)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}