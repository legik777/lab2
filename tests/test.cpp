// Copyright 2020 Andreytorix
#include <utility>
#include "SP.hpp"
#include <gtest/gtest.h>

class testClass {
public:
    int value;
    std::string name;

    explicit testClass(int value_ = 10,
                     std::string name_ = "Typical Class") { //изменить
        value = value_;
        name = std::move(name_);
    }

    bool operator==(const testClass& ref) const {
        bool out = false;
        out = value == ref.value; //изменить
        out = name == ref.name;
        return out;
    }
};

int testf(int value) {
    return value + 777;
}

int testfL(int& value) {
    return value += 999;
}

testClass testfClass(testClass object) {
    object.name = "testf";
    object.value = 10500;
    return object;
}

testClass testfClass_Link(testClass& object) {
    object.name = "testfL";
    object.value = 10500800;
    return object;
}

TEST(SP, defaultType) {
    testClass testObject;

    SharedPtr<testClass> pobject1(&testObject);
    SharedPtr<testClass> pobject2(pobject1);

    EXPECT_EQ(pobject1.GetCount(), 2);
    EXPECT_EQ(pobject2.GetCount(), 2);

    EXPECT_EQ(pobject1.Get()->name, "Typical Class");
    EXPECT_EQ(pobject2.Get()->name, "Typical Class");

    EXPECT_EQ(pobject1.Get()->value, 10);
    EXPECT_EQ(pobject2.Get()->value, 10);

    EXPECT_EQ(pobject1->value, 10);
    EXPECT_EQ(pobject2->value, 10);

    EXPECT_TRUE(pobject1);
    EXPECT_TRUE(pobject2);

    EXPECT_EQ(testfClass(*pobject1), testClass(100500, "testf"));
    EXPECT_EQ(testfClass(*pobject2), testClass(100500, "testf"));

    EXPECT_EQ(
        testfClass_Link(*pobject1),
        testClass(100500800, "testfL"));
    EXPECT_EQ(
        *pobject2,
        testClass(100500800, "testfL"));
}

TEST(SP, SwapTestTempType) {
    int firstValue = 5;

    SharedPtr<int> pvalue1_1(&firstValue);
    SharedPtr<int> pvalue1_2(pvalue1_1);

    int secondValue = 10;

    SharedPtr<int> pvalue2_1(&secondValue);
    SharedPtr<int> pvalue2_2(pvalue2_1);
    SharedPtr<int> pvalue2_3(pvalue2_2);

    pvalue2_1.Swap(pvalue1_1);

    EXPECT_EQ(pvalue1_1.GetCount(), 3);
    EXPECT_EQ(pvalue2_1.GetCount(), 2);

    EXPECT_EQ(*pvalue1_1, 10);
    EXPECT_EQ(*pvalue2_1, 5);
}

TEST(SP, SwapTestCustomType) {
    testClass firstObject{
        10, "First"
    };
    testClass secondObject{
        5, "Second"
    };

    SharedPtr<testClass> pobject1_1(&firstObject);
    SharedPtr<testClass> pobject1_2(pobject1_1);

    SharedPtr<testClass> pobject2_1(&secondObject);
    SharedPtr<testClass> pobject2_2(pobject2_1);
    SharedPtr<testClass> pobject2_3(pobject2_2);

    pobject1_1.Swap(pobject2_1);

    EXPECT_EQ(pobject1_1.GetCount(), 3);
    EXPECT_EQ(pobject2_1.GetCount(), 2);

    EXPECT_EQ(*pobject1_1, testClass(5, "Second"));
    EXPECT_EQ(*pobject2_1, testClass(10, "First"));
}

class NotCopiable {
public:
    NotCopiable& operator= (NotCopiable&) = delete;
};

TEST(ErrorTest, TestCopiable) {
    try {
        NotCopiable notCopiableObject;
        SharedPtr<NotCopiable> pointer(&notCopiableObject);
        SharedPtr<NotCopiable> error(pointer);
    }
    catch (std::runtime_error& er) {
        std::string ref = "ERROR: Not copiable type!";
        EXPECT_EQ(ref, er.what());
    }
}

class NotAssignable {
public:
    NotAssignable& operator= (NotAssignable&&) = delete;
};

TEST(ErrorTest, TestAssignable) {
    try {
        NotAssignable notAssignableObject;

        SharedPtr<NotAssignable> pointer(&notAssignableObject);
        SharedPtr<NotAssignable> error;
    }
    catch (std::runtime_error& er) {
        std::string ref = "ERROR: Not assignable type!";
        EXPECT_EQ(ref, er.what());
    }
}

TEST(ErrorTest, TestCopiableOperator) {
    try {
        NotCopiable notCopiableObject;
        SharedPtr<NotCopiable> pointer(&notCopiableObject);
        SharedPtr<NotCopiable> error = pointer;
    }
    catch (std::runtime_error& er) {
        std::string ref = "ERROR: Not copiable type!";
        EXPECT_EQ(ref, er.what());
    }
}
