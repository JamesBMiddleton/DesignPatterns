enable_testing()

add_executable(factory_test abstract_factory_test.cpp)
add_test(FactoryTest factory_test)

add_executable(builder_test builder_test.cpp)
add_test(BuilderTest builder_test)

add_executable(prototype_test prototype_test.cpp ../src/prototype.cpp)
add_test(PrototypeTest prototype_test)

add_executable(composite_test composite_test.cpp ../src/composite.cpp)
add_test(CompositeTest composite_test)
