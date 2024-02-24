//12
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std;
class Product {
    string productName;
    double price;
public:
    Product(string name, double p) : productName(name), price(p) {}
    bool isDiscount(double currentPrice) {
        if (currentPrice < price)
            return true;
        else
            return false;
    }
    void printDiscount(double currentPrice) {
        if (isDiscount(currentPrice))
            cout << "There is discount for \"" << productName << "\". New price: " << currentPrice << endl;
        else
            cout << "There is no discount for \"" << productName << "\". Price: " << price << endl;
    }
};
int main() {
    Product book1("Confessions", 360);
    Product book2("Dancer", 345);
    book1.printDiscount(340);
    book2.printDiscount(345);
    return 0;
}
TEST_CASE("Discount test") {
    Product book1("Confessions", 360);
    Product book2("Dancer", 345);

    SECTION("Discount for book1") {
        REQUIRE(book1.isDiscount(350) == true);
        REQUIRE(book1.isDiscount(345) == true);
        REQUIRE(book1.isDiscount(360) == false);
    }

    SECTION("Discount for book2") {
        REQUIRE(book2.isDiscount(340) == true);
        REQUIRE(book2.isDiscount(330) == true);
        REQUIRE(book2.isDiscount(345) == false);
    }
}