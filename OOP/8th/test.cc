#include "gtest/gtest.h"
#include "car_parts_factory.h"
#include "car.h"
#include "car_builder.h"
#include "kia_parts_factory.h"
#include "hyundai_parts_factory.h"

// 1. Car 객체 생성 테스트 - Kia Factory 기반
TEST(CarBuilderTest, CreateKiaCar) {
    KiaPartsFactory* kiaFactory = KiaPartsFactory::GetInstance();
    CarBuilder builder(kiaFactory);

    Car* kiaCar = builder.CreateDoor().CreateWheel().
    CreateRoof().SetColor("Red").Build();
    ASSERT_NE(kiaCar, nullptr);
    ASSERT_EQ(kiaCar->GetSpec(), "[kia] Door, [kia] Wheel, [kia] Roof, Red");

    delete kiaCar;
}

// 2. Car 객체 생성 테스트 - Hyundai Factory 기반
TEST(CarBuilderTest, CreateHyundaiCar) {
    HyundaiPartsFactory* hyundaiFactory = HyundaiPartsFactory::GetInstance();
    CarBuilder builder(hyundaiFactory);

    Car* hyundaiCar = builder.CreateDoor().CreateWheel().
    CreateRoof().SetColor("Blue").Build();
    ASSERT_NE(hyundaiCar, nullptr);
    ASSERT_EQ(hyundaiCar->GetSpec(),
    "[hyundai] Door, [hyundai] Wheel, [hyundai] Roof, Blue");

    delete hyundaiCar;
}

// 3. 중복 생성 오류 테스트 - Door
TEST(CarBuilderTest, DuplicateDoorError) {
    KiaPartsFactory* kiaFactory = KiaPartsFactory::GetInstance();
    CarBuilder builder(kiaFactory);

    builder.CreateDoor();
    ASSERT_DEATH(builder.CreateDoor(), "Duplicated Parts retain : Door");
}

// 4. 중복 생성 오류 테스트 - Wheel
TEST(CarBuilderTest, DuplicateWheelError) {
    HyundaiPartsFactory* hyundaiFactory = HyundaiPartsFactory::GetInstance();
    CarBuilder builder(hyundaiFactory);

    builder.CreateWheel();
    ASSERT_DEATH(builder.CreateWheel(), "Duplicated Parts retain : Wheel");
}

// 5. 중복 생성 오류 테스트 - Roof
TEST(CarBuilderTest, DuplicateRoofError) {
    KiaPartsFactory* kiaFactory = KiaPartsFactory::GetInstance();
    CarBuilder builder(kiaFactory);

    builder.CreateRoof();
    ASSERT_DEATH(builder.CreateRoof(), "Duplicated Parts retain : Roof");
}

// 6. 부품누락 테스트
TEST(CarBuilderTest, FewPartsTest) {
    KiaPartsFactory* kiaFactory = KiaPartsFactory::GetInstance();
    CarBuilder builder(kiaFactory);

    Car* DepectedCar = builder.CreateDoor().CreateRoof().
    SetColor("Red").Build();
    ASSERT_NE(DepectedCar, nullptr);
    ASSERT_EQ(DepectedCar->GetSpec(), "[kia] Door, [kia] Roof, Red");

    delete DepectedCar;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
