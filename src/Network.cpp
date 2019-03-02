// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "blockchain/BalanceList.hpp"
#include "blockchain/BalanceTree.hpp"
#include "blockchain/HDChain.hpp"
#include "blockchain/Network.hpp"

#include "Network.hpp"

namespace opentxs::blockchain::implementation
{
Network::Network(
    const Type type,
    const BalanceList& addresses,
    const std::string rpc,
    const std::string ws)
    : addresses_(addresses)
    , type_(type)
    , rpc_(rpc)
    , ws_(ws)
    , chain_callback_()
{
    init();
}

bool Network::Connect() { return false; }

bool Network::Disconnect() { return false; }

ChainHeight Network::GetConfirmations(const std::string& txid) const
{
    return 0;
}

ChainHeight Network::GetHeight() const { return 0; }

std::size_t Network::GetPeerCount() const { return 0; }

void Network::init()
{
    for (std::size_t i = 0; i < addresses_.GetAccountCount(); ++i) {
        init_account(addresses_.Account(i));
    }

    addresses_.SetNewAccountCallback([this](const std::size_t i) -> void {
        init_account(addresses_.Account(i));
    });
}

void Network::init_account(const blockchain::BalanceTree& account)
{
    for (std::size_t i = 0; i < account.GetHDCount(); ++i) {
        init_hdchain(account.HDChain(i));
    }

    for (std::size_t i = 0; i < account.GetPaymentCodeCount(); ++i) {
        init_paymentcode(account.PaymentCodeChain(i));
    }

    for (std::size_t i = 0; i < account.GetImportedCount(); ++i) {
        init_imported(account.Imported(i));
    }

    account.SetNewSubaccountTypeCallback(
        [this,
         &account](const SubaccountType type, const std::size_t i) -> void {
            switch (type) {
                case SubaccountType::HD: {
                    init_hdchain(account.HDChain(i));
                } break;
                case SubaccountType::PaymentCode: {
                    init_paymentcode(account.PaymentCodeChain(i));
                } break;
                case SubaccountType::Imported: {
                    init_imported(account.Imported(i));
                } break;
                default: {
                    throw;
                }
            }
        });
}

void Network::init_hdchain(const blockchain::HDChain& subaccount)
{
    subaccount.SetAddressAllocatedCallback([this](const HDIndex i) -> void {
        // TODO the library customer has allocated a new receiving address
        // Update lookahead window as appropriate.
    });

    // TODO find and watch for incoming / outgoing transactions associated with
    // the internal and external chains on this aubaccount
}

void Network::init_imported(const blockchain::Imported& subaccount)
{
    // TODO find and watch for incoming / outgoing transactions associated with
    // this single address (or Ethereum account)
}

void Network::init_paymentcode(const blockchain::PaymentCodeChain& subaccount)
{
    // TODO find and watch for incoming / outgoing transactions associated with
    // this payment code channel
}

std::string Network::SendToAddress(
    const std::string& address,
    const Amount amount,
    const BalanceTree& source) const
{
    // NOTE Call Deterministic::AllocateNext on the appropriate subaccount
    // to inform the library customer which change address was used

    return {};
}

std::string Network::SendToPaymentCode(
    const std::string& address,
    const Amount amount,
    const PaymentCodeChain& source) const
{
    // NOTE Call Deterministic::AllocateNext on the appropriate subaccount
    // to inform the library customer which change address was used

    // NOTE Call Deterministic::AllocateNext on the appropriate subaccount
    // to inform the library customer which outgoing address was used

    return {};
}

bool Network::SetChainExtendedCallback(ChainExtendedCallback&& callback)
{
    // NOTE chain_callback_ should be executed every time the best chain head
    // changes

    chain_callback_ = callback;

    return true;
}

bool Network::shutdown(const Type type)
{
    std::lock_guard<std::mutex> lock(network_map_lock_);
    auto it = network_map_.find(type);

    if (network_map_.end() == it) { return false; }

    if (it->second) { it->second->Disconnect(); }

    network_map_.erase(it);

    return true;
}

bool Network::Shutdown() { return shutdown(type_); }
}  // namespace opentxs::blockchain::implementation
