// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_BLOCKCHAIN_BALANCETREE_HPP
#define OPENTXS_BLOCKCHAIN_BALANCETREE_HPP

#include "blockchain/Interface.hpp"

#include <opentxs-proto/Types.hpp>

namespace opentxs
{
namespace blockchain
{
class BalanceTree
{
public:
    virtual std::size_t CreatePaymentCodeChain(
        const std::string& localPaymentCode,
        const std::string& localRemoteCode) const = 0;

    virtual std::size_t GetHDCount() const = 0;
    virtual std::size_t GetImportedCount() const = 0;
    virtual std::size_t GetPaymentCodeCount() const = 0;

    virtual const blockchain::HDChain& HDChain(
        const std::size_t index) const = 0;
    virtual const blockchain::Imported& Imported(
        const std::size_t index) const = 0;
    virtual const blockchain::PaymentCodeChain& PaymentCodeChain(
        const std::size_t index) const = 0;

    virtual bool SetNewSubaccountTypeCallback(
        SubaccountTypeAddedCallback&& callback) const = 0;

    virtual bool AssociateOutgoingTransaction(
        const proto::BlockchainTransaction& transaction) const = 0;

    virtual ~BalanceTree() = default;

protected:
    BalanceTree() = default;

private:
    BalanceTree(const BalanceTree&) = delete;
    BalanceTree(BalanceTree&&) = delete;
    BalanceTree& operator=(const BalanceTree&) = delete;
    BalanceTree& operator=(BalanceTree&&) = delete;
};
}  // namespace blockchain
}  // namespace opentxs
#endif  // OPENTXS_BLOCKCHAIN_BALANCETREE_HPP
