#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint8_t top_speed;
    bool auto_mode;
    uint8_t left_speed;
    uint8_t right_speed;
} setting_fan_t;

typedef struct {
    int channel;
} setting_scan_t;

typedef enum {
    SETTING_AUTOSCAN_STATUS_ON = 0,
    SETTING_AUTOSCAN_STATUS_LAST = 1,
    SETTING_AUTOSCAN_STATUS_OFF = 2
} setting_autoscan_status_t;

typedef enum {
    SETTING_AUTOSCAN_SOURCE_LAST = 0,
    SETTING_AUTOSCAN_SOURCE_HDZERO = 1,
    SETTING_AUTOSCAN_SOURCE_EXPANSION = 2,
    SETTING_AUTOSCAN_SOURCE_AV_IN = 3,
    SETTING_AUTOSCAN_SOURCE_HDMI_IN = 4
} setting_autoscan_source_t;

typedef struct {
    setting_autoscan_status_t status;
    setting_autoscan_source_t last_source;
    setting_autoscan_source_t source;
} setting_autoscan_t;

typedef enum {
    SETTING_POWER_CELL_COUNT_MODE_AUTO = 0,
    SETTING_POWER_CELL_COUNT_MODE_MANUAL = 1
} setting_power_cell_count_mode_t;

typedef enum {
    SETTING_POWER_OSD_DISPLAY_MODE_TOTAL = 0,
    SETTING_POWER_OSD_DISPLAY_MODE_CELL = 1
} setting_power_osd_display_mode_t;

typedef enum {
    SETTING_POWER_WARNING_TYPE_BEEP = 0,
    SETTING_POWER_WARNING_TYPE_VISUAL = 1,
    SETTING_POWER_WARNING_TYPE_BOTH = 2
} setting_power_warning_type_t;

typedef struct {
    int voltage;
    bool display_voltage;
    setting_power_warning_type_t warning_type;
    setting_power_cell_count_mode_t cell_count_mode;
    int cell_count;
    setting_power_osd_display_mode_t osd_display_mode;
    bool power_ana;
} setting_power_t;

typedef enum {
    SETTING_RECORD_AUDIO_SOURCE_MIC = 0,
    SETTING_RECORD_AUDIO_SOURCE_LINE_IN = 1,
    SETTING_RECORD_AUDIO_SOURCE_AV_IN = 2
} setting_record_audio_source_t;

typedef struct {
    bool mode_manual;
    bool format_ts;
    bool osd;
    bool audio;
    setting_record_audio_source_t audio_source;
} setting_record_t;

typedef struct {
    uint8_t oled;
    uint8_t brightness;
    uint8_t saturation;
    uint8_t contrast;
    uint8_t auto_off; // 0=1min,1=3min,2=4min,3=5min,4=never,
} setting_image_t;

typedef struct {
    bool enable;
    int max_angle;
    int32_t acc_x;
    int32_t acc_y;
    int32_t acc_z;
    int32_t gyr_x;
    int32_t gyr_y;
    int32_t gyr_z;
} setting_head_tracker_t;

typedef struct {
    bool enable;
} setting_elrs_t;

typedef enum {
    EMBEDDED_4x3,
    EMBEDDED_16x9
} setting_embedded_mode_t;

typedef enum {
    SETTING_OSD_SHOW_AT_STARTUP_SHOW,
    SETTING_OSD_SHOW_AT_STARTUP_HIDE,
    SETTING_OSD_SHOW_AT_STARTUP_LAST
} setting_osd_show_at_startup_t;

typedef struct {
    int x;
    int y;
} setting_osd_goggle_element_position_t;

typedef struct {
    setting_osd_goggle_element_position_t mode_4_3;
    setting_osd_goggle_element_position_t mode_16_9;
} setting_osd_goggle_element_positions_t;

typedef struct {
    bool show;
    setting_osd_goggle_element_positions_t position;
} setting_osd_goggle_element_t;

typedef enum {
    OSD_GOGGLE_TOPFAN_SPEED = 0,
    OSD_GOGGLE_LATENCY_LOCK,
    OSD_GOGGLE_VTX_TEMP,
    OSD_GOGGLE_VRX_TEMP,
    OSD_GOGGLE_BATTERY_LOW,
    OSD_GOGGLE_BATTERY_VOLTAGE,
    OSD_GOGGLE_CHANNEL,
    OSD_GOGGLE_SD_REC,
    OSD_GOGGLE_VLQ,
    OSD_GOGGLE_ANT0,
    OSD_GOGGLE_ANT1,
    OSD_GOGGLE_ANT2,
    OSD_GOGGLE_ANT3,
    OSD_GOGGLE_TEMP_TOP,
    OSD_GOGGLE_TEMP_LEFT,
    OSD_GOGGLE_TEMP_RIGHT,
    OSD_GOGGLE_NUM,
} osd_goggle_element_e;

typedef struct {
    setting_embedded_mode_t embedded_mode;
    setting_osd_show_at_startup_t startup_visibility;
    bool is_visible;
    setting_osd_goggle_element_t element[OSD_GOGGLE_NUM];
} setting_osd_t;

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int format;
} setting_clock_t;

#define WIFI_RF_CHANNELS  14 // World Channels
#define WIFI_NETWORK_MAX  16 // Includes NULL-Terminator
#define WIFI_SSID_MAX     33 // Includes NULL-Terminator
#define WIFI_PASSWD_MAX   64 // Includes NULL-Terminator
#define WIFI_PASSWD_MIN   8  // Minimum characters allowed
#define WIFI_CLIENTID_MAX 15 // Includes NULL-Terminator

enum {
    WIFI_MODE_AP = 0,
    WIFI_MODE_STA,
    WIFI_MODE_COUNT
};

typedef struct {
    bool enable;
    uint8_t mode; // 0 == WIFI_MODE_AP, 1 == WIFI_MODE_STA
    char clientid[WIFI_CLIENTID_MAX];
    char ssid[WIFI_MODE_COUNT][WIFI_SSID_MAX];
    char passwd[WIFI_MODE_COUNT][WIFI_PASSWD_MAX];
    bool dhcp;
    char ip_addr[WIFI_NETWORK_MAX];
    char netmask[WIFI_NETWORK_MAX];
    char gateway[WIFI_NETWORK_MAX];
    char dns[WIFI_NETWORK_MAX];
    uint8_t rf_channel;
    char root_pw[WIFI_SSID_MAX];
    bool ssh;
} wifi_t;

typedef struct {
    uint8_t no_dial; // 1=disable turning channels under video mode
} ease_use_t;

typedef enum {
    SETTING_SOURCES_ANALOG_FORMAT_NTSC = 0,
    SETTING_SOURCES_ANALOG_FORMAT_PAL = 1
} setting_sources_analog_format_t;
typedef enum {
    SETTING_SOURCES_HDZERO_BAND_RACEBAND = 0,
    SETTING_SOURCES_HDZERO_BAND_LOWBAND = 1
} setting_sources_hdzero_band_t;
typedef enum {
    SETTING_SOURCES_HDZERO_BW_27MHZ = 0,
    SETTING_SOURCES_HDZERO_BW_17MHZ = 1
} setting_sources_hdzero_bw_t;

typedef struct {
    setting_sources_analog_format_t analog_format; // 0=NTSC, 1= PAL
    setting_sources_hdzero_band_t hdzero_band;
    setting_sources_hdzero_bw_t hdzero_bw;
} setting_sources_t;

typedef struct {
    bool logging;
    bool selftest;
} setting_storage_t;

typedef struct {
    setting_scan_t scan;
    setting_fan_t fans;
    setting_autoscan_t autoscan;
    setting_power_t power;
    setting_sources_t source;
    setting_record_t record;
    setting_image_t image;
    setting_head_tracker_t ht;
    setting_elrs_t elrs;
    wifi_t wifi;
    setting_osd_t osd;
    setting_clock_t clock;
    ease_use_t ease;
    setting_storage_t storage;
} setting_t;

extern setting_t g_setting;
extern const setting_t g_setting_defaults;

void settings_reset(void);
void settings_init(void);
void settings_load(void);
bool settings_get_bool(char *section, char *key, bool default_val);
int settings_put_bool(char *section, char *key, bool value);

int settings_put_osd_element(const setting_osd_goggle_element_t *element, char *config_name);
int settings_put_osd_element_pos_y(const setting_osd_goggle_element_positions_t *pos, char *config_name);
int settings_put_osd_element_pos_x(const setting_osd_goggle_element_positions_t *pos, char *config_name);
int settings_put_osd_element_shown(bool show, char *config_name);
