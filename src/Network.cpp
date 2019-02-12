// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "blockchain/Network.hpp"

#include "Network.hpp"

namespace opentxs::blockchain::implementation
{

ChainHeight Network::GetConfirmations(const std::string& txid) const
{
    return 0;
}

ChainHeight Network::GetHeight() const { return 0; }

std::size_t Network::GetPeerCount() const { return 0; }

Type Network::GetType() const { return {}; }

std::string Network::SendToAddress(
    const std::string& address,
    const Amount amount,
    const BalanceTree& source) const
{
    return {};
}

std::string Network::SendToPaymentCode(
    const std::string& address,
    const Amount amount,
    const PaymentCodeChain& source) const
{
    return {};
}

bool Network::Connect() { return false; }

bool Network::Disconnect() { return false; }

bool Network::SetChainExtendedCallback(ChainExtendedCallback&& callback)
{
    return false;
}

}  // namespace opentxs::blockchain::implementation
