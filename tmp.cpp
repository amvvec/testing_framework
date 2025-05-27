/*
#define TEST_F(FixtureClass, TestName) { \
    struct FixtureClass##_##TestName : public FixtureClass { \
        void TestBody(); \
    } \
    static void FixtureClass##_##TestName##_runner() { \
        FixtureClass##_##TestName## fixture; \
        fixture.SetUp(); \
        fixture.TestBody(); \
        fixture.TearDown(); \
    } \
    static ::unit::AutoRegister auto_##FixtureClass##_##TestName(
        #FixtureClass, #TestName, &Fixtureclass##_##TestName##_runner
    )
    void FixtureClass##_##TestName::TestBody()
}
*/

#define TEST_F(FixtureClass, TestName) { \
    
}
