#!/bin/bash

# ================================
# Build and Run Unit Tests Script
# Author: Nguyen Van Thanh
# ================================

AUTHOR="THANH"
ROOT_DIR=$(pwd)
LOG_DIR="$ROOT_DIR/LOGGING"
LOG_FILE="$LOG_DIR/test_build.log"
BUILD_DIR="$ROOT_DIR/tests/build"
TEST_BINARY="uart_builder_test"

# Ensure build and log directories exist
mkdir -p "$LOG_DIR"
mkdir -p "$BUILD_DIR"

# Start logging
echo "===============================" > "$LOG_FILE"
echo "Test Build started at: $(date '+%Y-%m-%d %H:%M:%S')" >> "$LOG_FILE"
echo "===============================" >> "$LOG_FILE"
echo "" >> "$LOG_FILE"

# Build project
cd "$BUILD_DIR" || {
  echo "❌ Failed to cd to build directory: $BUILD_DIR" | tee -a "$LOG_FILE"
  exit 1
}

echo "🔨 Running cmake and make..." | tee -a "$LOG_FILE"
if cmake .. 2>&1 | tee -a "$LOG_FILE" && make VERBOSE=1 2>&1 | tee -a "$LOG_FILE"; then
  echo "✅ Build completed successfully!" | tee -a "$LOG_FILE"
else
  echo "❌ Build failed!" | tee -a "$LOG_FILE"
  exit 1
fi

# Run tests
if [ -x "$TEST_BINARY" ]; then
  echo "" | tee -a "$LOG_FILE"
  echo "▶️ Running unit tests ($TEST_BINARY)..." | tee -a "$LOG_FILE"
  ./"$TEST_BINARY" 2>&1 | tee -a "$LOG_FILE"
  TEST_RESULT=${PIPESTATUS[0]}
  
  if [ $TEST_RESULT -eq 0 ]; then
    echo "✅ Tests passed!" | tee -a "$LOG_FILE"
  else
    echo "❌ Tests failed!" | tee -a "$LOG_FILE"
    exit 1
  fi
else
  echo "❌ Test binary $TEST_BINARY not found or not executable!" | tee -a "$LOG_FILE"
  exit 1
fi

echo "🕒 Completed at: $(date '+%Y-%m-%d %H:%M:%S')" | tee -a "$LOG_FILE"
echo "Build and test started by: $AUTHOR" >> "$LOG_FILE"
echo "===============================" >> "$LOG_FILE"

exit 0
