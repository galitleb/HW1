#include <iostream>
#include <fstream>
#include "BlockChain.h"
#include "Utilities.h"

using std::string;
using std::ifstream;
using std::ofstream;

void format(ifstream &in_file, ofstream &out_file) {
    BlockChain block = BlockChainLoad(in_file);
    BlockChainDump(block, out_file);
}

void hash(ifstream &in_file, ofstream &out_file){
    BlockChain block = BlockChainLoad(in_file);
    BlockChainDumpHashed(block, out_file);
}
void compress(ifstream &in_file, ofstream &out_file) {
    BlockChain block = BlockChainLoad(in_file);
    BlockChainDump(block, out_file);
    BlockChainCompress(block);
}
void verify(ifstream &source, ifstream &target) {
    BlockChain block = BlockChainLoad(source);
    if(BlockChainVerifyFile(block,target)){
        std::cout << "Verification passed" << std::endl;
    }
    else std::cout << "Verification failed" << std::endl;
}
int main(int argc, char **argv) {
    if(argc != 4){
        getErrorMessage();
        std::cout << "Usage: Usage: ./mtm_blockchain <op> <source> <target>" << std::endl;
        return 0;
    }
    const string &sourcefile = argv[2];
    const string &target = argv[3];

    ifstream in_file(sourcefile);

    if (strcmp(argv[1],"format") == 0) {
        ofstream out_file(target);
        format(in_file,out_file);
        out_file.close();
    }
    if (strcmp(argv[1],"hash") == 0) {
        ofstream out_file(target);
        hash(in_file,out_file);
        out_file.close();
    }
    if (strcmp(argv[1],"compress") == 0) {
        ofstream out_file(target);
        compress(in_file,out_file);
        out_file.close();
    }
    if (strcmp(argv[1],"verify") == 0) {
        ifstream out_file(target);
        verify(in_file,out_file);
        out_file.close();
    }
    in_file.close();
    return 0;
}
