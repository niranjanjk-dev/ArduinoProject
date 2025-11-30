# 🛠️ VC-02 Module Flashing Instructions

This guide explains how to upload the voice commands to your VC-02 module using the provided files.

## 📂 Required Files

All necessary files are included in this package:

1. **Firmware File:** `VC-02 module load file`
   * *This contains the specific Hex codes (11, 21, etc.) required for this project.*

2. **Flashing Tool:** `UniOne Update Tool` (or the included executable)
   * *Use this software to write the firmware to the module.*

## 📺 Video Tutorial

For a visual guide on how to connect the USB-TTL adapter and use the software, please refer to this video:

* **Reference Video:** [https://youtu.be/P0UDOAZBqr4?si=rcjoGAf1GvdJjoPM]

## ⚡ Quick Steps

1. Connect your VC-02 module to your computer using a USB-to-TTL adapter (USB-Serial converter).
   * **VCC** -> 5V
   * **GND** -> GND
   * **TX** -> RX
   * **RX** -> TX

2. Open the **Flashing Tool** 
named  **`UniOneUpdateTool.exe`**
application provided in the folder **`UniOne Update Tool`**.

3. Click the **"Select"** or **"Browse"** button.

4. Choose the file named **`uni_app_release_update`** in the folder **`VC-02 module load file`**.

5. Select the correct **COM Port**.

6. Click **"Update"** or **"Burn"** to start the process.