#include <eosio.token/eosio.token.hpp>
#include "gravy.sx.hpp"
#include "eosio.hpp"

void sx::gravy::reset()
{
    require_auth( get_self() );
    sx::gravy::state _state( get_self(), get_self().value );
    _state.remove();
}

[[eosio::on_notify("gravyhftdefi::transfer")]]
void sx::gravy::on_gravy( const name from, const name to, const asset quantity, const string memo )
{
    const name contract = "gravyhftdefi"_n;
    const symbol_code symcode = symbol_code{"GRV"};

    // record state
    sx::gravy::state _state( get_self(), get_self().value );
    auto state = _state.get_or_default();
    state.last = current_time_point();
    state.count += 1;
    state.total += quantity;
    _state.set(state, get_self());

    // const time_point last = current_time_point();
    // check(state.last != last, "can only mine 1 block per transaction");
    check(quantity.amount > 30000, "must be above 30000 GRV");

    // empty GRV
    const asset balance = eosio::token::get_balance( contract, get_self(), symbol_code{"GRV"});
    if ( balance.amount > 10000000 ) {
        eosio::token::transfer_action transfer( contract, { get_self(), "active"_n });
        transfer.send(get_self(), "swap.defi"_n, balance, "swap,0,786");
    }

    // empty EOS
    const asset balance_eos = eosio::token::get_balance( "eosio.token"_n, get_self(), symbol_code{"EOS"});
    if ( balance_eos.amount > 0 ) {
        eosio::eosiosystem::deposit_action deposit( "eosio"_n, { get_self(), "active"_n });
        eosio::eosiosystem::rentcpu_action rentcpu( "eosio"_n, { get_self(), "active"_n });
        deposit.send(get_self(), balance );
        rentcpu.send(get_self(), get_self(), balance, asset{0, balance.symbol });
    }
}
