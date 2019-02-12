// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "blockchain/Interface.hpp"

namespace opentxs::blockchain::implementation
{
class Network : public opentxs::blockchain::Network
{
public:
    virtual ChainHeight GetConfirmations(
        const std::string& txid) const override;
    virtual ChainHeight GetHeight() const override;
    virtual std::size_t GetPeerCount() const override;
    virtual Type GetType() const override;
    virtual std::string SendToAddress(
        const std::string& address,
        const Amount amount,
        const BalanceTree& source) const override;
    virtual std::string SendToPaymentCode(
        const std::string& address,
        const Amount amount,
        const PaymentCodeChain& source) const override;

    virtual bool Connect() override;
    virtual bool Disconnect() override;
    virtual bool SetChainExtendedCallback(
        ChainExtendedCallback&& callback) override;

    virtual ~Network() = default;

protected:
    friend std::unique_ptr<opentxs::blockchain::Network> opentxs::blockchain::
        Factory(const Type type, const BalanceList& addresses);
    friend std::unique_ptr<opentxs::blockchain::Network> opentxs::blockchain::
        Factory(
            const Type type,
            const BalanceList& addresses,
            const std::string rpcUri,
            const std::string wsUri);
    Network() = default;

private:
    Network(const Network&) = delete;
    Network(Network&&) = delete;
    Network& operator=(const Network&) = delete;
    Network& operator=(Network&&) = delete;
};
}  // namespace opentxs::blockchain::implementation
