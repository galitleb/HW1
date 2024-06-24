#pragma once

#include <iostream>
#include "Transaction.h"
#include "Utilities.h"



void TransactionDumpInfo(const Transaction& transaction, ofstream& file){
    std::cout << "Sender Name:" << transaction.sender << std:: endl;

    std::cout << "Receiver Name:" << transaction.receiver << std:: endl;

    std::cout << "ransaction Value:" << transaction.value << std:: endl;
}


string TransactionHashedMessage(const Transaction& transaction){

    return hash(transaction.value , transaction.sender , transaction.receiver);
}

bool TransactionVerifyHashedMessage(
        const Transaction& transaction,
        string hashedMessage){

    string s1 ;
    s1 = hash(transaction.value , transaction.sender , transaction.receiver);

    //possible in cpp
    if( s1 == hashedMessage){
        return true;
    }
    return false;
}


