add_test( HelloTest.BasicAssertions /home/mo/Desktop/Github/ce-road-to-mastery/03-textbooks/02-nand2tetris/projects/06/cc/dev/hack_assembler/build/hack_assembler_test [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties( HelloTest.BasicAssertions PROPERTIES WORKING_DIRECTORY /home/mo/Desktop/Github/ce-road-to-mastery/03-textbooks/02-nand2tetris/projects/06/cc/dev/hack_assembler/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( hack_assembler_test_TESTS HelloTest.BasicAssertions)
