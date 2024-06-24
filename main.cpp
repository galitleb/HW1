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
void verify(ifstream &source, ofstream &target) {
    BlockChain block = BlockChainLoad(source);

}
int main(int argc, char **argv) {
    //  std::cout << "Hello, World!" << std::endl;
    if(argc != 4){
        getErrorMessage();
        return 0;
    }
    const string &sourcefile = argv[2];
    const string &target = argv[3];

    ifstream in_file(sourcefile);
    ofstream out_file(target);

    if (strcmp(argv[1],"format") == 0) {
        format(in_file,out_file);
    }
    if (strcmp(argv[1],"hash") == 0) {
        hash(in_file,out_file);
    }
    if (strcmp(argv[1],"compress") == 0) {
        compress(in_file,out_file);
    }
    if (strcmp(argv[1],"verify") == 0) {
        verify(in_file,out_file);
    }
    in_file.close();
    out_file.close();
    return 0;
}
