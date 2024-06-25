//
// Created by Galit Lebedev on 24/06/2024.
//
#include "BlockChain.h"
int BlockChainGetSize(const BlockChain& blockChain){
    int count = 0;
    const BlockChain* block_ptr = &blockChain;
    while(block_ptr != nullptr){
        count++;
        block_ptr = block_ptr->next;
    }
    return count;
}

void BlockChainAppendTransaction(
        BlockChain& blockChain,
        const Transaction& transaction,
        const string& timestamp
)
{
    BlockChain new_block =BlockChain(transaction,timestamp,&blockChain);
}

void BlockChainAppendTransaction(
        BlockChain& blockChain,
        unsigned int value,
        const string& sender,
        const string& receiver,
        const string& timestamp
){
    Transaction transaction;
    transaction.value=value;
    transaction.receiver=sender;
    transaction.receiver=receiver;
    BlockChain new_block =BlockChain(transaction,timestamp,&blockChain);
}