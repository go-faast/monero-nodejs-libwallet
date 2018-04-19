#pragma once

#include "deferredtask.h"
#include "walletargs.h"

namespace exawallet {

class CreateWalletTask: public DeferredTask {
public:
    CreateWalletTask(v8::Isolate* isolate, const CreateWalletArgs& args): DeferredTask(isolate), args_(args) {}

    virtual std::string doWork() override;
    virtual v8::Local<v8::Value> afterWork(v8::Isolate* isolate, std::string& error) override;

private:
    CreateWalletArgs args_;
    Monero::Wallet* wallet_ = nullptr;
};

class OpenWalletTask: public DeferredTask {
public:
    OpenWalletTask(v8::Isolate* isolate, const OpenWalletArgs& args): DeferredTask(isolate), args_(args) {}

    virtual std::string doWork() override;
    virtual v8::Local<v8::Value> afterWork(v8::Isolate* isolate, std::string& error) override;

private:
    OpenWalletArgs args_;
    Monero::Wallet* wallet_ = nullptr;
};

class StoreWalletTask: public DeferredTask {
public:
    StoreWalletTask(v8::Isolate* isolate, Monero::Wallet* wallet): DeferredTask(isolate), wallet_(wallet) {}

    virtual std::string doWork() override;
    virtual v8::Local<v8::Value> afterWork(v8::Isolate* isolate, std::string& error) override;
private:
    Monero::Wallet* wallet_;
};

class CreateTransactionTask: public DeferredTask {
public:
    CreateTransactionTask(v8::Isolate* isolate, const CreateTransactionArgs& args, Monero::Wallet* wallet): DeferredTask(isolate), args_(args), wallet_(wallet) {}

    virtual std::string doWork() override;
    virtual v8::Local<v8::Value> afterWork(v8::Isolate* isolate, std::string& error) override;

private:
    CreateTransactionArgs args_;
    Monero::PendingTransaction* transaction_ = nullptr;
    Monero::Wallet* wallet_;
};

class CommitTransactionTask: public DeferredTask {
public:
    CommitTransactionTask(v8::Isolate* isolate, Monero::PendingTransaction* transaction): DeferredTask(isolate), transaction_(transaction) {}

    virtual std::string doWork() override;
    virtual v8::Local<v8::Value> afterWork(v8::Isolate* isolate, std::string& error) override;

private:
    Monero::PendingTransaction* transaction_;
};

} //namespace exawallet
