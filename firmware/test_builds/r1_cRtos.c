#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_wifi.h>
#include <esp_log.h>
#include <pubsub.h>
#include <driver/gpio.h>

#define WIFI_SSID "Germanium"
#define WIFI_PASSWORD "Germanium"
#define MQTT_SERVER "192.168.0.101"
#define MQTT_PORT 1883
#define MQTT_CLIENT_ID "ESP32_ROOM_1"

#define LED_PIN 2

#define SWITCH_1_PIN 15
#define SWITCH_2_PIN 4
#define SWITCH_3_PIN 16
#define SWITCH_4_PIN 17

#define TOUCH_1_PIN 13
#define TOUCH_2_PIN 33
#define TOUCH_3_PIN 14
#define TOUCH_4_PIN 27

const char *TAG = "PRISM_SENSOR";

static const char *topics[] = {
    "prism/board1/switch1",
    "prism/board1/switch2",
    "prism/board1/switch3",
    "prism/board1/switch4",
};

static const char *touch_topics[] = {
    "prism/board1/touch1",
    "prism/board1/touch2",
    "prism/board1/touch3",
    "prism/board1/touch4",
};

static pubsub_t *mqtt_client;

static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_CONNECTED) {
        ESP_LOGI(TAG, "Connected to Wi-Fi");
        pubsub_connect(mqtt_client, MQTT_SERVER, MQTT_PORT, MQTT_CLIENT_ID, 0);
        pubsub_subscribe(mqtt_client, topics, sizeof(topics) / sizeof(topics[0]));
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        ESP_LOGI(TAG, "Disconnected from Wi-Fi");
    }
}

static void touch_read_task(void *pvParameters)
{
    while (1) {
        for (int i = 0; i < sizeof(touch_topics) / sizeof(touch_topics[0]); i++) {
            int touch_state = gpio_get_level(touch_pins[i]);
            const char *message = touch_state ? "high" : "low";
            pubsub_publish(mqtt_client, touch_topics[i], message, 0);
            ESP_LOGI(TAG, "%s: %s", touch_topics[i], message);
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

static void mqtt_event_handler(pubsub_event_t *event)
{
    switch (event->type) {
        case PUBSUB_EVENT_CONNECT:
            ESP_LOGI(TAG, "Connected to MQTT broker");
            break;
        case PUBSUB_EVENT_DISCONNECT:
            ESP_LOGI(TAG, "Disconnected from MQTT broker");
            break;
        case PUBSUB_EVENT_PUBLISH:
            // Not used for this application
            break;
        default:
            break;
    }
}

void app_main(void)
{
    esp_log_level_set(TAG, ESP_LOG_INFO);

    // Initialize Wi-Fi
    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_EVENT, wifi_event_handler, NULL);
    wifi_init_config config = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&config);

    // Configure pins
    gpio_config_t io_conf = {};
    // LED pin as output
    io_conf.pin_bit = (1ULL << LED_PIN);
    io_conf.mode = GPIO_MODE_OUTPUT;
    gpio_config(&io_conf);
    gpio

