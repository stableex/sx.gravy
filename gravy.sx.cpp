#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>

using namespace eosio;
using namespace std;

class [[eosio::contract("gravy.sx")]] gravy : public eosio::contract {
public:
    using contract::contract;

    [[eosio::on_notify("gravyhftdefi::transfer")]]
    void on_gravy( const name from, const name to, const asset quantity, const string memo )
    {
        check(quantity.amount > 35000, "must be above 35000 GRV");
    }
};
