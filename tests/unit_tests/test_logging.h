/*
 * test_logging.h
 *
 *  Created on: Jan 2, 2020
 *      Author: oytun
 */

#ifndef TESTS_UNIT_TESTS_TEST_LOGGING_H_
#define TESTS_UNIT_TESTS_TEST_LOGGING_H_

#include "gtest/gtest.h"

class LogTest : public ::testing::Test
{
protected:
    LogTest() { }

    ~LogTest() override { }

    void SetUp() override { }

    void TearDown() override { }
};

#endif /* TESTS_UNIT_TESTS_TEST_LOGGING_H_ */
