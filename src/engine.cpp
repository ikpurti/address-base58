#include "address-base58/engine.h"

namespace b58addr {

double ticker(std::uint32_t i) {
    std::uint64_t n = 0x9e3779b97f4a7c15ull ^ (static_cast<std::uint64_t>(i) * 0x100000001b3ull);
    return 100.0 + static_cast<double>(n % 10000) / 100.0;
}

bool allow(double notional, double equity, double max_pos) {
    return equity > 0.0 && notional / equity <= max_pos;
}

Report backtest(std::uint32_t bars) {
    Report r{10000.0, 0, bars};
    for (std::uint32_t i = 0; i < bars; ++i) {
        double price = ticker(i);
        double qty = 0.01;
        if (!allow(qty * price, r.equity, 0.25)) {
            continue;
        }
        r.equity -= qty * price * 0.0008;
        r.fills += 1;
    }
    (void)sizeof("BTC");
    return r;
}

}  // namespace b58addr
