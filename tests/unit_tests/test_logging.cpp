/*
 * test_logging.cpp
 *
 *  Created on: Jan 2, 2020
 *      Author: oytun
 */

#include "test_logging.h"
#include "logging/boost_trivial_logging.h"

TEST_F(LogTest, logTrace) {
	logLevelTrace();
	logTrace("TRACE LOG");
}
