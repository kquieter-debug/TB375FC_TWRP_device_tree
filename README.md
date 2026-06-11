# TWRP Device Tree for Lenovo Xiaoxin Pad Pro 12.7 2025 (TB375FC)

## Device specifications

| Basic       | Spec Sheet                                                |
| -----------:|:----------------------------------------------------------|
| SoC         | MediaTek Dimensity 8300 (MT6897)                          |
| CPU         | 1x 3.35 GHz Cortex-A715, 3x 3.2 GHz Cortex-A715, 4x 2.2 GHz Cortex-A510 |
| GPU         | Immortalis-G615 MC5                                       |
| Memory      | 6/8/12 GB                                                 |
| Shipped Android | 14 (ZUI 17.5)                                         |
| Storage     | 128/256 GB UFS                                            |
| Battery     | 10600 mAh, Li-Polymer                                     |
| Display     | 12.7" LCD, 2944x1840                                     |
| Dimensions  | 294.4 x 184.0 x 6.9 mm                                    |

## Build Instructions

### Environment Setup
```bash
# Initialize TWRP minimal manifest
repo init --depth=1 -u https://github.com/minimal-manifest-twrp/platform_manifest_twrp_aosp -b twrp-12.1
repo sync

# Clone this device tree
mkdir -p device/lenovo/tb375fc
# Copy files from this repo to device/lenovo/tb375fc

# Build
source build/envsetup.sh
lunch twrp_tb375fc-eng
mka vendorboot
```

### Working Features
- [X] ADB
- [X] Display (BGRA_8888)
- [X] Touch (NT36xxx + GT9772B)
- [X] Fastbootd
- [X] USB OTG / MTP
- [X] FBE Decryption (aes-256-xts + aes-256-cts)
- [X] Virtual A/B
- [X] Dynamic Partitions

## Firmware Reference

| Item | Value |
|------|-------|
| Build | TB375FC_CN_OPEN_USER_M21.814_A16_ZUI_17.5.10.060_ST_260225 |
| Android | 14 (API 34) |
| Firmware Date | 2026-02-25 |
| Platform | MT6897 (Dimensity 8300) |
| Product Board | mgvi_t_64_wifi_armv82 |
| Screen Density | 340 dpi |
| DTB | 411876 bytes (from vendor_boot) |
| Kernel | 34 MB ARM64 Image (4K pages) |

## Partition Layout
- **Slot**: A/B (Virtual A/B with compression)
- **Super**: Dynamic partitions
- **System**: EROFS
- **Vendor**: EROFS
- **Data**: F2FS (inlinecrypt)
- **Metadata**: F2FS
- **Boot**: Vendor boot v4 (ramdisk in vendor_boot)
