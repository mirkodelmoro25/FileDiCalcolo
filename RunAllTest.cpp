#include <QApplication>
#include "/home/mirko25/CLionProjects/fileDiCalcolo/test/lib/googletest/include/gtest/gtest.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
