// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "Network.hpp"

namespace opentxs::blockchain
{
namespace implementation
{
std::mutex Network::network_map_lock_{};
std::map<Type, std::shared_ptr<opentxs::blockchain::Network>>
    Network::network_map_{};
}  // namespace implementation

std::shared_ptr<Network> Factory(
    const Type type,
    const BalanceList& addresses,
    const std::string rpc,
    const std::string ws)
{
    std::lock_guard<std::mutex> lock(
        implementation::Network::network_map_lock_);
    auto& network = implementation::Network::network_map_[type];
    network =
        std::make_shared<implementation::Network>(type, addresses, rpc, ws);

    return network;
}
}  // namespace opentxs::blockchain
