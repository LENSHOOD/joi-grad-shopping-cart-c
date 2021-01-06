#include "../include/shopping_cart.h"
#include <stdio.h>

ShoppingCart shopping_cart_init(Product *products, int size, Customer customer) {
    Product *copy_products = malloc(sizeof(Product) * size);
    memcpy(copy_products, products, size * sizeof(Product));
    ShoppingCart cart = {copy_products, size, size, customer};
    return cart;
}

void shopping_cart_add_product(ShoppingCart *cart, Product product) {
    if (cart->product_size == cart->capacity) {
        int new_size = cart->capacity * 2;
        Product *copy_products = malloc(sizeof(Product) * new_size);
        memcpy(copy_products, cart->products, cart->product_size * sizeof(Product));
        free(cart->products);
        cart->products = copy_products;
        cart->capacity = new_size;
    }
    cart->products[cart->product_size++] = product;
}

void shopping_cart_print(const ShoppingCart *cart) {
    printf("Customer: %s\n", cart->customer.name);
    printf("Bought: \n");
    for (int i = 0; i < cart->product_size; ++i) {
        printf("- %s, %f\n", cart->products[i].name, cart->products[i].price);
    }
}

Order shopping_cart_checkout(const ShoppingCart *cart) {
    double total_price = 0;

    int loyalty_points_earned = 0;
    for (int i = 0; i < cart->product_size; i++) {
        double discount = 0;
        const char *product_code = cart->products[i].product_code;
        const double product_price = cart->products[i].price;
        if (strstr(product_code, "DIS_10") == product_code) {
            discount = (product_price * 0.1);
            loyalty_points_earned += (product_price / 10);
        } else if (strstr(product_code, "DIS_15") == product_code) {
            discount = (product_price * 0.15);
            loyalty_points_earned += (product_price / 15);
        } else if (strstr(product_code, "DIS_20") == product_code) {
            discount = (product_price * 0.2);
            loyalty_points_earned += (product_price / 20);
        } else {
            loyalty_points_earned += (product_price / 5);
        }
        total_price += product_price - discount;
    }
    Order order = {total_price, loyalty_points_earned};
    return order;
}
