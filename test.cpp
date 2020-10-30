#include <QtWidgets/QTableWidget>
#include "/home/mirko25/CLionProjects/fileDiCalcolo/Sum.cpp"
#include "/home/mirko25/CLionProjects/fileDiCalcolo/Sum.h"
#include "/home/mirko25/CLionProjects/fileDiCalcolo/Max.cpp"
#include "/home/mirko25/CLionProjects/fileDiCalcolo/Max.h"
#include "/home/mirko25/CLionProjects/fileDiCalcolo/Min.cpp"
#include "/home/mirko25/CLionProjects/fileDiCalcolo/Min.h"
#include "/home/mirko25/CLionProjects/fileDiCalcolo/Media.cpp"
#include "/home/mirko25/CLionProjects/fileDiCalcolo/Media.h"
#include "/home/mirko25/CLionProjects/fileDiCalcolo/Cells.cpp"
#include "/home/mirko25/CLionProjects/fileDiCalcolo/Cells.h"
#include "/home/mirko25/CLionProjects/fileDiCalcolo/test/lib/googletest/include/gtest/gtest.h"

//cells tester
TEST(CellsTest, getValueTest) {
    Cells* c = new Cells(2,3,2, new QTableWidget);
    c->setValue(10);
    ASSERT_EQ(c->getValue(), 10);
}

 TEST(CellsTest, getBoolTest) {
    Cells* c = new Cells(2,4,6,new QTableWidget );
    c->setRegistered(true);
    ASSERT_EQ(c->getRegistered(), true);
 }

 TEST(CellsTest, getRowTest) {
    Cells* c = new Cells(2,5,0,new QTableWidget );
    ASSERT_EQ(c->getRow(), 5);
 }

TEST(CellsTest, getColumnTest) {
    Cells* c = new Cells(2,0,8,new QTableWidget );
    ASSERT_EQ(c->getColumn(), 8);
}

//sum tester
TEST(SumTest, opTest) {
    list<Cells*> c;
    Cells* c1 = new Cells(2,1,1,new QTableWidget );
    c.push_back(c1);
    Cells* c2 = new Cells(3,1,2,new QTableWidget );
    c.push_back(c2);
    Cells* c3 = new Cells(7,1,3,new QTableWidget );
    c.push_back(c3);
    Sum* sum = new Sum(c, new QTableWidget);
    ASSERT_EQ(sum->op(c), 12);
    c.remove(c2);
    ASSERT_EQ(sum->op(c), 9);
    c2->setValue(10);
    c.push_back(c2);
    ASSERT_EQ(sum->op(c), 19);

}

//max tester
TEST(MaxTest, opTest) {
    list<Cells*> c;
    Cells* c1 = new Cells(10,1,1,new QTableWidget );
    c.push_back(c1);
    Cells* c2 = new Cells(2,1,2,new QTableWidget );
    c.push_back(c2);
    Cells* c3 = new Cells(5,1,3,new QTableWidget );
    c.push_back(c3);
    Max* max = new Max(c, new QTableWidget);
    ASSERT_EQ(max->op(c), 10);
    c.remove(c1);
    ASSERT_EQ(max->op(c), 5);
}

//min tester
TEST(MnTest, opTest) {
    list<Cells*> c;
    Cells* c1 = new Cells(2,1,1,new QTableWidget );
    c.push_back(c1);
    Cells* c2 = new Cells(3,1,2,new QTableWidget );
    c.push_back(c2);
    Cells* c3 = new Cells(1,1,3,new QTableWidget );
    c.push_back(c3);
    Min* min = new Min(c, new QTableWidget);
    ASSERT_EQ(min->op(c), 1);
    c.remove(c3);
    ASSERT_EQ(min->op(c), 2);
    c2->setValue(0);
    ASSERT_EQ(min->op(c), 0);
}

//media tester
TEST(MediaTest, opTest) {
    list<Cells*> c;
    Cells* c1 = new Cells(4,1,1,new QTableWidget );
    c.push_back(c1);
    Cells* c2 = new Cells(6,1,2,new QTableWidget );
    c.push_back(c2);
    Cells* c3 = new Cells(8,1,3,new QTableWidget );
    c.push_back(c3);
    Media* media = new Media(c, new QTableWidget);
    ASSERT_EQ(media->op(c), 6);
    c.remove(c1);
    c.remove(c3);
    ASSERT_EQ(media->op(c), 6);
    Cells* c4 = new Cells(6,1,3,new QTableWidget );
    c.push_back(c4);
    ASSERT_EQ(media->op(c), 6);
}
    list<Cells*> c;
    Cells* c1 = new Cells(10,1,1,new QTableWidget );
    c.push_back(c1);
    Cells* c2 = new Cells(2,1,2,new QTableWidget );
    c.push_back(c2);
    Cells* c3 = new Cells(5,1,3,new QTableWidget );
    c.push_back(c3);
    Max* max = new Max(c, new QTableWidget);
    ASSERT_EQ(max->op(c), 10);
}
//min tester
TEST(MnTest, opTest) {
    list<Cells*> c;
    Cells* c1 = new Cells(2,1,1,new QTableWidget );
    c.push_back(c1);
    Cells* c2 = new Cells(3,1,2,new QTableWidget );
    c.push_back(c2);
    Cells* c3 = new Cells(1,1,3,new QTableWidget );
    c.push_back(c3);
    Min* min = new Min(c, new QTableWidget);
    ASSERT_EQ(min->op(c), 1);
}
//media tester
TEST(MediaTest, opTest) {
    list<Cells*> c;
    Cells* c1 = new Cells(4,1,1,new QTableWidget );
    c.push_back(c1);
    Cells* c2 = new Cells(6,1,2,new QTableWidget );
    c.push_back(c2);
    Cells* c3 = new Cells(8,1,3,new QTableWidget );
    c.push_back(c3);
    Media* media = new Media(c, new QTableWidget);
    ASSERT_EQ(media->op(c), 6);
}
