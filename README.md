# `gravy.sx`

> Profitable Gravy mining

```c++
[[eosio::on_notify("gravyhftdefi::transfer")]]
void on_gravy( const name from, const name to, const asset quantity, const string memo )
{
    check(quantity.amount > 35000, "must be above 35000 GRV");
}
```

## Quickstart

**register miner**

```bash
cleos push action gravyhftdefi regminer '["gravy.sx","8,GRV"]' -p gravy.sx
```

**mine**

```bash
$ cleos push action gravyhftdefi mine '["gravy.sx", "8,GRV", 123]' -p gravy.sx
```
