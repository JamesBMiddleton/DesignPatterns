enable_testing()

add_executable(factory_test abstract_factory_test.cpp)
add_test(FactoryTest factory_test)

add_executable(builder_test builder_test.cpp)
add_test(BuilderTest builder_test)
