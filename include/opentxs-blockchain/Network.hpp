// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_BLOCKCHAIN_NETWORK_HPP
#define OPENTXS_BLOCKCHAIN_NETWORK_HPP

#include "opentxs-blockchain/Interface.hpp"

namespace opentxs
{
namespace blockchain
{
class Network
{
public:
    virtual ChainHeight GetConfirmations(const std::string& txid) const = 0;
    virtual ChainHeight GetHeight() const = 0;
    virtual std::size_t GetPeerCount() const = 0;
    virtual Type GetType() const = 0;
    virtual std::string SendToAddress(
        const std::string& address,
        const Amount amount,
        const BalanceTree& source) const = 0;
    virtual std::string SendToPaymentCode(
        const std::string& address,
        const Amount amount,
        const PaymentCodeChain& source) const = 0;

    virtual bool Connect() = 0;
    virtual bool Disconnect() = 0;
    virtual bool SetChainExtendedCallback(ChainExtendedCallback&& callback) = 0;

    virtual ~Network() = default;

protected:
    Network() = default;

private:
    Network(const Network&) = delete;
    Network(Network&&) = delete;
    Network& operator=(const Network&) = delete;
    Network& operator=(Network&&) = delete;
};
}  // namespace blockchain
}  // namespace opentxs
#endif  // OPENTXS_BLOCKCHAIN_NETWORK_HPP
