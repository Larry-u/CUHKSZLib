#include "gtest/gtest.h"
#include "containers/Map.h"

#include <map>

cuhksz::Map<int, char> testMap {
    {1, 'A'},
    {2, 'C'},
    {4, 'E'},
    {3, 'F'}
};

std::map<int, char> stlMap {
    {1, 'A'},
    {2, 'C'},
    {4, 'E'},
    {3, 'F'}
};

TEST(mapTest, initialize) {
    cuhksz::Map<int, char> initMap1;
    cuhksz::Map<int, char> initMap2( stlMap );
}

TEST(mapTest, typeConvert) {
    auto map1 = testMap.toStlMap();
    std::map<int, char> map2 = testMap;
    EXPECT_EQ(typeid(map1), typeid(stlMap));
    EXPECT_EQ(typeid(map2), typeid(stlMap));
}

TEST(mapTest, eqOperator) {
    cuhksz::Map<int, char> initMap2( stlMap );
    testMap = initMap2;
    EXPECT_EQ(testMap.size(), 4);
}

TEST(mapTest, get) {
	EXPECT_EQ(testMap.get(1), 'A');
	testMap.get(1) = 'B';
	EXPECT_EQ(testMap.get(1), 'B');
}

TEST(mapTest, indexOperator) {
	EXPECT_EQ(testMap[2], 'C');
	testMap[2] = 'S';
	EXPECT_EQ(testMap[2], 'S');
    testMap[5] = 'Z'; //access a non-exist key will create it
    EXPECT_EQ(testMap.size(), 5);
}

TEST(mapTest, erase) {
	testMap.erase(2);
	EXPECT_EQ(testMap.size(), 4);
}

TEST(mapTest, contains) {
	EXPECT_TRUE(testMap.contains(4));
	EXPECT_FALSE(testMap.contains(9));
}

TEST(mapTest, clear) {
	testMap.clear();
	EXPECT_TRUE(testMap.isEmpty());
}

TEST(mapDeathTest, keyDeath) {
	EXPECT_DEATH(testMap.get(10), "key");
}