/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/*******************************************************************************
 * MSP432 Timer Interrupt
 *
 *
 *                MSP432P401
 *             ------------------
 *         /|\|                  |
 *          | |                  |
 *          --|RST         P3.6  |---> Trigger
 *            |                  |
 *            |            P3.7  |<--- Echo
 *            |                  |
 *            |                  |
 *
 ******************************************************************************/
/* DriverLib Includes */
#include <driverlib.h>

#define MIN_DISTANCE    10.0f
#define TICKPERIOD      1000

uint32_t SR04IntTimes;
uint32_t SR04IntTimes1;
uint32_t SR04IntTimes2;
uint32_t countval0=0, countval1=0, countval2=0, countval3=0, countstat;
uint32_t countval01=0, countval11=0, countval21=0, countval31=0, countstat1;
uint32_t countval02=0, countval12=0, countval22=0, countval32=0, countstat2;
uint32_t tval1, tval2, nn=0; avgdist;
// -------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------

void Initalise_HCSR04(void)
{
    /* Timer_A UpMode Configuration Parameter */
    const Timer_A_UpModeConfig upConfig =
    {
            TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
            TIMER_A_CLOCKSOURCE_DIVIDER_3,          // SMCLK/3 = 1MHz
            TICKPERIOD,                             // 1000 tick period
            TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
            TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
            TIMER_A_DO_CLEAR                        // Clear value
    };



    int a = CS_getSMCLK();

    /* Configure P1.0 and set it to LOW */
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);

    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);


    /* Configuring P3.6 as Output */
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN6);//
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);//
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, GPIO_PIN7);

    /* Configuring P6.6 as Output */
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN6);//
    GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN6);//
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN7);

    /* Configuring P2.6 as Output */
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN6);//
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN6);//
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P4, GPIO_PIN7);

    /* Configuring Timer_A0 for Up Mode */
    Timer_A_configureUpMode(TIMER_A0_BASE, &upConfig);


    /* Enabling interrupts and starting the timer */
    Interrupt_enableInterrupt(INT_TA0_0);


    //Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);

    //Timer_A_stopT
}
void TA0_0_IRQHandler(void)
{
    /* Increment global variable (count number of interrupt occurred) */
    SR04IntTimes++;
    SR04IntTimes1++;
    SR04IntTimes2++;

    /* Clear interrupt flag */
    Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
    Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1);
    Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_2);
}


// -------------------------------------------------------------------------------------------------------------------

// 10000 counter, effective clock 1/1mhz = 1ms, smclk3mhz, div = 3 , effective clk = 1mhz
//get ticks
// can chang counter , clk and divider
static uint32_t getHCSR04Time(void)
{
    uint32_t pulsetime=0;

    /* Number of times the interrupt occurred (1 interrupt = 1000 ticks)    */
    pulsetime = SR04IntTimes * TICKPERIOD;

    /* Number of ticks (between 1 to 999) before the interrupt could occur */
    pulsetime += Timer_A_getCounterValue(TIMER_A0_BASE);

    /* Clear Timer */
    Timer_A_clearTimer(TIMER_A0_BASE);

 //   Delay(3000);

    return pulsetime;
}

static uint32_t getHCSR04Time1(void)
{
    uint32_t pulsetime=0;

    /* Number of times the interrupt occurred (1 interrupt = 1000 ticks)    */
    pulsetime = SR04IntTimes1 * TICKPERIOD;

    /* Number of ticks (between 1 to 999) before the interrupt could occur */
    pulsetime += Timer_A_getCounterValue(TIMER_A0_BASE);

    /* Clear Timer */
    Timer_A_clearTimer(TIMER_A0_BASE);

 //   Delay(3000);

    return pulsetime;
}

static uint32_t getHCSR04Time2(void)
{
    uint32_t pulsetime=0;

    /* Number of times the interrupt occurred (1 interrupt = 1000 ticks)    */
    pulsetime = SR04IntTimes2 * TICKPERIOD;

    /* Number of ticks (between 1 to 999) before the interrupt could occur */
    pulsetime += Timer_A_getCounterValue(TIMER_A0_BASE);

    /* Clear Timer */
    Timer_A_clearTimer(TIMER_A0_BASE);

 //   Delay(3000);

    return pulsetime;
}

// -------------------------------------------------------------------------------------------------------------------

float getHCSR04Distance(void)
{
    uint32_t pulseduration = 0;
    float calculateddistance = 0;

    /* Generate 10us pulse at P3.6 */
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6);//--------
  //  Delay(30);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);  // ------_____



    /* Wait for positive-edge, 3.7 = 0 i will wait here, wait for input */
    /*improvement set interrupt low to high or something*/
    while(GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN7) == 0);

    /* Start Timer */
    SR04IntTimes = 0;
    Timer_A_clearTimer(TIMER_A0_BASE);
    Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);

    /* Detects negative-edge */
    /*stop when high to low*/
    while(GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN7) == 1);
    /* Stop Timer */
    Timer_A_stopTimer(TIMER_A0_BASE);

    /* Obtain Pulse Width in microseconds */
    pulseduration = getHCSR04Time();


    /* Calculating distance in cm */
    calculateddistance = (float)pulseduration / 58.0f;





    return calculateddistance;
}

float getHCSR04Distance1(void)
{
    uint32_t pulseduration = 0;
    float calculateddistance = 0;

    /* Generate 10us pulse at P3.6 */
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN6);//--------
  //  Delay(30);
    GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN6);  // ------_____



    /* Wait for positive-edge, 3.7 = 0 i will wait here, wait for input */
    /*improvement set interrupt low to high or something*/
    while(GPIO_getInputPinValue(GPIO_PORT_P6, GPIO_PIN7) == 0);

    /* Start Timer */
    SR04IntTimes1 = 0;
    Timer_A_clearTimer(TIMER_A0_BASE);
    Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);

    /* Detects negative-edge */
    /*stop when high to low*/
    while(GPIO_getInputPinValue(GPIO_PORT_P6, GPIO_PIN7) == 1);
    /* Stop Timer */
    Timer_A_stopTimer(TIMER_A0_BASE);

    /* Obtain Pulse Width in microseconds */
    pulseduration = getHCSR04Time1();


    /* Calculating distance in cm */
    calculateddistance = (float)pulseduration / 58.0f;





    return calculateddistance;
}

float getHCSR04Distance2(void)
{
    uint32_t pulseduration = 0;
    float calculateddistance = 0;

    /* Generate 10us pulse at P3.6 */
    GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN6);//--------
  //  Delay(30);
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN6);  // ------_____



    /* Wait for positive-edge, 3.7 = 0 i will wait here, wait for input */
    /*improvement set interrupt low to high or something*/
    while(GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN7) == 0);

    /* Start Timer */
    SR04IntTimes2 = 0;
    Timer_A_clearTimer(TIMER_A0_BASE);
    Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);

    /* Detects negative-edge */
    /*stop when high to low*/
    while(GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN7) == 1);
    /* Stop Timer */
    Timer_A_stopTimer(TIMER_A0_BASE);

    /* Obtain Pulse Width in microseconds */
    pulseduration = getHCSR04Time2();


    /* Calculating distance in cm */
    calculateddistance = (float)pulseduration / 58.0f;





    return calculateddistance;
}

// -------------------------------------------------------------------------------------------------------------------

uint32_t main(void)
{
    Initalise_HCSR04();


    while(1)
    {
        int dist = getHCSR04Distance();
        int dist1 = getHCSR04Distance1();
        int dist2 = getHCSR04Distance2();

        /*take an average of 4 reading because single reading a bit inactive*/
                  countval3=countval2;
                  countval2=countval1;
                  countval1=countval0;
                  countval0 = dist;

                  countval31=countval21;
                  countval21=countval11;
                  countval11=countval01;
                  countval01 = dist1;

                  countval32=countval22;
                  countval22=countval12;
                  countval12=countval02;
                  countval02 = dist2;




                  // ignore outliers
                  countstat=(countval3+countval2+countval1+countval0)>>2;
                  countstat1=(countval31+countval21+countval11+countval01)>>2;
                  countstat2=(countval32+countval22+countval12+countval02)>>2;


                  nn=nn+1;
                  if(nn>3)
                  {

                      //printf("s1 %d cm\n", (int)(countstat));
                      //printf("s2 %d cm\n", (int)(countstat1));
                      //printf("s3 %d cm\n", (int)(countstat2));

                     nn=0;
                  }



        if((getHCSR04Distance() < MIN_DISTANCE)){

            printf("s1 = 1 \n");
            GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0 | GPIO_PIN2);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);


        }

        else
            printf("s1 = 0 \n");

        if((getHCSR04Distance1() < MIN_DISTANCE)){

            printf("s2 = 1 \n");
            GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0 | GPIO_PIN2);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
        }

        else
            printf("s2 = 0 \n");

        if((getHCSR04Distance2() < MIN_DISTANCE)){

            printf("s3 = 1 \n");
            GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0 | GPIO_PIN2);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);

        }

        else
            printf("s2 = 0 \n");


     }
}
