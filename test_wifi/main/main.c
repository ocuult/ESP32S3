#include <stdio.h>
#include <nvs_flash.h>
#include <esp_wifi.h>
#include <wifi_provisioning/manager.h>
#include "wifi_provisioning/scheme_ble.h"

// 申明一个配网的注册事件的回调函数
void wifi_event_callback(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    if (WIFI_EVENT)
    {
        printf("hehe");
    }
    else if (WIFI_PROV_EVENT)
    {
    }
    else if (IP_EVENT)
    {
    }
};

void app_main(void)
{
    // 初始化NVS存储
    nvs_flash_init();
    // 初始化网络接口
    esp_netif_init();
    // 创建事件循环
    esp_event_loop_create_default();
    // 创建wifi station 模式的网络接口
    esp_netif_create_default_wifi_sta();
    // 初始化wifi参数
    wifi_init_config_t config = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&config);

    // 注册wifi
    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_callback, NULL);
    // 配网事件
    esp_event_handler_register(WIFI_PROV_EVENT, ESP_EVENT_ANY_ID, wifi_event_callback, NULL);
    // ip事件
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_callback, NULL);

    // 初始化配网管理器
    wifi_prov_mgr_config_t config_mgr = {
        .scheme = wifi_prov_scheme_ble, // 低功率蓝牙模式
        .scheme_event_handler = WIFI_PROV_SCHEME_BLE_EVENT_HANDLER_FREE_BLE,
    };
    wifi_prov_mgr_init(config_mgr);

    // 启动配网
    /* wifi_prov_mgr_start_provisioning(wifi_prov_security_t security, const void *wifi_prov_sec_params,
                                           const char *service_name, const char *service_key)
    1.wifi_prov_security_t security=1  安全机制为1，连接蓝牙的时候会弹窗确认。0为自动连接。
    2.const void *wifi_prov_sec_params  弹窗需要输入的密码
    3.const char *service_name  蓝牙名字的前缀
    4.const char *service_key
    */
    wifi_prov_mgr_start_provisioning(WIFI_PROV_SECURITY_1, "888888","PROV_Hello", NULL);
}
