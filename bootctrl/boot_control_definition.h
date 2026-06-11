struct bootloader_message_ab {
    struct bootloader_message message;
    char slot_suffix[32];
    char update_channel[128];
    char reserved[1888];
};

#if (__STDC_VERSION__ >= 201112L) || defined(__cplusplus)
static_assert(sizeof(struct bootloader_message_ab) == 4096,
              "struct bootloader_message_ab size changes");
#endif

#define BOOT_CTRL_MAGIC   0x42414342
#define BOOT_CTRL_VERSION 1

struct slot_metadata {
    uint8_t priority : 4;
    uint8_t tries_remaining : 3;
    uint8_t successful_boot : 1;
    uint8_t verity_corrupted : 1;
    uint8_t reserved : 7;
} __attribute__((packed));

struct bootloader_control {
    char slot_suffix[4];
    uint32_t magic;
    uint8_t version;
    uint8_t nb_slot : 3;
    uint8_t recovery_tries_remaining : 3;
    uint8_t merge_status : 3;
    uint8_t reserved0[1];
    struct slot_metadata slot_info[4];
    uint8_t reserved1[8];
    uint32_t crc32_le;
} __attribute__((packed));

#if (__STDC_VERSION__ >= 201112L) || defined(__cplusplus)
static_assert(sizeof(struct bootloader_control) ==
              sizeof(((struct bootloader_message_ab *)0)->slot_suffix),
              "struct bootloader_control has wrong size");
#endif

namespace android {
namespace bootable {
    bool UpdateAndSaveBootloaderControl(const std::string& misc_device, bootloader_control* buffer);
    bool LoadBootloaderControl(const std::string& misc_device, bootloader_control* buffer);
    uint32_t BootloaderControlLECRC(const bootloader_control* boot_ctrl);
}
}
