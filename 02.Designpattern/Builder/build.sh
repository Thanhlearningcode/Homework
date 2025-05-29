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
echo "Build started at: $TIME_START" >> "$LOG_FILE"
echo "===============================" >> "$LOG_FILE"
echo "" >> "$LOG_FILE"

# === Run build and capture exit status ===
echo "🔨 Running make..."
make all 2>&1 | tee -a "$LOG_FILE"
MAKE_EXIT_CODE=${PIPESTATUS[0]}  # Bắt mã lỗi từ lệnh make (dù tee luôn thành công)

# === Check result ===
if [ $MAKE_EXIT_CODE -eq 0 ]; then
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
