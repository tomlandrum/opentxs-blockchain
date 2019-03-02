// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "blockchain/Network.hpp"

#include <map>
#include <mutex>
#include <string>

namespace opentxs::blockchain::implementation
{
class Network : virtual public opentxs::blockchain::Network
{
public:
    static std::mutex network_map_lock_;
    static std::map<Type, std::shared_ptr<opentxs::blockchain::Network>>
        network_map_;

    ChainHeight GetConfirmations(const std::string& txid) const override;
    ChainHeight GetHeight() const override;
    std::size_t GetPeerCount() const override;
    Type GetType() const override { return type_; }
    std::string SendToAddress(
        const std::string& address,
        const Amount amount,
        const BalanceTree& source) const override;
    std::string SendToPaymentCode(
        const std::string& address,
        const Amount amount,
        const PaymentCodeChain& source) const override;

    bool Connect() override;
    bool Disconnect() override;
    bool SetChainExtendedCallback(ChainExtendedCallback&& callback) override;
    bool Shutdown() override;

    Network(
        const Type type,
        const BalanceList& addresses,
        const std::string rpc,
        const std::string ws);

    ~Network() override = default;

private:
    const BalanceList& addresses_;
    const Type type_;
    const std::string rpc_;
    const std::string ws_;
    ChainExtendedCallback chain_callback_;

    static bool shutdown(const Type type);

    void init();
    void init_account(const blockchain::BalanceTree& account);
    void init_hdchain(const blockchain::HDChain& subaccount);
    void init_imported(const blockchain::Imported& subaccount);
    void init_paymentcode(const blockchain::PaymentCodeChain& subaccount);

    Network() = delete;
    Network(const Network&) = delete;
    Network(Network&&) = delete;
    Network& operator=(const Network&) = delete;
    Network& operator=(Network&&) = delete;
};
}  // namespace opentxs::blockchain::implementation
