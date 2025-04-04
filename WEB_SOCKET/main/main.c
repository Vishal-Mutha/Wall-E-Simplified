#include <stdio.h>
#include <sys/param.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_http_server.h"

#define SSID "your ssid"
#define PASS "your password"

int integer;
char stringg[64];

static const char *TAG = "ESP32 Server";

static void wifi_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    switch (event_id)
    {
    case WIFI_EVENT_STA_START:
        printf("WiFi connecting ... \n");
        break;
    case WIFI_EVENT_STA_CONNECTED:
        printf("WiFi connected ... \n");
        break;
    case WIFI_EVENT_STA_DISCONNECTED:
        printf("WiFi lost connection ... \n");
        break;
    case IP_EVENT_STA_GOT_IP:
        printf("WiFi got IP ... \n\n");
        break;
    default:
        break;
    }
}

void wifi_connection()
{
    // 1 - Wi-Fi/LwIP Init Phase
    esp_netif_init();                    // TCP/IP initiation 					s1.1
    esp_event_loop_create_default();     // event loop 			                s1.2
    esp_netif_create_default_wifi_sta(); // WiFi station 	                    s1.3
    wifi_init_config_t wifi_initiation = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&wifi_initiation); // 					                    s1.4
    // 2 - Wi-Fi Configuration Phase
    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler, NULL);
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL);
    wifi_config_t wifi_configuration = {
        .sta = {
            .ssid = SSID,
            .password = PASS}};
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_configuration);
    // 3 - Wi-Fi Start Phase
    esp_wifi_start();
    // 4- Wi-Fi Connect Phase
    esp_wifi_connect();
}

esp_err_t get_handler(httpd_req_t *req)
{
    const char resp[] = 
        "<!DOCTYPE HTML>\n"
        "<html>\n"
        "<head>\n"
        "    <title>ESP Input Form</title>\n"
        "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
        "</head>\n"
        "<body>\n"
        "\n"
        "    <form id=\"intForm\">\n"
        "        int: <input type=\"text\" id=\"intInput\" name=\"int\">\n"
        "        <input type=\"submit\" value=\"Submit Int\">\n"
        "    </form>\n"
        "    <br>\n"
        "\n"
        "    <form id=\"strForm\">\n"
        "        string: <input type=\"text\" id=\"strInput\" name=\"str\">\n"
        "        <input type=\"submit\" value=\"Submit String\">\n"
        "    </form>\n"
        "    <br>\n"
        "\n"
        "    <div id=\"response\"></div>\n"
        "\n"
        "    <script>\n"
        "        document.getElementById(\"intForm\").addEventListener(\"submit\", function(event) {\n"
        "            event.preventDefault();\n"
        "\n"
        "            var intVal = document.getElementById(\"intInput\").value;\n"
        "            var params = \"int=\" + encodeURIComponent(intVal);\n"
        "\n"
        "            var xhr = new XMLHttpRequest();\n"
        "            xhr.open(\"GET\", \"/get?\" + params, true);\n"
        "\n"
        "            xhr.onreadystatechange = function() {\n"
        "                if (xhr.readyState === 4 && xhr.status === 200) {\n"
        "                    document.getElementById(\"response\").innerHTML = \"Response: \" + xhr.responseText;\n"
        "                }\n"
        "            };\n"
        "\n"
        "            xhr.send();\n"
        "        });\n"
        "\n"
        "        document.getElementById(\"strForm\").addEventListener(\"submit\", function(event) {\n"
        "            event.preventDefault();\n"
        "\n"
        "            var strVal = document.getElementById(\"strInput\").value;\n"
        "            var params = \"str=\" + encodeURIComponent(strVal);\n"
        "\n"
        "            var xhr = new XMLHttpRequest();\n"
        "            xhr.open(\"GET\", \"/get?\" + params, true);\n"
        "\n"
        "            xhr.onreadystatechange = function() {\n"
        "                if (xhr.readyState === 4 && xhr.status === 200) {\n"
        "                    document.getElementById(\"response\").innerHTML = \"Response: \" + xhr.responseText;\n"
        "                }\n"
        "            };\n"
        "\n"
        "            xhr.send();\n"
        "        });\n"
        "    </script>\n"
        "\n"
        "</body>\n"
        "</html>\n"
        "";
    
    httpd_resp_send(req, resp, HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

esp_err_t get_handler_str(httpd_req_t *req)
{
    // Read the URI line and get the host
    char *buf;
    size_t buf_len;
    buf_len = httpd_req_get_hdr_value_len(req, "Host") + 1;
    if (buf_len > 1)
    {
        buf = malloc(buf_len);
        if (httpd_req_get_hdr_value_str(req, "Host", buf, buf_len) == ESP_OK)
        {
            ESP_LOGI(TAG, "Host: %s", buf);
        }
        free(buf);
    }

    // Read the URI line and get the parameters
     buf_len = httpd_req_get_url_query_len(req) + 1;
    if (buf_len > 1) {
        buf = malloc(buf_len);
        if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK) {
            ESP_LOGI(TAG, "Found URL query: %s", buf);
            char param[32];
            if (httpd_query_key_value(buf, "str", param, sizeof(param)) == ESP_OK) {
                strcpy(stringg, param);
                printf("%s\n", stringg);
                ESP_LOGI(TAG, "The string value = %s", param);
            }
            if (httpd_query_key_value(buf, "int", param, sizeof(param)) == ESP_OK) {
                integer = atoi(param);
                printf("%d\n", integer);
                ESP_LOGI(TAG, "The int value = %s", param);
            }
        }
        free(buf);
    }

    // The response
    const char resp[] = "The data was sent ...";
    httpd_resp_send(req, resp, HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

/* URI handler structure for GET /uri */
httpd_uri_t uri_get = {
    .uri = "/",
    .method = HTTP_GET,
    .handler = get_handler,
    .user_ctx = NULL};

httpd_uri_t uri_get_input = {
    .uri = "/get",
    .method = HTTP_GET,
    .handler = get_handler_str,
    .user_ctx = NULL};

httpd_handle_t start_webserver(void)
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    httpd_handle_t server = NULL;
    if (httpd_start(&server, &config) == ESP_OK)
    {
        httpd_register_uri_handler(server, &uri_get);
        httpd_register_uri_handler(server, &uri_get_input);
    }
    return server;
}

void stop_webserver(httpd_handle_t server)
{
    if (server)
    {
        httpd_stop(server);
    }
}

void app_main(void)
{
    nvs_flash_init();
    wifi_connection();
    start_webserver();
}