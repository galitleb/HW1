#pragma once

#include <iostream>
#include "Transaction.h"
#include "Utilities.h"


void TransactionDumpInfo(const Transaction& transaction, ofstream& file){
    std::cout << "Sender Name:" << transaction.sender << std:: endl;

    std::cout << "Receiver Name:" << transaction.receiver << std:: endl;

    std::cout << "ransaction Value:" << transaction.value << std:: endl;
}

