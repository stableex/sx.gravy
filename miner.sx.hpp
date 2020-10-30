#pragma once

#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <eosio/system.hpp>

namespace sx {

using eosio::name;
using eosio::asset;
using eosio::symbol_code;
using eosio::current_time_point;
using eosio::check;
using eosio::time_point_sec;
using eosio::print;

using std::string;

class [[eosio::contract("miner.sx")]] miner : public eosio::contract {
public:
    using contract::contract;

    [[eosio::action]]
    void test();

    [[eosio::on_notify("gravyhftdefi::transfer")]]
    void on_gravy( const name from, const name to, const asset quantity, const string memo );
};
}