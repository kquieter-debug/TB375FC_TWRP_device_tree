$(call inherit-product, $(SRC_TARGET_DIR)/product/base.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, vendor/twrp/config/common.mk)
$(call inherit-product, device/lenovo/tb375fc/device.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/virtual_ab_ota/launch_with_vendor_ramdisk.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/emulated_storage.mk)

PRODUCT_DEVICE := tb375fc
PRODUCT_NAME := twrp_tb375fc
PRODUCT_BRAND := Lenovo
PRODUCT_MODEL := TB375FC
PRODUCT_MANUFACTURER := Lenovo

PRODUCT_PROPERTY_OVERRIDES +=     ro.twrp.vendor_boot=true     persist.sys.fuse.passthrough.enable=true
