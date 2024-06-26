//
// Created by Galit Lebedev on 24/06/2024.
//
#include "BlockChain.h"

int BlockChainGetSize(const BlockChain& blockChain){
    int count = 0;
    Block* block_ptr = blockChain.head;
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
){
    Block* New_Block = new Block(transaction,timestamp,blockChain.head);
    blockChain.head = New_Block;
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

    Block* New_Block = new Block(transaction,timestamp,blockChain.head);
    blockChain.head = New_Block;
}

void BlockChainDump(const BlockChain& blockChain, ofstream& file){
    Block* block_ptr = blockChain.head;
    int i = 1;
    file << "BlockChain Info:";
    while(block_ptr != nullptr){
        file << std::endl << i << "." << std::endl;
        file << "Sender Name: " << block_ptr->transaction.sender << std::endl;
        file << "Receiver Name: " << block_ptr->transaction.receiver << std::endl;
        file << "Transaction Value: " << block_ptr->transaction.value << std::endl;
        file << "timestamp: " << block_ptr->transaction.value;
        block_ptr = block_ptr->next;
    }
}

bool BlockChainVerifyFile(const BlockChain& blockChain, std::ifstream& file){
    Block* block_ptr = blockChain.head;
    string file_line;
    while (!file.eof()){
        std::getline(file,file_line);
        if(!TransactionVerifyHashedMessage(block_ptr->transaction,file_line)) {
            return false;
        }
        block_ptr = block_ptr->next;
    }
    return true;
}

void BlockChainTransform(BlockChain& blockChain, updateFunction function) {
    Block* block_ptr = blockChain.head;
    while (block_ptr != nullptr) {
        block_ptr->transaction.value = function(block_ptr->transaction.value);
        block_ptr = block_ptr->next;
    }
}