// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_BLOCKCHAIN_BALANCENODE_HPP
#define OPENTXS_BLOCKCHAIN_BALANCENODE_HPP

#include "opentxs-blockchain/Interface.hpp"

namespace opentxs
{
namespace blockchain
{
class BalanceNode
{
public:
    virtual const BalanceTree& Parent() const = 0;

    virtual Data GetLastBlockHash() const = 0;

    virtual bool SetLastBlockHash(const Data& hash) const = 0;

    virtual bool AssociateIncomingTransaction(
        const proto::BlockchainTransaction& transaction,
        const Subchain chain,
        const HDIndex index) const = 0;

    virtual ~BalanceNode() = default;

protected:
    BalanceNode() = default;

private:
    BalanceNode(const BalanceNode&) = delete;
    BalanceNode(BalanceNode&&) = delete;
    BalanceNode& operator=(const BalanceNode&) = delete;
    BalanceNode& operator=(BalanceNode&&) = delete;
};
}  // namespace blockchain
}  // namespace opentxs
#endif  // OPENTXS_BLOCKCHAIN_BALANCENODE_HPP
