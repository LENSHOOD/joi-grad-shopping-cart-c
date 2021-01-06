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

void shopping_cart_test_should_calculate_price_for_buy_2_get_1(void) {
    Product products[] = {
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
    };

    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.total_price, 200)
}

void shopping_cart_test_should_calculate_loyalty_points_for_buy_2_get_1(void) {
    Product products[] = {
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
    };

    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.loyalty_points, 40)
}

void shopping_cart_test_should_calculate_price_for_buy_2_get_1_with_two_products(void) {
    Product products[] = {
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
    };

    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.total_price, 200)
}

void shopping_cart_test_should_calculate_loyalty_points_for_buy_2_get_1_two_products(void) {
    Product products[] = {
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
    };

    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.loyalty_points, 40)
}

void shopping_cart_test_should_calculate_price_for_buy_2_get_1_with_different_products(void) {
    Product products[] = {
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "DIS_20_ABCD", kProduct},
    };

    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.total_price, 280)
}

void shopping_cart_test_should_calculate_loyalty_points_for_buy_2_get_1_different_products(void) {
    Product products[] = {
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "DIS_20_ABCD", kProduct},
    };

    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.loyalty_points, 45)
}

void shopping_cart_test_should_calculate_price_for_buy_2_get_1_with_5_same_products(void) {
    Product products[] = {
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
    };

    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.total_price, 400)
}

void shopping_cart_test_should_calculate_loyalty_points_for_buy_2_get_1_with_5_same_products(void) {
    Product products[] = {
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
    };

    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.loyalty_points, 80)
}

void shopping_cart_test_should_calculate_price_for_buy_2_get_1_with_6_same_products(void) {
    Product products[] = {
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
    };

    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.total_price, 400)
}

void shopping_cart_test_should_calculate_loyalty_points_for_buy_2_get_1_with_6_same_products(void) {
    Product products[] = {
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
            {kPrice, "BULK_BUY_2_GET_1", kProduct},
    };

    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    CU_ASSERT_EQUAL(order.loyalty_points, 80)
}