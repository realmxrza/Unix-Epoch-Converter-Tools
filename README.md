# 🛠️ Epoch Converter Tool
C++ utility for converting dates into Unix Epoch timestamps and vice versa.

## 🚀 Features
* **Date to Timestamp:** Convert Year, Month, Day, Hour, Minute, and Second into a Unix Epoch.
* **Timestamp to Date:** Convert any 10-digit Epoch number back into a local date string.
* **Live Time:** A real-time updating clock showing both the current Epoch and formatted local time.
* **Input Validation:** Built-in checks to prevent invalid dates (e.g., Month 13) or out-of-range years.
* **Cross-Platform:** Automatically detects OS to clear the terminal screen correctly (Windows/Linux/macOS).

## 📅 Supported Range
The tool is optimized for the **Unix 32-bit era**:
- **Minimum:** January 1, 1970 (0)
- **Maximum:** January 19, 2038 (2147483647)
