// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "blockchain/Network.hpp"

#include "Network.hpp"

namespace opentxs::blockchain
{

std::unique_ptr<Network> Factory(const Type type, const BalanceList& addresses)
{
    std::unique_ptr<opentxs::blockchain::Network> network;
    network.reset(new implementation::Network());
    return network;
}

std::unique_ptr<Network> Factory(
    const Type type,
    const BalanceList& addresses,
    const std::string rpcUri,
    const std::string wsUri)
{
    std::unique_ptr<opentxs::blockchain::Network> network;
    network.reset(new implementation::Network());
    return {};
}

}  // namespace opentxs::blockchain
