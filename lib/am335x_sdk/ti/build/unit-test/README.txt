Unity unit test framework
=========================

Directory structure
-------------------
.
├── config --> configuration files to redirect Unity prints to UART
│   ├── unity_config.c
│   └── unity_config.h
├── README.txt --> This README file
└── Unity --> Unity unit test framework
    ├── LICENSE.txt --> license file for Unity source code
    ├── src --> source and header files for Unity

What is Unity?
--------------
Unity is an open source C unit test framework targetted for embedded software.
Unity source code is packaged into Processor RTOS SDK for use in our PDK unit
tests. To view the latest source or read further documentation on Unity you
can visit the developer's GitHub page and website at the links below.
    https://github.com/ThrowTheSwitch/Unity
    http://www.throwtheswitch.org/unity

How to build
------------
Including Unity into your project is simple. 
In your test file you need to include the following two header files:
    #include "unity.h"
    #include "unity_config.h"
In your makefile you need to build the following two source files:
    ./config/unity_config.c
    ./Unity/src/unity.c
And define the UNITY_INCLUDE_CONFIG_H symbol to let Unity know you are using
a custom config:
    -DUNITY_INCLUDE_CONFIG_H

Test code structure
-------------------
Test code written using Unity is structured as follows:
    * There is a runner function that is responsible for running each of the
      individual test cases in the test file. The runner function adheres to
      the following naming convention: test_<AREA>_<test project>_runner.
      Inside the runner function you will see the following function calls:
        * UNITY_BEGIN(); /* Begin collecting test results */
        * RUN_TEST(<test function>); /* One RUN_TEST call per test function */
        * UNITY_END(); /* End testing and aggregate results */
        * print_unity_output_buffer(); /* Print Unity results summary over UART */
    * Each test case has its own test function which adheres to the following
      naming convention: test_<AREA>_<test name>, where area typically maps to
      the name of the driver being tested. Inside each test function you will
      see one or more assertions which determine the outcome of the test.
