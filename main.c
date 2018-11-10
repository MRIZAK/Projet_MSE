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
void PWM_Config (uint32_t alpha); // Configuration d'une PWM variable
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
	Clock_Init();
	Gpio_Init();
	Timer_Init();
	//PWM_Config(1000); // Debug
	while(1)
	{
	}
}

/* Private function declaration -----------------------------------------------*/
void Clock_Init (void)// Initialisation de l'ensemble des clock
{
	// Input : None 
	// Output : None
	//###########################################################################################
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE); // Init clock GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);// Init clock TIM3
	
}	

void Gpio_Init (void) // Initialisation des GPIO
{
	// Input : None 
	// Output : None
	//###########################################################################################
	/** TypeDef declaration **/
	GPIO_InitTypeDef pin_GPIOB;
	
	/** Configuration GPIOB Moteur **/
	pin_GPIOB.GPIO_Pin = GPIO_Pin_4; 
	pin_GPIOB.GPIO_Mode = GPIO_Mode_AF;
  pin_GPIOB.GPIO_Speed = GPIO_Speed_40MHz;
	GPIO_Init(GPIOB, &pin_GPIOB);	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_TIM3);
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
	//###############################################################################
	/** TypeDef declaration **/
		TIM_TimeBaseInitTypeDef timer;
	/** Configuration TIM3 Moteur **/
	timer.TIM_ClockDivision = TIM_CKD_DIV1; // Division de la clock par 1
	timer.TIM_CounterMode = TIM_CounterMode_Up; // Mode incrémentation du compteur
	timer.TIM_Period = 1000; // Periode de la PWM
	timer.TIM_Prescaler = 500; // Division de la clock par 500
	TIM_TimeBaseInit(TIM3, &timer);	
	TIM_SetAutoreload(TIM3, 0x2710); // Valeur max du nombre de comptage = 10 000 
	TIM_Cmd(TIM3, ENABLE); // Activation du TIM3
	
	TIM_OCInitTypeDef channel = {0,};
  channel.TIM_OCMode = TIM_OCMode_PWM1; // Initialisation du mode de comparaison pour générer une PWM
  channel.TIM_Pulse = 0; // On initialise le rapport cyclique de la PWM à 0%
  channel.TIM_OutputState = TIM_OutputState_Enable;
  channel.TIM_OCPolarity = TIM_OCPolarity_High;
 
  TIM_OC1Init(TIM3, &channel);
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
}
void PWM_Config (uint32_t alpha) // Configuration d'une PWM variable
{
	// Input : alpha 
	// Output : None
	//###############################################################################
	if (alpha > 0 || alpha < 1000) // Gestion des erreurs
	{
	TIM_OCInitTypeDef channel;
		channel.TIM_Pulse = alpha; // Association de la valeur alpha au temps haut de la PWM = rapport cyclique
	TIM3->CCR1 = channel.TIM_Pulse;
	}
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
