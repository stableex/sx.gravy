#pragma once

#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <eosio/singleton.hpp>

namespace sx {

using eosio::name;
using eosio::asset;
using eosio::symbol_code;
using eosio::current_time_point;
using eosio::check;
using eosio::time_point;
using eosio::symbol;
using eosio::print;

using std::string;

class [[eosio::contract("gravy.sx")]] gravy : public eosio::contract {
public:
    using contract::contract;

    struct [[eosio::table("state")]] state_row {
        time_point      last;
        uint64_t        count = 0;
        asset           total = asset{0, symbol{"GRV", 8}};
    };
    typedef eosio::singleton< "state"_n, state_row > state;

    [[eosio::action]]
    void reset();

    [[eosio::on_notify("gravyhftdefi::transfer")]]
    void on_gravy( const name from, const name to, const asset quantity, const string memo );
};
}