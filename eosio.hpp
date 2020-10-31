namespace eosio {
class [[eosio::contract("eosio")]] eosiosystem : public eosio::contract {
public:
    using contract::contract;

    [[eosio::action]]
    void rentcpu( const name from, const name receiver, const asset loan_payment, const asset loan_fund );

    [[eosio::action]]
    void deposit( const name owner, const asset amount );

    using rentcpu_action = eosio::action_wrapper<"rentcpu"_n, &eosio::eosiosystem::rentcpu>;
    using deposit_action = eosio::action_wrapper<"deposit"_n, &eosio::eosiosystem::deposit>;
};
}