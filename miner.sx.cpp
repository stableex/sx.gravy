#include "gravy.hpp"
#include "miner.sx.hpp"

[[eosio::on_notify("gravyhftdefi::transfer")]]
void sx::miner::on_gravy( const name from, const name to, const asset quantity, const string memo )
{
    const name contract = "gravyhftdefi"_n;
    const symbol_code symcode = symbol_code{"GRV"};

    // only mine once per block
    sx::miner::state _state( get_self(), get_self().value );
    auto state = _state.get_or_default();
    const time_point last = current_time_point();
    check(state.last != last, "can only mine 1 block per transaction");

    // update state
    state.last = last;
    state.count += 1;
    state.total += quantity;
    _state.set(state, get_self());
}
