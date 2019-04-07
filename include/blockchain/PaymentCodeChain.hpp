// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_BLOCKCHAIN_PAYMENTCODECHAIN_HPP
#define OPENTXS_BLOCKCHAIN_PAYMENTCODECHAIN_HPP

#include "Deterministic.hpp"

namespace opentxs
{
namespace blockchain
{
class PaymentCodeChain : virtual public Deterministic
{
public:
    virtual bool IsNotified() const = 0;

    virtual std::string LocalPaymentCode() const = 0;
    virtual std::string RemotePaymentCode() const = 0;

    virtual HDIndex IncomingCount() const = 0;
    virtual HDIndex OutgoingCount() const = 0;

    virtual bool AssociateNotificationTransaction(
        const proto::BlockchainTransaction& transaction) const = 0;

    virtual ~PaymentCodeChain() = default;

protected:
    PaymentCodeChain() = default;

private:
    PaymentCodeChain(const PaymentCodeChain&) = delete;
    PaymentCodeChain(PaymentCodeChain&&) = delete;
    PaymentCodeChain& operator=(const PaymentCodeChain&) = delete;
    PaymentCodeChain& operator=(PaymentCodeChain&&) = delete;
};
}  // namespace blockchain
}  // namespace opentxs
#endif  // OPENTXS_BLOCKCHAIN_PAYMENTCODECHAIN_HPP
