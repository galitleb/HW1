#include <iostream>
#include <fstream>
#include "BlockChain.h"

void format(std::ifstream &in_file, std::ofstream &out_file) {
    BlockChain block = BlockChainLoad(in_file);
    BlockChainDump(block, out_file);
}

void hash(std::ifstream &in_file, std::ofstream &out_file){
    BlockChain block = BlockChainLoad(in_file);
    BlockChainDumpHashed(block, out_file);
}
void compress(std::ifstream &in_file, std::ofstream &out_file) {
    BlockChain block = BlockChainLoad(in_file);
    BlockChainDump(block, out_file);
    BlockChainCompress(block);
}

int main(int argc, char **argv) {
    //  std::cout << "Hello, World!" << std::endl;
    if(argc != 4){
        return 0;
    }
    const std::string &sourcefile = argv[2];
    const std::string &target = argv[3];

    std::ifstream in_file(sourcefile);
    std::ofstream out_file(target);

    if (argv[1] == "format") {
        format(in_file,out_file);
    }
    if (argv[1] == "hash")) {
        hash(in_file,out_file);
    }
    if (argv[1] == "compress") {
        compress(in_file,out_file);
    }
    in_file.close();
    out_file.close();
    return 0;
}
