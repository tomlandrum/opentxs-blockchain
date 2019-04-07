// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_BLOCKCHAIN_BALANCELIST_HPP
#define OPENTXS_BLOCKCHAIN_BALANCELIST_HPP

#include "Interface.hpp"

namespace opentxs
{
namespace blockchain
{
class BalanceList
{
public:
    virtual std::size_t GetAccountCount() const = 0;

    virtual const blockchain::BalanceTree& Account(
        const std::size_t index) const = 0;

    virtual bool SetNewAccountCallback(
        AccountAddedCallback&& callback) const = 0;

    virtual ~BalanceList() = default;

protected:
    BalanceList() = default;

private:
    BalanceList(const BalanceList&) = delete;
    BalanceList(BalanceList&&) = delete;
    BalanceList& operator=(const BalanceList&) = delete;
    BalanceList& operator=(BalanceList&&) = delete;
};
}  // namespace blockchain
}  // namespace opentxs
#endif  // OPENTXS_BLOCKCHAIN_BALANCELIST_HPP
