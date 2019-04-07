// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_BLOCKCHAIN_IMPORTED_HPP
#define OPENTXS_BLOCKCHAIN_IMPORTED_HPP

#include "BalanceNode.hpp"

namespace opentxs
{
namespace blockchain
{
class Imported : virtual public BalanceNode
{
public:
    virtual Data PrivateKey() const = 0;

    virtual ~Imported() = default;

protected:
    Imported() = default;

private:
    Imported(const Imported&) = delete;
    Imported(Imported&&) = delete;
    Imported& operator=(const Imported&) = delete;
    Imported& operator=(Imported&&) = delete;
};
}  // namespace blockchain
}  // namespace opentxs
#endif  // OPENTXS_BLOCKCHAIN_IMPORTED_HPP
