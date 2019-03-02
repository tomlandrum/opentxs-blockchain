// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_BLOCKCHAIN_ETHEREUM_HPP
#define OPENTXS_BLOCKCHAIN_ETHEREUM_HPP

#include "blockchain/Imported.hpp"

namespace opentxs
{
namespace blockchain
{
class Ethereum : virtual public Imported
{
public:
    virtual Nonce operator++() const = 0;

    virtual Amount GetBalance() const = 0;
    virtual Nonce GetNonce() const = 0;
    virtual void SetBalance(const Amount balance) const = 0;
    virtual void SetNonce(const Nonce nonce) const = 0;

    virtual ~Ethereum() = default;

protected:
    Ethereum() = default;

private:
    Ethereum(const Ethereum&) = delete;
    Ethereum(Ethereum&&) = delete;
    Ethereum& operator=(const Ethereum&) = delete;
    Ethereum& operator=(Ethereum&&) = delete;
};
}  // namespace blockchain
}  // namespace opentxs
#endif  // OPENTXS_BLOCKCHAIN_ETHEREUM_HPP
