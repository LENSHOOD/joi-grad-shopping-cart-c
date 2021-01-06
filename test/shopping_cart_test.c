#include "./shopping_cart_test.h"
#include "../include/shopping_cart.h"
#include <CUnit/Basic.h>

static int kPrice = 100;
static char *kProduct = "Product";

void shopping_cart_test_should_calculate_price_with_no_discount(void) {
    Product products[] = {
            {kPrice, "", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_DOUBLE_EQUAL(order.total_price, 100.0, 0.0);
}

void shopping_cart_test_should_calculate_loyalty_points_with_no_discount(void) {
    Product products[] = {
            {kPrice, "", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.loyalty_points, 20);
}

void shopping_cart_test_should_calculate_price_for_10_percent_discount(void) {
    Product products[] = {
            {kPrice, "DIS_10_ABCD", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_DOUBLE_EQUAL(order.total_price, 90.0, 0.0);
}

void shopping_cart_test_should_calculate_loyalty_points_for_10_percent_discount(void) {
    Product products[] = {
            {kPrice, "DIS_10_ABCD", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.loyalty_points, 10);
}

void shopping_cart_test_should_calculate_price_for_15_percent_discount(void) {
    Product products[] = {
            {kPrice, "DIS_15_ABCD", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_DOUBLE_EQUAL(order.total_price, 85.0, 0.0);
}

void shopping_cart_test_should_calculate_loyalty_points_for_15_percent_discount(void) {
    Product products[] = {
            {kPrice, "DIS_15_ABCD", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.loyalty_points, 6);
}

void shopping_cart_test_should_calculate_price_for_20_percent_discount(void) {
    Product products[] = {
            {kPrice, "DIS_20_ABCD", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_DOUBLE_EQUAL(order.total_price, 80.0, 0.0);
}

void shopping_cart_test_should_calculate_loyalty_points_for_20_percent_discount(void) {
    Product products[] = {
            {kPrice, "DIS_20_ABCD", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.loyalty_points, 5);
}