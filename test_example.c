#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

int32_t num = 16;
int32_t num2 = 16;


// Example test function
static void test_example_true(void **state) {
    (void) state; // unused
    assert_int_equal(num, num2);
}

static void test_example_false(void **state) {
    (void) state; // unused
    assert_int_equal(2, 2);
}

static void test_example_bool(void **state) {
    (void) state; // unused
    assert_false(5 == 6);
}

static void test_example_range(void **state) {
    (void) state; 
    assert_in_range(2, 1, 7);
}

int func()
{
    int r = return_int();

    return r;
}

int return_int(void)
{
    return (int)mock();
}

static void test_return(void **state) {
    (void) state; 
    will_return(return_int, 42);

    assert_int_equal(func(), 42);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_example_true),
        cmocka_unit_test(test_example_false),
        cmocka_unit_test(test_example_bool),
        cmocka_unit_test(test_example_range),
        cmocka_unit_test(test_return)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
