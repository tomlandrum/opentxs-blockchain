// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_BLOCKCHAIN_INTERFACE_HPP
#define OPENTXS_BLOCKCHAIN_INTERFACE_HPP

#include "Forward.hpp"

#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <vector>
#include <string>

namespace opentxs
{
namespace blockchain
{
enum class Type {
    Bitcoin,
    Bitcoin_testnet3,
    BitcoinCash,
    BitcoinCash_testnet3,
    Ethereum_frontier,
    Ethereum_ropsten,
};

enum class SubaccountType {
    HD,
    PaymentCode,
    Imported,
};

enum class Subchain {
    None,
    Internal,
    External,
    Incoming,
    Outgoing,
};

using Amount = std::uint64_t;
using Nonce = Amount;
using ChainHeight = std::uint32_t;
using HDIndex = std::uint32_t;

// Callbacks provided by this library
using AccountAddedCallback = std::function<void(const std::size_t)>;
using SubaccountTypeAddedCallback =
    std::function<void(const SubaccountType type, const std::size_t)>;
using AddressAllocatedCallback = std::function<void(const HDIndex)>;

// Callbacks provided by library customers
using ChainExtendedCallback = std::function<void(const ChainHeight)>;
using IndexUpdatedCallback =
    std::function<void(const Subchain type, const std::size_t)>;

using Data = std::vector<std::byte>;

std::shared_ptr<Network> Factory(
    const Type type,
    const BalanceList& addresses,
    const std::string rpcUri = "",
    const std::string wsUri = "");
}  // namespace blockchain
}  // namespace opentxs
#endif  // OPENTXS_BLOCKCHAIN_INTERFACE_HPP
