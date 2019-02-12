// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_BLOCKCHAIN_HDCHAIN_HPP
#define OPENTXS_BLOCKCHAIN_HDCHAIN_HPP

#include "opentxs-blockchain/Interface.hpp"

namespace opentxs
{
namespace blockchain
{
class HDChain : virtual public Deterministic
{
public:
    virtual HDIndex ExternalCount() const = 0;
    virtual HDIndex InternalCount() const = 0;

    virtual bool SetIndexUpdatedCallback(
        IndexUpdatedCallback&& callback) const = 0;

    virtual ~HDChain() = default;

protected:
    HDChain() = default;

private:
    HDChain(const HDChain&) = delete;
    HDChain(HDChain&&) = delete;
    HDChain& operator=(const HDChain&) = delete;
    HDChain& operator=(HDChain&&) = delete;
};

}  // namespace blockchain
}  // namespace opentxs
#endif  // OPENTXS_BLOCKCHAIN_HDCHAIN_HPP
