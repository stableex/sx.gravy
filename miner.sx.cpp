#include "gravy.hpp"
#include "miner.sx.hpp"

[[eosio::on_notify("gravyhftdefi::transfer")]]
void sx::miner::on_gravy( const name from, const name to, const asset quantity, const string memo )
{
    const name contract = "gravyhftdefi"_n;
    const symbol_code symcode = symbol_code{"GRV"};

    // now check
    gravy::stat _stat(contract, symcode.raw());
    const int64_t now = current_time_point().time_since_epoch().count();
    const int64_t last_mine_time = _stat.get(symcode.raw()).last_mine_time;
    check(now != last_mine_time, "Error 3080002: transaction exceeded the current network usage limit imposed on the transaction");
}

[[eosio::action]]
void sx::miner::test()
{
    print("time");
}
