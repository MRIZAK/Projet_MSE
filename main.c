/**
  ******************************************************************************
  * @file    Project/STM32L1xx_StdPeriph_Templates/main.c
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    16-May-2014
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Clock_Init (void); // Initialisation de l'ensemble des clock
void Gpio_Init (void); // Initialisation des GPIO
/* AFFICHEUR 7 SEGMENTS */
void Spi_Init (void); // Initialisation du port SPI afficheur 7 segments
void Set_CS (void); // Sélection du chip
void Reset_CS (void); // Désélection du chip
void SendData_SPI (uint8_t data); // Ecriture des données dans le buffer
void WriteData_SPI (uint8_t add, uint8_t data); // Envoie des données dans le chip
/* CAPTEUR DE TEMPERATURE */
void I2c_Init (void); // Initialisation du port I2C capteur de Température
void I2c_Read (uint8_t add, uint8_t nb_byte, uint8_t *data); // Acquisition des données de Température
void I2c_Write (uint8_t add, uint8_t nb_byte, uint8_t *data); // Ecriture sur les registres du capteur de Température
/* MOTEUR */
void Timer_Init (void); // Initialisation du timer pour le moteur
void PWM_Config (uint8_t alpha, uint8_t freq); // Configuration d'une PWM variable
void Speed_Set (uint8_t temp); // Asservissement de la vitesse en fonction de la température 
/* LED */
uint8_t is_dangerous(uint8_t temp); // Allumage des led en fonction de la température
/* outils*/
void Delay (uint32_t);
/* Private functions ---------------------------------------------------------*/


/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	
}

/* Private function declaration -----------------------------------------------*/
void Clock_Init (void)// Initialisation de l'ensemble des clock
{
	// Input : None 
	// Output : None
	
}	

void Gpio_Init (void) // Initialisation des GPIO
{
	// Input : None 
	// Output : None
}

/* AFFICHEUR 7 SEGMENTS */

void Spi_Init (void) // Initialisation du port SPI afficheur 7 segments
{
	// Input : None 
	// Output : None	
}
void Set_CS (void) // Sélection du chip
{
	// Input : None 
	// Output : None
}

void Reset_CS (void) // Désélection du chip
{
	// Input : None 
	// Output : None	
}
void SendData_SPI (uint8_t data) // Ecriture des données dans le buffer
{
	// Input : data  
	// Output : None
}
void WriteData_SPI (uint8_t add, uint8_t data) // Envoie des données dans le chip
{
	// Input : add,data
	// Output : None		
}
/* CAPTEUR DE TEMPERATURE */
void I2c_Init (void) // Initialisation du port I2C capteur de Température
{
	// Input : None  
	// Output : None
}
void I2c_Read (uint8_t add, uint8_t nb_byte, uint8_t *data) // Acquisition des données de Température
{
	// Input : add, nb_byte,*data  
	// Output : None	
}
void I2c_Write (uint8_t add, uint8_t nb_byte, uint8_t *data) // Ecriture sur les registres du capteur de Température
{
	// Input : add, nb_byte,*data  
	// Output : None	
}
/* MOTEUR */
void Timer_Init (void) // Initialisation du timer pour le moteur
{
	// Input : None  
	// Output : None
}
void PWM_Config (uint8_t alpha, uint8_t freq) // Configuration d'une PWM variable
{
	// Input : alpha, freq 
	// Output : None
}
void Speed_Set (uint8_t temp)// Asservissement de la vitesse en fonction de la température 
{
	// Input : temp
	// Output : None
}
/* LED */
uint8_t is_dangerous(uint8_t temp) // Allumage des led en fonction de la température
{
	// Input : temp
	// Output : 0 or 1
}
/* outils*/
void Delay (uint32_t Tempo)
{
	// Input : tempo
	// Output : none
	while(Tempo--); 
}






#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
