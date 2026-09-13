#include "address-base58/engine.h"

#include <iostream>

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            std::cerr << "fail: " #cond "\n";                                \
            return 1;                                                        \
        }                                                                    \
    } while (0)

int main() {
    CHECK(b58addr::ticker(1) > 0);
    CHECK(!b58addr::allow(50, 100, 0.1));
    CHECK(b58addr::allow(10, 100, 0.5));
    auto r = b58addr::backtest(16);
    CHECK(r.bars == 16);
    CHECK(r.equity > 0);
    std::cout << "ok\n";
    return 0;
}
