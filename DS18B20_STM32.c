#include "main.h"
#include "ds18b20.h"

UART_HandleTypeDef huart2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

int main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  DS18B20_Init(GPIOA, GPIO_PIN_12, &huart2); // Initialize DS18B20 with your GPIO pin

  char buffer[50];
  float temperature;

  while (1) {
    if (DS18B20_ReadTemperature(&temperature) == DS18B20_OK) {
      sprintf(buffer, "Temperature: %.2f C\r\n", temperature);
      HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
    }
    HAL_Delay(2000); // Delay for 2 seconds before reading temperature again
  }
}

void SystemClock_Config(void) {
  // Configure the system clock
  // ...
}

static void MX_GPIO_Init(void) {
  // Configure GPIO pins for DS18B20
  // ...
}

static void MX_USART2_UART_Init(void) {
  // Configure UART2 for communication with your computer
  // ...
}
