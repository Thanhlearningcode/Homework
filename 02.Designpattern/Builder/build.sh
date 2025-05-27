#!/bin/bash

# ================================
# Build Script for STM32 Project
# Author: Nguyen Van Thanh
# ================================

# === Config ===
AUTHOR="THANH"
LOG_DIR="LOGGING"
LOG_FILE="$LOG_DIR/build.log"
TIME_START=$(date '+%Y-%m-%d %H:%M:%S')

# === Ensure build folder exists ===
mkdir -p "$LOG_DIR"

# === Start logging ===
echo "===============================" > "$LOG_FILE"
echo "Build started at: $TIME_START" >>  "$LOG_FILE"
echo "===============================" >> "$LOG_FILE"
echo "" >> "$LOG_FILE"

# === Run build ===
echo "🔨 Running make..."
if make all 2>&1 | tee -a "$LOG_FILE"; then
    echo "" | tee -a "$LOG_FILE"
    echo "✅ Build completed successfully!" | tee -a "$LOG_FILE"
    echo "🕒 Completed at: $(date '+%Y-%m-%d %H:%M:%S')" | tee -a "$LOG_FILE"
    echo "Build started by: $AUTHOR" >> "$LOG_FILE"
    echo "===============================" >> "$LOG_FILE"
    exit 0
else
    echo "" | tee -a "$LOG_FILE"
    echo "❌ Build failed!" | tee -a "$LOG_FILE"
    echo "🕒 Failed at: $(date '+%Y-%m-%d %H:%M:%S')" | tee -a "$LOG_FILE"
    echo "===============================" >> "$LOG_FILE"
    exit 1
fi