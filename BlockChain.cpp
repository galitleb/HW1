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
void BlockChainDump(const BlockChain& blockChain, ofstream& file){
    const BlockChain* block_ptr = &blockChain;
    int i = 1;
    file << "BlockChain Info:" << std::endl;
    while(block_ptr != nullptr){
        file << i << "." << std::endl;
        file << "Sender Name: " << block_ptr->transaction.sender << std::endl;
        file << "Receiver Name: " << block_ptr->transaction.receiver << std::endl;
        file << "Transaction Value: " << block_ptr->transaction.value << std::endl;
        file << "timestamp: " << block_ptr->transaction.value << std::endl;
        block_ptr = block_ptr->next;
    }
}

bool BlockChainVerifyFile(const BlockChain& blockChain, std::ifstream& file)
{
    const BlockChain* block_ptr = &blockChain;
    string file_line;
    while (!file.eof()){
        std::getline(file,file_line);
        if(!TransactionVerifyHashedMessage(block_ptr->transaction,file_line)) return false;
        block_ptr = block_ptr->next;
    }
    return true;
}