#ifndef __RELAY_H
#define __RELAY_H

#define RELAY_GPIO_CLK   (RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC)

#define RELAY_PORT_AUX     GPIOB
#define RELAY_AUX1_PIN     GPIO_Pin_8
#define RELAY_AUX2_PIN     GPIO_Pin_3
#define RELAY_AUX3_PIN     GPIO_Pin_6
#define RELAY_AUX4_PIN     GPIO_Pin_7

#define RELAY_PORT_AUX56   GPIOC
#define RELAY_AUX5_PIN     GPIO_Pin_5
#define RELAY_AUX6_PIN     GPIO_Pin_4

#define D_PORT_CHARGE      GPIOB
#define D_CHARGE_PIN       GPIO_Pin_4

#define RELAY_PORT_CRANK   GPIOA
#define RELAY_CRANK_PIN    GPIO_Pin_15


void RELAY_Init(void);
void RELAY_AUX1_ON(void);
void RELAY_AUX1_OFF(void);
void RELAY_AUX1_Flick(void);

void RELAY_AUX2_ON(void);
void RELAY_AUX2_OFF(void);
void RELAY_AUX2_Flick(void);

void RELAY_AUX3_ON(void);
void RELAY_AUX3_OFF(void);
void RELAY_AUX3_Flick(void);

void RELAY_AUX4_ON(void);
void RELAY_AUX4_OFF(void);
void RELAY_AUX4_Flick(void);

void RELAY_AUX5_ON(void);
void RELAY_AUX5_OFF(void);
void RELAY_AUX5_Flick(void);

void RELAY_AUX6_ON(void);
void RELAY_AUX6_OFF(void);
void RELAY_AUX6_Flick(void);

void RELAY_DCHARGE_ON(void);
void RELAY_DCHARGE_OFF(void);
void RELAY_DCHARGE_Flick(void);

void RELAY_CRANK_ON(void);
void RELAY_CRANK_OFF(void);
void RELAY_CRANK_Flick(void);

void RELAY_ALL_ON(void);
void RELAY_ALL_OFF(void);
void RELAY_ALL_Flick(void);


#endif


