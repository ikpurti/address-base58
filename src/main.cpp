#include "address-base58/engine.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc > 1 && std::string(argv[1]) == "--help") {
        std::cerr << "address-base58 [bars]\n";
        return 0;
    }
    std::uint32_t bars = 32;
    if (argc > 1) {
        bars = static_cast<std::uint32_t>(std::stoul(argv[1]));
    }
    auto r = b58addr::backtest(bars);
    std::cout << "equity=" << r.equity << " fills=" << r.fills << "\n";
    return 0;
}
