#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_wifi.h>
#include <esp_log.h>
#include <pubsub.h>
#include <dht.h>

#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PWD"
#define MQTT_SERVER "RPI_IP"
#define MQTT_PORT 1883
#define MQTT_CLIENT_ID "ESP32_SENSOR_ROOM_1"

#define DHT_PIN 15
#define LDR_PIN 4
#define LED_PIN 2

#define DHT_TYPE DHT11

static const char *TAG = "PRISM_SENSOR";

static dht_sensor_t *dht_sensor;

static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_CONNECTED) {
        esp_event_t *event = (esp_event_t *)event_data;
        wifi_event_sta_connected_t *connected = &event->event.sta_connected;
        ESP_LOGI(TAG, "Connected to %s, channel %d", connected->ssid, connected->channel);
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        ESP_LOGI(TAG, "Disconnected from access point");
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
            ESP_LOGI(TAG, "Published message: %s", event->data.publish.data);
            break;
        default:
            break;
    }
}

static void sensor_read_task(void *pvParameters)
{
    while (1) {
        int ldr_state = gpio_get_level(LDR_PIN);
        int dht_temp = dht_read_temperature(dht_sensor);
        int dht_humi = dht_read_humidity(dht_sensor);

        if (ldr_state) {
            pubsub_publish(mqtt_client, "prism/sboard1/sensor3", "high", 0);
            ESP_LOGI(TAG, "Light HIGH");
        } else {
            pubsub_publish(mqtt_client, "prism/sboard1/sensor3", "low", 0);
            ESP_LOGI(TAG, "Light LOW");
        }

        if (dht_temp != DHT_READ_ERROR) {
            char temp_str[10];
            sprintf(temp_str, "%d", dht_temp);
            pubsub_publish(mqtt_client, "prism/sboard1/sensor1", temp_str, 0);
            ESP_LOGI(TAG, "TEMP: %d", dht_temp);
        }

        if (dht_humi != DHT_READ_ERROR) {
            char humi_str[10];
            sprintf(humi_str, "%d", dht_humi);
            pubsub_publish(mqtt_client, "prism/sboard1/sensor2", humi_str, 0);
            ESP_LOGI(TAG, "HUMI: %d", dht_humi);
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void app_main(void)
{
    esp_log_level_set(TAG, ESP_LOG_INFO);

    // Initialize Wi-Fi
    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_EVENT, wifi_event_handler, NULL);
    wifi_init_config

