#include "src/Worker.h"
#include "src/multithreadedFileHandler.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "usage: ./multithreadedFileHandler [file1] [file2]" << std::endl;
        return 1;
    }
    std::ifstream file1(argv[1]);
    std::ifstream file2(argv[2]);
    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "error" << std::endl;
        return 1;
    }
    MultithreadedFileHandler handler;
    Worker worker;
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &handler, argv[1]);
    worker.startNewThread(&MultithreadedFileHandler::processFile, &handler);
    worker.joinAllThreads();
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &handler, argv[2]);
    worker.startNewThread(&MultithreadedFileHandler::processFile, &handler);
    worker.joinAllThreads();

}
