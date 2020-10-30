#pragma once

#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>

using eosio::name;
using eosio::asset;
using eosio::symbol;

class [[eosio::contract("gravyhftdefi")]] gravy : public eosio::contract {
public:
    using contract::contract;

    name account = "gravyhftdefi"_n;

    struct [[eosio::table]] stat_row {
        asset           supply;
        asset           max_supply;
        name            issuer;
        uint64_t        genesis_time;
        uint64_t        last_mine_time;

        uint64_t primary_key() const { return supply.symbol.code().raw(); }
    };
    typedef eosio::multi_index< "stat"_n, stat_row > stat;

    [[eosio::action]]
    void mine( const name miner, const symbol symbol, const uint64_t rando );

    using mine_action = eosio::action_wrapper<"mine"_n, &gravy::mine>;
};
