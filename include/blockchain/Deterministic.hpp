// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_BLOCKCHAIN_DETERMINISTIC_HPP
#define OPENTXS_BLOCKCHAIN_DETERMINISTIC_HPP

#include "BalanceNode.hpp"

namespace opentxs
{
namespace blockchain
{
class Deterministic : virtual public BalanceNode
{
public:
    virtual HDIndex AllocateNext(const Subchain type) const = 0;
    virtual Data Xpriv() const = 0;

    virtual bool SetIndexUpdatedCallback(
        IndexUpdatedCallback&& callback) const = 0;

    virtual ~Deterministic() = default;

protected:
    Deterministic() = default;

private:
    Deterministic(const Deterministic&) = delete;
    Deterministic(Deterministic&&) = delete;
    Deterministic& operator=(const Deterministic&) = delete;
    Deterministic& operator=(Deterministic&&) = delete;
};
}  // namespace blockchain
}  // namespace opentxs
#endif  // OPENTXS_BLOCKCHAIN_DETERMINISTIC_HPP
