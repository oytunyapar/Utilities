/*
 * boost_trivial_logging.cpp
 *
 *  Created on: Jan 2, 2020
 *      Author: oytun
 */
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "logging/boost_trivial_logging.h"

namespace logging = boost::log;

void setLoggingLevel( const logging::trivial::severity_level& logging_level )
{
    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging_level
    );
}

void logLevelTrace()
{
    setLoggingLevel( logging::trivial::trace );
}

void logLevelDebug()
{
    setLoggingLevel( logging::trivial::debug );
}

void logLevelInfo()
{
    setLoggingLevel( logging::trivial::info );
}

void logLevelWarning()
{
    setLoggingLevel( logging::trivial::warning );
}

void logLevelError()
{
    setLoggingLevel( logging::trivial::error );
}

void logLevelFatal()
{
    setLoggingLevel( logging::trivial::fatal );
}

void logTrace(const char* log)
{
	BOOST_LOG_TRIVIAL(trace) << log;
}

void logDebug(const char* log)
{
	BOOST_LOG_TRIVIAL(debug) << log;
}

void logInfo(const char* log)
{
	BOOST_LOG_TRIVIAL(info) << log;
}

void logWarning(const char* log)
{
	BOOST_LOG_TRIVIAL(warning) << log;
}

void logError(const char* log)
{
	BOOST_LOG_TRIVIAL(error) << log;
}

void logFatal(const char* log)
{
	BOOST_LOG_TRIVIAL(fatal) << log;
}
