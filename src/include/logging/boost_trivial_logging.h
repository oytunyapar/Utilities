#pragma once

void logLevelTrace();
void logLevelDebug();
void logLevelInfo();
void logLevelWarning();
void logLevelError();
void logLevelFatal();

void logTrace(const char* log);
void logDebug(const char* log);
void logInfo(const char* log);
void logWarning(const char* log);
void logError(const char* log);
void logFatal(const char* log);
